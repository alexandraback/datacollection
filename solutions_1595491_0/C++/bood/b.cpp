#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>

using namespace std;
int t,n,s,p;
int min_,min_s;
vector<int> v;
int ret;
void calc()
{
    min_ = p+2*max(p-1,0);
    min_s = p+2*max(p-2,0);
    ret = 0;
    ret += count_if(v.begin(), v.end(), [](int i) {return i>=min_;});
    ret += min(s, count_if(v.begin(), v.end(), [](int i) {return (i<min_ && i>=min_s);}));
}
void input()
{
    cin>>n>>s>>p;
    v.resize(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
}
void output(int ncase)
{
    cout<<"Case #"<<ncase<<":"<<" "<<ret<<endl;
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
