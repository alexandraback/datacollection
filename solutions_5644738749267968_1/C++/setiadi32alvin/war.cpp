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
void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
double A[1111],B[1111];
bool F[1111];
int t,n,i,j,a1,a2;
int main(){
	OPEN();
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d",&n);
		memset(F,0,sizeof(F));
		for(i=0;i<n;i++)	scanf("%lf",&A[i]);
		for(i=0;i<n;i++)	scanf("%lf",&B[i]);
		for(i=0;i<n;i++){
			A[i]*=1000;
			B[i]*=1000;
		}
		sort(A,A+n);
		sort(B,B+n);
		a1=a2=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				if(A[i]<B[j] && !F[j]){
					a1++;
					F[j]=1;
					break;
				}
		}
		memset(F,0,sizeof(F));
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(B[i]<A[j] && !F[j]){
					a2++;
					F[j]=1;
					break;
				}
			}
		}
		a1=n-a1;
		printf("Case #%d: %d %d\n",z,a2,a1);
	}
	return 0;
}