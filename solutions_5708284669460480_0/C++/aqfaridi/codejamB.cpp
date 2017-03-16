#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <set>
#include <map>
#include <queue> 
#include <climits>
#include <cassert>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define pb push_back
#define mp make_pair
#define sz size()
#define ln length()
#define forr(i,a,b)                 for(int i=a;i<b;i++)
#define rep(i,n)                    forr(i,0,n) 
#define all(v)                      v.begin(),v.end()	
#define uniq(v)                     sort(all(v));v.erase(unique(all(v)),v.end())
#define clr(a)                      memset(a,0,sizeof a)
	
#define debug                       if(1)
#define debugoff                    if(0)	

#define print(x)                 cerr << x << " ";    
#define pn()				     cerr << endl;
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define MAX 100010
#define MOD 1000000007
#define endl '\n'
int cnt;
int K,L,S;
string keyboard,target,strt;
namespace KMP
{
	int b[MAX],m,n;
	void LPS(string pat)
	{
		int i=0,j=-1;//j => border
		m = L;
		b[i] = j;
		while(i<m)
		{
			while(j>=0 && pat[i]!=pat[j]) j=b[j];//next widest border
			i++;j++;
			b[i] = j;
		}
	}
	void kmpSearch(string txt,string pat)
	{	
		int i=0,j=0;
		n = S;
		while(i<n)
		{
			while(j>=0 && txt[i]!=pat[j]) j=b[j];//next widest border of some prefix of pat
			i++;j++;
			if(j==m)
			{
				cnt++;
				//printf("%d\n",(i-j));
				j = b[j]; //widest border of pat
			}
		}			
	}
}
using namespace KMP;
char str[100];
int banana[110];
int inst,tot,maxx;
void recurse(int idx){
	if(idx == S){
		//process
		int cnt = 0,temp;
		for(int i=0;i<=(S-L);i++){
			temp = 0;
			for(int j=0;j<L;j++)
				if(str[i+j] == target[j])
					temp++;
			if(temp == L)
				cnt += 1;
		}
		/*
		cnt = 0;
		strt = "";
		for(int i=0;i<S;i++)
			strt += str[i];		
		kmpSearch(str,target);
		*/
		banana[cnt] += 1;
		maxx = max(maxx,cnt);
		inst += cnt;
		tot++;
		return;
	}

	for(int i=0;i<K;i++){
		str[idx] = keyboard[i];
		recurse(idx+1);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,cases = 1;
	double ans;
	cin>>t;
	while(t--)
	{
		memset(banana,0,sizeof(banana));
		cin>>K>>L>>S;
		cin>>keyboard;
		cin>>target;
		sort(keyboard.begin(),keyboard.end());
		//LPS(target);
		inst = tot = maxx = 0;
		recurse(0);
		//cout<<maxx<<" "<<inst<<" "<<tot<<endl;
		ans = 0.0;
		for(int i=0;i<10;i++){
			double prob = (banana[i]*1.0)/tot;
			//cout<<i<<" "<<banana[i]<<" "<<prob<<endl;
			ans += ((maxx - i >= 0)?(maxx-i):0) * prob;
		}


		//ans = (inst*1.0)/tot;
		//ans = maxx - ans;
		cout<<"Case #"<<cases<<": "<<fixed<<setprecision(7)<<ans<<endl;
		cases++;
	}
	return 0; 
}