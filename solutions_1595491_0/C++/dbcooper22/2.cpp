#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){
    freopen("input2.txt","r",stdin);
    freopen("output2.txt","w",stdout);
    bool yes[1000];
    int T, S, p, N, num[1000];
    cin >> T;
    for(int ts = 1; ts <= T; ts++)
    {
        memset(yes,0,sizeof(yes));
        cin >> N >> S >> p;
        for(int i = 0; i < N; i++) cin >> num[i];
        int ans = 0;
        //not surprising
        for(int i = 0; i < N; i++)
        {
            if(num[i] % 3 == 0 && (num[i] / 3) >= p)
            {
                ans++;
                yes[i] = 1;
            }
            if((num[i] % 3 == 1 || num[i] % 3 == 2) && num[i] / 3 + 1 >= p)
            {
                ans++;
                yes[i] = 1;
            }
        }
        //surprising
        for(int i = 0; i < N && S; i++)
        {
            if(yes[i]) continue;
            if(num[i] % 3 == 0 && (num[i] / 3) + 1 >= p && num[i] >= 3)
            {
                S--;
                ans++;
            }
            if(num[i] % 3 == 2 && (num[i] / 3) + 2 >= p)
            {
                S--;
                ans++;
            }
        }
        cout << "Case #" << ts << ": " << ans << endl;
    }
    return 0;
}
