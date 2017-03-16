#include<bits/stdc++.h>
using namespace std;
int den[35];
int val[35];
int main(){
    int c,d,v,t;
    cin>>t;
    for(int x=1;x<=t;x++){
        memset(val,0,sizeof(val));
        cin>>c>>d>>v;
        for(int i=0;i<d;i++){
            cin>>den[i];
        }
        int tmp;
        for(int m=0;m<(1<<d);m++){
            tmp=0;
            for(int i=0;i<d;i++){
                if((m&(1<<i))!=0)tmp+=den[i];
            }
            if(tmp<=v)val[tmp]=2;
            //cout<<m<<" "<<tmp<<endl;

        }
        int ans=0;
        for(int i=1;i<=v;i++){
            if(val[i]==0){
                ans++;
                val[i]=1;
                //cout<<"added "<<i<<endl;
                for(int j=1;j<=v-i;j++){
                    if(val[j]==2){
                        if(val[i+j]==0)val[i+j]=1;
                    }
                    if(val[j]==1)val[j]=2;
                }
            }
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}
