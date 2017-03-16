#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))


int main()
{
    int t;
    int cc[26];
    int num[10];
    string s;
    cin>>t;
    /*
    Z 0
    W 2
    H 3 8
    F 4 5
    U 4
    V 5 7
    X 6
    S 6 7
    G 8
    I 5 6 9
    O 1 2 4
    */
    
    REP(k,t)
    {
        cin>>s;
        CLR(cc);
        CLR(num);
        REP(j,s.size())
        {
            cc[s[j]-'A']++;
        }
        num[4]=cc['U'-'A'];
        num[8]=cc['G'-'A'];
        num[6]=cc['X'-'A'];
        num[0]=cc['Z'-'A'];
        num[2]=cc['W'-'A'];
        num[7]=cc['S'-'A'] - num[6];
        num[3]=cc['H'-'A'] - num[8];
        num[5]=cc['F'-'A'] - num[4];
        num[9]=cc['I'-'A'] - num[5] - num[6] - num[8];
        num[1]=cc['O'-'A'] - num[0] - num[2] - num[4];
        
        string ans="";
        REP(i,10)
        {
            REP(j,num[i])
                ans+='0'+i;
        }
        cout<<"Case #"<<k+1<<": "<<ans<<endl;
    }
    
}