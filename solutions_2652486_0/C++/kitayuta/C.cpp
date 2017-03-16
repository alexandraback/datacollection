// {{{
// vim:filetype=cpp foldmethod=marker foldmarker={{{,}}}
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <climits>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define ALL(A)		(A).begin(),(A).end()
#define DUMP(A)    cout<<#A<<"="<<(A)<< endl
#define SIZE(A)    (int)((A).size())
#define MP  make_pair
#define PB  push_back
using namespace std;
typedef long long ll;

int vx[]={1,0,-1,0},vy[]={0,1,0,-1};
// }}}

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d:\n",ix+1);
        int R,N,M,K;
        scanf("%d%d%d%d",&R,&N,&M,&K);
        vector<int> ks(K);
        for(int i=0;i<R;i++){
            for(int j=0;j<K;j++){
                scanf("%d",&ks[j]);
            }
            for(int k0=2;k0<=5;k0++){
                for(int k1=k0;k1<=5;k1++){
                    for(int k2=k1;k2<=5;k2++){
                        int kk[3];
                        kk[0]=k0;kk[1]=k1;kk[2]=k2;
                        bool is2=true;
                        for(int j=0;j<K;j++){
                            bool is=false;
                            for(int l=0;l<8;l++){
                                int pro=1;
                                for(int m=0;m<3;m++){
                                    if(l&(1<<m)) pro*=kk[m];
                                }
                                if(pro==ks[j]) is=true;
                            }
                            if(!is) is2=false;
                        }
                        if(is2){
                            printf("%d%d%d\n",k0,k1,k2);
                            goto QUIT;
                        }
                    }
                }
            }
QUIT:       ;
        }
    }
}
