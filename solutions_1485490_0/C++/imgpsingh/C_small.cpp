#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#define int long long int
using namespace std;
struct st{
    int x;
    int y;
}ar1[101],ar2[101],box,toys;
int ans1=0;
int recur(int n,int m,int pos1,int pos2,int ans){
//    cout<<pos1<<" "<<pos2<<" "<<ans<<"\n";
//    system("pause");
    if(pos1==n || pos2==m)
        return ans;
    if(ar1[pos1].y==ar2[pos2].y){
        if(ar1[pos1].x==ar2[pos2].x){
            ans=max(ans,(recur(n,m,pos1+1,pos2+1,ans+ar1[pos1].x)));
        }
        else if(ar1[pos1].x<ar2[pos2].x){
            ar2[pos2].x-=ar1[pos1].x;
            ans=max(ans,(recur(n,m,pos1+1,pos2,ans+ar1[pos1].x)));
            ar2[pos2].x+=ar1[pos1].x;
        }
        else{
            ar1[pos1].x-=ar2[pos2].x;
            ans=max(ans,(recur(n,m,pos1,pos2+1,ans+ar2[pos2].x)));
            ar1[pos1].x+=ar2[pos2].x;
        }
    }
    else
        ans=max(ans,max(recur(n,m,pos1+1,pos2,ans),recur(n,m,pos1,pos2+1,ans)));
    return ans;
}
main(){
    int t,Kases=0;
    scanf("%lld",&t);
    while(t--){
        int n,m;
        ans1=0;
        scanf("%lld %lld",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%lld %lld",&ar1[i].x,&ar1[i].y);
        for(int i=0;i<m;i++)
            scanf("%lld %lld",&ar2[i].x,&ar2[i].y);
//        int ans=0,res=0;
        cout<<"Case #"<<++Kases<<": ";
        cout<<recur(n,m,0,0,0)<<"\n";
        //for(int i=0;i<n;i++){
//            for(int j=0;j<m;j++){
//                ans=0;
//                box.x=0;
//                box.y=0;
//                toys.x=0;
//                toys.y=0;
//                for(int k=j,l=i;k<m && l<n;){
//                    if(box.x==0 && toys.x==0){
//                        box.x=ar1[l].x;
//                        box.y=ar1[l].y;
//                        toys.x=ar2[k].x;
//                        toys.y=ar2[k].y;
//                        ++l;
//                        ++k;
//                    }
//                    else if(box.x==0){
//                        box.x=ar1[l].x;
//                        box.y=ar1[l].y;
//                        ++l;
//                    }
//                    else if(toys.x==0){
//                        toys.x=ar2[k].x;
//                        toys.y=ar2[k].y;
//                        ++k;
//                    }
//                    if(box.y==toys.y)
//                        ans+=min(box.x,toys.x);
//                    if(box.x<toys.x){
//                        toys.x-=box.x;
//                        box.x=0;
//                    }
//                    else{
//                        box.x-=toys.x;
//                        toys.x=0;
//                    }
//                }
//                res=max(res,ans);
//                cout<<i<<" "<<j<<" "<<ans<<"\n";
//            }
//        }
//        cout<<res<<"\n";
    }
    //system("pause");
    return 0;
}


