#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	freopen("inputB","r",stdin);
	freopen("outputB.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		string s;
		cin>>s;
		printf("Case #%d: ",t);
		int l=s.length();
		bool p[l+1];
		for(int i=0;i<l;i++)
			p[i]=(s[i]=='+')?true:false;
		p[l]=true;
		int ans=0;
		for(int i=1;i<l+1;i++)
			if(p[i]!=p[i-1])ans++;
		printf("%d\n",ans);	
	}
}

