#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<climits>
using namespace std;
typedef long long LL;
int n,r,e,m=0;
int a[100];
int b[100];
void back(int source,int v,int total){
	if(source==n)
		return;
	if(v>e)v=e;
	for(int i=0;i<=v;i++){
		total+=i*a[source];
		if(total>m)m=total;
		back(source+1,v-i+r,total);
		total-=i*a[source];
	}
}
int main(){
int test,o=0;
cin>>test;
while(o++<test){
printf("Case #%d: ",o);
int i;m=0;
	scanf("%d %d %d",&e,&r,&n);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i] = 0;
		}
	back(0,e,0);
printf("%d\n",m);
}
return 0;
}
