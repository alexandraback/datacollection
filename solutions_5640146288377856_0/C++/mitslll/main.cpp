#include<cstdio>
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<memory.h>
#include<algorithm>
#include<queue>
#define ll long long
#define vi vector<int>
using namespace std;

struct BIT{
    vi v;
    BIT(int n) : v(vi(n+1)){}
    
    int read(int idx)
    {
        int sum = 0;
        while(idx > 0)
        {
            sum += v[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(int idx, int val)
    {
        while(idx <v.size())
        {
            v[idx] += val;
            idx += (idx & - idx);
        }
    }
    int r_sum(int l,int r){
        return read(r) - read(l-1);
    }
};


void test_case()
{
    int r, c, w;
    cin >> r >> c>> w;
    int cost_find = r*(c/w);
    int cost_kill = cost_find + (w-1);
    if(c%w > 0 )
    {
        cost_kill ++;
    }
    
    cout << cost_kill << endl;
}
int main(){
    int iCase;
    cin >> iCase;
    for(int i=0; i<iCase; i++)
    {
        printf("Case #%d: ",i+1);
        test_case();
    }
    return 0;
}