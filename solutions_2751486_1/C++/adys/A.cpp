#include<iostream>
#include<vector>
#include<string>
using namespace std;

unsigned long long solve(string name, int N) {
    vector<int> smallest(name.length(),-1);
    int start = 0;
    int end1 = 0, end2 = 0;
    while (end1 < name.length()) {
        if (!(name[end1] == 'a' || name[end1] == 'e' || name[end1] == 'i' || name[end1] == 'o' || name[end1] == 'u')) {
            while (end2 < name.length()) {
                if (!(name[end2] == 'a' || name[end2] == 'e' || name[end2] == 'i' || name[end2] == 'o' || name[end2] == 'u')) {
                    ++end2;
                } else
                    break;
            }
            int len = end2 - end1;
            if (len >= N) {
                for (int i = start; i < end1; ++i)
                    smallest[i] = end1 + N - 1;
                for (int i = end2-N; i >= end1; --i)
                    smallest[i] = i + N - 1;
                start = end2 - N + 1;
                end1 = end2;
            } else {
                end1 = end2;
            }
        } else {
            ++end1;
            end2 = end1;
        }
    }
    unsigned long long total = 0;
    for (int i = 0; i < name.length(); ++i)
        if (smallest[i] != -1)
            total += name.length()-smallest[i];
    return total;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string name;
        int N;
        cin >> name;
        cin >> N;
        unsigned long long ans = solve(name,N);
        cout << "Case #" << t << ": " << ans << endl;
    }
}
