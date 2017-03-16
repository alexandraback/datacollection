#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>

bool cmp(const int cmp1,const int cmp2){
     return cmp1>cmp2;
}

int main()
{
	freopen("B-small-attempt5.in","rt",stdin);
	freopen("B-small.out","wt",stdout);
    int t;
    std::cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        std::cin>>n;
        int* a=new int[n];
        int* b=new int[n];
        for(int j=0;j<n;j++)
        {
            std::cin>>a[j]>>b[j];
        }
        int p=0;
        int c=0;
        int t=0;
        bool ff=false;
        while (true)
        {
            //2점짜리 검색
            bool f=false;
            for(int j=0;j<n;j++)
            {
                if (p>=b[j]&&a[j]!=10000000)
                {
                    b[j]=10000000;
                    p+=2;
                    a[j]=10000000;
                    c++;
                    f=true;
                    break;
                }
            }
            for(int j=0;j<n;j++)
            {
                if (p>=b[j]&&a[j]==10000000)
                {
                    b[j]=10000000;
                    if (a[j]==10000000)
                        p++;
                    else
                        p+=2;
                    a[j]=10000000;
                    c++;
                    f=true;
                    break;
                }
            }
            if (!f)
            {
            //1점짜리 검색
                for(int j=0;j<n;j++)
                {
                    if (p>=a[j])
                    {
                        a[j]=10000000;
                        f=true;
                        p++;
                        break;
                    }
                }
            }
            if (!f) break;
            t++;
            if (c==n) {
                ff=true;
                break;
            }
        }
        if (ff)
            std::cout<<"Case #"<<i+1<<": "<<t<<std::endl;
        else
            std::cout<<"Case #"<<i+1<<": Too Bad"<<std::endl;
        delete[] b;
        delete[] a;
    }
}