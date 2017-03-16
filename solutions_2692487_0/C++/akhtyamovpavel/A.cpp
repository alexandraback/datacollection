#include<cstdio>
#include<ctime>
#include<cmath>
#include<cctype>

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
#include<algorithm>
#include<utility>
#include<stack>
#include<queue>
using namespace std;
#define pb push_back
#define mp make_pair
#define FILEIN "A.in"
#define FILEOUT "A.txt"
int main(){
    freopen(FILEIN,"r",stdin);
    freopen(FILEOUT,"w",stdout);
    int t;
    cin>>t;
    for(int u=1;u<=t;++u){
        int sz,N;
        cin>>sz>>N;
        int A[N];
        for(int i=0;i<N;++i){
            cin>>A[i];
        }
        sort(A,A+N);
        int res=0;
        int fullres=N;
        if(sz==1){
            cout<<"Case #"<<u<<": ";
            cout<<N<<endl;
        }
        else{
        for(int i=0;i<N;++i){
            if(sz>A[i])
                sz+=A[i];
            else{
                if(res+N-i<fullres)
                    fullres=res+N-i;
                while(sz<=A[i]){
                    sz=2*sz-1;
                    ++res;
                }
                sz+=A[i];
            }
        }
        cout<<"Case #"<<u<<": ";
        cout<<min(res,fullres)<<endl;
        }
    }


    return 0;
}
