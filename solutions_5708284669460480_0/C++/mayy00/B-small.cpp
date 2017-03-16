#include <iostream>
#include <string>
#define N 110
using namespace std;

int k,l,s;
string key, str;
long long total;
long long totalPos;
char S[N];

int containOff(string &s1, string &s2){
    int l1 = s1.length();
    int l2 = s2.length();
    for(int i=1;i<=l1-l2;++i){
        bool suc = true;
        for(int j=0;j<l2;++j)
            if(s1[i+j] != s2[j]){
                suc = false;
                break;
            }
        if(suc)
            return i;
    }
    return -1;
}

bool keySucceed(){
    for(int i=0;i<l;++i){
        bool suc = false;
        for(int j=0;j<k;++j)
            if(str[i] == key[j]){
                suc = true;
                break;
            }
        if(!suc)
            return false;
    }
    return true;
}

void calc(int n){
    if(n == s){
        totalPos++;

        for(int i=0;i<=s-l;++i){
            bool suc = true;
            for(int j=0;j<l;++j)
                if(S[i+j] != str[j]){
                    suc = false;
                    break;
                }
            if(suc){
                //cout << S << endl;
                total++;
            }
            
        }
        return;
    }
    
    for(int i=0;i<k;++i){
        S[n] = key[i];
        calc(n+1);
    }
}

int main(){
    int T;
    cin >> T;

    for(int i=1;i<=T;++i){
        double res=0;
        
        cin >> k >> l >> s;
        cin >> key >> str;

        if(keySucceed()){
            string doubstr = str+str;
//            int over = containOff(doubstr, str);
//            int posMax = (s - l)/over + 1;
            string x;
            for(int j=0;j<s;++j)
                x += str[j%l];
            long long posMax = 0;
            for(int a=0;a<=s-l;++a){
                bool suc = true;
                for(int b=0;b<l;++b)
                    if(x[a+b] != str[b]){
                        suc = false;
                        break;
                    }
                if(suc)
                    posMax++;
            }
            
                
            total = 0;
            totalPos = 0;
            S[s] = '\0';
            calc(0);
            res = posMax - (double)total/totalPos;
            //cout << posMax << " " << totalPos << " " << total << endl;
        }
        
        cout << "Case #" << i << ": " << res << endl;
    }
    return 0;
}