#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main ()
{
    int n,m,i,j,k,t,s,p,a,b[1024],br;
    cin>>t;
    for(k=1;k<=t;k++)
    {
                    cin>>n>>s>>p;
                    br=0;
                    for(i=0;i<n;i++)
                                    {
                                        cin>>a;
                                        if(a==0){if(p==0)br++;}
                                        else
                                        {
                                        if(a%3==0)
                                        {
                                        if(a/3<p){if(((a/3)+1)>=p&&s!=0){br++;s--;}}
                                        else br++;
                                        }
                                        if(a%3==1)if((a/3+1)>=p)br++;
                                        if(a%3==2)
                                        {
                                        if((a/3+1)>=p)br++;
                                        else
                                        if((a/3+2)>=p&&s!=0){br++;s--;}
                                        }
                                        }
                                    }
                    
                    b[k]=br;      
    }
    for(k=1;k<=t;k++)
    cout<<"Case #"<<k<<": "<<b[k]<<endl;
    return 0;
}
