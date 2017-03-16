#include <iostream>
#include <fstream>
#include <cassert>
#include <cctype>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;



int main()
{
    fstream in,out;
    in.open("large.in",fstream::in);
    out.open("large.out",fstream::out|fstream::app);
    int num;
    in >> num;
    for(int i = 0;i != num; ++i)
    {
        int t = 0;
        in >> t;
        vector<int> diners{};
        for(int j=0;j!=t;++j)
        {
            int temp=0;
            in >> temp;
            diners.push_back(temp);
        }
        int m = *max_element(begin(diners),end(diners));
        int rlt=m;
        for(int k = 2; k < m; ++k)
        {
            int sum = k;
            for(auto j=begin(diners);j!=end(diners);++j)
            {
                if((*j) % k == 0) sum += (*j) / k - 1;
                else sum += (*j) / k;
            }
            if(sum < rlt) rlt = sum;
        }

        out << "Case #" << i+1 << ": "<<rlt<<endl;

    }
    return 0;
}
