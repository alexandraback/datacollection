#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <stdlib.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>
#include <utility>
#include <deque>
#include <stack>
#include <bitset>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#include <fstream>
#include <list>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

vector<int> A;
vector<int> B;

int main()
{
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );
    int t,kase = 1;
    cin>>t;
    while(t--)
{
    A.clear();
    B.clear();
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        double x;
        cin>>x;
        B.push_back(x*100000);

    }
    for(int i=0;i<n;++i)
    {
        double x;
        cin>>x;
        A.push_back(x*100000);
    }
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    cout<<"Case #"<<kase++<<": ";
    int l = 0,r = n-1,cnt1 = 0;
    for(int i=0;i<n;++i)
    {
        if(B[i] < A[l])
            --r;
        else
        {
            ++cnt1;
            ++l;

        }
    }

    cout<<cnt1<<" ";
    int r2 = 0 ,cnt2 = 0;
    for(int i=0;i<n;++i,++r2)
    {
        while(r2<n && A[r2]<B[i])
            ++r2;
        if(r2>=n)
            break;
        else
            ++cnt2;


    }
    cout<<n-cnt2<<endl;
}
}
