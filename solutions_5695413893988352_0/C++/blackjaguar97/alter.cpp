#include <bits/stdc++.h>
#define P(x,y) make_pair(x,y)
using namespace std;
const int MX=(1<<20);
//int arr[MX] ;
string str1 , str2 , orig1 , orig2;
bool tt1[123] , tt2[123];
int s1 , s2 , n , ans=(1<<29);
void check(){
    int cur1=0 , cur2=0;
    for(int j=0;j<n;j++){
        cur1*=10; cur1+=str1[j]-'0';
        cur2*=10; cur2+=str2[j]-'0';
    }
    int dif = abs(cur1 - cur2);
    if(ans > dif){
        ans = dif;
        s1 = cur1;
        s2 = cur2;
    }
    else{
        if(ans == dif){
            if(s1 > cur1){
                s1 = cur1;
                s2 = cur2;
            }
            else{
                if(s1 == cur1){
                    if(s2 > cur2){
                        s2 = cur2;
                    }
                }
            }
        }
    }
}
void BF(int x){
    if(x==n){
        check();
        return;
    }
    int st1='0' , st2='0' , en1='9' , en2='9';
    if(!tt1[x]) st1=en1=orig1[x];
    if(!tt2[x]) st2=en2=orig2[x];
    for(char j = st1;j<=en1;j++){
        for(char i = st2;i<=en2;i++){
            str1[x] = j;
            str2[x] = i;
            BF(x+1);
        }
    }
}
int main(){
   // freopen("in.in","r",stdin);
    //freopen("out.out","w",stdout);
    int T , Tn=0;
    cin>>T;
    while(T--){
        ans=(1<<29);
        cin>>str1>>str2;
        orig1 = str1;
        orig2 = str2;
        memset(tt1 , 0 , sizeof(tt1));
        memset(tt2 , 0 , sizeof(tt2));
        n = str1.size();
        for(int j=0;j<n;j++){
            if(str1[j] == '?') tt1[j] = 1;
            if(str2[j] == '?') tt2[j] = 1;
        }
        BF(0);
        printf("Case #%d: ",++Tn);

        cout<<setfill('0')<<setw(n)<<s1<<' ';
        cout<<setfill('0')<<setw(n)<<s2<<endl;
        //cout<<s1<<' '<<s2<<endl;
    }
}

