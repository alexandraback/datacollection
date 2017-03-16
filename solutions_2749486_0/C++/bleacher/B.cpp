#include<cstdio>
#include<utility>
#include<map>
#include<string>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

map< pair<int,int> , string > mymap;
queue< pair<int,int> > q;

int X = 100,Y= 100;
void pre()
{
    int x,y,jump=1;
    
    pair<int,int> p;
    string s ("");
    p = make_pair(0,0);
    mymap[p] = s;
    q.push(p);
    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        x = curr.first;
        y = curr.second;
        jump = mymap[make_pair(x,y)].length() + 1;
        if(mymap.find(make_pair(x+jump,y))==mymap.end() && abs(x+jump)<=X)
        {
            q.push(make_pair(x+jump,y));
            mymap[make_pair(x+jump,y)] = mymap[make_pair(x,y)] + "E";
            cout<<x+jump<<" "<<y<<" "<<mymap[make_pair(x+jump,y)]<<endl;
        }
        if(mymap.find(make_pair(x,y+jump))==mymap.end() && abs(y+jump)<=Y)
        {
            q.push(make_pair(x,y+jump));
            mymap[make_pair(x,y+jump)] = mymap[make_pair(x,y)] + "N";
            cout<<x<<" "<<y+jump<<" "<<mymap[make_pair(x,y+jump)]<<endl;
        }
        if(mymap.find(make_pair(x-jump,y))==mymap.end() && abs(x-jump)<=X)
        {
            q.push(make_pair(x-jump,y));
            mymap[make_pair(x-jump,y)] = mymap[make_pair(x,y)] + "W";
            cout<<x-jump<<" "<<y<<" "<<mymap[make_pair(x-jump,y)]<<endl;
        }
        if(mymap.find(make_pair(x,y-jump))==mymap.end() && abs(y-jump)<=Y)
        {
            q.push(make_pair(x,y-jump));
            mymap[make_pair(x,y-jump)] = mymap[make_pair(x,y)] + "S";
            cout<<x<<" "<<y-jump<<" "<<mymap[make_pair(x,y-jump)]<<endl;
        }
        q.pop();
    }
}

int main()
{
    FILE *in,*out;
    char c;
    in = fopen("B-small-attempt0.in","r");
    out = fopen("B-small.out","w");
    if(in && out)
    {
 	int T,count=1;
	fscanf(in,"%d\n",&T);
        pre();

	while(T--)
	{
            int i,j;
            fscanf(in,"%d %d",&i,&j);
            fgetc(in);
   
            fprintf(out,"Case #%d: %s\n",count++,mymap[make_pair(i,j)].c_str());
	}
	fclose(in);
	fclose(out);
    }
    return 0;
}
