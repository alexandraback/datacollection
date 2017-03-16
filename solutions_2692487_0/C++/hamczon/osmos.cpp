#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<cmath>
using namespace std;

int min_operation(vector<int> &mote, int i, int k) {
    int count = 0;

    for(; i < mote.size(); ++i) {
        int cur = mote[i];
        if(k > cur) {
            k += cur;
        } else if(k + k - 1 > cur) {
            ++count;
            k = k + k - 1 + cur;
        } else {
            int a = mote.size() - i;
            if(k == 1) return a;
            int b = 1 + min_operation(mote, i, k+k-1);
            return min(a, b) + count;
        }
    }
    
    return count;
}

int main(int argc, char **argv) {
    ifstream input(argv[1], ios::in);
    ofstream output("output.txt", ios::out);

    int T;
    input>>T;
    
    for(int i = 1; i <= T; ++i) {
        int k, n;
        input>>k>>n;

        vector<int> mote(n);
        for(int j = 0; j < n; ++j)
            input>>mote[j];       
        sort(mote.begin(), mote.end());

        output<<"Case #"<<i<<": ";
        output<<min_operation(mote, 0, k)<<endl;
    }

    return 0;
}
