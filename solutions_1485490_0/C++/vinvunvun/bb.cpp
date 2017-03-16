#include <ctime>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>
#include <iomanip>
#include<bitset>


using namespace std;

typedef long long int64;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define fornd(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forabd(i, a, b) for (int i = (int)(b); i >= (int)(a); i--)
#define sz(x) ((int) (x).size())
#define pb push_back

int main() {
    ifstream fin ("C-small-attempt0.in");
    ofstream fout("B.out");
    int T; fin >> T;
    forn (i,T)
    {
        int N, M; fin >> N >> M;

        vector <long long int> a(N);
        vector <int> A(N);
        vector <long long int> b(M);
        vector <int> B(M);
        forn (i,N) fin >> a[i] >> A[i];
        forn (i,M) fin >> b[i] >> B[i];

        int64 value_1 = 0;
        int64 data1 = a[0];
        int64 buffer, buf2;
        int64 result = 0;
        forab (i,-1,M-1){
            int64 data2=0;
            if (N>1) data2 = a[1];
            int64 value_2 = 0;
            buffer  = b[i];
            if (A[0]==B[i] && i>=0)
            {
                if (b[i]<=data1)
                {
                    value_1+=b[i];
                    data1-=b[i];
                    buffer = b[i];
                    b[i] = 0;
                }
                else{
                    value_1+=data1;
                    buffer = b[i];
                    b[i] = b[i]-data1;
                    data1 = 0;
                }
            }

            if (N>1)
            {
                forab (j,i,M-1)
                {
                    int64 data3;
                    if (N>2) data3 = a[2];
                    int64 value_3 = 0;
                    buf2 = b[j];
                    if (A[1]==B[j])
                    {
                        if (b[j]<=data2)
                        {
                            value_2+=b[j];
                            buf2 = b[j];
                            data2-=b[j];
                            b[j] = 0;
                        }
                        else{
                            value_2+=data2;
                            buf2 = b[j];
                            b[j] = b[j]-data2;
                            data2 = 0;
                        }
                    }

                    if (N>2)
                    {
                        forab (k,j,M-1)
                        {
                            if (A[2]==B[k])
                            {
                                if (b[k]<=data3)
                                {
                                    value_3+=b[k];
                                    data3-=b[k];
                                }
                                else{
                                    value_3+=data3;
                                    data3 = 0;
                                }
                            }
                        }
                        if (result<value_1+value_2+value_3) result = value_1 + value_2 + value_3;
                    }
                    b[j] = buf2;

                }
                if (result<value_1+value_2) result = value_1+value_2;
            }
            b[i] = buffer;}
        if (result<value_1) result = value_1;
        fout << "Case #" << i+1 << ": " << result << endl;
    }
}


