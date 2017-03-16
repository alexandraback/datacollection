
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

int A, B, K;

int main()
{
    string filename = "B-small-attempt0";
    ifstream infile((filename+".in").c_str());
    ofstream outfile((filename+".out").c_str());

    int T;
    infile >> T;

    for(int t=0; t<T; t++)
    {
        infile >> A >> B >> K;

        int count=0;
        for(int a=0; a<A; a++)
        {
            for(int b=0; b<B; b++)
            {
                if( (a&b) < K)
                    count++;
            }
        }

        outfile << "Case #" << t+1 << ": " << count << endl;
    }

    return 0;
}
