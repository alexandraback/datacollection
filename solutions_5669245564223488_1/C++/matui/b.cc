#include<iostream>
#include<string>
using namespace std ;
int T,N;
const int mod=1000000007,Alp=26;
int mid[26];
int thr[26];
int start[26];
int tail[26];
string s;
long long fact(int x){
    if(x==0 || x==1)
        return 1;
    return (x*fact(x-1))%mod;
}
main(){
    cin>>T;
    for(int num=1;num<=T;++num){
        cin>>N;

        for(int i=0;i<Alp;++i){
            mid[i]=0;
            thr[i]=0;
            start[i]=0;
            tail[i]=0;
        }
        for(int i=0;i<N;++i){
            cin>>s;
            int _size=s.size();
            char x=s[0],y=s[_size-1];
            bool through=1,beg=1;
            for(int j=0;j<_size;++j){
                if(s[j]!=x){
                    if(through==0){
                        int t=x-'a';
                        mid[t]++;
                    }
                    else
                        through=0;
                    x=s[j];
                }
            }
            int t=s[0]-'a',p=s[_size-1]-'a';
            if(through)
                thr[t]++;
            else{
                start[t]++;
                tail[p]++;
            }
        }
        /*
        for(int i=0;i<Alp;++i){
            cout<<'a'+i<<' '<<mid[i]<<' '<<thr[i]<<' '<<start[i]<<' '<<tail[i]<<endl;
        }
        */
        bool flag=1;
        int block=0;
        for(int i=0;i<Alp;++i){
            if(start[i]>1 || tail[i]>1 || mid[i]>1){
                flag=0;
                break;
            }
            if(mid[i]==1){
                if(start[i]+tail[i]+thr[i]>0){
                    flag=0;
                    break;
                }
            }
            if(start[i]==1 && tail[i]==0)
                block++;
            if(start[i]==0 && tail[i]==0 && thr[i]>0)
                block++;

        }
        cout<<"Case #"<<num<<": ";
        if(!flag||block==0){
            cout<<0<<endl;
            continue;
        }
        long long ans=1;
        for(int i=0;i<Alp;++i){
            ans*=fact(thr[i]);
            ans%=mod;
        }
        ans*=fact(block);
        ans%=mod;
        cout<<ans<<endl;
    }

}
