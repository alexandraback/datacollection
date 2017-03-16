#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <list>
#include <cmath>
#include <string>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <fstream>
#include <sstream>
#include <utility>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;

struct Point
{
    int x,y;
    
    Point(int a =0 , int b = 0)
    {
	x = a;
	y = b;
    }
};



ifstream infile;
ofstream outfile;



const double INF = 1e20;



bool cmp(const Point &a, const Point & b)
{
	if(a.x<b.x)
		return true;
	else
		return false;
}


int main()
{
	string inputfilename = "C-small-attempt0.in";
	string outputfilename = "c.out";

	infile.open(inputfilename, ios::in);
	outfile.open(outputfilename, ios::out);

	int i,j,k,m,n,M,N,T;

	string line;
	istringstream ss;

	getline(infile,line);
	ss.clear();
	ss.str(line);

	//cout<<line<<endl;
	ss>> T;
	Point * c= new Point[2<<20];

	for(i=1;i<=T;i++)
	{
		getline(infile,line);
	ss.clear();
	ss.str(line);

	ss>>N;
	vi b(N,0);
	for(j=0;j<N;j++)
		ss>>b[j];
	
	sort(b.begin(),b.end());

	
	memset(c,0,sizeof(c));

	for(j=0;j<(2<<20);j++)
	{
		int temp = 0;
		for (k=0;k<20;k++)
		{
			if( (j&(1<<k)) !=0)
				temp+=b[k];
		}
		c[j].x = temp;
		c[j].y = j;
	}

	sort(c,c + (1<<20),cmp);

	bool flag = false;

	k=0;
	vi s;
	s.clear();
	j=0;
	int k1,k2,res1,res2;

	while(k< (1<<20))
	{
		int tt = c[k].x;
		s.push_back(c[k].y);

		j=k+1;
		while(j<(1<<20)&&c[j].x==tt)
		{s.push_back(c[j].y);j++;}

		if(s.size()<2)
		{
			s.clear();
			k = j;
			if(k>= (1<<20))
				break;
			continue;
		}


	

		for(k1=0;k1<s.size();k1++)
			if(flag)
				break;
			else

			for(k2=k1+1;k2<s.size();k2++)
			{
				if(flag)
					break;
				else
					if ( (s[k1]&s[k2]) ==0)
						{flag = true;
				res1 = s[k1];
				res2 = s[k2];
				break;}

			}


		if(flag)
			break;

		s.clear();
		k = j;
		if(k>= (1<<20))
				break;


	}


	j=res1;
	k=res2;

	outfile<<"Case #"<<i<<":  "<<endl;
	if (flag==false)
		outfile<<"Impossible"<<endl;
	else
	{
		for(m=0;m<20;m++)
			if(j&(1<<m))
				outfile<<b[m]<<" ";
		outfile<<endl;

		for(m=0;m<20;m++)
			if(k&(1<<m))
				outfile<<b[m]<<" ";
		outfile<<endl;

	}

		


		

	}
	




	

	//delete []c;







	infile.close();
	outfile.close();

	
	


}
