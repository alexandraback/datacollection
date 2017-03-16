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

int main() {
    int T; cin>>T;
    for(int case_id = 1;case_id<=T;case_id++){
        int max_S; cin>>max_S;
        string S; cin>>S;
        int total = 0;
        int score = 0;
        for(int j=0;j<S.length();j++){
            total+=S[j]-'0';
            total--;
            if (total<0) {total++; score++;}
        }
        printf("Case #%d: %d\n", case_id, score);
    }
}