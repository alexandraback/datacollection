#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int s[2000000]={0};

int r(int a){
	char c[20];
	sprintf(c,"%d",a);
	int h=strlen(c);
	for(int i=0,j=h-1;i<j;i++,j--){ char g=c[i]; c[i]=c[j]; c[j]=g; }
	return atoi(c);
}

int main(void){
	
	s[1]=1;
	for(int i=1;i<1000001;i++)
	{
		if(s[i+1]==0 || s[i+1]>s[i]+1)
			s[i+1]=s[i]+1;
		int y=r(i);
		if(s[y]==0 || s[y]>s[i]+1)
			s[y]=s[i]+1;
	}
	
	// for(int i=0;i<200;i++)
	// 	 printf("%d: %d\n", i, s[i]);
	
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d", &n);
        
        printf("Case #%d: %d\n", tt, s[n]);
    }
    return 0;
}

