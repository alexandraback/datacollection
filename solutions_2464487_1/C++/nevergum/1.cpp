#include<iostream>
#include<fstream>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

typedef int64_t Int64;



int main()
{
    ifstream infile("file.in");
    ofstream outfile("file.out");

    int TestCase;
    infile>>TestCase;

    Int64 r;
    Int64 t;
    for (int testcase = 0; testcase < TestCase; testcase++) {
        infile>>r>>t;
        Int64 low = 1;
        Int64 h1 = t / (2 * r -1) + 1;
        Int64 h2 = (Int64)(sqrt(t/2+1));
        Int64 h = std::min(h1,h2);

        while(low+1<h) {
            Int64 mid = (low+h)/2;
            if (mid * (2*(mid+r)-1) > t){
                h = mid;
            }
            else
                low = mid;
        }

        Int64 area = low * (2 * (low +r) -1);
        Int64 N = low;
        while (area <= t) {
            area += (2*r + 1) + 4 * N;
            N++;
        }

        outfile<<"Case #"<<testcase+1<<": "<<N-1<<endl;
    }
}






