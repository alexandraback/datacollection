#include <iostream>

using namespace std;

int main()
{
  char A[8], B[8], M[14];
  int T, d, a, b, n, m, r[50]={0};
  int i, j;
  cin >> T;
  for (i=0;i<T;i++) {
    cin >> a >> b;
    itoa(a, A, 10);
    itoa(b, B, 10);
    d = strlen(A);
    for (n=a;n<=b;n++) {
      itoa(n, M, 10);
      j = 1;
      do {
        M[d+j-1] = M[j-1];
        M[d+j] = 0;
        m = atoi(M+j);
        if (m > n && m <= b) {
          r[i]++;
        }
        j++;
      } while (n != m);
    }
  }
  for (i=0;i<T;i++)
    cout << "Case #" << i+1 << ": " << r[i] << endl;
  return 0;
}
