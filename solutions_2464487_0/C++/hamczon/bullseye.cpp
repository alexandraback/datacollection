#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

long long num_of_rings(long long r, long long t) {
    long long count = 0;
    
    while(t > 0) {
        long long need_area = 2 * r + 1;
        if(t >= need_area) {
            ++count;
            t -= need_area;
            r += 2;
        }
        else break;
    }

    return count;
}

int main(int argc, char **argv) {
    ifstream input(argv[1], ios::in);
    ofstream output("output.txt", ios::out);

    int T;
    input>>T;
    
    for(int i = 1; i <= T; ++i) {
        long long r, t;
        input>>r>>t;
        output<<"Case #"<<i<<": ";
        output<<num_of_rings(r, t)<<endl;
    }

    return 0;
}
