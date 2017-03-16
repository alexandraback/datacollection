#include<iostream>
#include<cstdio>
#include<math.h>

using namespace std;

int T,K,L,S;
string k;
string l;
float ans=1.0;

#define SMALL


int main(){
    freopen("a.txt","rt",stdin);
    #ifdef SMALL
         freopen("B-smallC.in","rt",stdin);
         freopen("outBCsmall.out","wt",stdout);
    #endif
    char c;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        cin>>K>>L>>S;
        cin>>k>>l;
        float prob[L];
        int check=-1;
        for(int j=0;j<L;j++){
            c=l.at(j);
            prob[j]=0;
            for(int m=0;m<K;m++){
                if(k.at(m)==c){
                    prob[j]+=1;
                }
            }
            if(prob[j]==0.0){
                ans=0;
                check=j;
                break;
            }
        }
        float possible = 0.0;
        float totprob=1.0;
        if(check==-1){
                possible=(int)(S/L);
            for(int w=0;w<L;w++){

                totprob = totprob*prob[w];
            }
            for(int w=0;w<L;w++){
                totprob = totprob/K;
            }
        }
        ans = possible - (possible*totprob);
        cout<<ans<<"\n";
    }
}


