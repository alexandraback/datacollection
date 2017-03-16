//Author: Siddharth Saluja
//Quote: "DIE FOR YOUR AIM"
#include <bits/stdc++.h>

using namespace std;


#define mod 1000000007
//#define DEBUG
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define fs(a) fscanf(fp,"%d",&a)
#define flls(a) fscanf(fp,"%lld",&a)
#define fss(a) fscanf(fp,"%s",a)
#define fp(a) fprintf(fo,"%d",a)
#define fllp(a) fprintf(fo,"%lld",a)
#define fsp(a) fprintf(fo,"%s",a)
#define fcp(a) fprintf(fo,"%c",a)
#define fnline fprintf(fo,"\n")
#define fspace fprintf(fo," ")
#define ll long long


int main()
{
#ifdef DEBUG
    cout<<"Debugging\n";
#endif
ios::sync_with_stdio(false);
FILE *fp,*fo;
fp=fopen("input.txt","r");
fo=fopen("output.txt","w");

int t,a,b,k,x,i,j,cnt,u=0;
fscanf(fp,"%d",&t);
while(t--)
{
    u++;
    cnt=0;
    fscanf(fp,"%d%d%d",&a,&b,&k);
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            x=i&j;
            if(x<k)
                cnt++;
        }
    }
    fprintf(fo,"Case #%d: %d\n",u,cnt);
}




return 0;
}
