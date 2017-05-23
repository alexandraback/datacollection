#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
bool b[1000002];
char L[1000002];
long long c[1000002],T,n,len,cnt,total,i,j;
int main (){
    scanf("%I64d",&T);
    for (i=1;i<=T;i++){
    	scanf("%s %I64d",L,&n);
    	len=strlen(L);
    	for (j=0;j<len;j++){
    		if (L[j]=='a' || L[j]=='e' || L[j]=='i' || L[j]=='o' || L[j]=='u'){
    			b[j]=1;
    		} else {
    			b[j]=0;
    		}
    	}
    	cnt=0;
    	for (j=0;j<n;j++){
    		cnt+=b[j];
    	}
    	if (cnt==0){
    		c[n-1]=n-1;
    	} else {
    		c[n-1]=-1;
    	}
    	for (j=n;j<len;j++){
    		cnt+=b[j]-b[j-n];
    		if (cnt==0){
    			c[j]=j;
    		} else {
    			c[j]=-1;
    		}
    	}
    	for (j=len-1;j>=n-1;j--){
    		if (c[j]==-1 && j<len-1){
    			c[j]=c[j+1];
    		}
    	}
    	total=0;
    	for (j=n-1;j<len;j++){
    		if (c[j]!=-1){
				total+=len-c[j];
    		}
    	}
    	printf("Case #%I64d: %I64d\n",i,total);
    }
	return 0;
}
