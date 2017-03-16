#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("output1.txt", "w", stdout);
    int t=1, l, i, n;
    string s;
    cin>>t;
    for(l=1; l<=t; l++)
    {
        cin>>s;
        int a[200], b[10];
        for(i=0; i<200; i++)
            a[i]=0;
        for(i=0; i<10; i++)
            b[i]=0;
        n=s.size();
        for(i=0; i<n; i++)
            a[s[i]]++;
        b[0]+=a['Z'];
        a['E']-=a['Z'];
        a['R']-=a['Z'];
        a['O']-=a['Z'];
        a['Z']=0;

        b[2]+=a['W'];
        a['T']-=a['W'];
        a['O']-=a['W'];
        a['W']=0;

        b[4]+=a['U'];
        a['F']-=a['U'];
        a['O']-=a['U'];
        a['R']-=a['U'];
        a['U']=0;

        b[8]+=a['G'];
        a['E']-=a['G'];
        a['I']-=a['G'];
        a['H']-=a['G'];
        a['T']-=a['G'];
        a['G']=0;

        b[6]+=a['X'];
        a['S']-=a['X'];
        a['I']-=a['X'];
        a['X']=0;

        b[3]+=a['R'];
        a['T']-=a['R'];
        a['H']-=a['R'];
        a['E']-=2*a['R'];
        a['R']=0;

        b[5]+=a['F'];
        a['I']-=a['F'];
        a['V']-=a['F'];
        a['E']-=a['F'];
        a['F']=0;

        b[7]+=a['V'];
        a['S']-=a['V'];
        a['N']-=a['V'];
        a['E']-=2*a['F'];
        a['V']=0;

        b[1]+=a['O'];
        a['N']-=a['O'];
        a['E']-=a['O'];
        a['O']=0;

        b[9]+=a['I'];

        cout<<"Case #"<<l<<": ";
        for(i=0; i<10; i++)
        {
            while(b[i]!=0)
            {
                cout<<i;
                b[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}
