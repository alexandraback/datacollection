#include<bits/stdc++.h>

// Author : Archit Jain :) Delhi Technological University
//#pragma comment (linker, "/STACK:256000000")

#define mp(x,y) make_pair(x,y)
#define trace1(x)                cerr << #x << ": " << x << endl;
#define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define pi   3.14159265358979323846264338327950288

using namespace std;
typedef long long lld;
typedef pair<int,int> p;
//snippets
template<class T>  T gcd(T a,T b){if(b==0)return a;else return gcd(b,a%b);}
template<class T>T power(T a,T b){T result=1;while(b>0){if(b&1)	result = result * a;a = a*a;b>>=1;}return result;}
template<class T>T powerMod(T a,T b,T c){T result =1%c;while(b>0){if(b&1)result = (result * a)%c;a = (a*a)%c;b>>=1;}return result;}
template<class T>bool prime(T a){if(a==2)return true;else if(a%2==0)return false;for(int i=3;i*i<=a;i+=2){if(a%i==0)return false;}return true;}


#define lld long long
#define MAX 17

lld dp[MAX][(1<<MAX)];

int n;
struct node{
	
	string first;
	string second;
}a[MAX];


lld compute(int i,int mask){
	
	if(i>=n){
		return 0;
	}
	
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	
	for(int j = 0;j<n;j++){
		
		if(mask&(1<<j))continue;
		
		int f1 =0 ;
		int f2 = 0;
		
		for(int k = 0;k<n;k++){
			
			if(mask&(1<<k)){
				
				if(a[k].first==a[j].first)
					f1 = 1;
					
				if(a[k].second==a[j].second)
					f2 = 1;
			}
		}
		if(f1 && f2)
			dp[i][mask] = max(dp[i][mask],compute(i+1,mask|(1<<j))+1);
		else
			dp[i][mask] = max(dp[i][mask],compute(i+1,mask|(1<<j)));
	}
	return dp[i][mask];
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	
	cin.sync_with_stdio(0);
	cout.sync_with_stdio(0);
	

	int t;
	cin>>t;
	
	for(int tst=1;tst<=t;tst++){
		
	
		memset(dp,-1,sizeof(dp));
		
		cin>>n;
		
		for(int i = 0;i<n;i++)
			cin>>a[i].first>>a[i].second;
		
		cout<<"Case #"<<tst<<": "<<compute(0,0)<<endl;
	}
	
	return 0;
}

