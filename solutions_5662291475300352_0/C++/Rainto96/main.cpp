/*
*Rainto96
*Beijing University of Posts and Telecommunications School of Software Engineering
*http://blog.csdn.net/u011775691
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <climits>
using namespace std;
#define pb push_back
#define ALL(x) x.begin(),x.end()
#define VINT vector<int>
#define PII pair<int,int>
#define MP(x,y) make_pair((x),(y))
#define ll long long
#define ull unsigned long long
#define MEM0(x)  memset(x,0,sizeof(x))
#define scand(x) scanf("%d",&x)
#define Max(a,b) a=max(a,b)
const double eps=1e-10;
int dcmp(double x1){
        if(x1>eps) return 1;
        else if(x1<-eps) return -1;
        else return 0;
}
double v1,v2,p1,p2,dis;
int getAns(){
        //if(dcmp(v1-v2)==0) return 0;

        double t=dis/(v1-v2);
        double slowerPos=p2+v2*t;
        if(dcmp(slowerPos-360)>0) return 0;
        else return 1;
}
int main(){
        #ifndef ONLINE_JUDGE
                //freopen("C-small-1-attempt1.in","r",stdin);
                //freopen("C-small-1-attempt1.out","w",stdout);
        #endif // ONLINE_JUDGE
        int T;scand(T);
        for(int t=1;t<=T;t++){
                printf("Case #%d: ",t);
                int n;scand(n);
                VINT v;
                VINT pos;
                for(int i=1;i<=n;i++){
                        int d,h,m;
                        scanf("%d%d%d",&d,&h,&m);
                        for(int j=1;j<=h;j++){
                                v.pb(m+j-1);
                                pos.pb(d);
                        }
                }
                double lenth=360.0;
                if(v.size()==1){
                        cout<<0<<endl;
                        continue;
                }else{
                        v1=min(v[0],v[1]);// 1 is faster
                        v2=max(v[0],v[1]);// 2 is slower
                        p1=v[0]<v[1] ? pos[0] : pos[1];
                        p2=v[0]<v[1] ? pos[1] : pos[0];
                        if(v1==v2){
                                cout<<0<<endl;
                                continue;
                        }

                        dis=p2-p1;
                        if(dis==0) dis=360;

                        v1=lenth/v1;
                        v2=lenth/v2;
                        if(dis>0 && dis<360){
                                double t=dis/(v1-v2);
                                double meetPos=p2+v2*t;
                                if(dcmp(meetPos-360)>0){
                                        cout<<0<<endl;
                                        continue;
                                }else{
                                        p1=p2=meetPos;
                                        dis=360.0;
                                        int res=getAns();
                                        cout<<res<<endl;
                                        continue;
                                }
                        }else{
                                if(dis<0) dis+=360;
                                int res=getAns();
                                cout<<res<<endl;
                                continue;
                        }
                }
        }
        return 0;
}
