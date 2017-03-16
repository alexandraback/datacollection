#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 1000;
struct tribe{
    int d,n,w,l,s,dd,dp,ds;
}t[1100];
struct att{
    int id,day,num;
}c[1100000];
bool cmp(const struct att& a,const struct att& b){
    return a.day<b.day;
}
int h[10000],th[10000];
int main()
{
    freopen("C3.in","r",stdin);
    freopen("C3.txt","w",stdout);
    int T;
    cin>>T;
    for (int cas = 1; cas <= T; cas++){
        int n;
        cin>>n;
        int tot = 0;
        for (int i = 0; i < n; i++){
            cin>>t[i].d>>t[i].n>>t[i].w>>t[i].l>>t[i].s>>t[i].dd>>t[i].dp>>t[i].ds;
            t[i].l = t[i].l-t[i].w;
            for (int j = 0; j < t[i].n; j++){
                c[tot].id = i;
                c[tot].day = t[i].d+j*t[i].dd;
                c[tot++].num = j;
            }
        }
        sort(c,c+tot,cmp);
        //for (int i = 0; i < tot; i++) cout<<c[i].id<<' '<<c[i].day<<' '<<c[i].num<<' '<<endl;
        memset(h,0,sizeof(h));
        int now = -1,i = 0,ans = 0;
        while(i<tot){
            memset(th,0,sizeof(th));
            now = c[i].day;
            int j,maxs= -1,k;
            for (j = i;c[j].day==now;j++){
                int pos =  t[c[j].id].w+t[c[j].id].dp*c[j].num+M,flag = 0,
                    ts = t[c[j].id].s+t[c[j].id].ds*c[j].num;
                for (k =0;k<t[c[j].id].l;k++)
                    if (h[pos+k]<ts){
                        flag = 1;
                        th[pos+k] = max(th[pos+k],ts);
                    };
                if (flag) ans++;

            };
//            for (j = i;c[j].day==now;j++){
//                int pos =  t[c[j].id].w+t[c[j].id].dp*c[j].num+M;
//                for (k =0;k<t[c[j].id].l;k++) h[pos+k] = maxs;
//            };
            for (i = 0; i < 10000; i++) h[i] = max(h[i],th[i]);
            i = j;
            //cout<<i<<endl;
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
    return 0;
}
