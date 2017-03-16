#include<cstdio>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<set>
using namespace std;

int T, N, CaseNo = 1, KN;
set<char> digits;

int count(){
    KN += N;
    string s = to_string(KN);
    for(int i = 0; i < s.size(); ++i){
        digits.insert(s[i]);
    }
    if(digits.size() == 10) return KN;
    else return count();
}

int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N); KN = 0; digits.clear();
        if(N == 0) printf("Case #%d: INSOMNIA\n", CaseNo++);
        else printf("Case #%d: %d\n", CaseNo++, count());
    }
}
