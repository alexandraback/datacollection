#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <cassert>
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
int N;
int A[1001];
int B[1001];
pi ar[1001];
pi f[1001];
int stars = 0;
int main()
{
    freopen("B-small-attempt3.in","r",stdin);
    freopen("SB.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int I=1;I<=T;I++){
        
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d%d",&A[i],&B[i]);
            ar[i] = pi(A[i],B[i]);
            f[i] = pi(A[i],i); 
        }
        sort(f,f+N);
        priority_queue<pi,vector<pi>,greater<pi> >Q;
        for(int i=0;i<N;i++)Q.push(pi(B[i],i));
        bool taken[1001]={false};
        int ans =0;
        stars =0;
        bool pos = true;
        while(!Q.empty()){
            pi tt = Q.top();
            Q.pop();
            int top = tt.F;
            int idx = tt.S;
            if ( top <= stars ){
                if ( taken[idx] == true ){
                    stars++;   
                }    
                else{
                    stars+=2;
                    taken[idx]=true;
                }
                ans++;
                continue;
            } 
            for ( int k=N-1;k>=0;k--){
                if ( taken[f[k].S]==false && f[k].F <= stars ){
                    stars++;
                    ans++; 
                    taken[f[k].S]=true;  
                }  
                if ( stars == top )break;
            } 
            if ( stars < top ){
                pos=false;
                break;
            }
            ans++;
            assert(stars == top );
            if ( taken[idx]==false){
                stars+=2;
                taken[idx]=true;
            }
            else stars++;
        }
        printf("Case #%d: ",I);
        if ( pos==false)printf("Too Bad\n");
        else printf("%d\n",ans);
        
    }
    
return 0;   
}
