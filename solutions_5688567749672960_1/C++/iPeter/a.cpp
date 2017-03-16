#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int s[2000000]={0};

long long r(long long a){
	char c[20];
	sprintf(c,"%lld",a);
	int h=strlen(c);
	for(int i=0,j=h-1;i<j;i++,j--){ char g=c[i]; c[i]=c[j]; c[j]=g; }
	long long x=0;
	for(int i=0;c[i];i++){ x=x*10+c[i]-'0'; }
	return x;
}

long long f(long long a){
	// printf("%lld\n", a);
	if(a<=20) return a;
	
	char c[20], d[20];
	sprintf(c,"%lld",a);
	int h=strlen(c);
	if(c[h-1]=='0') return f(a-1)+1;
	
	d[h]=0;
	for(int i=0;i<h;i++)
		d[i]=(i<h/2?c[i]:'0');
	d[h-1]='1';

	long long x=0;
	for(int i=0;d[i];i++){ x=x*10+d[i]-'0'; }
	// printf("X: %lld %lld\n",a,x);
	
	if(x!=a) return f(x)+a-x;
	
	x = r(a);
	// printf("R: %lld\n\n",x);
	if(x!=a) return f(x)+1;
	return f(a-1)+1;
}

int main(void){
	
	// s[1]=1;
	// for(int i=1;i<1000001;i++)
	// {
	// 	if(s[i+1]==0 || s[i+1]>s[i]+1)
	// 		s[i+1]=s[i]+1;
	// 	long long y=r(i);
	// 	if(s[y]==0 || s[y]>s[i]+1)
	// 		s[y]=s[i]+1;
	//
	// 	long long j=f(i);
	// 	if(s[i]!=j)printf("%d: %d-%lld\n", i, s[i], j);
	// }
	
	// f(1011);
	
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		long long n;
		scanf("%lld", &n);
        
        printf("Case #%d: %lld\n", tt, f(n));
        // printf("Case #%d: %d\n", tt, s[n]);
    }
    return 0;
}

