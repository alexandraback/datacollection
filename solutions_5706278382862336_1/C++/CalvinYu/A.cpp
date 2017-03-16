#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<queue>
#include<list>
#include<vector>
#define LL long long
#define INF 0x7fffffff
#define For(i,a,b) for(int i=a; i<b; ++i)
using namespace std;
typedef pair<int,int> ii;
int main(){
	int T;
	cin>>T;
	for(int cas = 1; cas<=T; ++cas){
		LL a,b;
		scanf("%lld/%lld", &a, &b);
		//cout<<a<<" "<<b<<endl;
		int cnt = 0;
		while(b%2==0 && a%2==0){
			a/=2;
			b/=2;
		}
		while(b%2==0){
			b/=2;
			cnt++;
		}
		if(a%b!=0){
			printf("Case #%d: impossible\n", cas);
		}
		else{
			int ans=0;
			while(b<=a){
				ans++;
				b*=2;
			}
			ans = cnt-ans+1;
			printf("Case #%d: %d\n", cas, ans);
		}
	}	
	return 0;
}
