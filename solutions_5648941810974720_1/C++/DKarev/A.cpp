//
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<fstream>
#include<iomanip>
#include<queue>
#include<stack>
#define lli long long

using namespace std;

int a[550],Ans[100];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("A.in");
    ofstream cout("A.out");

    int T,num0;
    cin>>T;


    for(int t1=1;t1<=T;t1++)
    {

        cout<<"Case #"<<t1<<": ";
        cin>>s;

        memset(Ans,0,sizeof(Ans));
        memset(a,0,sizeof(a));
        for(int i=0;i<s.size();i++)
        {
            a[s[i]-'A']++;
        }

        num0=a['Z'-'A'];
        a['E'-'A']-=num0;
        a['R'-'A']-=num0;
        a['O'-'A']-=num0;
        Ans[0]=num0;

        num0=a['W'-'A'];
        a['T'-'A']-=num0;
        a['O'-'A']-=num0;
        Ans[2]=num0;

        num0=a['X'-'A'];
        a['S'-'A']-=num0;
        a['I'-'A']-=num0;
        Ans[6]=num0;

        num0=a['S'-'A'];
        a['E'-'A']-=num0;
        a['V'-'A']-=num0;
        a['E'-'A']-=num0;
        a['N'-'A']-=num0;
        Ans[7]=num0;

        num0=a['U'-'A'];
        a['F'-'A']-=num0;
        a['O'-'A']-=num0;
        a['R'-'A']-=num0;
        Ans[4]=num0;


        num0=a['F'-'A'];
        a['I'-'A']-=num0;
        a['V'-'A']-=num0;
        a['E'-'A']-=num0;
        Ans[5]=num0;


        num0=a['G'-'A'];
        a['E'-'A']-=num0;
        a['I'-'A']-=num0;
        a['H'-'A']-=num0;
        a['T'-'A']-=num0;
        Ans[8]=num0;

        num0=a['O'-'A'];
        a['N'-'A']-=num0;
        a['E'-'A']-=num0;
        Ans[1]=num0;

        num0=a['T'-'A'];
        a['H'-'A']-=num0;
        a['R'-'A']-=num0;
        a['E'-'A']-=num0;
        a['E'-'A']-=num0;
        Ans[3]=num0;

        Ans[9]=a['I'-'A'];

        for(int i=0;i<=9;i++)
        {
            for(int j=0;j<Ans[i];j++)
            {
                cout<<i;
            }
        }
        cout<<"\n";

    }


    return 0;
}


