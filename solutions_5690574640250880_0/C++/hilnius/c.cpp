#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>

#define fo(a,b,c) for( a = ( b ); a < ( c ); ++ a )
#define fr(a,b) fo( a, 0, ( b ) )
#define fi(a) fr( i, ( a ) )
#define fj(a) fr( j, ( a ) )
#define fk(a) fr( k, ( a ) )

using namespace std;
int ni() { int a; scanf( "%d", &a ); return a; }
double nf() { double a; scanf( "%lf", &a ); return a; }
char sbuf[100005]; string ns() { scanf( "%s", sbuf ); return sbuf; }
long long nll() { long long a; scanf( "%lld", &a ); return a; }

void printOne(int r, int c, int cnt)
{
    int i,j;
    fi(r) {
        fj(c) {
            if (i==0&&j==0) cout << "c";
            else if (cnt > 0) {
                cout << ".";
                cnt--;
            }
            else cout << "*";
        }
        cout << endl;
    }
}
int main()
{
    int i, j, k;
    int nbTestCases = 0;
    //freopen ("Example.in","r",stdin);
    //freopen ("Example.out","w",stdout);
    //FILE *f;
    //f = fopen("Example.debug.out", "w");
    freopen ("C-small-attempt3.in","r",stdin);
    freopen ("C-small-attempt3.out","w",stdout);
    cin >> nbTestCases;

    fi(nbTestCases) {
        int r = ni(), c = ni(), m = ni();
        cout << "Case #" << i+1 << ":" << endl;
        int regularCells = r*c-m;
        if (min(r,c)==1)
            printOne(r,c,regularCells-1);
        else if (regularCells == 0 || regularCells == 2 || regularCells == 3 || regularCells == 5 || regularCells == 7 || (min(r,c)==2 && m%2==1 && r*c-m!=1) || m>r*c) {
            cout << "Impossible" << endl;
            continue;
        }
        else {
            bool moreRows = (max(r,c)==r);
            if (!moreRows) {
                int tmp = c;
                c = r;
                r = tmp;
            }

            vector<vector<char> > solution(r, vector<char>(c));
            fj(r)
                fk(c)
                    solution[j][k] = '*';

            int remainingCells = r*c - m;
            if (remainingCells == 9) {
                if (min(r,c) == 2) {
                    cout << "Impossible" << endl;
                    continue;
                }
            }
            if (remainingCells >= 9 && remainingCells % 2 == 1) {
                fj(3) {
                    fk(3) {
                        solution[j][k] = '.';
                    }
                }
                remainingCells -= 9;
            }
            int couplesToAdd = remainingCells/2;

            while(couplesToAdd > 0) {
                // add vertically
                int i = 0, j = 0;
                bool verticalCouple = false;
                bool break2 = false;
                while(solution[i][j] != '*')
                {
                    if (j+1 < c && solution[i][j+1] == '*')
                    {
                        if ( i+1 < r && solution[i+1][j] == '*')
                        {
                            solution[i][j+1] = '.';
                            solution[i+1][j] = '.';
                            couplesToAdd --;
                            break2 = true;
                            break;
                        } else if (i+1 >= r) {
                            i = 0;
                            j++;
                            continue;
                        }
                        j++;
                        bool verticalCouple = true;
                        break;
                    }
                    i++;
                    if (i >= r)
                    {
                        i = 0;
                        j += 2;
                    }
                }
                if (break2)
                    continue;
                if (verticalCouple || j+1 == c || (couplesToAdd == 1 && i == 0)) // must add couple vertically
                {
                    solution[i][j] = '.';
                    solution[i+1][j] = '.';
                }
                else {
                    solution[i][j] = '.';
                    solution[i][j+1] = '.';
                }
                couplesToAdd --;
            }

            solution[0][0] = 'c';

            if (moreRows) {
                fj(r) {
                    fk(c) {
                        cout << solution[j][k];
                    }
                    cout << endl;
                }
            } else {
                fj(c) {
                    fk(r) {
                        cout << solution[k][j];
                    }
                    cout << endl;
                }
            }

        }
    }
    return 0;
}

