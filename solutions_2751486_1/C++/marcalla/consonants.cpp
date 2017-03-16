#include <cstdio>
#include <cstring>

bool isConsonant (char x) {
  return (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u');
}

int main () {

  char str [1001100];
  int nCases;
  scanf ("%d", &nCases);
  for (int nc = 1; nc <= nCases; ++nc) {
    int L;
    scanf ("%s%d", str, &L);
    int k = strlen (str);
    int c = 0; // How many consecutive consonants
    int ant = 0;
    unsigned long long int n = 0;
    for (int i = 0; i < k; ++i) {
      bool isC = isConsonant(str[i]);
      if (!isC)
	c = 0;
      else {
	++c; 
	if (c == L) {
	  //printf ("n = %lld + (%d * %d - %d * %d = %d)\n", n, i-c+2, k-i, ant, k-i, (i-c+2)*(k-ant-i)-(ant-i)*(k-i));
	  n = n + (unsigned long long int)(i-c+2) * (k-i) - (ant) * (k-i);
	  --c; // To prepare the next iteration
	  ant = i-c+1;
	}
      }
    }
    printf ("Case #%d: %lld\n", nc, n);
  }

  return 0;
}
