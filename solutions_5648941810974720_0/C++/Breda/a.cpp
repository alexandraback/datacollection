#include <bits/stdc++.h>

using namespace std;

void resolver(int t)
{
    char tex[3000];
    int q[100], i, f[10];
    memset(f, 0, sizeof(f));
    memset(q, 0, sizeof(q));
    scanf("%s", tex);
    for(i=0;i<strlen(tex);i++)
    {
        q[tex[i]-'A']++;
    }

    while(q['Z'-'A']>0)
    {
        f[0]++;
        q['Z'-'A']--;
        q['E'-'A']--;
        q['R'-'A']--;
        q['O'-'A']--;
    }
    while(q['X'-'A']>0)
    {
        f[6]++;
        q['S'-'A']--;
        q['I'-'A']--;
        q['X'-'A']--;
    }
    while(q['U'-'A']>0)
    {
        f[4]++;
        q['F'-'A']--;
        q['O'-'A']--;
        q['U'-'A']--;
        q['R'-'A']--;
    }
    while(q['F'-'A']>0)
    {
        f[5]++;
        q['F'-'A']--;
        q['I'-'A']--;
        q['V'-'A']--;
        q['E'-'A']--;
    }
    while(q['V'-'A']>0)
    {
        f[7]++;
        q['S'-'A']--;
        q['E'-'A']--;
        q['V'-'A']--;
        q['E'-'A']--;
        q['N'-'A']--;
    }
    while(q['W'-'A']>0)
    {
        f[2]++;
        q['T'-'A']--;
        q['W'-'A']--;
        q['O'-'A']--;
    }
    while(q['O'-'A']>0)
    {
        f[1]++;
        q['O'-'A']--;
        q['N'-'A']--;
        q['E'-'A']--;
    }
    while(q['G'-'A']>0)
    {
        f[8]++;
        q['E'-'A']--;
        q['I'-'A']--;
        q['G'-'A']--;
        q['H'-'A']--;
        q['T'-'A']--;
    }
    while(q['H'-'A']>0)
    {
        f[3]++;
        q['T'-'A']--;
        q['H'-'A']--;
        q['R'-'A']--;
        q['E'-'A']--;
        q['E'-'A']--;
    }
    while(q['N'-'A']>0)
    {
        f[9]++;
        q['N'-'A']--;
        q['I'-'A']--;
        q['N'-'A']--;
        q['E'-'A']--;
    }
    cout<<"Case #"<<t<<": ";
    for(i=0;i<10;i++)
    {
        while(f[i]!=0)
        {
            cout<<i;
            f[i]--;
        }
    }
    cout<<endl;
}

int main()
{
    int t, i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        resolver(i);
    }
    return 0;
}
