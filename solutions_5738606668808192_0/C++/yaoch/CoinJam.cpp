#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

long long power(int b, int e) {
    long long ans = 1;
    while (e > 0) {
        ans *= b;
        e--;
    }
    return ans;
}

int main()
{
    ifstream fin("");
    ofstream fout("c-small.out");

    const int N = 16;
    int J = 50;

    vector<int> digits(N,0);
    digits[0] = 1;
    digits[N-1] = 1;

    int counter = 0;

    //cout << "Case #1:\n";
    fout << "Case #1:\n";

    for (int idx=1; idx<N-1; idx+=2) {
        digits[idx] = 1;
        digits[idx+1] = 1;

        do {
            vector<int> factors;
            for (int b=2; b<=10; b++) {
                long long num = 0;
                for (int i=0; i<N; i++) {
                    num += ((long long)digits[i]) * power(b,i);
                }
                //fout << num << "\n";
                long long limit;
                if (2000000 < num) limit = 2000000;
                else limit = num;
                for (long long i=2; i<limit; i++) {
                    if (num % i == 0) {
                        factors.push_back(i);
                        break;
                    }
                }
            }

            if (factors.size() != 9) continue;

            //for (int i=N-1; i>=0; i--) cout << digits[i];
            //for (int i=0; i<9; i++) cout << " " << factors[i];
            for (int i=N-1; i>=0; i--) fout << digits[i];
            for (int i=0; i<9; i++) fout << " " << factors[i];

            //cout << "\n";
            fout << "\n";
            counter++;

            if (counter >= J) break;

        } while (next_permutation(digits.begin()+1, digits.end()-1));

        if (counter >= J) break;
    }

    //fin.close();
    //fout.close();

    return 0;
}
