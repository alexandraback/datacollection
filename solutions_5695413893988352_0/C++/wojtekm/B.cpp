#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>

using namespace std;

struct score {
    int coders;
    int jammers;
};

int substitute(string s, int num) {
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '?') {
            s[i] = (num%10) + '0';
            num /= 10;
        }
    return atoi(s.c_str());
}

bool isBetter(score newScore, score oldScore) {
    if (abs(newScore.coders - newScore.jammers) != abs(oldScore.coders - oldScore.jammers))
        return abs(newScore.coders - newScore.jammers) < abs(oldScore.coders - oldScore.jammers);
    else if (newScore.coders != oldScore.coders)
        return newScore.coders < oldScore.coders;
    else
        return newScore.jammers < newScore.coders;
}

void printPadding(int a, int pad) {
    char buff[3000];
    sprintf(buff, "%d", a);
    string s(buff);
    for (int i = 0; i < pad - s.length(); i++)
        cout << "0";
    cout << s;
}

int main() {
    int t;
    cin >> t;
    
    for (int T = 1; T <= t; T++) {
        string s1, s2;
        cin >> s1 >> s2;
        score best; best.coders = substitute(s1, 0), best.jammers = substitute(s2, 0);
        
        for (int i = 0; i <= 999; i++)
            for (int j = 0; j <= 999; j++) {
                score newScore; newScore.coders = substitute(s1, i); newScore.jammers = substitute(s2, j);
                if (isBetter(newScore, best))
                    best = newScore;
            }
        
//        printf("Case #%d: %.3d %.3d\n", T, best.coders, best.jammers);
        cout << "Case #" << T << ": "; printPadding(best.coders, s1.length()); cout << " "; printPadding(best.jammers, s2.length()); cout << "\n";
    }
    
    return 0;
}
