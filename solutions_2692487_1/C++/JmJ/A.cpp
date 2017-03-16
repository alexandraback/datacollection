#include<iostream>
#include<queue>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<cstring>
#include<map>
#include<numeric>
#include<sstream>
#include<cmath>
using namespace std;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).end,(v).begin
#define pb push_back
#define f(i,x,y) for(int i=x;i<y;i++)
#define FOR(it,A) for(typeof A.begin() it = A.begin();it!=A.end();it++)
#define sqr(x) (x)*(x)
#define mp make_pair
#define clr(x,y) memset(x,y,sizeof x)
typedef pair<int,int> pii;
typedef long long ll;
typedef long double ld;
ll arr[103];
int N;
map<int,ll> memo[103];
int go(int pos,ll val){
	//cout<<pos<<" x "<<val<<endl;
	if(pos>=N)return 0;
	if(memo[pos].count(val))return memo[pos][val];
	int res=1000000;
	if(val > arr[pos] ) {
		//cout<<"ad"<<endl;
		res=min(res,go(pos+1,val+arr[pos]));
	}
	else {
		res=min(res,1+go(pos+1,val));
		//if(pos==3 && val==6 )cout<<res<<" adadd"<<endl;
		if(val!=1){	
			int cur=val+(val-1);
			int cont=1;
			while(cur <= arr[pos]){
				cont++;
				cur+=(cur-1);
			}

		//	cout<<"xx"<<" "<<cur+arr[pos]<<" "<<cont<<endl;
			res=min(res,go(pos+1,cur+arr[pos])+cont);
		}
	}
	
	return memo[pos][val]=res;
}
int main(){
	int cases;
	cin>>cases;
	int A;
	f(t,1,cases+1){
		cin>>A>>N;
		f(i,0,N)cin>>arr[i];
		sort(arr,arr+N);
		/*
		ll cur=A;
		ll res=55000;
		ll res1=0;
		int faltan=N;
		f(i,0,N){
			if(cur > arr[i]){
				cur+=arr[i];
				faltan--;
			}
			else 
			{
				int cont=0;
				while(cur+(cur-1) < = arr[i]){
					cont++;
					cur+=cur
				}				
			}
		}
		res=min(res1,mejor);
		*/
		f(i,0,103)memo[i].clear();
		int res=go(0,A);
		cout<<"Case #"<<t<<": "<<res<<endl;
	}
	return 0;

}
