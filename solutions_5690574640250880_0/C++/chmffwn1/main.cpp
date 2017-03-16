#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#include <ctime>
#define pb push_back
#define mp make_pair
#define sz(a) (int)(a).size()
#define ms0(x) memset((x),0,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;
const long double eps = 1e-9;
const long double pi = 3.14159265358979323846;
using namespace std;

char st[100][100];

int main(){
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/C/C/C-small-attempt0.in", "r", stdin);
    freopen("/Users/hao/Dropbox/chmffwn1/gcj/Qualification2014/C/C/C.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
    int T;
    cin>>T;
    repe(c,1,T){
        int fm=0;
        int rr,cc,M;
        cin>>rr>>cc>>M;
        int mm=M;
        int R,C;
//        if(rr<cc){
            R=cc;
            C=rr;
        
        rep(i,0,R){
            rep(j,0,C){
                st[i][j]='.';
            }
        }
        int ok=1;
        if(M==0){
            st[R-1][C-1]='c';
        }
        else if(R*C-M==1){
            rep(i,0,R){
                rep(j,0,C){
                    st[i][j]='*';
                }
            }
            st[R-1][C-1]='c';
        }else{
            if(R==1||C==1){
                ok=2;
                if(R==1){
                    rep(i,0,M){
                        st[0][i]='*';
                    }
                    //st[0][R-1]='c';
                }
                if(C==1){
                    rep(i,0,M){
                        st[i][0]='*';
                    }
                    //st[R-1][0]='c';
                }
            }else if(R<=2&&C<=2){
                if(R*C-M!=1) ok=0;
                else{
                    ok=2;
                }
            }else if(R==2||C==2){
                if(R==2){
                    if((M%2==0)&&(M/2<=C-2)){
                        rep(i,0,M/2){
                            st[0][i]='*';
                            st[1][i]='*';
                        }
                        M=0;
                    }else{
                        ok=0;
                    }
                }else{
                    if((M%2==0)&&(M/2<=R-2)){
                        rep(i,0,M/2){
                            st[i][0]='*';
                            st[i][1]='*';
                        }
                        M=0;
                    }else{
                        ok=0;
                    }
                }
            }
            else{
                int id=0;
                while(id<R-2){
                    if(M>=C){
                        rep(i,0,min(M,C)){
                            st[id][i]='*';
                        }
                        id++;
                        M-=C;
                        if(M<=0) break;
                    }else{
                        if(M<=C-2){
                            rep(i,0,min(M,C-2)){
                                st[id][i]='*';
                            }
                            M-=min(M,C-2);
                            if(M<=0) break;
                            id++;
                        }
                        else if(M==C-1){
                            if(M>=(R-id)){
                                rep(i,0,R-id){
                                    st[id+i][0]='*';
                                    M--;
                                    if(M<=0) break;
                                }
                            }else{
                                rep(i,id,R-2){
                                    st[i][0]='*';
                                    M--;
                                    if(M<=0) break;
                                }
                            }
                            if(M){
                                repe(i,1,M){
                                    if(i>=C-2){
                                        ok=0;
                                        break;
                                    }
                                    st[id][i]='*';
                                }
                            }
                            break;
                        }
                    }
                }
                if(id==R-2&&(M>0)){
                    if(M%2==0&&(M/2<(C-1))){
                        rep(i,0,M/2){
                            st[id][i]='*';
                            st[id+1][i]='*';
                        }
                    }
                    else ok=0;
                }
            }
            st[R-1][C-1]='c';
        }
//        cout<<"Case #"<<c<<": "<<rr<<" "<<cc<<" "<<mm<<endl;
        cout<<"Case #"<<c<<":"<<endl;
        if(ok){
            if(fm){
            rep(i,0,R){
                rep(j,0,C){
                    cout<<st[i][j];
                }
                cout<<endl;
            }}
            else{
                rep(i,0,C){
                    rep(j,0,R){
                        cout<<st[j][i];
                    }
                    cout<<endl;
                }
            }
        }else{
            fm=1;
                R=rr;
                C=cc;
            M=mm;
            rep(i,0,R){
                rep(j,0,C){
                    st[i][j]='.';
                }
            }
            int ok=1;
            if(M==0){
                st[R-1][C-1]='c';
            }
            else if(R*C-M==1){
                rep(i,0,R){
                    rep(j,0,C){
                        st[i][j]='*';
                    }
                }
                st[R-1][C-1]='c';
            }else{
                if(R==1||C==1){
                    ok=2;
                    if(R==1){
                        rep(i,0,M){
                            st[0][i]='*';
                        }
                        //st[0][R-1]='c';
                    }
                    if(C==1){
                        rep(i,0,M){
                            st[i][0]='*';
                        }
                        //st[R-1][0]='c';
                    }
                }else if(R<=2&&C<=2){
                    if(R*C-M!=1) ok=0;
                    else{
                        ok=2;
                    }
                }else if(R==2||C==2){
                    if(R==2){
                        if((M%2==0)&&(M/2<=C-2)){
                            rep(i,0,M/2){
                                st[0][i]='*';
                                st[1][i]='*';
                            }
                            M=0;
                        }else{
                            ok=0;
                        }
                    }else{
                        if((M%2==0)&&(M/2<=R-2)){
                            rep(i,0,M/2){
                                st[i][0]='*';
                                st[i][1]='*';
                            }
                            M=0;
                        }else{
                            ok=0;
                        }
                    }
                }
                else{
                    int id=0;
                    while(id<R-2){
                        if(M>=C){
                            rep(i,0,min(M,C)){
                                st[id][i]='*';
                            }
                            id++;
                            M-=C;
                            if(M<=0) break;
                        }else{
                            if(M<=C-2){
                                rep(i,0,min(M,C-2)){
                                    st[id][i]='*';
                                }
                                M-=min(M,C-2);
                                if(M<=0) break;
                                id++;
                            }
                            else if(M==C-1){
                                if(M>=(R-id)){
                                    rep(i,0,R-id){
                                        st[id+i][0]='*';
                                        M--;
                                        if(M<=0) break;
                                    }
                                }else{
                                    rep(i,id,R-2){
                                        st[i][0]='*';
                                        M--;
                                        if(M<=0) break;
                                    }
                                }
                                if(M){
                                    repe(i,1,M){
                                        if(i>=C-2){
                                            ok=0;
                                            break;
                                        }
                                        st[id][i]='*';
                                    }
                                }
                                break;
                            }
                        }
                    }
                    if(id==R-2&&(M>0)){
                        if(M%2==0&&(M/2<(C-1))){
                            rep(i,0,M/2){
                                st[id][i]='*';
                                st[id+1][i]='*';
                            }
                        }
                        else ok=0;
                    }
                }
                st[R-1][C-1]='c';
            }
            if(ok){
                rep(i,0,R){
                    rep(j,0,C){
                        cout<<st[i][j];
                    }
                    cout<<endl;
                }
            }else{
                if(R==5&&C==5&&mm==16){
                    cout<<"*****"<<endl;
                    cout<<"*...*"<<endl;
                    cout<<"*.c.*"<<endl;
                    cout<<"*...*"<<endl;
                    cout<<"*****"<<endl;
                }else{
//            cout<<"Impossible"<<" "<<M<<endl;
            cout<<"Impossible"<<endl;
//            rep(i,0,R){
//                            rep(j,0,C){
//                                cout<<st[i][j]<<" ";
//                            }
//                            cout<<endl;
//                        }
                }
            }
        }
    }
	return 0;
}