#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;


long long L, X;
int *v;

int mult(int c1, int c2){
    int sign = (c1*c2>0)? 1:-1;
    c1 = (c1>0)?c1:-c1;
    c2 = (c2>0)?c2:-c2;
    if (c1==1 || c2==1) return sign*c2*c1;
    if (c1==c2) return sign*-1;
    if (c1==2 && c2==3) return sign*4;
    if (c1==3 && c2==4) return sign*2;
    if (c1==4 && c2==2) return sign*3;
    return -1*sign*mult(c2, c1);
}

int combine(int start, int end){
    int out = 1;
    while(start<end){
        out=mult(out, v[start]); start++;
    }
    return out;
}

bool solve(){
    if (combine(0, L*X)!=-1) return 0;
    long long first_i = 1;
    while(first_i<L*X && combine(0, first_i)!=2) first_i++;
    long long last_k = L*X-1;
    while(last_k>0 && combine(last_k, L*X)!=4) last_k--;
    //cout<<first_i<<":"<<last_k<<endl;
    return (first_i<last_k);
}

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        cin>>L; cin>>X;
        if (X/12) X=12+X%12;
        //printf("%lld\n", L*X);
        string str; cin>>str;
        string s = "";
        for(int i=0;i<X;i++) s+=str;
        int vec[L*X];
        for(int i=0;i<L*X;i++) vec[i] = s[i]-'g';
        v = &vec[0];
        //cout<<s<<endl;
        if (solve()) printf("Case #%d: YES\n", case_id);
        else printf("Case #%d: NO\n", case_id);
    }
}