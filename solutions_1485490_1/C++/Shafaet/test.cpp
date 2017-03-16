#include <string>
#include <cstdio>
#define si 	scanf("%s",s);
#define LOOP for(int i=0;s[i];i++)
#define OUT printf("%d\n",c);
#define DEC char s[200];
#define FILL mp[s[i]]=1;
#define INIT bool mp[200]={0};
#define CC int c=0;
#define CNT c+=(mp[s[i]]==1);
#define GETCASE scanf("%d",&t);
#define CASELOOP while(t--)
#define MAINF int main()
#define T int t;
#define BR {
#define CBR }
#define RET return 0;
#define ALLMYCODE MAINF BR	T	GETCASE	CASELOOP BR		DEC 		si			INIT			LOOP FILL 		si			CC	LOOP 		CNT			OUT;		CBR	RET CBR
ALLMYCODE
