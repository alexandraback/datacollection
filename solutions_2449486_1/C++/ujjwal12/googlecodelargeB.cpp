#include<iostream>
#include<map>
#include<vector>
#include<set>
#include<string>
#include<stack>
#include<queue>
#include<deque>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define pinf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a);
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define ps(a) printf("%s",a);
#define nline printf("\n")
#define pc(a) printf("%c",a)
#define ll long long
#define MAX(a,b,c) ((a>b)?(a>c?a:c):(b>c?b:c))
#define MIN(a,b,c) ((a<b)?(a<c?a:c):(b<c?b:c))
int a[100][100];
int check_row(int i,int j,int n,int m)
{
int p;
    for(p=j;p>=0;p--)
        if(a[i][j]<a[i][p])
            break;
    if(p!=(-1))
        return 0;
    for(p=j;p<m;p++)
        if(a[i][j]<a[i][p])
            break;
    if(p!=m)
        return 0;
    return 1;
}
int check_col(int i,int j,int n,int m)
{
int p;
    for(p=i;p>=0;p--)
        if(a[i][j]<a[p][j])
            break;
    if(p!=(-1))
        return 0;
    for(p=i;p<n;p++)
        if(a[i][j]<a[p][j])
            break;
    if(p!=n)
        return 0;
    return 1;
}
int main()
{
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
int p,i,j,t;
FILE* fp,*fw;
fp=fopen("B-large.in","r");
fw=fopen("outputforlargefinal.txt","w");
fscanf(fp,"%d",&t);
for(p=1;p<=t;p++)
{
int n,m,flag=0;
fscanf(fp,"%d %d",&n,&m);
for(i=0;i<n;i++)
    for(j=0;j<m;j++)
        {
        fscanf(fp,"%d",&a[i][j]);
        }

for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {

              if(check_row(i,j,n,m)||check_col(i,j,n,m))
                {
                flag=0;
                }

              else
                {
                flag=1;
                break;
                }
        }
if(flag)
    break;
    }
 if(flag)
        fprintf(fw,"Case #%d: NO\n",p);
else
        fprintf(fw,"Case #%d: YES\n",p);
}
return 0;
}
