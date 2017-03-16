#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h> 
#include <boost/multiprecision/cpp_int.hpp>
#include <set>

using namespace::std;
using namespace boost::multiprecision;

ofstream fout("out.txt");
ifstream fin("in.txt");

int T, t;

set<string> seen;

int main() {
	fout << "Case #1:" << endl;
	//srand(time(NULL));
	
	const int N = 32;
	int J = 500;

	while (J > 0) {
		vector<int> arr(N, 0);
		arr[0] = 1;
		for (int i = 1; i <= N - 2; i++)
			arr[i] = rand() % 2;
		arr[N - 1] = 1;
		
		string s = "";
		for (int i = 0; i < N; i++)
			s += to_string(arr[i]);

		if (seen.count(s) != 0)
			continue;
		else
			seen.emplace(s);

		bool prime = false;
		vector<int> factor(11, -1);
		for (int b = 2; b <= 10; b++) {
			cpp_int n=0;
			cpp_int p = 1;
			for (int i = N-1; i >=0; i--) {
				if (arr[i])
					n += p;
				p *= b;
			}	
			//cout << n << endl;

			if (n % 2 == 0)
				factor[b] = 2;
			else if (n % 3 == 0)
				factor[b] = 3;
			else if (n % 5 == 0)
				factor[b] = 5;
			else if (n % 7 == 0)
				factor[b] = 7;
			else if (n % 11 == 0)
				factor[b] = 11;
			else if (n % 13 == 0)
				factor[b] = 13;
			else if (n % 17 == 0)
				factor[b] = 17;
			else if (n % 19 == 0)
				factor[b] = 19;
			else {
				prime = true;
				break;
			}
		}

		if (!prime) {			
			cout << s << " ";
			fout << s << " ";
			for (int b = 2; b <= 10; b++) {
				cout << factor[b] << " ";
				fout << factor[b] << " ";
			}
			cout << endl;
			fout << endl;			
			J--;
		}
		else {
			cout << s << endl;
		}		
	}	
}

