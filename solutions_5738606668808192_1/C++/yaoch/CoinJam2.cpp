#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <cstdint>

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
    //ifstream fin("");
    ofstream fout("c-big.out");

    const int N = 32;
    int J = 500;

    //1,3,5,..
    //2,4,6,..
    vector<int> odds((N-2)/2,0);
    vector<int> evens((N-2)/2,0);
    for (int i=0; i<(N-2)/2; i++) {
        odds[i] = 2*(i+1)-1;
        evens[i] = 2*(i+1);
    }

    //cout << "Case #1:\n";
    fout << "Case #1:\n";

    int counter = 0;

    for (int i=0; i<(N-2)/2; i++) {
        for (int j=0; j<(N-2)/2; j++) {
            for (int k=i+1; k<(N-2)/2; k++) {
                for (int l=j+1; l<(N-2)/2; l++) {
                    vector<int> digits(N,0);
                    digits[0] = 1;
                    digits[N-1] = 1;

                    digits[odds[i]] = 1;
                    digits[evens[j]] = 1;
                    digits[odds[k]] = 1;
                    digits[evens[l]] = 1;

                    vector<int> factors;
/*
                    for (int b=2; b<=10; b++) {
                        long long num = 0;
                        for (int e=0; e<N; e++) {
                            num += ((long long)digits[e]) * power(b,e);
                        }
                        //cout << num << "\n";

                        if (num % (b+1) == 0) {
                            factors.push_back(b+1);
                        }
                    }

                    if (factors.size() != 9) continue;*/

                    for (int b=2; b<=10; b++) {
                        factors.push_back(b+1);
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
                }
                if (counter >= J) break;
            }
            if (counter >= J) break;
        }
        if (counter >= J) break;
    }

    //fin.close();
    //fout.close();

    return 0;
}
