// g++ v4.8.3
// Flags: -O2

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

typedef vector<int> IntVec;

int main() {
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int smax;
	string s;
	cin >> smax >> s;
	int guestsTot = 0, membersTot = 0;
	forall (shyness, smax+1) {
	    const int membersNew = s[shyness] - '0';
	    const int guestsNew = max(0, shyness - membersTot);
	    guestsTot += guestsNew;
	    membersTot += guestsNew + membersNew;
	}
	cout << "Case #" << iTask << ": " << guestsTot << endl;
    }
}
