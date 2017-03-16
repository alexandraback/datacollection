#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#define pb push_back
using namespace std;
string S,s;
int N,T;
int st,dr;
int v[110];
vector<int> l[155];
int isf[444];
int ret[1010];
int get(int val, int pos) {
    map<int,int> h;

    for(int i=1;i<=2*N-1;++i) {
        if(isf[i] && l[i][pos] == val) {
            for(int j=st;j<=dr;++j) {
                ++h[l[i][j]];
            }
        }
    }
    for(int i=1;i<=2*N-1;++i) {
       if(isf[i]) {
           --h[l[i][pos]];
        }   
    }
    for(int i=1;i<=2*N-1;++i) {
        if(isf[i] && l[i][pos] == val) {
            for(int j=st;j<=dr;++j) {
                if(h[l[i][j]]) {
                    return l[i][j];
                }
            }
        }
    }
    return -1;
}

int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    scanf("%d",&T);
    for(int t=1;t<=T;++t) {
        cin >> N;
        for(int i=1;i<=2*N-1;++i){
            l[i].clear();
            isf[i] = 1;
            for(int j=0;j<N;++j) {
                int x;
                cin >> x;
                l[i].pb(x);
            }
        }
        st=0, dr = N-1;
        for(int i=1;i<=N;++i) {
            
            int mn = 2555,cnt=0;
                int ma = -1,cmt = 0;
                vector<int> v1,v2;
                
            
            for(int j=1;j<=2*N-1;++j) {
                if(!isf[j]) {
                continue;
                }
                for(int k=st;k<=dr;++k) {
                    if(l[j][k] > ma) {
                        ma = l[j][k];
                        cmt = 0;
                        v1.clear();
                    }
                    if(l[j][k] == ma) {
                        ++cmt;
                        v1.pb(j);
                    }
                     if(l[j][k] < mn) {
                        mn = l[j][k];
                        cnt = 0;
                        v2.clear();
                    }
                    if(l[j][k] == mn) {
                        ++cnt;
                        v2.pb(j);
                    }
                }
            }
                if(v2.size() == 2) {
                    ret[st] = get(mn,st);
                    for(auto nx : v2) isf[nx] = 0;
                    ++st;
                } else if(v1.size() == 2) {
                    ret[dr] = get(ma,dr);
                    for(auto nx : v1) isf[nx] = 0;
                    --dr;
                }
                else {
                    ret[st] = ma;
                }
        }
        cout<<"Case #"<<t<<": ";
        for(int i=0;i<N;++i)
            cout << ret[i] << " " ;
        cout << endl;
    }
}
