#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t,n,idx;
int names[1111][4];
map<string,int>chkstr;
string inp;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);


    scanf("%d ",&t);
    for(int ca=1;ca<=t;ca++){
        idx=1;
        chkstr.clear();
       scanf("%d",&n);
       for(int i = 0 ; i < n;i++){
            for(int j =0 ; j < 2;j++){
                cin>>inp;
                if(!chkstr[inp]){
                    chkstr[inp]=idx++;
                }
                names[i][j]=chkstr[inp];
            }
       }

       int ans = 0;

       for(int cnt, i = 0,lim = (1<<n) ; i<lim;i++ ){
            cnt = 0;
            for(int j = 0 ,f1; j < n;j++){
                if((i&(1<<j))){
                    f1=1;
                    for(int k = 0;k < n && f1;k++){
                        if(k==j || (i&(1<<k)))continue;
                        if(names[k][0]==names[j][0]){
                            for(int p = 0 ; p<n && f1;p++){
                                if(p==j || p==k || (i&(1<<p)))continue;
                                if(names[p][1]==names[j][1]){
                                    f1=0;
                                }
                            }
                        }
                    }
                    if(f1==0)cnt++;
                }
            }
            ans = max(ans,cnt);

       }
       printf("Case #%d: %d\n",ca,ans);


    }


    return 0;
}
