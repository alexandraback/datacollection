#include <iostream>
using namespace std;
typedef long long i64;
i64 pf[110000],pfNum,mn,d[110000],n,m,t,change;
i64 ipow(i64 dn,i64 up)
{
                                    i64 ret=1;
                                    while(up--) ret*=dn;
                                    return ret;
}
void getChange(i64 btm,i64 now,i64 top)
{
                                    i64 get=m,i;
                                    if(now==top)
                                    {
                                     for(i=0;i<top;i++) get/=d[i];
                                     change+=i64(ipow(get,n));
                                    }
                                    else for(i=btm;i<pfNum;i++) d[now]=pf[i],getChange(i+1,now+1,top);
}
int main()
{
                                    i64 i,ans,mm;
                                    while(cin>>n>>m)
                                    {
                                     pfNum=0; mm=m;
                                     for(i=2;i*i<=mm;i++)
                                     {
                                               if(mm%i==0)
                                               {
                                                        while(mm%i==0) mm/=i;
                                                        pf[pfNum++]=i;
                                               }
                                     }
                                     if(mm!=1) pf[pfNum++]=mm;
                                     ans=mn=i64(ipow(m,n));
                                     for(i=0;i<pfNum;i++)
                                     {
                                               change=0;
                                               getChange(0,0,i+1);
                                               if(i%2) ans+=change;
                                               else ans-=change;
                                     }
                                     cout<<ans<<endl;
                                    }
                                    return 0;
}
