#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

int main()
{
	freopen("output.txt","w",stdout);
	freopen("input.txt","r",stdin);
	int it;
    int t=1;
    cin>>it;
    for(t=1;t<=it;t++)
    {	
    	int n,m,k;
    	cin>>n>>m>>k;
        if(n>m){int temp=n;n=m;m=temp;}
        if(n==1&&m==1){cout<<"Case #"<<t<<": "<<1<<"\n";continue;}
        else if(n==1){if(k==1){cout<<"Case #"<<t<<": "<<1<<"\n";}else cout<<"Case #"<<t<<": "<<2<<"\n";continue;}
        if(n==2){if(n>=4)cout<<"Case #"<<t<<": "<<4<<"\n";else {cout<<"Case #"<<t<<": "<<k<<"\n";}continue;}
        //if(n!=3&&n!=4){cout<<"Case #"<<t<<": "<<k<<"\n";continue;}
        if(n==3)
        {
                if(m==3){if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                         else cout<<"Case #"<<t<<": "<<k<<"\n";}
                else if(m==4){if(k>=8)cout<<"Case #"<<t<<": "<<k-2<<"\n";
                              else if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                              else cout<<"Case #"<<t<<": "<<k<<"\n";}
                else if(m==5){if(k>=11)cout<<"Case #"<<t<<": "<<k-3<<"\n";
                              else if(k>=8)cout<<"Case #"<<t<<": "<<k-2<<"\n";
                              else if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                              else cout<<"Case #"<<t<<": "<<k<<"\n";}
                else if(m==6){if(k>=14)cout<<"Case #"<<t<<": "<<k-4<<"\n";
                              else if(k>=11)cout<<"Case #"<<t<<": "<<k-3<<"\n";
                              else if(k>=8)cout<<"Case #"<<t<<": "<<k-2<<"\n";
                              else if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                              else cout<<"Case #"<<t<<": "<<k<<"\n";
                     
                              }
        }
        else
        {
            if(m==4){         if(k>=12)cout<<"Case #"<<t<<": "<<k-4<<"\n";
                              else if(k>=8)cout<<"Case #"<<t<<": "<<k-2<<"\n";
                              else if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                              else cout<<"Case #"<<t<<": "<<k<<"\n";}
            else if(m==5){         if(k>=16)cout<<"Case #"<<t<<": "<<k-6<<"\n";
                              else if(k>=12)cout<<"Case #"<<t<<": "<<k-4<<"\n";
                              else if(k==11)cout<<"Case #"<<t<<": "<<k-3<<"\n";
                              else if(k>=8)cout<<"Case #"<<t<<": "<<k-2<<"\n";
                              else if(k>=5)cout<<"Case #"<<t<<": "<<k-1<<"\n";
                              else cout<<"Case #"<<t<<": "<<k<<"\n";}  
        }
        //cout<<"LOL";
}
return 0;
}
