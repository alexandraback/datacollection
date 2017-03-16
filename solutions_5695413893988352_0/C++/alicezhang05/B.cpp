#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> m = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN"};
bool valid(string a, int left, int middle, int right) {
    bool x = a[0] == '?' || a[0] == (left + '0');
    bool y = a[1] == '?' || a[1] == (middle + '0');
    bool z = a[2] == '?' || a[2] == (right + '0');
    return x && y && z;
}

string solve(string a, string b) {
    size_t size = a.size();
    while (a.size() < 3) a.insert(a.begin(), '0');
    while (b.size() < 3) b.insert(b.begin(), '0');

   int min_diff = 999;
   int fir = 0;
   int sec = 0;

   for (int i = 0; i < 1000; ++i) {
        int left = (i / 100) % 10;
        int middle = (i / 10) % 10;
        int right = i % 10;

        if (!valid(a, left, middle, right)) {
            continue;
        }


        for (int j = 0; j < 1000; ++j) {
            int x = (j / 100) % 10;
            int y = (j / 10) % 10;
            int z = j % 10;
            if (valid(b, x, y, z) && abs(i-j) < min_diff) {
                min_diff = abs(i-j);
                fir = i;
                sec = j;
            }
        }
   }
   string fir_ans =  to_string(fir);
   string sec_ans = to_string(sec);
   while (fir_ans.size() < size) fir_ans.insert(fir_ans.begin(), '0');
   while (sec_ans.size() < size) sec_ans.insert(sec_ans.begin(), '0');
   return fir_ans + " " + sec_ans;
}

int main() {
    int T;
    string a, b;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> a >> b;
        cout << "Case #" << i << ": " << solve(a, b) << endl;
    }
    return 0;
}
