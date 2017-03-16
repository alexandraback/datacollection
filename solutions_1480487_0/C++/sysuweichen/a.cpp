#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    ofstream output;
    ifstream input ("A-small-attempt0.in");
    output.open("A-small-attempt0.out");

    int t;
    input >> t;

    for (int i=0; i<t; i++)
    {
        output<<"Case #"<<i+1<<": ";

        int n;
        input >> n;
        vector<int> s(n);
        int x = 0;
        int min1;
        int min2;
        double delta = 1.0/10000000;
        for(int j=0; j<n; j++)
        {
            input >> s[j];
            x += s[j];
        }
        double avg = double(2*x)/n;
        int newx = 0;
        int newn = 0;
        for(int j=0; j<n;j++)
        {
            if ( s[j] < avg)
            {
                newx+=s[j];
                newn++;
            }
        }
        double ret;
        for(int j=0; j<n; j++)
        {
            if(s[j]<avg)
            {

                    ret = double(x+newx)/newn - s[j];
                    ret /= x;
                    ret *=100;
            }
            else
                ret = 0;

            output <<setprecision(6)<<fixed<<ret;
             if(j!=n-1)
                output <<" ";
        }
        output << endl;
    }
}

