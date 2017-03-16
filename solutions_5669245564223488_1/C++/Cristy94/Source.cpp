#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <conio.h>

#define MOD 1000000007
#define Nmax 256

using namespace std;

int T, N, un[256], K, nr[256];
long long perm[Nmax];
string a[Nmax];

void minimize(string &x){

    int L = x.length();
    for (int i = 0; i + 1 < L; ++i){
        if (x[i] == x[i + 1]){
            x.erase(x.begin() + i);
            --L;
            --i;
        }
    }
}

void eraseElement(string a[], int p, int &N){

    for (int i = p; i < N; ++i)
        a[i] = a[i+1];

    a[N].clear();
    --N;
}

int main(){

	ifstream f("fis.in");
	ofstream g("fis.out");

	f >> T;

    perm[0]  = 1;
    for (int i = 1; i <= 100; ++i){
        perm[i] = i * perm[i-1];
        perm[i] %= MOD;
    }


    for(int t = 1; t <= T; ++t){
		
        f >> N;
        K = N;

        // Reinit
        for (int p = 'a'; p <= 'z'; ++p){
            un[p] = nr[p] = 0;
            
        }

        for (int i = 1; i <= K; ++i){
            f >> a[i];
            minimize(a[i]);

            for (int p = 0; p < a[i].length(); ++p)
                nr[a[i][p]]++;

            if (a[i].length() == 1){
                un[a[i][0]]++;
                --i;
                --K;
            }
        }
        
        
        long long sol = 0;

        if (N == 1){
            sol  = 1;
            for (int p = 'a'; p <= 'z'; ++p){
                if (nr[p] > 1){
                    sol = 0;
                    break;
                }
            }
        }
        else{
            
            // We have to unite all sets with distinct values
            sol = 1;
            bool ok =  true;
            while (ok){
                ok = false;

                // i-Last = j-First
                for (int i = 1; i <= K && !ok; ++i)
                    for (int j = i + 1; j <= K; ++j){
                        if(i == j) continue;
                        char c = a[i][a[i].length()-1];
                        if (a[j][0] == c){
                            ok = true;
                            a[i] = a[i] + a[j].substr(1);
                            sol *= perm[un[c]];
                            sol %= MOD;
                            un[c] = 0;
                            eraseElement(a, j, K);
                            break;
                        }            
                    }

                if (!ok){
                    // i-First = j-Last
                    for (int i = 1; i <= K && !ok; ++i)
                        for (int j = i + 1; j <= K; ++j){
                            if (i == j) continue;
                            char c = a[i][0];
                            if (a[j][a[j].length() - 1] == c){
                                ok = true;
                                a[i] = a[j] + a[i].substr(1);
                                sol *= perm[un[c]];
                                sol %= MOD;
                                un[c] = 0;
                                eraseElement(a, j, K);
                                break;
                            }
                        }
                }

            }

            // Add single characters
            for (int c = 'a'; c <= 'z' && sol; ++c){
                if (!un[c]) continue;
                for (int i = 1; i <= K && sol; ++i){

                    // Character found in middle
                    int len = a[i].length();
                    for (int p = 1; p < len - 1; ++p)
                        if (a[i][p] == c){
                            sol = 0;
                            break;
                        }

                    // Character to the left
                    if (a[i][0] == c || a[i][len - 1] == c){
                        sol *= perm[un[c]];
                        sol %= MOD;
                        un[c] = 0;
                    }
                }
            }

            // No solution check
            int viz[256]{};
            for (int i = 1; i <= K; ++i){
                for (int p = 0; p < a[i].length(); ++p){
                    if (viz[a[i][p]]){
                        K = 0;
                        sol = 0;
                        break;
                    }
                    else viz[a[i][p]] = 1;
                }
            }

            if (sol){
                // The rest of the strings can be permutted
                for (int c = 'a'; c <= 'z'; ++c){
                    if (un[c]){
                        K++;
                        sol *= perm[un[c]];
                        sol %= MOD;
                        un[c] = 0;
                    }
                }
                sol *= perm[K];
                sol %= MOD;
            }           

        }

        g << "Case #" << t << ": " << sol % MOD;
		g << '\n';
	}

	return 0;
}