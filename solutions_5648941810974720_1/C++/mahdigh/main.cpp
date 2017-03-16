//IN THE NAME OF ALLAH
//

#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair
#define pb push_back
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
typedef long long int ll;
typedef long double ld;
typedef pair < ll, ll > pii;
typedef vector < ll > vi;
typedef set < ll > si;
const ld pi=3.1415926535897932384626433832795028841971693993751;
const ll maxn=2*1e5+1,inf=1e9+1;
string s;
int a[10],b[26];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    fin>>t;
    for(int j=0;j<t;j++){
        fin>>s;
        for(int i=0;i<26;i++)
            b[i]=0;
        for(int i=0;i<10;i++)
            a[i]=0;
        for(int i=0;i<s.size();i++){
            b[s[i]-'A']++;
        }
        a[0]=b[25];
        b[4]-=a[0];
        b['R'-'A']-=a[0];
        b['O'-'A']-=a[0];
        a[2]=b[22];
        b['T'-'A']-=a[2];
        b['O'-'A']-=a[2];
        a[8]=b['G'-'A'];
        b['E'-'A']-=a[8];
        b['I'-'A']-=a[8];
        b['H'-'A']-=a[8];
        b['T'-'A']-=a[8];
        a[3]=b['T'-'A'];
        b['E'-'A']-=2*a[3];
        b['R'-'A']-=a[3];
        a[4]=b['U'-'A'];
        b['F'-'A']-=a[4];
        b['O'-'A']-=a[4];
        b['R'-'A']-=a[4];
        a[1]=b['O'-'A'];
        b['N'-'A']-=a[1];
        b['E'-'A']-=a[1];
        a[6]=b['X'-'A'];
        b['I'-'A']-=a[6];
        b['S'-'A']-=a[6];
        a[7]=b['S'-'A'];
        b['V'-'A']-=a[7];
        a[5]=b['V'-'A'];
        b['I'-'A']-=a[5];
        a[9]=b['I'-'A'];
        fout<<"Case #"<<j+1<<": ";
        for(int i=0;i<10;i++){
            while(a[i]){
                a[i]--;
                fout<<i;
            }
        }
        fout<<endl;
    }
    return 0;
}
