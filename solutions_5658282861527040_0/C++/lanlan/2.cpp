#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a,b,kk;
long long ans;
int f1[40];
int f2[40];
int f3[40];
int f[40];
int tobinary(int a){
	int cnt=0;
	while(a){
		f[cnt++] = a%2;
		a /= 2;
	}
	return cnt;
}
int main(){
	int T,cnt=0;
	cin>>T;
	while(T--){
		cnt++;
		ans = 0;
		scanf("%d%d%d",&a,&b,&kk);
		int len1,len2,len3;
		for(int i=0;i<a;i++){
			len1 = tobinary(i);
			memset(f1,0,sizeof(f1));
			for(int k=0;k<len1;k++){
				f1[k] = f[k];
			}
			for(int j=0;j<b;j++){		
				len2 = tobinary(j);
				memset(f2,0,sizeof(f2));
				for(int k=0;k<len2;k++){
					f2[k] = f[k];
				}
				int len = max(len1,len2);
				int tt=0;
				for(int k=0;k<len;k++){
					if(f1[k] && f2[k]){
						f3[k]=1;
					}else{
						f3[k]=0;
					}
				}
				int ep = 1;
				for(int k=0;k<len;k++){
					tt += f3[k] * ep;
					ep *= 2;
				}
				if(tt<kk){
					ans++;
				}
			}
		}
		printf("Case #%d: %lld\n",cnt,ans);
	}
	return 0;
}
