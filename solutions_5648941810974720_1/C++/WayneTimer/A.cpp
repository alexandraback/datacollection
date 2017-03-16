#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int a[10][26];
int b[26];
int c[10];

void count(int x,int v)
{
    c[x]+=v;
    for (int j=0;j<26;j++)
        b[j] -= a[x][j]*v;
}

int main()
{
    memset(a,0,sizeof(a));
    a[0]['Z'-'A']++;
    a[0]['E'-'A']++;
    a[0]['R'-'A']++;
    a[0]['O'-'A']++;

    a[1]['O'-'A']++;
    a[1]['N'-'A']++;
    a[1]['E'-'A']++;

    a[2]['T'-'A']++;
    a[2]['W'-'A']++;
    a[2]['O'-'A']++;

    a[3]['T'-'A']++;
    a[3]['H'-'A']++;
    a[3]['R'-'A']++;
    a[3]['E'-'A']++;
    a[3]['E'-'A']++;

    a[4]['F'-'A']++;
    a[4]['O'-'A']++;
    a[4]['U'-'A']++;
    a[4]['R'-'A']++;

    a[5]['F'-'A']++;
    a[5]['I'-'A']++;
    a[5]['V'-'A']++;
    a[5]['E'-'A']++;

    a[6]['S'-'A']++;
    a[6]['I'-'A']++;
    a[6]['X'-'A']++;

    a[7]['S'-'A']++;
    a[7]['E'-'A']++;
    a[7]['V'-'A']++;
    a[7]['E'-'A']++;
    a[7]['N'-'A']++;

    a[8]['E'-'A']++;
    a[8]['I'-'A']++;
    a[8]['G'-'A']++;
    a[8]['H'-'A']++;
    a[8]['T'-'A']++;

    a[9]['N'-'A']++;
    a[9]['I'-'A']++;
    a[9]['N'-'A']++;
    a[9]['E'-'A']++;

    int T,o;
    char s[2100];
    scanf("%d",&T);
    for (int o=1;o<=T;o++)
    {
        scanf("%s",s);
        memset(b,0,sizeof(b));
        int l;
        l = strlen(s);
        for (int i=0;i<l;i++)
            b[s[i]-'A']++;

        memset(c,0,sizeof(c));
        //====================

        count(0,b['Z'-'A']);
        count(2,b['W'-'A']);
        count(4,b['U'-'A']);
        count(6,b['X'-'A']);
        count(8,b['G'-'A']);

        count(1,b['O'-'A']);
        count(3,b['H'-'A']);
        count(5,b['F'-'A']);
        count(7,b['S'-'A']);
        count(9,b['E'-'A']);

        string ans;
        ans="";
        for (int i=0;i<10;i++)
            for (int j=0;j<c[i];j++)
            {
                char t;
                t = '0'+i;
                ans = ans + t;
            }
        printf("Case #%d: ",o);
        cout << ans << endl;
    }
    return 0;
}
