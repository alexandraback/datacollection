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

int ar[100][100];
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        int N,M;
        scanf("%d%d",&N,&M);
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                scanf("%d",&ar[i][j]);
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                bool isrow=true,iscol=true;
                for(int k=0;k<N;k++){
                    if(ar[k][j]>ar[i][j]) isrow=false;
                }
                for(int k=0;k<M;k++){
                    if(ar[i][k]>ar[i][j]) iscol=false;
                }
                if(!(isrow || iscol)){
                    printf("NO\n");
                    goto EXIT;
                }
            }
        }
        printf("YES\n");
EXIT:   ;
    }
}
