#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{int T,A,N,i,j,ans; 
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    cin>>T;
    for(i=1;i<=T;i++)
    {cin>>A>>N;
     vector<int>V(N);
     for(j=0;j<N;j++)
     cin>>V[j];
     if(A==1)ans=N;
     else
     {
     sort(V.begin(),V.end());
     long long Ma=A; int min=N,k;
     ans=0;
     for(j=0;j<N;j++)
     if(Ma>V[j])Ma+=V[j];
     else {k=0; while(Ma<=V[j]){Ma+=Ma-1;k++;}Ma+=V[j]; if(ans+N-j<min)min=ans+N-j;ans+=k; if(ans>N)break;}
     if(min<ans)ans=min;
     }
     cout<<"Case #"<<i<<": "<<ans<<endl;
//     cout<<A<<" "<<N<<endl;
//     for(j=0;j<N && j<15;j++)
//     cout<<V[j]<<" "; cout<<endl;
    }
//    system("PAUSE");
    return EXIT_SUCCESS;
}
