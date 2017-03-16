#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

int log2(int x, int y)
{
    int t = (y-1)/(x-1);
    int ret = 1;
    for (int i=2; i<=t; i *= 2) {
	ret++;
    }
    return ret;
}

int main()
{
    int T,A,N,x;
    cin >> T;
    for (int c=1; c<=T; c++) {
	cin >> A >> N;
	vector<int> seq;
	for (int i=0; i<N; i++) {
	    cin >> x;
	    seq.push_back(x);
	}
	sort(seq.begin(), seq.end());
	long long cur = A;
	int sum = 0;
	for (int i=0; i<N; i++) {
	    if (cur < 2) {
		sum += N-i;
		break;
	    }
	    if (cur > seq[i]) cur += seq[i];
	    else {
		int tmp = log2(cur, seq[i]);
		if (tmp < N-i) {
		    long long p = pow(2, tmp);
		    cur = p*(cur-1)+1+seq[i];
		    sum += tmp;
		} else {
		    sum += N-i;
		    break;
		}
	    }
	}
	cout << "Case #" << c << ": " << sum << endl;
    }
    return 0;
}
