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
string c,j,ac,aj,cc,jj;
int t;
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    fin>>t;
    for(int i=1;i<=t;i++){
        fin>>c>>j;
        fout<<"Case #"<<i<<": ";
        ll x,y,ans=inf;
        string nc,nj;
        int b=0;
        if(c.size()==1){
            if(c=="?" && j=="?"){
                c="0";
                j="0";
            }
            else if(c=="?")
                c=j;
            else if(j=="?")
                j=c;
            nc=c;
            nj=j;
        }
        else if(c.size()==2){
            for(int k1=0;k1<10;k1++){
                for(int k2=0;k2<10;k2++){
                    for(int k3=0;k3<10;k3++){
                        for(int k4=0;k4<10;k4++){
                            x=0;
                            y=0;
                            cc="00";
                            jj="00";
                            if(c[0]=='?'){
                                x+=k1;
                                cc[0]=k1+'0';
                            }
                            else{
                                x+=c[0]-'0';
                                cc[0]=c[0];
                            }
                            if(j[0]=='?'){
                                y+=k2;
                                jj[0]=k2+'0';
                            }
                            else{
                                y+=j[0]-'0';
                                jj[0]=j[0];
                            }
                            x*=10;
                            y*=10;
                            if(c[1]=='?'){
                                x+=k3;
                                cc[1]=k3+'0';
                            }
                            else{
                                x+=c[1]-'0';
                                cc[1]=c[1];
                            }
                            if(j[1]=='?'){
                                y+=k4;
                                jj[1]=k4+'0';
                            }
                            else{
                                y+=j[1]-'0';
                                jj[1]=j[1];
                            }
                            if(abs(x-y)<ans){
                                ans=abs(x-y);;
                                nc=cc;
                                nj=jj;
                            }
                        }
                    }
                }
            }
        }
        else{
            for(int k1=0;k1<10;k1++){
                for(int k2=0;k2<10;k2++){
                    for(int k3=0;k3<10;k3++){
                        for(int k4=0;k4<10;k4++){
                            for(int k5=0;k5<10;k5++){
                                for(int k6=0;k6<10;k6++){
                                    x=0;
                                    y=0;
                                    cc="000";
                                    jj="000";
                                    if(c[0]=='?'){
                                        x+=k1;
                                        cc[0]=k1+'0';
                                    }
                                    else{
                                        x+=c[0]-'0';
                                        cc[0]=c[0];
                                    }
                                    if(j[0]=='?'){
                                        y+=k2;
                                        jj[0]=k2+'0';
                                    }
                                    else{
                                        y+=j[0]-'0';
                                        jj[0]=j[0];
                                    }
                                    x*=10;
                                    y*=10;
                                    if(c[1]=='?'){
                                        x+=k3;
                                        cc[1]=k3+'0';
                                    }
                                    else{
                                        x+=c[1]-'0';
                                        cc[1]=c[1];
                                    }
                                    if(j[1]=='?'){
                                        y+=k4;
                                        jj[1]=k4+'0';
                                    }
                                    else{
                                        y+=j[1]-'0';
                                        jj[1]=j[1];
                                    }
                                    x*=10;
                                    y*=10;
                                    if(c[2]=='?'){
                                        x+=k5;
                                        cc[2]=k5+'0';
                                    }
                                    else{
                                        x+=c[2]-'0';
                                        cc[2]=c[2];
                                    }
                                    if(j[2]=='?'){
                                        y+=k6;
                                        jj[2]=k6+'0';
                                    }
                                    else{
                                        y+=j[2]-'0';
                                        jj[2]=j[2];
                                    }
                                    if(abs(x-y)<ans){
                                        ans=abs(x-y);;
                                        nc=cc;
                                        nj=jj;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        fout<<nc<<" "<<nj<<endl;
    }
    return 0;
}
