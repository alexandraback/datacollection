#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for ( int tc=1 ; tc<=T ; ++tc ) {
        string S;
        cin >> S;

        deque<char> dq = { S[0] };
        for ( int i=1 ; i<S.length() ; ++i ) {
            if ( S[i] >= dq.front() ) {
                dq.push_front(S[i]);
            }
            else {
                dq.push_back(S[i]);
            }
        }
        cout << "Case #" << tc << ": " << string(dq.begin(), dq.end()) << endl;
    }
    return 0;
}