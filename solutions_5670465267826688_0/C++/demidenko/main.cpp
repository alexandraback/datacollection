#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
#include <unistd.h>
#include <wait.h>
using namespace std;
typedef long long ll;
const int __limitofthreads = 4;
vector<pid_t> __ids;
char __str[256];

const int N = 1e6+6;

///1,i,j,k,-1,-i,-j,-k
///0,1,2,3, 4, 5, 6, 7
int g[8][8] = {
    {
        0,1,2,3
    },
    {
        1,4,3,6
    },
    {
        2,7,4,1
    },
    {
        3,2,5,4
    }
};


int q[8][8];
int inv[8];

inline int cnt(int all){
    if(all==0) return 1;
    if(all==4) return 2;
    return 4;
}

void solve(int test){
    /*+++start read data+++*/
    
    int n;
    ll x;
    string s;
    cin>>n>>x>>s;
    
    /*---end read data---*/
    if(__ids.size()>=__limitofthreads) wait(0);
    pid_t __id = fork();
    if(__id>0){
        __ids.push_back(__id);
        return ;
    }else{
        sprintf(__str, "thread%d.out", test);
        freopen(__str,"w",stdout);
    }
    /*+++start solution and write output+++*/
    cout<<"Case #"<<test<<": ";
    
    vector<int> a(n);
    for(int i=0;i<n;++i){
        if(s[i]=='i') a[i] = 1;
        if(s[i]=='j') a[i] = 2;
        if(s[i]=='k') a[i] = 3;
    }
    vector<int> sf(n+1);
    sf[n] = 0;
    for(int i=n-1;i>=0;--i) sf[i] = g[a[i]][sf[i+1]];
    int all = sf[0];
   // cout<<"all = "<<all<<endl;
    //cout<<g[3][4]<<endl;
    int c = cnt(all);
    int pr = 0;
    int ans = false;
    for(int i=1;i<=n;++i){
        pr = g[pr][a[i-1]];
        int f1 = g[1][inv[pr]];
        if(q[all][f1]==-1) continue;
        //cout<<i<<' '<<pr<<' '<<f1<<' '<<g[f1][pr]<<endl;
        for(int j=n-1;j>=0;--j){
            int f3 = g[inv[sf[j]]][3];
            if(q[all][f3]==-1) continue;
            //cout<<"!"<<n-j<<endl;
            int p2 = g[inv[pr]][all];
            int s2 = g[all][inv[sf[j]]];
            int f2 = g[g[inv[p2]][2]][inv[s2]];
            
            int c1 = q[all][f1];
            int c2 = q[all][f2];
            int c3 = q[all][f3];
            if(q[all][f2]!=-1){
                //cout<<"!!!"<<c1<<' '<<c2<<' '<<c3<<endl;
                if(c1+c2+c3+2<=x){
                    if((x-2-c1-c2-c3)%c==0){
                        ans = true;
                        i = n+1;
                        break;
                    }
                }
            }
            
            if(i+n-j<n){
                f2 = g[sf[i]][inv[sf[j]]];
                if(2==f2){
                    if(c1+c3+1<=x){
                        if((x-1-c1-c3)%c==0){
                            ans = true;
                            i = n+1;
                            break;
                        }
                    }
                }
            }
        }
    }
    /*
    bool ans2 = false;
    string z;
    for(int k=0;k<x;++k) z+=s;
    swap(z,s);
    n = s.length();
    a = vector<int>(n);
    
    for(int i=0;i<n;++i){
        if(s[i]=='i') a[i] = 1;
        if(s[i]=='j') a[i] = 2;
        if(s[i]=='k') a[i] = 3;
    }
    sf = vector<int>(n+1);
    sf[n] = 0;
    for(int i=n-1;i>=0;--i) sf[i] = g[a[i]][sf[i+1]];
    
    for(int i=0;i<n-2;++i)
    for(int j=i+1;j<n-1;++j){
        int f1 = g[sf[0]][inv[sf[i+1]]];
        int f2 = g[sf[i+1]][inv[sf[j+1]]];
        int f3 = sf[j+1];
        if(f1==1 && f2==2 && f3==3){
            ans2 = true;
            j = n;
            break;
        }
    }
    
    if(ans!=ans2){
        cout<<"!!"<<x<<' '<<z<<endl;
        
    }
    */
    cout<<(ans ? "YES" : "NO")<<endl;
    
    /*---end solution---*/
    sprintf(__str, "test #%d ok.%c", test,10);
    cerr<<__str;
    exit(0);
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    
    for(int i=0;i<4;++i)
    for(int j=0;j<4;++j){
        g[i][j^4] = g[i][j]^4;
        g[i^4][j] = g[i][j]^4;
        g[i^4][j^4] = g[i][j];
    }
    
    memset(q, -1, sizeof q);
    for(int i=0;i<8;++i){
        int x = 0;
        for(int j=0;j<8;++j){
            if(q[i][x]==-1) q[i][x] = j;
            x = g[x][i];
            
            if(g[i][j]==0){
                inv[i] = j;
            }
        }
    }
    
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
    
    /*combining outputs*/
    for(pid_t __id : __ids) waitpid(__id,0,0);
    int __bufsize = 1<<16;
    char *__buf = new char[__bufsize];
    for(int i=1;i<=t;++i){
        sprintf(__str, "thread%d.out", i);
        FILE *f = fopen(__str, "r");
        while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
        fclose(f);
        remove(__str);
    }
    
    return 0;
}
