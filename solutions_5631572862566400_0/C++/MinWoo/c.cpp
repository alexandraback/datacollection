
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool good(vector<int> student, const vector<int>& bff) {
    sort(student.begin(), student.end());
    const int N = student.size();
    do {
        bool ok = true;
        for ( int i=0 ; i<N ; ++i ) {
            const int next = (i + 1 + N) % N;
            const int prev = (i - 1 + N) % N;
            if ( student[next] != bff[student[i]] && student[prev] != bff[student[i]] ) {
                ok = false;
                break;
            }
        }
        if ( ok ) return true;
    } while ( next_permutation(student.begin(), student.end()) );

    return false;
}

int solve(const vector<int>& bff) {
    const int N = bff.size();
    int res = 0;
    for ( int i=0 ; i<(1<<N) ; ++i ) {
        vector<int> student;
        for ( int j=0 ; j<N ; ++j ) {
            if ( i & (1<<j) ) {
                student.push_back(j);
            }
        }
        if ( good(student, bff) ) {
            res = max(res, (int)student.size());
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        int N;
        cin >> N;
        vector<int> bff(N);
        for ( int i=0 ; i<N ; ++i ) {
            cin >> bff[i];
            bff[i]--;
        }

        cout << "Case #" << tc << ": " << solve(bff) << endl;
    }
    return 0;
}