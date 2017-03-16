#include<bits/stdc++.h>
using namespace std;
long long int dp[1000001];
long long int flip(long long int n){
    int new_num=0;
      while(n > 0)
    {
            new_num = new_num*10 + (n % 10);
            n = n/10;
    }
    return new_num;
}
int main(){
    int t,j;
        memset(dp, 0x3f, sizeof dp);
    	dp[1] = 1;
	for(long long int i = 1; i < 1000000; ++i) {
		long long int reverse_n=flip(i);
		dp[i+1] = min(dp[i+1], dp[i] + 1);
		dp[reverse_n]= min(dp[reverse_n], dp[i] + 1);
	}
    FILE *fp,*fp1;
    fp=fopen("A-small-attempt3.in","r");
    fp1=fopen("output.txt","w");
    fscanf(fp,"%d",&t);
    for(j=0;j<t;j++){
    long long int n;
        fscanf(fp,"%lld",&n);
        fprintf(fp1,"Case #%d: %lld\n",j+1,dp[n]);
    }
    return 0;
}
