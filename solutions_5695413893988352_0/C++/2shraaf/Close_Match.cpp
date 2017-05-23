
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define fs first
#define sc second
typedef long long ll;
string ans1 ;
string ans2 ;
int v = 100000;
int toint(string s){
    int ans = 0;
    for(int i = 0 ;i<s.size(); i++){
        ans*=10;
        ans+=(s[i]-'0');
    }
    return ans;
}

void brf(string s1 , string s2 , int i , int val1 , int val2){
    if(i==s1.size()){
        if(abs(val1-val2)<v){
            v = abs(val1-val2);
            ans1  = s1 ;
            ans2 = s2;

        }else if(abs(val1-val2)==v){

            if(toint(s1)<toint(ans1)){
                ans1  = s1 ;
                ans2 = s2;

            }else if(toint(s1)==toint(ans1) && toint(s2)<toint(ans2)){
                ans1  = s1 ;
                ans2 = s2;

            }
        }
        return ;
    }
    if(s1[i]=='?'){
        for(int j = 0 ;j<10 ;j++){
            s1[i]= '0'+j;
            brf(s1,s2,i,val1,val2);

        }

    }else if(s2[i]=='?'){
        for(int j = 0 ;j<10 ;j++){
            s2[i]= '0'+j;
            brf(s1,s2,i,val1,val2);

        }

    }else{
        val1*=10;
        val2*=10;
        val1+=(s1[i]-'0');
        val2+=(s2[i]-'0');
        brf(s1,s2,i+1,val1,val2);

    }




}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);
        freopen ("file.out","w",stdout);
        freopen ("file.in","r",stdin);
        int t ;
        cin>>t;
        for(int p =1 ; p<=t ;p++){
            v = 100000;
            string s1 , s2 ;
            cin>>s1>>s2;
            brf(s1,s2,0,0,0);
            cout<<"Case #"<<p<<": ";
            cout<<ans1<<" "<<ans2;
            cout<<'\n';



        }
    return 0;

}


