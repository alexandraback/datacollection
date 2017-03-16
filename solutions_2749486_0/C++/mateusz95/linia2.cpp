#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#define LL long long
#define ff first
#define ss second
#define PB push_back
#define MP make_pair


using namespace std;
LL wynik;
int t;
bool odw[205][205][505];
queue<pair<pair<int,int>,int> >Q;
pair<int,int >prz[205][205][505];
int n,b,a;
int S[1000005],size;


int main()
{
  ios_base::sync_with_stdio(0);
  
  
  odw[100][100][0]=1;
  Q.push(MP(MP(100,100),0));
  
  while(!Q.empty())
  {
    int x=Q.front().ff.ff;
    int y=Q.front().ff.ss;
    int dl=Q.front().ss;
    Q.pop();
    if(dl==500)break;
    dl++;
    if(x-dl>=0&&odw[x-dl][y][dl]==0)
    {
      odw[x-dl][y][dl]=1;
      Q.push(MP(MP(x-dl,y),dl));
      prz[x-dl][y][dl]=MP(x,y);
      
    }
    
      if(x+dl<=200&&odw[x+dl][y][dl]==0)
    {
      odw[x+dl][y][dl]=1;
      Q.push(MP(MP(x+dl,y),dl));
      prz[x+dl][y][dl]=MP(x,y);
      
    }
    
      if(y-dl>=0&&odw[x][y-dl][dl]==0)
    {
      odw[x][y-dl][dl]=1;
      Q.push(MP(MP(x,y-dl),dl));
      prz[x][y-dl][dl]=MP(x,y);
      
    }
    
        if(y+dl<=200&&odw[x][y+dl][dl]==0)
    {
      odw[x][y+dl][dl]=1;
      Q.push(MP(MP(x,y+dl),dl));
      prz[x][y+dl][dl]=MP(x,y);
      
    }
    
  }
  
  cin>>t;
  for(int z=1;z<=t;z++)
  {
    
    //printf("Case #%d: ",z);
    cout<<"Case #"<<z<<": ";
    size=0;
    cin>>b>>a;
    a+=100;
    b+=100;
    for(int i=0;i<=500;i++)
    {
      if(odw[a][b][i]==1)
      {
	  int dl=i;
	  
	  
	  while(dl>0)
	  {
	    int x2=prz[a][b][dl].ff;
	    int y2=prz[a][b][dl].ss;
	    
	    if(x2<a)
	    {
	      S[++size]=1;
	    }
	    if(x2>a)
	    {
	      S[++size]=3;
	    }
	    if(y2<b)
	    {
	      S[++size]=2;
	      
	    }
	    if(y2>b)
	    {
	      S[++size]=4;
	    }
	    a=x2;
	    b=y2;
	    
	    dl--;
	  }
	  for(int j=size;j>0;j--)
	  {
	    if(S[j]==1)cout<<"N";
	    if(S[j]==2)cout<<"E";
	    if(S[j]==3)cout<<"S";
	    if(S[j]==4)cout<<"W";
	  }
	  
	  break;
      }
    }
    
    cout<<"\n";
  
  }
  return 0;
}