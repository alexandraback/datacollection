#include <bits/stdc++.h>
using namespace std;
string a,b;
int k,l,s;
char c[10000];
double maxx;
double summ;
void check(){
	double num=0;
	int i,j;
	for(i=0;i+l<=s;i++){
		int f=1;
		for(j=0;j<l&&i+j<s;j++){
			if(c[i+j]!=b[j]){
				f=0;
				break;
			}
		}
		if(f==1)
			num++;
	}
	summ+=num;
	maxx=max(num,maxx);
}
void dfs(int step){
	if(step==s){
		check();
		return;
	}
	int i;
	for(i=0;i<k;i++){
		c[step]=a[i];
		dfs(step+1);
	}
}
int main(){
	int t;
	scanf("%d",&t);
	int cas=0;
	while(t--){
		scanf("%d%d%d",&k,&l,&s);
		cin>>a>>b;
		int i;
		maxx=summ=0;
		dfs(0);
		for(int i=0;i<s;i++){
			summ/=k;
		}
		printf("Case #%d: %.8lf\n",++cas,maxx-summ);
	}
}