#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>


using namespace std;

long long p3(int n)
{
    long long i, ret = 1;
    for(i = 0 ; i  < n ; i++)
        ret *= 3;
    return ret;
}

int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int tt= 0,T;
    cin >> T;
    while(T--)
    {
        cout << "Case #"<<++tt<<":" << endl;
        int n , i , j ;
        scanf("%d",&n);
        int a[25];
        for(i = 0 ; i < n ; i++)
            cin>>a[i];
        srand(time(0));

        int sum1 = 0 , sum2 = 0;
        int f = 1;
            int hash[25] ={0};
        while(f)
        {
            sum1=0,sum2=0;
            memset(hash,0,sizeof hash);
            for(i = 0 ; i < n ; i++)
            {
                int t =rand()%3;
                if(t==1)
                {
                    hash[i]=1;
                    sum1+= a[i];
                }
                if(t==2)
                {
                    hash[i]=2;
                    sum2+=a[i];
                }
                if(sum1==sum2 && sum1!=0 && sum2!=0)
                {
                    f = 0;
                     break;
                }
            }
        }
        for(i = 0 ; i < n ; i++)
            if(hash[i]==1)
                printf("%d ",a[i]);
        putchar(10);
        for(i = 0 ; i < n ; i++)
            if(hash[i]==2)
                printf("%d ",a[i]);
        putchar(10);
    }
    return 0;
}

