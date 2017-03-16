#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

int cache[(1<<20) + 1];
string calc()
{
    int N;
    cin >> N;
    vector<int> nums(N);

    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    int i, j;
    cache[0] = 0;
    map<int, vector<int> > sum2set;
    for (i = 1; i < (1<<N)-1; ++i) {
        for (j = 0; j < N; ++j) if ((i>>j)&1) {
            cache[i] = cache[i&~(1<<j)] + nums[j];
            sum2set[cache[i]].push_back(i);
            break;
        }
    }

    stringstream S;
    for (map<int, vector<int> >::iterator it=sum2set.begin(); it!=sum2set.end(); ++it) {
        vector<int> &vi = (*it).second;
        if (vi.size() >= 2) {
            for (i = 0; i < 2; ++i) {
                //cout << "--- " << vi[i] << endl;
                S << endl;
                vector<int> vs;
                int a = vi[i];
                for (j = 0; j < N; ++j) if ((a>>j)&1) {
                    vs.push_back(nums[j]);
                }

                for (j=0; j<vs.size(); ++j) {
                    if (j !=0) {
                        S << ' ';
                    }
                    S << vs[j];
                }
            }

            return S.str();
        }
     }

     return "Impossible";
    //S << ans;
    //return S.str();
}

int main(void)
{
	int N;
	cin >> N;

    // NOTE: if using getline() to read the input, the following two lines should be
    // added to read the line sepeartor in the first line. 
    //string line;
    //getline(cin, line);
	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
