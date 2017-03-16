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
    const int m_table[5][5]={{},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
    for(int i = 0;i != num; ++i)
    {
        int l=0,x=0;
        in >> l >> x;
        vector<int> numbers{};
        for(auto j=0;j!=l;++j)
        {
            char c;
            in >> c;
            numbers.push_back(c-'g');
        }
        x=(x>12)?(12+x%4):x;
        int target = 2, mul=1;
        for(auto j=0;j!=x;++j)
        {
            for(auto k=begin(numbers);k!=end(numbers);++k)
            {
                if(mul>0) mul=m_table[mul][*k];
                else mul=-m_table[-mul][*k];
                if(mul==target)
                {
                    mul=1;
                    target++;
                }
            }
        }

        out << "Case #" << i+1 << ": ";
        if(target==5&&mul==1) out<<"Yes"<<endl;
        else out<<"No"<<endl;

    }
    return 0;
}
