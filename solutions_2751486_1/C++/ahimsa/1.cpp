#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<vector>
#include<queue>
#include<sstream>
using namespace std;

bool is_vowel(char a){
    if(a == 'a' || a =='e' || a=='i' || a == 'o' || a== 'u')
        return true;
    else
        return false;
}

int main(){
    long long test;
    cin>>test;
    for(long long te=0;te < test; te++){
        long long ans = 0;
        string test;
        int grp;
        cin>>test>>grp;
        long long cons_count = 0;
        long long lastindex = 0;
        for(int i=0; i < test.size();i++){
            if(!is_vowel(test[i])){
                cons_count += 1;
                if(cons_count >= grp){
                    ans += (i - grp + 2 - lastindex) * (test.size() - i);
                    lastindex = i - grp + 2;
                }
            }
            else{
                cons_count = 0;
            }

        }


        cout<<"Case #"<<te + 1<<": "<<ans<<endl;
    }

}
