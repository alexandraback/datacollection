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

bool path[1000][1000];
bool sed[1000];
int main(){
    int T;
    scanf("%d",&T);
    for(int ix=0;ix<T;ix++){
        printf("Case #%d: ",ix+1);
        int N;
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            sed[i]=false;
            for(int j=0;j<N;j++){
                path[i][j]=false;
            }
        }
        int M;
        for(int i=0;i<N;i++){
            scanf("%d",&M);
            int X;
            for(int j=0;j<M;j++){
                scanf("%d",&X);
                path[i][X-1]=true;
            }
        }
        bool ret=false;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                sed[j]=false;
            }
            sed[i]=true;
            queue<int> q;
            q.push(i);
            while(!q.empty()){
                int nnow=q.front();
                q.pop();
                for(int j=0;j<N;j++){
                    if(path[nnow][j]){
                        if(sed[j]){
                            ret=true;
                        }else{
                            sed[j]=true;
                            q.push(j);
                        }
                    }
                }
            }
        }
        if(ret) printf("Yes\n");
        else printf("No\n");
    }
}
