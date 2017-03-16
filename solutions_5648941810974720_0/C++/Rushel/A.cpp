#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <map>

#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cmath>

using namespace std;

int countDigit[10];
int countS[300];
string arrayS[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void reduce(string s, int c) {
    for(int i = 0; i < s.size(); i++) {
        countS[s[i]]-=c;
    }
}

void findUnique(int digit, char c) {
    string s = arrayS[digit];
    if(countS[c]) {
        int d = countS[c];
        countDigit[digit]+=d;
        reduce(s, d);
        
    }

}


int main() {
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("A-small-output3.text", "w", stdout);
    int T;
    cin>>T;
    for(int tc = 1; tc <= T; tc++) {
        cout<<"Case #"<<tc<<": ";
        string S;
        
        cin>>S;
       // cout<<S<<endl;
        memset(countDigit, 0, sizeof(countDigit));
        memset(countS,0,sizeof(countS));
        for(int i = 0; i < S.size(); i++) {
            countS[S[i]]++;
        }
        
        findUnique(0, 'Z');
        findUnique(2, 'W');
        findUnique(6, 'X');
        findUnique(8, 'G');
        findUnique(4, 'U');
        findUnique(7, 'S');
        findUnique(5, 'V');
        findUnique(1, 'O');
        findUnique(3, 'T');
        findUnique(9, 'N');
        
        string res = "";
    
        for(int i = 0; i < 10; i++) {
            int ct = countDigit[i];
            if(i==9)
            ct/=2;
            for(int j = 0; j < ct; j++) {
                cout<<i;
                res+=arrayS[i];
            }
            
        }
        
//        sort(res.begin(), res.end());
//        sort(S.begin(), S.end());
//        if(S != res) {
//            cout<<"Bug "<<S<<endl;
//            return 0;
//        }
        
        
        
        
        cout<<endl;
    }
    return 0;
}