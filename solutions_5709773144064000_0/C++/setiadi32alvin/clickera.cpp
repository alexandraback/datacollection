#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>

#define inf 2123123123
#define LL long long
#define MP make_pair
#define ii pair<int,int>
using namespace std;
int n,i,j,t;
double x,f,c,ans,income,tmp,acu;

void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}

int main(){
	OPEN();
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%lf %lf %lf",&c,&f,&x);
		income=2;
		tmp=ans=x/income;
		acu=0;
		do{
			if(tmp<ans)	ans=tmp;
			acu+=c/income;
			income+=f;
			tmp=acu + x/income;
		}while(ans>tmp);
		printf("Case #%d: %.7lf\n",z,ans);
	}
	return 0;
}