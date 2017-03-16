#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
int main() {
    int Case = 1;
    int t,i,j;
    int A,B,K;
    cin>>t;
    while(t--)
    {
        int num = 0;
        cin>>A>>B>>K;
        for(i = 0; i < A; i++)
        {
            for(j = 0; j < B; j++)
            {
                //cout<<i&j<<endl;
                if((i&j) < K)
                {
                    num++;
                }
            }
        }
        cout<<"Case #"<<Case++<<": "<<num<<endl;
    
    }
    
    return 0;
}
