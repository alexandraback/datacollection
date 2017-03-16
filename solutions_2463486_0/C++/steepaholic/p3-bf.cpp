#include <iostream>
using namespace std;

int main()
{
    enum { NUM_FS = 5 };
    int fs[NUM_FS] = { 1, 4, 9, 121, 484 };
    
    int T;
    cin >> T;
    for(int t = 0; t < T; ++t)
    {
        int A, B;
        cin >> A >> B;
        int *lb = lower_bound(fs, fs + NUM_FS, A);
        int *ub = upper_bound(fs, fs + NUM_FS, B);
        cout << "Case #" << (t+1) << ": " << (ub - lb) << endl;
    }
    return 0;
}