#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
#include <memory.h>
using namespace std;
char str[110][110];
int a[30][30];
int cnt[30][30];
int degree[110];
int node[30];
int imp[30];
int check[30];
int T,Ti;
int n;
long long ans;
queue<int> q;
long long fact(int x) {
	if(x==0) return 1;
	return (x*fact(x-1))%1000000007;
}
long long top_sort(int s) {
	q.push(s);
	int head;
	long long temp_ans=1;
	int i;
	while(!q.empty()) {
		head=q.front();
		q.pop();
		check[head]=1;
		for(i=0;i<30;i++) {
			if(a[head][i]) {
				int k=i;
				i++;
				for(;i<30;i++) {
					if(a[head][i]) {temp_ans=0; break;}
				}
				degree[k]--;
				temp_ans*=fact(node[head]);
				q.push(k);
			}
		}
	}
	while(!q.empty()) q.pop();
	return temp_ans*fact(node[head]);
}
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	memset(check,-1,sizeof(check));
	for(Ti=1;Ti<=T;Ti++) {
		scanf("%d",&n);
		int i;
		int j,k;
		int impflag=0;
		for(i=0;i<n;i++) {
			scanf("%s",str[i]);
			cnt[(int)(str[i][0]-'a')][(int)(str[i][strlen(str[i])-1]-'a')]++;
			for(j=1;j<strlen(str[i])-1;j++) {
				for(k=i+2;k<strlen(str[i])-1;k++) {
					if(str[i][j]==str[i][k]) impflag=1;
				}
			}
			for(j=0;j<strlen(str[i]);j++) {
				if(j==0) {
					if(imp[str[i][j]-'a']==1) break;
				}else {
					if(imp[str[i][j]-'a']==1 && (str[i][j]!=str[i][0] || str[i][j]!=str[i][j-1])) break;
					if(j!=0 && j<strlen(str[i])-1 && (str[i][j]!=str[i][0] || str[i][j]!=str[i][j-1])
						&& (str[i][j]!=str[i][strlen(str[i])-1] || str[i][j]!=str[i][j+1])) imp[str[i][j]-'a']=2;
				}
			}
			if(j<strlen(str[i])) {
				impflag=1;
			}
			for(j=0;j<strlen(str[i]);j++) {
				if(imp[str[i][j]-'a']==2) imp[str[i][j]-'a']=1;
			}
		}
		for(i=0;i<30;i++) {
			for(j=0;j<30;j++) {
				if(i==j) node[i]=cnt[i][j];
				if(i!=j && cnt[i][j]) {
					if(cnt[i][j]>1) {
						impflag=1;
						break;
					}
					a[i][j]=1;
					degree[j]++;
					if(degree[j]>1) impflag=1;
				}
				if(cnt[i][j]) {
					check[i]=0;
					check[j]=0;
				}
			}
			if(impflag) break;
		}
		if(impflag) {
			printf("Case #%d: 0\n",Ti);
		} else {
			ans=1;
			int sub_graph=0;
			for(i=0;i<30;i++) {
				if(degree[i]==0 && check[i]==0) {
					ans=ans*top_sort(i);
					ans=ans%1000000007;
					sub_graph++;
				}
			}
			for(i=0;i<30;i++) {
				if(degree[i]>0) ans=0;
			}
			ans*=fact(sub_graph);
			ans=ans%1000000007;
			printf("Case #%d: %lld\n",Ti,ans);
		}
		memset(str,0,sizeof(str));
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		memset(degree,0,sizeof(degree));
		memset(node,0,sizeof(node));
		memset(imp,0,sizeof(imp));
		memset(check,-1,sizeof(check));
	}
	return 0;
}