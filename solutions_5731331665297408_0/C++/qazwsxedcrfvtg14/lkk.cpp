#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/priority_queue.hpp>
#define f first
#define s second
using namespace std;
//using namespace __gnu_pbds;
typedef pair<int,int> par;
int v[10];
int mp[10][10];
int ar[10];
int ans[10];
int n,m;
void F(int now,int x,int f=-1){
	//printf("%d %d %d\n",now,f,x);
	if(now==n){
		int ok=1;
		stack<int> st;
		st.push(ar[0]);
		for(int i=1;i<n;i++){
			int p=ar[i];
			while(!st.empty()){
				if(mp[st.top()][p])break;
				st.pop();
				}
			if(st.empty()){ok=0;break;}
			st.push(p);
			}
		if(ok){
			int ck=1;
			for(int i=0;i<n;i++){
				if(ans[i]>v[ar[i]])break;
				if(ans[i]<v[ar[i]])ck=0;
				}
			if(ck){
				for(int i=0;i<n;i++){
					ans[i]=v[ar[i]];
					}
				}
			}
		return ;
		}
	int k=x;
	for(int y;y=k&-k;k^=k&-k){
		ar[now]=__lg(y);
		F(now+1,x^y,__lg(y));
		}
	}
int main(){
	int t,T=0;
	scanf("%d",&t);
	while(t--){T++;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]),ans[i]=99999;
		memset(mp,0,sizeof(mp));
		for(int i=0;i<m;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			mp[a-1][b-1]=1;
			mp[b-1][a-1]=1;
			}
		F(0,(1<<n)-1);
		printf("Case #%d: ",T);
		for(int i=0;i<n;i++)
			printf("%d",ans[i]);
		puts("");
		}
	return 0;
	}
