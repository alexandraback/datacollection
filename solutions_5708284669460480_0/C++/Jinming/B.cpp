#include<bits/stdc++.h>
using namespace std;

int tot = 0;
map<char, int> counter;

class KMP{
public:
    int period;
    vector<int> next;
    string pattern;
    KMP(string &pattern){
        this->pattern = pattern;
        int m = pattern.size();
        next = vector<int>(m);
        next[0] = 0;

        for(int i = 1, j = 0; i < m; i++){
            while(j && pattern[i] != pattern[j]) j = next[j - 1];
            if(pattern[i] == pattern[j]) j++;
            next[i] = j;
        }
        period = next[m - 1];
    }

    KMP(){}

    int find(string &text){
        int cnt = 0;
        int n = text.size();
        int m = pattern.size();
        for(int i = 0, j = 0; i < n; i++){
            while(j && text[i] != pattern[j]) j = next[j - 1];
            if(text[i] == pattern[j]) j++;
            if(j == m){
                cnt++;
                j = next[j - 1];
            }
        }
        return cnt;
    }
}kmp;

int L, S;
double lost;
string cur;
double maxBanana;

void backtrack(int i, double prob){
    if(i == S){
        maxBanana = max(maxBanana, 1.0 * kmp.find(cur));
        lost += kmp.find(cur) * prob;
        return;
    }

    for(auto &p: counter){
        cur.push_back(p.first);
        backtrack(i + 1, prob * 1.0 * p.second / tot);
        cur.pop_back();
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        counter.clear();
        tot = 0;
        lost = 0;
        maxBanana = 0;
        int K;
        cin >> K >> L >> S;
        string keyboard, target;
        cin >> keyboard >> target;

        tot = keyboard.size();
        for(char ch: keyboard){
            counter[ch]++;
        }

        bool notFound = false;
        for(char ch: target){
            if(counter.find(ch) == counter.end()){
                printf("Case #%d: %lf\n", t, 0.0);
                notFound = true;
                break;
            }
        }
        if(notFound) continue;

        kmp = KMP(target);

        backtrack(0, 1.0);
        printf("Case #%d: %lf\n", t, maxBanana - lost);
    }
    return 0;
}
