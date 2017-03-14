#include <cstdio>
#include <tuple>
#include <queue>
#include <set>

using namespace std;

#define TESTCASE "D-small-attempt0"

/*
3
3 3 1
###
#X#
###
3 3 2
###
#X#
###
4 3 8
###
#X#
#.#
###
 
Case #1: 4
Case #2: 8
Case #3: 68
*/

typedef tuple<int,int,int,int> qt;

int gcd(int a,int b)
{
	while(b!=0)
	{
		int t=a%b;
		a=b;
		b=t;
	}
	return a;
}

pair<int,int>& normalize(pair<int,int>& p)
{
	if(p.first==0)
	{
		if(p.second>0) p.second=1;
		if(p.second<0) p.second=-1;
	}
	else if(p.second==0)
	{
		if(p.first>0) p.first=1;
		if(p.first<0) p.first=-1;
	}
	else
	{
		int g=gcd(abs(p.first),abs(p.second));
		p.first/=g;
		p.second/=g;
	}
	return p;
}

void insertimage(set<pair<int,int> >& images,queue<qt>& q,int px,int py,qt& n,int d2)
{
	int cx=get<0>(n),cy=get<1>(n),ct=get<2>(n),cr=get<3>(n);
	if((cx-px)*(cx-px)+(cy-py)*(cy-py)<=d2)
	{
		if(images.insert(normalize(make_pair(cx-px,cy-px))).second)
		{
			q.push(n);
		}
	}
}

int main()
{
	FILE* fin=fopen(TESTCASE ".in","r");
	FILE* fout=fopen(TESTCASE ".out","w");
	int testcases;
	fscanf(fin,"%d",&testcases);
	for(int t=0;t<testcases;++t)
	{
		int w,h,d,d2,px,py;
		char map[30][60];
		fscanf(fin,"%d %d %d\n",&h,&w,&d);
		for(int i=0;i<h;++i)
		{
			fgets(map[i],31,fin);
			for(int j=0;j<w;++j) if(map[i][j]=='X')
			{
				py=i;
				px=j;
			}
		}
		d2=d*d;
		/*
		#####
		#...#
		#.X.#
		#...#
		#####

		V-wall at y=0.5, y=h-1.5
		H-wall at x=0.5, x=w-1.5
		Player at (px,py)
		*/

		static const int REFL_VWALL=0;
		static const int REFL_HWALL=1;
		static const int REFL_ORIG=2;

		// image-x, image-y, reflection-type, refcoord
		queue<qt> q;
		set<pair<int,int> > images;
		q.push(qt(px,py,REFL_ORIG,0));

		while(!q.empty())
		{
			int cx,cy,ct,cr;
			{
				qt& f=q.front();
				cx=get<0>(f);
				cy=get<1>(f);
				ct=get<2>(f);
				cr=get<3>(f);
				q.pop();
			}

			// left wall
			insertimage(images,q,px,py,qt(1-cx,cy,REFL_VWALL,0),d2);

			// right wall
			insertimage(images,q,px,py,qt((2*w-3)-cx,cy,REFL_VWALL,0),d2);

			// top wall
			insertimage(images,q,px,py,qt(cx,1-cy,REFL_HWALL,0),d2);

			// bottom wall
			insertimage(images,q,px,py,qt(cx,(2*h-3)-cy,REFL_HWALL,0),d2);	
		}

		images.erase(make_pair(0,0));
		/*for(auto it=images.begin(),ite=images.end();it!=ite;++it)
		{
			fprintf(fout,"%d %d\n",it->first,it->second);
		}*/
		fprintf(fout,"Case #%d: %d\n",t+1,images.size());
	}
	fclose(fin);
	fclose(fout);
	return 0;
}