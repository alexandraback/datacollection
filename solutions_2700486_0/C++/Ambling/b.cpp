#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int get(int sum, const std::vector<int> &motes, int index)
{
    if (index >= motes.size())
    {
        return 0;
    }
    if (sum > motes[index])
    {
        return get(sum + motes[index], motes, index+1);
    }

    int cnt = 0;
    while(sum <= motes[index]){
        // cout<<" "<<sum-1<<" ";
        sum = sum * 2 -1;
        cnt++;
    }
    cnt += get(sum + motes[index], motes, index+1);

    if (cnt > motes.size() - index)
    {
        return motes.size() - index;
    }
    return cnt;
}

vector<double> ppow;

int main()
{
    // freopen("b6.in", "r", stdin);
    // freopen("b6.out", "w", stdout);

    ppow.push_back(1);
    ppow.push_back(1);
    for (int i = 2; i < 10000; ++i)
    {
        ppow.push_back(1.0*i*ppow[i-1]);
    }

    int t2;
    cin >> t2;
    for (int t1 = 1; t1 <= t2; ++t1) {
        printf("Case #%d: ", t1);

        int N, x, y;
        cin>>N>>x>>y;

        int k = (1+sqrt(1+8*N))/4;
        
        if (abs(x) + abs(y) <= (k-1)*2)
        {
            cout<<1.0;
        } else if(abs(x) + abs(y) > k*2) 
        {
            cout<<0.0;
        } else {
            int re = N - 2*k*k+k;
            int n = y+1;
            if (n == k*2+1)
            {
                if (re == n*2-1)
                {
                    cout<<1.0;
                } else {
                    cout<<0.0;
                }
            } else {
                if (re < n)
                {
                    cout<<0.0;
                } else if(re >= 2*k+n){
                    cout<<1.0;
                } else {
                    // cout<<"k: "<<k<<" n: "<<n<<" re:"<<re<<endl;
                    double p = pow(0.5, re);
                    double pt = pow(0.5, 2*k);
                    double result = 1;
                    for (int i = 0; i < n; ++i)
                    {
                        if(re - i < 2*k)
                            result -= p*ppow[re] / (ppow[i]*ppow[re-i]);
                        else if(re - i == 2*k)
                            result -= pt*ppow[re] / (ppow[2*k]*ppow[re-2*k]);
                    }
                    cout<<result;
                } 
            }
                
        }
        

        printf("\n");
    }
    
    return 0;
}
