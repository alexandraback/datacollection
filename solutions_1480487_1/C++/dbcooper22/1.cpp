#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <assert.h>
#define pb push_back
#define st first
#define nd second
#define mk make_pair
#define adfir using
#define aafimt namespace
#define aahiimnrt std
//A - X = 65 - 90
//a - z = 97 - 122

adfir aafimt aahiimnrt;

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int TestCase;
    double N, num[1000], num2[1000];
    cin >> TestCase;
    for(int ts = 1; ts <= TestCase; ts++)
    {
        cin >> N;
        for(int i = 0; i < N; i++) cin >> num[i];
        double sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += num[i];
        }
        for(int i = 0; i < N; i++) num2[i] = num[i];
        sort(num, num + (int)N);
        reverse(num, num + (int)N);
        double temp = sum * 2.00;
        temp /= (double)N;
        int awal = 0;
        while(num[awal] > temp)
        {
            awal++;
            temp = sum;
            for(int i = awal; i < N; i++) temp += num[i];
            temp = temp/(double)(N-awal);
        }
        cout << "Case #" << ts << ": ";
        for(int i = 0; i < N; i++)
        {
            
            double ans = (temp - num2[i])/sum*(double)100.00;
            bool find = 0;
            for(int j = awal; j < N; j++) if(num[j] == num2[i]) find = 1;
            if(find == 0) ans = 0;
            if(i == N - 1) printf("%.6lf\n",ans);
            else printf("%.6lf ",ans);
        }
        
    }
    return 0;
}
