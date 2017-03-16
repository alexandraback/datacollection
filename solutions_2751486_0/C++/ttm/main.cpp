#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <cstdint>

using namespace std;

bool is_consonant(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return false;
    return true;
}

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        string word; cin >> word;
        int n; cin >> n;
        int c = 0;
        vector<int> acc;
        for (int i = 0; i < word.size(); ++i) {
            if (i + n <= word.size()) {
                bool works = true;
                for (int j = i; j < i + n; ++j) { works = works && is_consonant(word[j]); if (!works) break; }
                if (works) {
					acc.push_back(1);
                    continue;
				}
			}
			acc.push_back(0);
		}
        int prev = -1;
        for (int i = 0; i < acc.size(); ++i) {
            if (acc[i]) {
                int l = i - prev;
                int r = word.length() - i - n + 1;
                c += l * r;
                prev = i;
			}
		}
		cout << "Case #" << cas << ": " << c << "\n";
	}
}