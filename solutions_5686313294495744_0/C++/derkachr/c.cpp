#include<bits/stdc++.h>
#define pb push_back
 using namespace std;

string a[100],b[100];
int A[100],B[100],p[100],kol1,kol2,i,mx,tt,j,last_mask,mask,t,t_,n;
 inline void ww()
 {
                    if(kol2>mx){

                for(i=1;i<=kol2;++i)
                {
                    tt=0;
                    for(j=1;j<=kol1;++j)
                        if(a[A[j]] == a[B[i]])
                    {
                        tt=1;
                        break;
                    }
                    if(tt)
                    {
                        tt=0;
                    for(j=1;j<=kol1;++j)
                         if(b[A[j]] == b[B[i]])
                    {
                        tt=1;
                        break;
                    }
                    }
                    if(!tt)return;
                }

                mx=kol2;

                    }

 }

  int main()
  {

//      freopen("output.txt","w",stdout);

p[1] = 1;
for(i=2;i<=25;++i) p[i] = p[i-1] * 2;

    cin>>t;
     for(t_=1;t_<=t;++t_)
     {
          cout<<"Case #"<<t_<<": ";
           cin>>n;
           for(i=1;i<=n;++i)
               cin>>a[i]>>b[i];

               mx = 0;

               last_mask = (1<<n) - 1;
                for(mask=0;mask<=last_mask;++mask){
                    kol1 = kol2 = 0;
                    for(i=1;i<=n;++i)
                    if((mask & p[i])>0) A[++kol1] = i; else B[++kol2] = i;
            ww();
                }

                cout<<mx<<endl;

     }

  }
