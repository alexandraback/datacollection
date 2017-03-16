#include <cstdio>
#include <iostream>

#define mp make_pair
#define pb push_back

#define REP(i, n) for(int i = 0; i < (n); ++i)
#define REP2(i, s, n) for (int i = (s); i < (n); ++i)

using namespace std;
typedef long long ll;

void solve()
{
    string S;
    cin >> S;

    int count[256] = {0, };
    int number[20] = {0, };

    REP(i, S.length()) {
        count[S[i]]++;
    }

    // count 0

    while(count['Z']) {
        number[0]++;
        count['Z']--;
        count['E']--;
        count['R']--;
        count['O']--;
    }
    // count 2
    while(count['W']) {
        number[2]++;
        count['T']--;
        count['W']--;
        count['O']--;
    }

    // count 4
    while(count['U']) {
        number[4]++;
        count['F']--;
        count['O']--;
        count['U']--;
        count['R']--;
    }

    // count 3
    while(count['R']) {
        number[3]++;
        count['T']--;
        count['H']--;
        count['R']--;
        count['E']--;
        count['E']--;
    }

    // count 8
    while(count['G']) {
        number[8]++;
        count['E']--;
        count['I']--;
        count['G']--;
        count['H']--;
        count['T']--;
    }
    // count 1
    while(count['O']) {
        number[1]++;
        count['O']--;
        count['N']--;
        count['E']--;
    }
    // count 5
    while(count['F']) {
        number[5]++;
        count['F']--;
        count['I']--;
        count['V']--;
        count['E']--;
    }
    // count 6
    while(count['X']) {
        number[6]++;
        count['S']--;
        count['I']--;
        count['X']--;
    }
    // count 7
    while(count['V']) {
        number[7]++;
        count['S']--;
        count['E']--;
        count['V']--;
        count['E']--;
        count['N']--;
    }
    // count 9
    while(count['I']) {
        number[9]++;
        count['N']--;
        count['I']--;
        count['N']--;
        count['E']--;
    }

    REP(i, 10) {
        REP(j, number[i]) cout << i;
    }
    cout << endl;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}
