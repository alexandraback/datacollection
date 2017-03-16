#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef vector <string> vs;
typedef vector <int> vi;
#define REP(a,b) for(int a=0;a<(b);++a)
#define FOR(a,c,b) for(int a=c;a<(b);++a) 


int main() 
{
	ifstream fin("C-small-attempt0.in");
	//ifstream fin("C-large.in");
	//ifstream fin("c.in");
	ofstream fout("c.out");

	int tc, res, a, b;

	fin >> tc;

	REP(tcase,tc) {
		fin >> a >> b;

		res = 0;

		FOR (n,a,b+1) {
			int num = n, tmp = n/10, mul = 1, cnt = 0;
			int nums[16], nNums = 0;

			while (tmp) {
				tmp /= 10;
				mul *= 10;
				++cnt;
			}

			REP(i,cnt) {
				int newnum = (num%10)*mul + num/10;
				nums[nNums++] = newnum;
				num = newnum;
			}
			sort(nums, nums+nNums);

			REP(i,nNums) {
				if (nums[i] > b) break;
				if (nums[i] > n && (i == 0 || (nums[i-1] != nums[i]))) {
					//cout << n << " " << nums[i] << endl;
					++res;
				}
			}
		}


		fout << "Case #" << tcase+1 << ": " << res << endl;
	}

	fout.close();

	return 0;
}