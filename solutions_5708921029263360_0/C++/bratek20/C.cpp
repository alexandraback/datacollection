#include<bits/stdc++.h>
#define f first
#define s second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
vector< pair<pii,int> >v;
int j,p,s,k;
bool check(int mask){
    //printf("chack dla %d ma %d\n",mask,__builtin_popcount(mask));
    vector< pair<pii,int> >v2;
    for(int i=0;i<v.size();i++)
        if( (1<<i) & mask)
            v2.pb(v[i]);
    /*printf("siz %d\n",v2.size());
    for(int i=0;i<v2.size();i++)
            printf("%d %d %d\n",v2[i].f.f,v2[i].f.s,v2[i].s);
            puts("");*/
    for(int i=0;i<v2.size();i++){
        int ile1=1,ile2=1,ile3=1;
        for(int l=i+1;l<v2.size();l++){
            if(v2[i].f.f==v2[l].f.f && v2[i].f.s==v2[l].f.s)ile1++;
            if(v2[i].f.f==v2[l].f.f && v2[i].s==v2[l].s)ile2++;
            if(v2[i].f.s==v2[l].f.s && v2[i].s==v2[l].s)ile3++;
        }
        //printf("%d %d %d\n",ile1,ile2,ile3);
        if(ile1>k || ile2>k || ile3>k)return false;
    }
    return true;
}
int main(){
    int t; scanf("%d",&t);
    for(int test=1;test<=t;test++){
        scanf("%d%d%d%d",&j,&p,&s,&k);
        v.clear();
        for(int a=1;a<=j;a++)
            for(int b=1;b<=p;b++)
                for(int c=1;c<=s;c++)
                    v.pb(mp(mp(a,b),c));

       // for(int i=0;i<v.size();i++)printf("%d: %d %d %d\n",i,v[i].f.f,v[i].f.s,v[i].s);
        //return 0;
        int siz=v.size(); int odp=0;
        if(j==p && p==s && s==3){
            if(k==1)odp=69773473;
            else odp=111848107;
        }
        if(odp==0 || k>2)
        for(int i=(1<<siz)-1;i>0;i--){
            if( __builtin_popcount(i)>__builtin_popcount(odp) && check(i)){
                //printf("yupi %d\n",i);
                odp=i;

            }
        }

        printf("Case #%d: %d\n",test,__builtin_popcount(odp));
        for(int i=0;i<v.size();i++)
            if( (1<<i) & odp)
                printf("%d %d %d\n",v[i].f.f,v[i].f.s,v[i].s);
    }
    return 0;
}
