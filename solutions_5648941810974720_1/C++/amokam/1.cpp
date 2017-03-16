#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=1; i<=t ; i++)
    {
        int alp[26]={0},num[10]={0};
        string s;
        cin>>s;
        for(int i=0 ; i<s.length() ; i++)
        {
            alp[s[i]-'A']++;
        }
        //zero
        num[0] = alp['Z'-'A'];
        alp['Z'-'A']-=num[0];
        alp['E'-'A']-=num[0];
        alp['R'-'A']-=num[0];
        alp['O'-'A']-=num[0];
        //six
        num[6] = alp['X'-'A'];
        alp['S'-'A']-=num[6];
        alp['I'-'A']-=num[6];
        alp['X'-'A']-=num[6];
        //seven
        num[7] = alp['S'-'A'];
        alp['S'-'A']-=num[7];
        alp['E'-'A']-=2*num[7];
        alp['V'-'A']-=num[7];
        alp['N'-'A']-=num[7];
        //four
        num[4] = alp['U'-'A'];
        alp['F'-'A']-=num[4];
        alp['O'-'A']-=num[4];
        alp['U'-'A']-=num[4];
        alp['R'-'A']-=num[4];
        //five
        num[5] = alp['V'-'A'];
        alp['F'-'A']-=num[5];
        alp['I'-'A']-=num[5];
        alp['V'-'A']-=num[5];
        alp['E'-'A']-=num[5];
        //eight
        num[8] = alp['G'-'A'];
        alp['E'-'A']-=num[8];
        alp['I'-'A']-=num[8];
        alp['G'-'A']-=num[8];
        alp['H'-'A']-=num[8];
        alp['T'-'A']-=num[8];
        //two
        num[2] = alp['W'-'A'];
        alp['T'-'A']-=num[2];
        alp['W'-'A']-=num[2];
        alp['O'-'A']-=num[2];
        //one
        num[1] = alp['O'-'A'];
        alp['O'-'A']-=num[1];
        alp['N'-'A']-=num[1];
        alp['E'-'A']-=num[1];
        //three
        num[3] = alp['H'-'A'];
        alp['T'-'A']-=num[3];
        alp['H'-'A']-=num[3];
        alp['R'-'A']-=num[3];
        alp['E'-'A']-=2*num[3];
        //nine
        num[9] = alp['E'-'A'];
        alp['N'-'A']-=2*num[8];
        alp['I'-'A']-=num[8];
        alp['E'-'A']-=num[8];

        cout<<"Case #"<<i<<": ";
        for(int i=0 ; i<10 ; i++)
        {
            while(num[i]>0)
            {
                cout<<i;
                num[i]--;
            }
        }
        cout<<endl;
    }
    return 0;
}
