#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n;
string s;
vector<string> CC={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
int main()
{
    cin>>t;
    for(int ij=1;ij<=t;ij++)
    {
        cin>>s;
        vector<int> V(26,0),od(10,0);
        for(int i=0;i<s.size();i++)V[s[i]-'A']++;
        od[0]=V[25];
        V['Z'-'A']-=od[0];V['E'-'A']-=od[0];V['R'-'A']-=od[0];V['O'-'A']-=od[0];

        od[2]=V['W'-'A'];
        V['T'-'A']-=od[2];V['W'-'A']-=od[2];V['O'-'A']-=od[2];

        od[4]=V['U'-'A'];
        V['F'-'A']-=od[4];V['O'-'A']-=od[4];V['U'-'A']-=od[4];V['R'-'A']-=od[4];

        od[5]=V['F'-'A'];
        V['F'-'A']-=od[5];V['I'-'A']-=od[5];V['V'-'A']-=od[5];V['E'-'A']-=od[5];

        od[6]=V['X'-'A'];
        V['S'-'A']-=od[6];V['I'-'A']-=od[6];V['X'-'A']-=od[6];

        od[7]=V['S'-'A'];
        V['S'-'A']-=od[7];V['E'-'A']-=od[7];V['V'-'A']-=od[7];V['E'-'A']-=od[7];V['N'-'A']-=od[7];

        od[1]=V['O'-'A'];
        V['O'-'A']-=od[1];V['N'-'A']-=od[1];V['E'-'A']-=od[1];

        od[9]=V['N'-'A']/2;
        V['N'-'A']-=od[9];V['I'-'A']-=od[9];V['N'-'A']-=od[9];V['E'-'A']-=od[9];

        od[8]=V['I'-'A'];
        V['E'-'A']-=od[8];V['I'-'A']-=od[8];V['G'-'A']-=od[8];V['H'-'A']-=od[8];V['T'-'A']-=od[8];

        od[3]=V['T'-'A'];
        cout <<"Case #"<<ij<<": ";
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<od[i];j++)cout <<i;
        }
        cout <<endl;
    }
    return 0;
}
