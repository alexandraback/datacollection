#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int sum, p, n;
int t[300], t2[300];
float wyn[300], taki;
int main()
{
    cin>>p;
    for(int l=1; l<=p; l++)
    {
        cout<<"Case #"<<l<<": ";
        cin>>n;
        sum=0;
        taki=0;
        int dod=0, dod2=0;
        for(int i=0; i<n; i++){
        cin>>t[i];
        wyn[i]=200;
        t2[i]=t[i];
        sum+=t[i];
        }
        sort (t2, t2+n);
        for(int i=0; i<n; i++)
        {
           // if()
         //   {
                float pom;

                pom=sum+sum;
                pom/=n;
                pom-=t[i];
                if (pom<0){
                wyn[i]=0.000000;
                pom/=sum;
                pom*=100;

                taki+=(float)pom*(-1);
                dod2++;
                continue;
                }
                pom/=sum;
                pom*=100;
                wyn[i]=pom;
         }
         for(int i=0; i<n; i++)
         {
             if(wyn[i]>0)
             {
                 wyn[i]-=((float)taki/(n-dod2));
             }

         }
         for(int i=0; i<n; i++)printf("%.6f ", wyn[i]);
          /*

          //  }
            /*else{
            float pom;
                pom=t[i]+t2[1]+sum;
                pom/=2;
                pom-=t[i];
                pom/=sum;
                pom*=100;
                printf("%.6f ", pom);

            }*/

        cout<<endl;
    }
}
