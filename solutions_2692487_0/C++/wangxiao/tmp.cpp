#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <cmath>
using namespace std;
int e,r,n,temp;

int main()
{
    fstream fin;
    fin.open("test.in");
    int tests;fin>>tests;
    for(int test = 0; test < tests; ++test)
    {
//FW
        int a, n, res=10000000;fin >> a>>n;
        vector<int> vec;
        for(int i = 0; i < n; ++i)
        {
            int tmp;fin >> tmp;
            vec.push_back(tmp);
        }
        sort(vec.begin(), vec.end());
        int sum = a, index = 0;
        while(vec[index] < a && index < vec.size())
        {
            a += vec[index];
            ++index;
      //      cout << a<<endl;
        }
        int mini = 100000000;
        int oldindex = index, cnt=0;
        if(index == vec.size())
            res=0;
        else{
         //  for(int i = index; i < vec.size(); ++i)
          //  cout << vec[i]<<" "<<endl;
            mini = vec.size() - index ;
            int nop = 0;
            while(true){
                ++nop;
                a=a*2-1;
                while(vec[index] < a && index < vec.size())
                {
                    a+= vec[index];
                    ++index;
                }
            //     cout << mini<<" "<< index<<" "<<vec.size()<<endl;
                mini =( mini > (nop + vec.size() - index ) ) ? ( nop + vec.size() - index ) : mini;
                if(index == vec.size())
                    break;
                if(oldindex == index)
                {
                    ++cnt;
                    if(cnt >= vec.size())
                        break;
                }
               oldindex = index; 
            }
        }
        res = mini > res ? res : mini;
    cout <<"Case #"<<test+1<<": "<<res;
    cout <<endl;
//FW
    }
    return 0;
}
