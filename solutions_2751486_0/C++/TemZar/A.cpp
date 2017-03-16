#include <cstdlib>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{int T,i,j; string D="aeiou";
 set<char>V(D.begin(),D.end());
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small.out","w",stdout);
    cin>>T;
//    cout<<T<<endl;
    for(i=1;i<=T;i++)
    {string S; int n,N,ans,k,prev=0,L,R;
     cin>>S>>n; N=S.size();
 //    cout<<S<<' '<<n<<endl;
     for(k=ans=j=0;j<N;j++)
     {if(V.count(S[j])==0)k++; else k=0;
 //     cout<<j<<' '<<k<<endl;
      if(k>=n){L=j-n+1;R=j;ans+=(L-prev+1)*(N-R); prev=L+1;}
     }
     cout<<"Case #"<<i<<": "<<ans<<endl;
    }
//    system("PAUSE");
    return EXIT_SUCCESS;
}
