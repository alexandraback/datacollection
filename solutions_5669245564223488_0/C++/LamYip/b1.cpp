#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdlib.h"
#include "iostream"
#include "algorithm"
#include "set"
#include "vector"
#include "queue"
#include "map"
#include "list"
#include "string"
using namespace std;
#define ll long long
#define rp(i,n) for(ll i=1;i<=n;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define clr(a,b) memset(a,b,sizeof(a))
#define si(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define sc(x) scanf("%c",&x)
#define line puts("");
#define IN freopen("i.txt","r",stdin);
#define OUT freopen("o.txt","w",stdout);
#define N 1000000
//lower_bound binary_search push_back insert

int T,C;

int main(){
	IN 
	OUT
	si(T);C=1;
	while(T--){
		string str[11],test[11];
		int ans,a,b,len,n;
		printf("Case #%d: ",C++);
		si(n);ans=0;
		
		rep(i,n){
			cin>>str[i];
		}
		vector<int> per(n);
		rep(i,n)per[i]=i;
		do{
			rep(i,n){
				test[i]=str[per[i]];
			}
			bool flag=1;
			rep(i,n){
				a=test[i].length();
				if(i==0){
					if(test[i][a-1]!=test[i+1][0]){
						flag=0;break;

					}
					continue;
				}
				b=test[i-1].length();
				if(i==n-1){
					if(test[i][0]!=test[i-1][b-1]){
						flag=0;break;
					}
					continue;
				}
				if(test[i][a-1]!=test[i+1][0]&&test[i][0]!=test[i-1][b-1]){
					flag=0;break;
				}
			}
			if(flag){
				ans++;
			}
		}while(next_permutation(all(per)));
		if(n==1)printf("0\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}














