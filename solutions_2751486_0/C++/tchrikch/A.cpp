#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<sstream>
#include<cmath>
#include<cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<n;++i)
#define REPD(i,n) for(int i=n;i>-1;--i)
#define FOR(i,j,k) for(int i=j;i<k;++i)
#define PB push_back
#define LL unsigned long long
#define MAX_S 101
#define MP make_pair
#define ALL(v) v.begin(),v.end()
#define INF 1000000000

bool isConsonant(char a)
{
  if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u') return false;
  
  return true;
}


LL calc(string a,LL n)
{
	LL ret = 0;
	
	int wsk = 0;
	int s = a.size();
	vector<int> v;
	
	REP(i,s)
	{
		int cnt = 0;
		int j = i;
		while(j<s && isConsonant(a[j]))
		{
			++j;
			++cnt;
			if(cnt==n) break;
		}
		
		if(cnt==n) v.PB(i);
	}
	
	//REP(i,v.size()) cout<<v[i]<<" ";cout<<endl;
	
	REP(i,v.size())
	{
		if(i==0) 
		{
			LL a = v[i] +1;
			LL b = (s-1) - (v[i]+n-1) +1;
			ret +=a*b;
		}
		else
		{
			LL a = v[i] - (v[i-1]+1) + 1;
			LL b = s-1 - (v[i]+n-1) +1;
			ret += a*b;
		}
	}
	
	return ret;
}


int main(){
	 int ts=0; cin>>ts;
	 REP(ww,ts)
	 {
	    string a;
	    int n;
	    cin>>a>>n;
	    
	    LL ret = calc(a,n);
		cout<<"Case #"<<(ww+1)<<": "<<ret<<endl;
	 }
	
	return 0;
}
