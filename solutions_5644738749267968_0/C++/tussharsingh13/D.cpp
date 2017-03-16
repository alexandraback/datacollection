#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define pb push_back

int main()
{
        freopen ("D-small-attempt0.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
               int n;
               cin>>n;
               vector<double> kim,naomi,kcopy,ncopy;
               double temp;
               for(int i=0;i<n;i++)
               {
                        cin>>temp;
                        naomi.pb(temp);
               }
               for(int i=0;i<n;i++)
               {
                        cin>>temp;
                        kim.pb(temp);
               }
               sort(naomi.begin(),naomi.end());
               sort(kim.begin(),kim.end());
               /*for(int i=0;i<n;i++)
                        cout<<naomi[i]<<" ";
               cout<<endl;
               for(int i=0;i<n;i++)
                        cout<<kim[i]<<" ";
               cout<<endl;*/
               int nor=0,exag=0;
               kcopy=kim;
               ncopy=naomi;
               //Normal play
               for(int i=0;i<n;i++)
               {
                        if(naomi[n-i-1]>kim[n-i-1])
                        {
                                naomi.erase(naomi.begin()+(int)naomi.size()-1);
                                kim.erase(kim.begin());
                                nor++;
                        }
                        else
                        {
                                naomi.erase(naomi.begin()+(int)naomi.size()-1);
                                kim.erase(kim.begin()+(int)kim.size()-1);
                        }
               }
               //cout<<nor<<endl;
               for(int i=0;i<n;i++)
               {
                        double curr=kcopy[n-i-1];
                        vector<double> ::iterator it;
                        for(it=ncopy.begin();it!=ncopy.end();it++)
                        {
                                if(*it>curr)
                                break;
                        }
                        if(it!=ncopy.end())
                        {
                                exag++;
                                kcopy.erase(kcopy.begin()+(int)kcopy.size()-1);
                                ncopy.erase(it);
                        }
                        else
                        {
                                kcopy.erase(kcopy.begin()+(int)kcopy.size()-1);
                                ncopy.erase(ncopy.begin());
                        }
               }
               //cout<<exag<<endl;
               cout<<"Case #"<<test<<": "<<exag<<" "<<nor<<"\n";
        }
        return 0;
}
