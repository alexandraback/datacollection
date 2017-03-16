#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
using namespace std;
int ntest;
#define F first
#define S second
vector< pair<int, int> > vt;
int n;
int l1,l2;
bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.F!=p2.F) return p1.F<p2.F;
    else return p1.S > p2.S;
}
int main(){
    freopen("B-large.in","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&ntest);
    for(int test=0; test<ntest; test++){            
        vt.clear();
        scanf("%d",&n);
        for(int i=0; i<n; i++){
            scanf("%d %d",&l1,&l2);            
            vt.push_back( make_pair(l2,l1) );
        }        
        sort(vt.begin(),vt.end(),comp);
        int res=0;
        int st=0;
        bool vis[1005]; memset(vis,false,sizeof vis);
        for(int i=0; i<n; i++){
            //cout << st << " "<< vt[i].F << " "<< vt[i].S <<endl;
            while(vt[i].F > st ){
                int t=n-1;
                int temp=0;
                while(t > i-1 && vt[i].F > st ){
                    if( vt[t].S <= st && !vis[t] ){
                        st++;
                        temp++;
                        vis[t]=true;
                        res++;
                        break;
                    }
                    t--;
                }        
                if(temp==0) break;
            }
            if(vt[i].F > st){ res=-1; break;}            
            st+= 2 - (vis[i]);            
        }
        printf("Case #%d: ",test+1);
        if(res==-1) printf("Too Bad\n");
        else printf("%d\n",res+n);
    }
    return 0;
}
