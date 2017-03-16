#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

int T,R,C,W;

#define SMALL


int main(){
    freopen("a.txt","rt",stdin);
    #ifdef SMALL
         freopen("A-largeC.in","rt",stdin);
         freopen("outAClarge.out","wt",stdout);
    #endif

    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        cin>>R>>C>>W;
        int k=C/W;
        k=k*R;
        if(C%W==0){
            k--;
        }

          k=k+W;
        cout<<k<<"\n";
    }
}

