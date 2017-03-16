#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

bool is_palin(long long n) {
    stringstream ss;
    ss<<n;
    string s = ss.str();

    int sz = s.size();
    for(int i=0; i<sz; i++) {
        if(s[i] != s[sz-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> palin;
    for(long long i=1; i<10000000; i++) {
        if(is_palin(i) && is_palin(i*i)) {
            palin.push_back(i*i);
        }
    }

    int T;
    cin>>T;
    for(int t=1; t<=T; t++) {
        long long a, b;
        cin>>a>>b;
        int cnt = 0;
        int sz = palin.size();
        for(int i=0; i<sz; i++) {
            if(palin[i] >= a && palin[i] <=b){
                cnt++;
            }
        }
        cout<<"Case #"<<t<<": "<<cnt<<endl;
    }
    return 0;
}
