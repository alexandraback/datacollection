#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool test[35];

bool rtt[500][500];
int coinc[500];
int main(){
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C_o2.txt","w",stdout);
    int t=0;
    for(int h=0;h<35;h++) test[h]=false;

    scanf("%d",&t);
    for(int gt=0;gt<t;gt++){
        for(int h=0;h<35;h++) test[h]=false;
        for(int h=0;h<500;h++){
            for(int i=0;i<500;i++) rtt[h][i]=false;
            coinc[h]=0;
        }
        test[0]=true;
        int c,d,v,coin[10];
        scanf("%d %d %d",&c,&d,&v);

        for(int g=0;g<d;g++) scanf("%d",&coin[g]);
        for(int g=0;g<d;g++){
            for(int b=1;b<=v;b++){
                if(test[b]==true && b+coin[g]<=v) test[b+coin[g]] = true;
            }
            test[coin[g]]=true;
        }

        for(int e=0;e<=v;e++){
            //if(test[e]==true) cout<<"O";
            //else cout<<"X";
            //cout<<endl;
            if(test[e]==true) continue;
            for(int r=0;r<e;r++){
                if(test[r]==true){
                    rtt[e][e-r] = true;
                    coinc[e-r]++;
                }
            }
        }
        int ans = 0;
        while(true){
            bool flag = false;
            for(int bf=1;bf<=v;bf++){
                if(test[bf]==false){
                    flag = true;
                    break;
                }
            }
            if(flag==false) break;
            ans++;

            int maxic=0;
            int maxicoin=0;
            for(int be=1;be<=v;be++){
                bool flag1=false;
                for(int g=0;g<d;g++){
                    if(coin[g]==be){
                        flag1 = true;
                        break;
                    }
                }
                if(flag1==true) continue;
                if(coinc[be]>maxic){
                    maxic = coinc[be];
                    maxicoin = be;
                }
            }
            for(int ht=1;ht<=v;ht++){
                if(rtt[ht][maxicoin] == true){
                    test[ht] = true;
                    rtt[ht][maxicoin]=false;
                    for(int g=1;g<=v;g++){
                        if(rtt[ht][g]==true){
                            rtt[ht][g]=false;
                            coinc[g]--;
                        }
                    }
                }
            }
            //cout<<maxicoin<<" "<<coinc[maxicoin]<<endl;
            //system("pause");
            coinc[maxicoin] = 0;
        }
        printf("Case #%d: %d\n",gt+1,ans);

    }
}
