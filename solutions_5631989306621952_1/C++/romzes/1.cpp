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
      string s, w = "";
      fin >> s;
      w += s[0];
      for (int i = 1; i < s.size(); i++)
        if (s[i] >= w[0]) w = s[i] + w;
          else w += s[i];
      fout << "Case #" << t + 1 << ": " << w << endl;
   	}

  fin.close ();
  fout.close ();
  return 0;
}