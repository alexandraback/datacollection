#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <functional> 
using namespace std;


int main(int argc, char* argv[])
{
	ifstream in("in.txt");
	ofstream out("out.txt");
	int t;
	in >> t;
	for (int c=1; c<=t; c++) {
		out << "Case #" << c << ": ";
		int a, n;
		in >> a >> n;
		vector<int> other(n);
		for (int i = 0; i < n; i++)
			in >> other[i];
		sort(other.begin(), other.end());
		int low = 0; int high = n-1, added(0);
		vector<int> add(n, n);
		for(; low < n; low++) {
			if (a > other[low]) {
				a += other[low];
			}
			else {
				while (added < n && a <= other[low]) {
					added++;
					a += (a-1);
				}
				if (added == n) {break;}
				a += other[low];
			}
			add[low] = added;
		}
		int best(n);
		for (int i(0); i < n; ++i) {
			int here = add[i] + (n-1-i);
			if (here < best) {
				best = here;
			}
		}
		out << best << endl;





	}

}//main