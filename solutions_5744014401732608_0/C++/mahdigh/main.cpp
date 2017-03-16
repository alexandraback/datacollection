//IN THE NAME OF ALLAH
//

#include <bits/stdc++.h>
#include <fstream>
#define mp make_pair
#define pb push_back
using namespace std;
ifstream fin("1.in");
ofstream fout("1.out");
typedef unsigned long long int ll;
typedef long double ld;
typedef pair < ll, ll > pii;
typedef vector < ll > vi;
typedef set < ll > si;
const ld pi=3.1415926535897932384626433832795028841971693993751;
const ll maxn=26,inf=1e9+1;
ll t,b,m;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fin>>t;
    for(int i=1;i<=t;i++){
        fout<<"Case #"<<i<<": ";
        fin>>b>>m;
        ll k=1,h=b-2,f=0;
        if(k>=m){
            f=-1;
            h=-1;
        }
        while(h){
            k*=2;
            if(k>=m){
                f=-1;
                break;
            }
            h--;
        }
        if(f!=-1){
            fout<<"IMPOSSIBLE"<<endl;
        }
        else{
            fout<<"POSSIBLE"<<endl;
            if(h==-1)
                h=0;
            else
                h=b-1-h;
            const int c=b;
            string s[c];
            for(int i=0;i<b;i++){
                for(int j=0;j<b;j++) s[i].pb('0');
            }
            for(int i=1;i<=h;i++){
                for(int j=i+1;j<=h;j++)
                    s[i][j]='1';
                if(i!=b-1)
                    s[i][b-1]='1';
            }
            if(!h) s[0][b-1]='1';
            else s[0][1]='1';
            if(h){
                k=1;
                int cnt=h;
                while(--h)
                    k*=2;
                m-=k;
                if(m==k){
                    s[0][b-1]='1';
                    m--;
                }
                while(m){
                    if(m%2){
                        s[0][cnt--]='1';
                    }
                    m/=2;
                }
            }
            for(int i=0;i<b;i++){
                fout<<s[i]<<endl;
            }
        }
    }
    return 0;
}
