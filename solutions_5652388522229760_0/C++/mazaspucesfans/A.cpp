#include <bits/stdc++.h>
using namespace std;

int solve(int N)
{
    if(N==0) return -1;
    bool have[10]={false};

    for(int i=1; true; i++)
    {
        int curr=i*N;
        while(curr!=0)
        {
            have[curr%10]=true;
            curr/=10;
        }

        bool ok=true;
        for(int j=0; j<10; j++) if(!have[j]) ok=false;

        if(ok) return i*N;
    }
}

int main()
{
    freopen("A_small.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        int N;
        cin >> N;
        int result=solve(N);
        cout << "Case #" << t << ": ";
        if(result==-1) cout << "INSOMNIA";
        else cout << result;
        cout << '\n';
    }
    return 0;
}
