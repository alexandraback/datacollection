#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int p[30];
int a[30], n, maxi;
bool use[30];

void gen (int k) {
  for (int i = 1; i <= n; i++)
    if (!use[i]) {
      use[i] = true;
      p[k + 1] = i;
      gen(k + 1);
      use[i] = false;
    }

  if (k == n) {
    int i;
    for (i = 1; i <= n; i++)
      if (p[i - 1 > 0 ? i - 1 : n] == a[p[i]] || p[i + 1 < n + 1 ? i + 1 : 0] == a[p[i]]) continue; else break; 
    if (i == n + 1) maxi = n; else {
    for (i = 1; i < n; i++)
      if (i == 1 && p[i + 1] == a[p[i]] || p[i - 1] == a[p[i]] || p[i + 1] == a[p[i]]) continue; else {
        int j = i;
        while (1)
          if (j == 1 || a[p[j]] == p[1] || a[p[j]] == p[j - 1] ) break;
        else j--;
        
        if (j > maxi && j != 1) maxi = j;
        break;
      }
    }
  }
}

int main () {
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	int T;
  fin >> T;

   	for (int t = 0; t < T; t++) {
      fin >> n;
      for (int i = 1; i <= n; i++)
        fin >> a[i];
      for (int i = 0; i < 30; i++)
        use[i] = false;
      maxi = 0;
      gen (0);
      fout << "Case #" << t + 1 << ": " << maxi << endl;

   	}

  fin.close ();
  fout.close ();
  return 0;
}