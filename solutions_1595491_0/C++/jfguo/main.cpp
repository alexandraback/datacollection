#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

string calc()
{
    int N, S, p;
    cin >> N >> S >> p;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        int ts;
        cin >> ts;
        if (ts >= p + 2*(p-1)) {
            ans++;
            continue;
        } 
        
        if (S > 0) {
            int t = p >= 2 ? p - 2 : 0;
            if (ts >= p + 2*t) {
                ans++;
                S--;
            }
        }
    }

    stringstream SS;
    SS << ans;
    return SS.str();
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
