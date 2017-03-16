#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large-out.txt","w",stdout);
    int T,i,j,c,N,M,K;
    cin>>T;
    for(c=1;c<=T;++c){
        cin>>N>>M>>K;
        if(N>M)swap(N,M);
//        cout<<endl<<N<<" "<<M<<" "<<K<<endl;

        int p=0.5+pow(K+4,0.5);
//        cout<<pow(K+4,0.5)<<" p="<<p<<endl;

        int n=min(p,N),add=0;
        int m=1.0*(K+4)/n+0.5;
//        cout<<n<<" "<<m<<endl;
        if(K>(n*m-4))add=K+4-n*m;
        else if(K<(n*m-4))add=(K-n*m+4)/2;
        cout<<"Case #"<<c<<": ";

        if(N<=2)cout<<K<<endl;
        else if(K<=4)
            cout<<K<<endl;
        else if(m>M){
          m=M;
          if(K>(n*m-4))add=K+4-n*m;
          else if(K<(n*m-4))add=-(K-n*m+4)/2;
          cout<<(n+m)*2-8+add<<endl;
        }else
            cout<<(n+m)*2-8+add<<endl;
    }
    return 0;
}
