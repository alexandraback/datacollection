#include<iostream>
#include<cstdio>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define ld long double
using namespace std;

int dp[11][11];
int e,r,n,maxi;
int v[100];
void doit(int pos,int en,int gnn);
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
                    int t;

                    cin>>t;

                    for(int tt=1;tt<=t;tt++)
                    {

                            cin>>e>>r>>n;

                            for(int i=0;i<n;i++)
                                    cin>>v[i];


                            maxi=0;

                            doit(0,e,0);


                            cout<<"Case #"<<tt<<": "<<maxi<<"\n";
                    }
                    scanf("\n");
                    return 0;
}
void doit(int pos,int en,int gnn)
{
                   if(pos==n)
                   {

                             maxi=max(maxi,gnn);
                             return ;
                   }


                   for(int i=0;i<=en;i++)
                   {
                                         if((en-i+r)<=e)
                                         doit(pos+1,(en-i)+r,gnn+v[pos]*i);
                                         else
                                         doit(pos+1,e,gnn+v[pos]*i);
                   }

                   return ;
}
