#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long ll;
bool isVowel(char x){
    return x=='a'||x=='e'||x=='o'||x=='u'||x=='i';
}

int main(void){
    freopen("A-large.in","r",stdin);
    freopen("out3.txt","w",stdout);
    string str, str2;
    ll tc, casecounter = 1;
    ll n;
    scanf("%lld",&tc);
    while(tc--){
        cin>>str>>n;
        ll length = str.length();
        ll prevstart = -1, curstart = 0;
        ll streak = 0, total = 0, clusters = 0;
        for(ll i=0;i<length;i++){
            if(!isVowel(str.at(i))){
                streak++;
                //if(streak == 1)curstart = i;
                //printf("AT: %d streak: %d\n",i,streak);
                if(streak == n){
                    if(prevstart == -1){
                        total+= length - n + 1;
                        total+= (i-n+1)*(length-i-1);
                        prevstart = i-n+1;
                    }else{
                        total+=length - prevstart - n;
                        total+= (i-prevstart-n)*(length-i-1);
                        prevstart = i-n+1;
                    }
                }else if(streak > n){
                    streak = n;
                    total+=length - prevstart - n ;
                    total+= (i-prevstart-n)*(length-i-1);
                    prevstart++;
                }
            }else {streak = 0;}
        }
        printf("Case #%lld: %lld\n",casecounter++, total);
    }



    return 0;
}
