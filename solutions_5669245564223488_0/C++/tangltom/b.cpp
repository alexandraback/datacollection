#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<char,char> pcc;
int N;
char cars[105][105];


int abc[30];

int check(vector<int> &p)
{
  string s="";
  for(int i=0;i<N;i++)
    {
      s+=cars[p[i]];
      //      s+=cars[p[i]].first;
      //s+=cars[p[i]].second;
    }
  memset(abc,-1,sizeof(abc));
  for(int i=0;i<s.size();i++)
    {
      int c = s[i]-'a';
      if(abc[c]==-1)
	abc[c]=i;
      else
	{
	  if(abc[c]!=i-1)
	    return 0;
	  abc[c]=i;
	}
    }
  return 1;
}

string uniq(string &s)
{
  string ret=""+s[0];
  for(int i=1;i<s.size();i++)
}


int main()
{
  int T;
  cin>>T;

  for(int t=1;t<=T;t++)
    {
      cin>>N;
      long long res=0;
      vector<int> perm;
      for(int i=1;i<=N;i++)
	{
	  cin>>cars[i];
	  //	  cars[i] = s;//make_pair(s.front(),s.back());
	  perm.push_back(i);
	}
      do
	{
	  res+=check(perm);
	}while(next_permutation(perm.begin(),perm.end()));
      printf("Case #%d: %lld\n",t,res);
    }
  return 0;
}
