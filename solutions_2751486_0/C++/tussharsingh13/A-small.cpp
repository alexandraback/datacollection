//Author: Tusshar Singh
#include<cstdlib>
#include<cmath>
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
#define lls(a) fscanf(fp,"%lld",&a)
#define ss(a) fscanf(fp,"%s",a)
#define p(a) printf("%d",a)
#define llp(a) printf("%lld",a)
#define sp(a) printf("%s",a)
#define cp(a) printf("%c",a)
#define nline printf("\n")
#define space printf(" ")
#define ll long long
int main()
{
    int i,j,k,t,x,l,m;
    FILE *fp,*fw;

    fp=fopen("A2.in","r");
    fw=fopen("output.txt","w");

    s(t);

    FOR(x,1,t+1)
    {
        int ans=0;
        int n;
        char s[1000];
        fscanf(fp,"%s %d",s,&n);
        int len=0;
        for(i=0;s[i];i++)
        len++;
        for(j=n;j<=len;j++)
        {
            for(i=0;i<=len-j;i++)
            {
                string st;
                for(k=0;k<j;k++)
                {
                    st+=(s[k+i]);
                }
                //cout<<st<<endl;
                int count = 0;
                for(k=0;k<st.size();k++)
                {
                    if(st[k]=='a'||st[k]=='e'||st[k]=='o'||st[k]=='i'||st[k]=='u')
                    count= 0;
                    else
                    count++;
                    if(count==n)
                    {
                        ans++;
                        //cout<<st<<endl;

                        break;
                    }
                }
            }
        }
        fprintf(fw,"Case #%d: %d\n",x,ans);
    }
    return 0;
}
