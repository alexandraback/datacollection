#define nPROFILE
#define nPROFILE_2
#define nGEN_LIST

#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
using namespace std;

#ifdef PROFILE
#include <windows.h>
unsigned long long t_check;
unsigned long long t_ntt;
#endif

// list of all fair and square integers up to 10^14
// generated with this program
#define MAX_FAS 39
unsigned long long list[MAX_FAS] = {1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004};


unsigned int num_to_tab(unsigned long long n, unsigned int tab[]) {
  unsigned int i = 0;

  unsigned long long div;
  do {
    div    = n / 10;
    tab[i] = (unsigned int)(n - 10*div);
    n      = div;
    i++;
  } while (n > 0);

  return i;
}

int check_palindrome(unsigned int t[], unsigned int len) {
#ifdef PROFILE_2
  LARGE_INTEGER t0, t1;
  ::QueryPerformanceCounter(&t0);
#endif
  int pal = 0;

  int i;
  unsigned int sym = (len - 1);
  unsigned int max = sym / 2  ;

  //for (i=0; i <= max; i++)
  for (i=max; i >= 0; i--)
    if (t[i] != t[sym-i])
      goto not_pal;

  /*
  // slower
  unsigned int *start, *end;
  start = t          ;
  end   = t + len - 1;
  while (start < end)
    if (*start++ != *end--)
      goto not_pal;
  */

  pal = 1;

not_pal:

#ifdef PROFILE_2
  ::QueryPerformanceCounter(&t1);
  t_check += (t1.QuadPart - t0.QuadPart);
#endif

  return pal;
}

int main() {
  int T, num=1;
  unsigned long long A, B;
  unsigned long long a, b;
  unsigned int digits[101];
  unsigned int len;
  unsigned long long n,s;
  unsigned long long found;

#ifdef PROFILE
  LARGE_INTEGER start, end, freq;
  ::QueryPerformanceFrequency(&freq);
  ::QueryPerformanceCounter(&start);
#endif
#ifdef PROFILE_2
  LARGE_INTEGER t0, t1;
#endif

  for (cin >> T; T--;) {
    cin >> A >> B;

#ifdef GEN_LIST
    A = 1;
    B = 100000000000000;

    a = (unsigned long long) sqrt((long double)A);
    if (a*a < A) a++;
    b = (unsigned long long) sqrt((long double)B);
    found = 0;

    cout << "unsigned long long list[MAX_FAS] = {" ;

    for (n = a; n <= b; n++) {

#ifdef PROFILE_2
      ::QueryPerformanceCounter(&t0);
#endif
      len = num_to_tab(n, digits);
#ifdef PROFILE_2
      ::QueryPerformanceCounter(&t1);
      t_ntt += (t1.QuadPart - t0.QuadPart);
#endif

      if (!check_palindrome(digits, len))
        continue;

      s = n * n;
      len = num_to_tab(s, digits);
      if (!check_palindrome(digits, len))
        continue;
      found++;
      cout << s << ", ";
    }

    cout << "};\n#define MAX_FAS " << found << endl;
    return 0;
#else

    found = 0;
    for (int k = 0; k < MAX_FAS; k++) {
      if (list[k] >= A && list[k] <= B)
        found++;
    }

#endif

    printf("Case #%d: %llu\n", num++, found);
  }

#ifdef PROFILE
  ::QueryPerformanceCounter(&end);
  cout << (end.QuadPart - start.QuadPart) / static_cast<float>(freq.QuadPart) << endl;
  cout << t_ntt / static_cast<float>(freq.QuadPart) << endl;
  cout << t_check / static_cast<float>(freq.QuadPart) << endl;
#endif

}
