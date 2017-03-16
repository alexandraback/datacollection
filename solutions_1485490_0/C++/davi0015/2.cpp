/*
ID: dhxav
PROG: 1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <queue>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)

int main() {
    ifstream fin ("C-small-attempt0.in");
    ofstream fout ("C-small-attempt0.out");

    int T;
    fin >> T;

    forn (i,T)
    {
        int N, M;
        fin >> N >> M;

        vector <long long int> a(N);
        vector <int> A(N);
        vector <long long int> b(M);
        vector <int> B(M);
        forn (i,N) fin >> a[i] >> A[i];
        forn (i,M) fin >> b[i] >> B[i];

        long long int best = 0;
        long long int temp1 = 0;
        long long int rest1 = a[0];
        long long int buf1, buf2;
        forab (i,-1,M-1)
        {
            long long int rest2=0;
            if (N>1) rest2 = a[1];
            long long int temp2 = 0;
            buf1  = b[i];
            if (A[0]==B[i] && i>=0)
            {
                if (b[i]<=rest1)
                {
                    temp1+=b[i];
                    rest1-=b[i];
                    buf1 = b[i];
                    b[i] = 0;
                }
                else{
                    temp1+=rest1;
                    buf1 = b[i];
                    b[i] = b[i]-rest1;
                    rest1 = 0;
                }
            }

            if (N>1)
            {
                forab (j,i,M-1)
                {
                    long long int rest3;
                    if (N>2) rest3 = a[2];
                    long long int temp3 = 0;
                    buf2 = b[j];
                    if (A[1]==B[j])
                    {
                        if (b[j]<=rest2)
                        {
                            temp2+=b[j];
                            buf2 = b[j];
                            rest2-=b[j];
                            b[j] = 0;
                        }
                        else{
                            temp2+=rest2;
                            buf2 = b[j];
                            b[j] = b[j]-rest2;
                            rest2 = 0;
                        }
                    }

                    if (N>2)
                    {
                        forab (k,j,M-1)
                        {
                            if (A[2]==B[k])
                            {
                                if (b[k]<=rest3)
                                {
                                    temp3+=b[k];
                                    rest3-=b[k];
                                }
                                else{
                                    temp3+=rest3;
                                    rest3 = 0;
                                }
                            }
                        }
                        if (best<temp1+temp2+temp3) best = temp1 + temp2 + temp3;
                    }
                    b[j] = buf2;

                }
                if (best<temp1+temp2) best = temp1+temp2;
            }
            b[i] = buf1;

        }
        //cout << "test" << endl;
        if (best<temp1) best = temp1;
        fout << "Case #" << i+1 << ": " << best << endl;
    }

    system("PAUSE");
}


