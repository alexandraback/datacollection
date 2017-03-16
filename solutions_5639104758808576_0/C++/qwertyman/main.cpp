#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(void)
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int count;
    fin >> count;
    for (int i = 0; i < count; i++) {
        int smax;
        string s;
        int ans = 0;
        int sum = 0;
        fin >> smax >> s;
        sum = s[0] - '0';
        for (int j = 1; j <= smax; j++) {
            if (sum < j) {
                ans += j - sum;
                sum = j;
            }
            sum += s[j] - '0';
        }
        fout << "Case #" << i + 1 << ": " << ans << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
