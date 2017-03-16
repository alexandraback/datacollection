#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("A-small-attempt0.in");
    ofstream output("A-small-output.out");
    int T;
    input>>T;
    for(int c=1;c<=T;c++)
    {
        int r,t;
        input>>r>>t;
        int N = 0;
        int sum = (N+1)*(2*N+1+2*r);
        while(sum<=t)
        {
            N ++;
            sum = (N+1)*(2*N+1+2*r);
        }
        output<<"Case #"<<c<<": "<<N<<endl;
    }
    return 0;
}
