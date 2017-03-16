#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

#define OO 101

ifstream fin("B-large.in");
ofstream fout("B-large.out");

int main() {
    int T,c;
    int ans = -1;
    fin>>T;

    for (c=1; c<=T; ++c) {
        int a[110][110];
        int n, m, i, j, k, min, target_i, target_j, ans;

        fin>>n>>m;
        for(i=0; i<n; ++i) {
            for (j=0; j<m; ++j) {
                fin>>a[i][j];
            }
        }
        
        while (ans != -1) {
            min = OO;
            for (i=0; i<n; ++i) {
                for (j=0; j<m; ++j) {
                    if (a[i][j] < min) {
                        min = a[i][j];
                        target_i = i;
                        target_j = j;
                    }
                }
            }

            if (min == OO) {
                ans = 1;
                break;
            }

            do {
                // scan rows
                k = 0;
                for (j=0; j<m; ++j) {
                    if (a[target_i][j] == OO) continue;
                    if (a[target_i][j] != min) {
                        k = 1;
                        break;
                    }
                }
                if (k==0) break;

                // scan columns
                for (i=0; i<n; ++i) {
                    if (a[i][target_j] == OO) continue;
                    if(a[i][target_j] != min) {
                        k = -1;
                        break;
                    }
                }
            } while (false);

            if (k == -1) {
                ans = 0;
                break;
            }

            // delete
            if (k == 0) {
                for (j=0; j<m; ++j) 
                    a[target_i][j] = OO;    
            }
            if (k == 1) {
                for (i=0; i<n; ++i) 
                    a[i][target_j] = OO;    
            }
        }

        // output
        fout<<"Case #"<<c<<": ";
        
        if (ans == 0) {
            fout<<"NO";
        } else {
            fout<<"YES";
        }

        fout<<endl;
    }
    return 0;
}
