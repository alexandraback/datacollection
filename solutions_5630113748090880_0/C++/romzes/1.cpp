#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main () {
	ifstream fin ("input.txt");
	ofstream fout ("output.txt");

	int T;
  fin >> T;

   	for (int t = 0; t < T; t++) {
      int n;
      fin >> n;
      int a[3000], m = 2 * n -1;
      for (int i = 0; i < 3000; i++)
        a[i] = 0;
      
      for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) {
          int x;
          fin >> x;
          a[x]++;
        }
      fout << "Case #" << t + 1 << ":";
      for (int i = 0; i < 3000; i++)
        if (a[i] % 2 != 0) fout << " " << i;
      fout << endl;

   	}

  fin.close ();
  fout.close ();
  return 0;
}