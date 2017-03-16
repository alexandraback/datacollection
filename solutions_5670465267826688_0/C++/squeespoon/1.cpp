#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <deque>
#include <set>
#include <queue>

using namespace std;

/*
1-1
i-2
j-3
k-4
*/

int tab[5][5]={
	{ 0, 0, 0, 0, 0},
	{ 0, 1, 2, 3, 4},
	{ 0, 2,-1, 4,-3},
	{ 0, 3,-4,-1, 2},
	{ 0, 4, 3,-2,-1}
};

int calc(int a,int b){
	bool flag=0;
	if(a<0){
		a=-a;
		flag=!flag;
	}
	if(b<0){
		b=-b;
		flag=!flag;
	}
	int re=tab[a][b];
	if(flag)re=-re;
	return re;
}

char str[10010];
char re[10010][10010];

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int l,x;
		cin>>l>>x;
		scanf("%s",str);
		for(int i=0;i<l;i++){
			if(str[i]=='i')str[i]=2;
			else if(str[i]=='j')str[i]=3;
			else str[i]=4;
		}
		for(int i=1;i<x;i++){
			for(int j=0;j<l;j++){
				str[i*l+j]=str[j];
			}
		}
		
		int tot=l*x;
		
		if(tot<3){
			printf("Case #%d: NO\n",cas);
			continue;
		}
		
		for(int i=0;i<tot;i++){
			re[i][i]=str[i];
			for(int j=i+1;j<tot;j++){
				re[i][j]=calc(re[i][j-1],str[j]);
			}
		}
		
		bool ok=false;
		for(int i=0;i<tot-2;i++){
			for(int j=tot-1;j>i+1;j--){
				if(re[0][i]==2&&re[j][tot-1]==4&&re[i+1][j-1]==3){
					ok=1;
				}
			}
		}
		
		if(ok){
			printf("Case #%d: YES\n",cas);
		}else{
			printf("Case #%d: NO\n",cas);
		}
	}
	return 0;
}

