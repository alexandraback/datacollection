#include <iostream>
#include <fstream>

#define SUBMIT 0
#ifdef SUBMIT
    #define cin fin
    #define cout fout
#endif // SUBMIT

using namespace std;

ifstream fin("A-large.in");
ofstream fout("A-large.out");

int T, N;
string S;
int standing, friends, all;

int main()
{
    cin >> T;

    for (int test=1; test<=T; test++) {
        cin >> N >> S;
        all = 0;
        standing = S[0]-'0';

        for (int i=1; i<=N; i++) {
            if (standing < i && S[i] != '0') {
                friends = i-standing;
            } else {
                friends = 0;
            }
            standing += (S[i]-'0')+friends;
            all += friends;
        }


        cout << "Case #" << test << ": " << all << endl;
    }


    return 0;
}
