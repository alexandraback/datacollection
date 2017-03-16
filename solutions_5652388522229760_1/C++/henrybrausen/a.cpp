#include <iostream>
#include <set>

using namespace std;

long long myzeros;

void seeit(set<long long>& seen, long long N)
{
	while (N) {
        seen.insert(N%10);
        N/=10;
	}
}

int main()
{
	int T;
	cin >> T;
	set<long long> seen;
	for (int i = 0; i < T; ++i) {
        seen.clear();
        myzeros = 0;
		long long N;
		cin >> N;
		long long temp = N;
		seeit(seen,temp);
		cout << "Case #" << i+1 << ": ";
		if (N == 0ll) cout << "INSOMNIA";
		else {
            while (seen.size() < 10) {
                temp += N;
                seeit(seen,temp);
                //while (!(temp%10ll)) {
                //    temp/=10ll;
                //    myzeros++;
                //}
            }
            cout << temp;
            //for (int j = 0; j < myzeros; ++j)
            //    cout << '0';
		}
		cout << endl;
	}
	return 0;
}
