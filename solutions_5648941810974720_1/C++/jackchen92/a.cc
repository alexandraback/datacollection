#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#include <cassert>

using namespace std;

const double EPSILON = 1e-10;

typedef double T;
typedef vector<T> VT;
typedef vector<VT> VVT;

int rref(VVT &a) {
  int n = a.size();
  int m = a[0].size();
  int r = 0;
  for (int c = 0; c < m && r < n; c++) {
    int j = r;
    for (int i = r + 1; i < n; i++)
      if (fabs(a[i][c]) > fabs(a[j][c])) j = i;
    if (fabs(a[j][c]) < EPSILON) continue;
    swap(a[j], a[r]);

    T s = 1.0 / a[r][c];
    for (int j = 0; j < m; j++) a[r][j] *= s;
    for (int i = 0; i < n; i++) if (i != r) {
      T t = a[i][c];
      for (int j = 0; j < m; j++) a[i][j] -= t * a[r][j];
    }
    r++;
  }
  return r;
}

void solve(const char* in)
{
    const char* digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
    const int n = 26, m = 11;
    double A[n][m];
    
    for(int r=0; r<n; r++)
        for(int c=0; c<m; c++)
            A[r][c] = 0;

    for(int i=0;i<10;i++)
        for(int j=0;j<strlen(digits[i]);j++)
        {
            int r = digits[i][j] - 'A';
            A[r][i]++;
        }
    for(int i=0;i<strlen(in);i++)
    {
        int r = in[i] - 'A';
        A[r][10]++;
    }

    VVT a(n);
    for (int i = 0; i < n; i++)
        a[i] = VT(A[i], A[i] + m);

    int rank = rref(a);
/*
    cout << "Rank: " << rank << endl;
    cout << "rref: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
*/
    for(int i=0;i<10;i++)
    {
        int c = round(a[i][10]);
        assert(abs(a[i][10] - c < 0.001));
        assert(c >= 0);
        for(int j=0;j<c;j++)
            printf("%c", '0'+i);
    }
}


int main()
{
    int TT;
    scanf("%d", &TT);
    for(int TI = 1; TI <= TT; TI++)
    {
        char in[3000];
        scanf(" %s", in);
        printf("Case #%d: ", TI);
        solve(in);
        printf("\n");
    }
}


