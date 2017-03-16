#include <fstream>
#include <string>

using namespace std;

const int SIGMA = 26, D = 10;
int cnt[SIGMA], ans[D];

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int t;
    in >> t;
    for(int tt = 0; tt < t; tt++) {
        for(int i = 0; i < SIGMA; i++)
            cnt[i] = 0;
        for(int i = 0; i < D; i++)
            ans[i] = 0;
        string s;
        in >> s;
        for(size_t i = 0; i < s.length(); i++)
            cnt[s[i] - 'A']++;
        while(cnt['Z' - 'A']) {
            cnt['Z' - 'A']--;
            cnt['E' - 'A']--;
            cnt['R' - 'A']--;
            cnt['O' - 'A']--;
            ans[0]++;
        }
        while(cnt['W' - 'A']) {
            cnt['T' - 'A']--;
            cnt['W' - 'A']--;
            cnt['O' - 'A']--;
            ans[2]++;
        }
        while(cnt['G' - 'A']) {
            cnt['E' - 'A']--;
            cnt['I' - 'A']--;
            cnt['G' - 'A']--;
            cnt['H' - 'A']--;
            cnt['T' - 'A']--;
            ans[8]++;
        }
        while(cnt['X' - 'A']) {
            cnt['S' - 'A']--;
            cnt['I' - 'A']--;
            cnt['X' - 'A']--;
            ans[6]++;
        }
        while(cnt['S' - 'A']) {
            cnt['S' - 'A']--;
            cnt['E' - 'A']--;
            cnt['V' - 'A']--;
            cnt['E' - 'A']--;
            cnt['N' - 'A']--;
            ans[7]++;
        }
        while(cnt['U' - 'A']) {
            cnt['F' - 'A']--;
            cnt['O' - 'A']--;
            cnt['U' - 'A']--;
            cnt['R' - 'A']--;
            ans[4]++;
        }
        while(cnt['O' - 'A']) {
            cnt['O' - 'A']--;
            cnt['N' - 'A']--;
            cnt['E' - 'A']--;
            ans[1]++;
        }
        while(cnt['T' - 'A']) {
            cnt['T' - 'A']--;
            cnt['H' - 'A']--;
            cnt['R' - 'A']--;
            cnt['E' - 'A']--;
            cnt['E' - 'A']--;
            ans[3]++;
        }
        while(cnt['F' - 'A']) {
            cnt['F' - 'A']--;
            cnt['I' - 'A']--;
            cnt['V' - 'A']--;
            cnt['E' - 'A']--;
            ans[5]++;
        }
        while(cnt['E' - 'A']) {
            cnt['N' - 'A']--;
            cnt['I' - 'A']--;
            cnt['N' - 'A']--;
            cnt['E' - 'A']--;
            ans[9]++;
        }
        out << "Case #" << tt + 1 << ": ";
        for(int i = 0; i < D; i++)
            for(int j = 0; j < ans[i]; j++)
                out << i;
        out << '\n';
    }
    return 0;
}
