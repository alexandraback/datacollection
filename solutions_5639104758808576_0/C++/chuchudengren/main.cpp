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
    in.open("small.in",fstream::in);
    out.open("small.out",fstream::out|fstream::app);
    int num;
    in >> num;
    for(int i = 0;i != num; ++i)
    {
        int smax=0,sum=0,rlt=0;
        in >> smax;
        for(auto j=0;j<=smax;++j)
        {
            char c;
            in >> c;
            if(c!='0'&&sum<j) rlt=(j-sum>rlt)?(j-sum):rlt;
            sum+=c-'0';
            //out<<sum<<' ';
        }

        out << "Case #" << i+1 << ": "<<rlt<<endl;

    }
    return 0;
}
