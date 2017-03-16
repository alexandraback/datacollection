#include<iostream>
#include<vector>
using namespace std;

vector<long long> res;

bool checkP(long long a)
{
    long long b = a;
    long long tmp = 0;
    while(b != 0)
    {
        tmp = tmp*10 + b%10;
        b/=10;
    }
    return a == tmp;
}

int main()
{
    freopen("c:\\3.txt","r",stdin);
    freopen("c:\\3-out.txt","w",stdout);
    
    for(long long i = 1; i < 10000001; ++i)
    {
        if(checkP(i))
        {
            long long s = i*i;
            if(checkP(s))
            {
                res.push_back(s);
                //cout<<i<<" "<<s<<endl;
            }
        }
    }
    int T;
    cin>>T;
    int len = res.size();
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
        long long cnt = 0, a, b;
        cin>>a>>b;
        for(int i = 0; i < len; ++i)
        {
            if(res[i] >= a && res[i] <= b)
                cnt++;
        }
        cout<<"Case #"<<caseIndex<<": "<<cnt<<endl;
    }
    return 0;
}
