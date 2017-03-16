#include <iostream>
#include <vector>

using namespace std;

struct node{
    long long num;
    long long type;
};

long long dp[101][101];

long long work(int n, int m, vector<node> &v1, vector<node> &v2);

int main()
{
    int T;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        vector <node> v1;
        vector <node> v2;
        memset(dp, -1, sizeof(dp));
        cout<<"Case #"<<i + 1<<": ";
        int n, m;
        cin>>n>>m;
        for (int j = 0; j < n; j++)
        {
            node tmp;
            long long type, num;
            cin>>num>>type;
            tmp.type = type;
            tmp.num = num;
            v1.push_back(tmp);
        }
        for (int j = 0; j < m; j++)
        {
            node tmp;
            long long type, num;
            cin>>num>>type;
            tmp.type = type;
            tmp.num = num;
            v2.push_back(tmp);
        }
        cout<<work(n - 1, m - 1, v1, v2)<<endl;
    }
    return 0;
}

long long work(int n, int m, vector<node> &v1, vector<node> &v2)
{
    if (n < 0) return 0;
    if (m < 0) return 0;
    if (dp[n][m] != -1) return dp[n][m];
    long long& rh = dp[n][m];
    rh = 0;
    long long tmp = 0;
    if (v1[n].type == v2[m].type)
    {
        if (v1[n].num > v2[m].num)
            tmp = v2[m].num ;
        else tmp = v1[n].num;
        long long t1 = work(n - 1, m - 1, v1, v2);
        if (rh < t1 + tmp) rh = t1 + tmp;
        if (v1[n].num > v2[m].num)
        {
            long long temp_num = v1[n].num;
            v1[n].num -= v2[m].num;
            long long t2 = work(n, m - 1, v1, v2);
            if (rh <  tmp + t2) rh =  tmp + t2;
            v1[n].num = temp_num;
        }
        if (v1[n].num < v2[m].num)
        {
            long long temp_num = v2[m].num;
            v2[m].num -= v1[n].num;
            long long t2 = work(n - 1, m, v1, v2);
            if (rh < tmp + t2) rh =  tmp + t2;
            v2[m].num = temp_num;
        }
    }

    long long t2 = work(n - 1, m, v1, v2);
    if (rh < t2) rh = t2;
    t2 = work(n, m - 1, v1, v2);
    if (rh < t2) rh = t2;
    return rh;
}
