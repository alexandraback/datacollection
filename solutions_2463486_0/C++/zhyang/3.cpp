#include<iostream>
using namespace std;

bool dp[1005];

bool checkP(int a)
{
    int b = a;
    int tmp = 0;
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
    
    memset(dp, false, sizeof(dp));
    for(int i = 1; i < 1001; ++i)
    {
        if(checkP(i))
        {
            int s = i*i;
            if(s < 1001 && checkP(s))
                dp[s] = true;
        }
    }
    
    int T;
    cin>>T;
    for(int caseIndex = 1; caseIndex <= T; ++caseIndex)
    {
        int cnt = 0, a, b;
        cin>>a>>b;
        for(int i = a; i <= b; ++i)
            if(dp[i])
               cnt++;
        cout<<"Case #"<<caseIndex<<": "<<cnt<<endl;
    }
    return 0;
}
