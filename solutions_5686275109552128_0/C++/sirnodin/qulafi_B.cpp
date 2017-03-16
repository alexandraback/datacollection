#include <iostream>
#include <string.h>

using namespace std;

const int MAX_N=1010;
int T,CASE,D;
int NUM[MAX_N];

int main(int argc, char const *argv[])
{
    cin>>T;
    for(CASE=1;CASE<=T;++CASE){
        //memset(NUM,0,sizeof(int)*MAX_N);
        cin>>D;
        for(int i=0;i<MAX_N;++i){
            NUM[i]=0;
        }
        int p,mp=0;
        for(int i=0;i<D;++i){
            cin>>p;
            NUM[p]++;
            mp=max(p,mp);
        }
        int op_tm=0;
        int ans=mp;
        for(int nmp=mp;nmp>0;--nmp){
            if(NUM[nmp]>0){
                ans=min(ans,op_tm+nmp);
                op_tm+=NUM[nmp];
                if(nmp%2==0){
                    NUM[nmp/2]+=NUM[nmp]*2;
                }else{
                    NUM[nmp/2]+=NUM[nmp];
                    NUM[nmp/2+1]+=NUM[nmp];
                }
                NUM[nmp]=0;
            }
            if(op_tm>ans){
                break;
            }
        }
        cout<<"Case #"<<CASE<<": "<<ans<<endl;
    }
    return 0;
}
