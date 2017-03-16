#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long long ll;

string ss[11];

int n;

int v;

void rec (int has,int cantuse,int ed){
    //cout <<has<<" "<<cantuse<<" "<<ed<<endl;
    int f=0;
    for (int i=0;i<n;i++){
        if (!((1<<i)&has)){
            f=1;
            int lol=0;
            int ccantuse=cantuse;
            if (ed>=0){
                if (ss[ed][ss[ed].size()-1]!=ss[i][0]){
                    //cout <<ss[ed][ss[ed].size()-1]<<endl;
                    ccantuse|=(1<<(ss[ed][ss[ed].size()-1]-'a'));
                }
            }
            int ncantuse=ccantuse;
            for (int ii=0;ii<ss[i].size();ii++){
                if (ccantuse&(1<<(ss[i][ii]-'a'))){
                    lol=1;
                    break;
                }
                if (ii>0){
                    if (ss[i][ii]!=ss[i][ii-1]){
                        ncantuse|=(1<<(ss[i][ii-1]-'a'));
                    }
                }
            }
            if (lol==0) rec(has|(1<<i),ncantuse,i);
        }
    }
    if (f==0){
        v++;
    }
}

int main(){
    freopen ("out.out","w",stdout);
    int tcs;
    cin>>tcs;
    for (int tc=1;tc<=tcs;tc++){
        cout <<"Case #"<<tc<<": ";
        cin>>n;
        for (int i=0;i<n;i++){
            cin>>ss[i];
        }
        v=0;
        rec(0,0,-1);
        cout <<v<<endl;
    }
}
