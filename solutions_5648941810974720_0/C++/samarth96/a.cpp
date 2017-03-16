#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
#define mp make_pair
#define pb push_back
#define ft first
#define sd second

#define mod 1000000007
#define inf 2000000001
#define N 2000

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    int qq,tt;
    scanf("%d",&tt);
    char ans[tt][N];
    for (qq=1;qq<=tt;qq++)
    {
        int i,j,k,n;
        char s[N+9];
        scanf("%s",s);
        n=strlen(s);
        int a[26]={0};
        int b[10]={0};
        for (i=0;i<n;i++)
            a[s[i]-'A']++;
        while(a['Z'-'A']>0)
        {
            b[0]++;
            a['Z'-'A']--;
            a['E'-'A']--;
            a['R'-'A']--;
            a['O'-'A']--;
        }
        while(a['W'-'A']>0)
        {
            b[2]++;
            a['W'-'A']--;
            a['T'-'A']--;
            a['O'-'A']--;
        }
        while(a['U'-'A']>0)
        {
            b[4]++;
            a['U'-'A']--;
            a['F'-'A']--;
            a['R'-'A']--;
            a['O'-'A']--;
        }
        while(a['X'-'A']>0)
        {
            b[6]++;
            a['X'-'A']--;
            a['I'-'A']--;
            a['S'-'A']--;
        }
        while(a['G'-'A']>0)
        {
            b[8]++;
            a['G'-'A']--;
            a['E'-'A']--;
            a['I'-'A']--;
            a['H'-'A']--;
            a['T'-'A']--;
        }
        while(a['O'-'A']>0)
        {
            b[1]++;
            a['O'-'A']--;
            a['E'-'A']--;
            a['N'-'A']--;
        }
        while(a['H'-'A']>0)
        {
            b[3]++;
            a['T'-'A']--;
            a['H'-'A']--;
            a['R'-'A']--;
            a['E'-'A']--;
            a['E'-'A']--;
        }
        while(a['S'-'A']>0)
        {
            b[7]++;
            a['S'-'A']--;
            a['E'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
            a['N'-'A']--;
        }
        while(a['V'-'A']>0)
        {
            b[5]++;
            a['F'-'A']--;
            a['I'-'A']--;
            a['V'-'A']--;
            a['E'-'A']--;
        }
        while(a['N'-'A']>0)
        {
            b[9]++;
            a['N'-'A']--;
            a['I'-'A']--;
            a['N'-'A']--;
            a['E'-'A']--;
        }
        k=0;
        for (i=0;i<10;i++)
        {
            for (j=0;j<b[i];j++)
                ans[qq][k++]=i+'0';
        }
        ans[tt][k]='\0';
    }
    fclose(stdin);
    freopen("out.txt","w",stdout);
    for (qq=1;qq<=tt;qq++)
    {
        printf("Case #%d: %s\n",qq,ans[qq]);
        fflush(stdout);
    }
    fclose(stdout);
}
