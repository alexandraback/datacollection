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

long long getsum(vector<int> & vec, int start, int last, long long inital)
{
    if(start == last)
    {
        return vec[start] * inital;
    }
//    cout << start<<" "<<last<<" "<<inital;
    long long sum = 0, sume=inital;
    long long totalen = inital +( last-start )*r;
    long long res = 0;
    if(totalen <= e)
       {
    //    cout<<" "<< vec[last]*totalen<<endl;
        return vec[last]*totalen;}

    vector<int>vv(vec.begin()+start, vec.begin()+last);
    sort(vv.begin(), vv.end());
    int i = 0;
    while(sume < e and i < last-start)
    {
        sume+=r;
        ++i;
    }
    res = e*vec[last] + vv[i-1]*(sume-e);
    while(i < last-start)
    {
        res += vec[i]*r;
        ++i;
    }
  //  cout <<" "<<res<<endl;
    return res;
}
int main()
{
    fstream fin;
    fin.open("test.in");
    int tests;fin>>tests;
    for(int test = 0; test < tests; ++test)
    {
//FW
        int cnt=0;
        fin>>e>>r>>n;
    //    cout << e<<" "<<r<<" "<<n<<endl;
        vector<int> vec;
        long maximum = -1;
        long index = -1;
        long long sum = 0;
        for(int i = 0; i < n; ++i)
        {
            fin >> temp;
      //      cout << temp<<" ";
            vec.push_back(temp);
            if(temp > maximum)
            {
                maximum = temp;
                index = i;
            }
            sum += temp;
        }
      //  cout <<"-"<<endl;
        long long res = 0, inital = e;
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i] == maximum)++cnt;
        }
        if(cnt == 1)
        {
            if(r < e)
                res = (sum-maximum)*r+maximum*e;
            else
                res = sum * e;
        }
        else{
        int start = 0, last = 0;
        for(int i = 0; i < vec.size(); ++i)
        {
            if(vec[i] == maximum)
            {
                res += getsum(vec, start, i, inital);
                start = i+1;
                inital = r;
            }
        }
        res+=getsum(vec, start, vec.size()-1, inital);
        }
            
    cout <<"Case #"<<test+1<<": "<<res;
    cout <<endl;
//FW
    }
    return 0;
}
