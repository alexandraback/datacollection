#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

vector< vector<char> > field;

template<class AnswerType>
void PrintAnswerToTestCase(size_t caseNumber, AnswerType ans)
{
	cerr << "Case #" << caseNumber << endl;
    cout << "Case #" << caseNumber << ": ";
    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

class TQuaternion {
private:
    int A;
    int B;
    int C;
    int D;

public:
    TQuaternion(int a, int b, int c, int d) 
        : A(a)
        , B(b)
        , C(c)
        , D(d)
    {

    }

    TQuaternion& operator *= (const TQuaternion& rhs) {
       

        int at = A * rhs.A - B * rhs.B - C * rhs.C - D * rhs.D;
        int bt = A * rhs.B + B * rhs.A + C *rhs.D - D * rhs.C;   
        int ct = A * rhs.C - B * rhs.D + C *rhs.A + D * rhs.B;    
        int dt = A * rhs.D + B * rhs.C - C * rhs.B + D *rhs.A;

        A = at;
        B = bt;
        C = ct;
        D = dt;

        return *this;
    }

    bool operator == (const TQuaternion& rhs) {
        return (A == rhs.A) && (B == rhs.B) && (C == rhs.C) && (D == rhs.D);
    }

};

bool SolveTestCase() {
    int len;
    long long x;
    cin >> len >> x;
    string seq;
    cin >> seq;
    TQuaternion one(1, 0, 0, 0);
    TQuaternion cur = one;
    TQuaternion ii(0, 1, 0, 0);
    TQuaternion jj(0, 0, 1, 0);
    TQuaternion kk(0, 0, 0, 1);
    TQuaternion oneSeq(1, 0, 0, 0);

    bool foundI = false;
    bool foundJ = false;

    for (int i = 0; i < len * min(x, 8LL); i++) {
        switch (seq[i % len]) {
            case 'i':
                cur *= ii;
                break;
            case 'j':
                cur *= jj;
                break;
            case 'k':
                cur *= kk;
                break;
            default:
                break;
        }
        if (cur == ii && !foundI) {
            foundI = true;
        }
        if (foundI && !foundJ && cur == kk) {
            foundJ = true;
        }
        if (i == len - 1) {
            oneSeq = cur;
        }
    }
    TQuaternion all = one;
    for (int i = 0; i < (x % 4); i++) {
        all *= oneSeq;
    }
    return (all == TQuaternion(-1, 0, 0, 0) && foundI && foundJ);
}

int main()
{
	//freopen("input.txt", "r", stdin);
	freopen("small.in", "r", stdin);
	//freopen("large.in", "r", stdin);

	freopen("output.txt", "w", stdout);

	int numCases;
	cin >> numCases;

	for (int caseNumber = 1; caseNumber <= numCases; caseNumber++)
		PrintAnswerToTestCase(caseNumber, SolveTestCase() );

	return 0;
}