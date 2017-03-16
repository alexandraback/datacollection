//Author: Tusshar Singh
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<algorithm>

using namespace std;

#define mod 1000000007
#define inf 2147483647
#define ninf -2147483648
#define FOR(i,a,b) for(i=a;i<b;i++)
#define s(a) fscanf(fp,"%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define ll long long
int arr[101][101];
int typical[10][10];
int n,m;

int main()
{
    FILE *fp,*fw;
    fp=fopen("B-large.in","r");
    fw=fopen("Output_Problem_B_Large.txt","w");
    int i,j,k,t,x,y;
    s(t);
    FOR(k,1,t+1)
    {

        s(n);
        s(m);
        int status=1,statusr=1,statusc=1;
        FOR(i,0,n)
            FOR(j,0,m)
                s(arr[i][j]);

        FOR(i,0,n)
            FOR(j,0,m)
            {
                statusr=statusc=1;
                {
                    FOR(x,0,m)
                    if(arr[i][x]>arr[i][j])
                    {
                        statusr=0;
                        break;
                    }
                    FOR(y,0,n)
                    if(arr[y][j]>arr[i][j])
                    {
                        statusc=0;
                        break;
                    }
                    if(statusc==0&&statusr==0)
                    {
                        status=0;
                        break;
                    }
                }
                if(status==0)
                break;
            }
        if(status)
        fprintf(fw,"Case #%d: YES\n",k);
        else
        fprintf(fw,"Case #%d: NO\n",k);
    }
    return 0;
}
