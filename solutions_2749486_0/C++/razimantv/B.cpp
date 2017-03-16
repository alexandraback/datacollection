# include <cstdio>
# include <iostream>
# include <string>
# include <queue>
# include <map>

using namespace std;

int neigh[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char move[]="NESW";

string getstring(int X,int Y)
{
  map<pair<int,int>,string> strmap;
  queue<pair<int,int> >bfsq;

  strmap[make_pair(0,0)]=string("");
  bfsq.push(make_pair(0,0));

  while(1)
  {
    int x=bfsq.front().first,y=bfsq.front().second;
    bfsq.pop();
    string s=strmap[make_pair(x,y)];
    int L=s.size()+1;

    for(int i=0;i<4;i++)
    {
      int xx=x+L*neigh[i][0],yy=y+L*neigh[i][1];
      if(strmap.count(make_pair(xx,yy)))continue;

      if((xx==X)&&(yy==Y))return s+move[i];
      bfsq.push(make_pair(xx,yy));
      strmap[make_pair(xx,yy)]=s+move[i];
    }
  }
}

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    int X,Y;
    scanf("%d%d",&X,&Y);

    string s=getstring(X,Y);
    cout<<"Case #"<<t<<": "<<s<<endl;
  }
  return 0;
}
