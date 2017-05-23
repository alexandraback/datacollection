#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int s[200],T,N;
    cin>>T;
    for(int i=0;i<T;i++)
    {
            double X=0,max=0,ban=0;
            cin>>N;
            for(int k=0;k<N;k++)
            {
                  cin>>s[k];
                  X+=s[k];
                  if(s[k]>max) max=s[k];
            }
            
            ban=X*2.0/N;
            if(max>ban) ban=max;
            double X3=0,ban3=ban,N3=N,max3=0; 
            for(;;)
            {
                double X2=0,ban2=0,N2=0,max2=0;           
                for(int k=0;k<N3;k++)
                {
                      if(s[k]<ban3)
                      {
                         X2+=s[k];
                         if(s[k]>max2) max2=s[k];
                         N2++;
                      }
                }
                ban2=(X2+X)/N2;  
                 ban3=ban2;
                   N3=N2; 
                if(max2<=ban2)               
                  break;                  
            }           
            cout<<"Case #"<<i+1<<":";   
            for(int k=0;k<N;k++)
            {
                       if(s[k]>=ban3) cout<<' '<<0;
                       else cout<<' '<<setiosflags(ios::fixed)<<setprecision(6)<<((ban3-s[k])/X)*100;
            }
            cout<<'\n';
    }
    return 0;
}
