#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

int cntbuf[2000000+1];



long long int count(int A, int B)
{
  int n, m;
  char nbuf[8], mbuf[8];
  long long int cnt;
  int i, j, l;
  int dtab[10];
  int bad;
  

  for (i = 0; i <= 2000000; i++) {
    cntbuf[i] = 0;
  }
  cnt = 0;


  for (n = A; n <= B; n++) { 
    set <int> Sm;
    sprintf(nbuf, "%d", n);
    l = strlen(nbuf);
    mbuf[l] = 0;

    for (i = 1; i < l; i++) {
      for (j = 0; j < l; j++) {
	mbuf[j] = nbuf[(j + i) % l];

      }
      sscanf(mbuf, "%ld", &m);
      if ( n < m && m <= B) {
	Sm.insert(m);
      }
    }
    cnt += Sm.size();

  }


  //  for (n = A; n <= B; n++) {
  //    cout << n << ";" << cntbuf[n] << endl;
  //  }

  return cnt;


}



int main(void)
{

  int T, c;

  cin >> T;

  for (c = 1; c <= T; c++) {
    int A, B;
    long long int num;
    vector <int> t;

    cin >> A;
    cin >> B;

    num = count(A,B);
    cout << "Case #" << c << ": " << num << endl;

  }

  
  return 0;

}
