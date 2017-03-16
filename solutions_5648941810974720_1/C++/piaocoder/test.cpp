#include <bits/stdc++.h>
using namespace std;

int ch[30];
int num[10];

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T,t = 0;
    scanf("%d",&T);
    while(T--){
        memset(ch,0,sizeof(ch));
        memset(num,0,sizeof(num));
        string str,ans = "";
        cin>>str;
        for(int i = 0; i < str.size(); ++i)
            ++ch[str[i]-'A'];
        num[0] = ch[25];
        num[2] = ch[22];
        num[4] = ch[20];
        num[6] = ch[23];
        num[8] = ch[6];
        num[1] = ch[14]-num[0]-num[2]-num[4];
        num[3] = ch[7]-num[8];
        num[5] = ch[5]-num[4];
        num[7] = ch[18]-num[6];
        num[9] = (ch[13]-num[1]-num[7])/2;
        for(int i = 0; i < 10; ++i){
            //cout<<num[i]<<endl;
            for(int j = 0; j < num[i]; ++j){
                ans += ('0'+i);
                //cout<<ans<<endl;
            }
        }
        printf("Case #%d: ",++t);
        cout<<ans<<endl;
    }
    return 0;
}
