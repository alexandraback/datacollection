#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define FOX(i,x) for(int i=0;i<x.size();i++)
#define FO(i,j,n) for(int i=j;i<n;i++)

typedef long long ll;
typedef long double ld;

#define X first
#define Y second
#define PB push_back
#define S(x) sort(x.begin(), x.end())
#define R(x) reverse(x.begin(), x.end())

typedef pair<ll,ll> PL;
typedef vector<int> VI;
typedef vector<PL> VP;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef vector<string> VS;

void process(string a, set<string>& b)
{
  string temp=a;
  FOX(i,a)
    {
      temp[i]='?';
      b.insert(temp);
      FO(j,i+1,a.size())
	{
	  temp[j]='?';
	  b.insert(temp);
	  temp[j]=a[j];
	}
      temp[i]=a[i];
    }
}

int memo[5000][10];
string S;
set<string> ers;

void good(int start, int stop, int currDist, VI& dist, VI& erc, VS& ss)
{
  string s=S.substr(start,stop-start+1);

  if(ers.count(s))
    {
      dist.PB(min(5, currDist+stop-start+1));
      erc.PB(0);
      ss.PB(s);
    }

  string temp = s;
  FO(i,5-currDist, stop-start+1)
    {
      temp[i]='?';
      if(ers.count(temp))
	{
	  //	  cout<<temp<<" in dict"<<endl;
	  erc.PB(1);
	  dist.PB(min(5, stop-start-i+1));
	  ss.PB(temp);
	}
      // else
      // 	cout<<temp<<" not in dict"<<endl;
      FO(j,i+5,stop-start+1)
	{
	  temp[j]='?';
	  if(ers.count(temp))
	    {
	      //	      cout<<temp<<" in dict"<<endl;
	      erc.PB(2);
	      dist.PB(min(5,stop-start-j+1));
	      ss.PB(temp);
	    }
	  // else
	  //   cout<<temp<<" not in dict"<<endl;
	  temp[j]=s[j];
	}
      temp[i]=s[i];
    }

}

int ans(int ind, int dist)
{
  int& ret=memo[ind][dist];
  if(ret!=-1)
    return ret;

  if(ind==S.size())
    return ret=0;

  ret=(int)(1e6);

  int last=min(ind+9,(int)(S.size())-1);
  FO(i,ind, last+1)
    {
      VI newDist;
      VI erc;
      VS ss;
      good(ind, i, dist, newDist, erc, ss);
      FOX(j,newDist)
	{
	  //	  cout<<"Matched "<<ss[j]<<", calling "<< i+1<<" "<<newDist[j]<<endl;
	  int temp = ans(i+1, newDist[j]);
	  ret=min(erc[j]+temp, ret);
	}
    }

  if(ret==(int)(1e6))
    {
      //      cout<<"No solution for "<<ind<<" "<<dist<<endl;
    }
  return ret;
}

int main()
{
  ifstream fin("dict.txt");
  VS inp;
  string temp;

  while(fin>>temp)
    inp.PB(temp);

  FOX(i,inp)
    ers.insert(inp[i]);

  FOX(i,inp)
    process(inp[i],ers);

  //  cout<<"done"<<endl;
  int t;
  cin>>t;
  FO(T,1,t+1)
    {
      cin>>S;
      memset(memo,-1,sizeof(memo));
      printf("Case #%d: %d\n", T, ans(0,5));
    }

  return 0;
}
