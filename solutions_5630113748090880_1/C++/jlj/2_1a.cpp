#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main()
{
  int t, ca, n, i, j, x, counter;
  ifstream fin;
  ofstream fout;
  
  fin.open("input.txt");
  fout.open("output.txt");
  fin >> t;
  for (ca = 1; ca <= t; ++ca) {
    cout << "Case #" << ca << ": ";
    fout << "Case #" << ca << ": ";
    fin >> n;
    map<int, int> m;
    for (i = 0; i < 2 * n - 1; ++i) {
      for (j = 0; j < n; ++j) {
	fin >> x;
	//cout << x << " ";
	m[x]++;
      }
      //cout << endl;
    }
    for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it) {
      if (it->second % 2 != 0) {
	cout << it->first << " ";
	fout << it->first << " ";
      }
    }
    cout << endl;
    fout << endl;
  }
  fin.close();
  fout.close();
  return 0;
}
