#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    #ifndef DEBUG

    ifstream in("c_l.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("c_l.out");
    cout.rdbuf(out.rdbuf());

    #endif

    int T;
    cin>>T;
    for(int X = 1; X <= T; X++)
    {
        int C,D,V;
        cin>>C>>D>>V;
        vector<int> arr(D);
        for(int i = 0; i < D; i++)
            cin>>arr[i];

        sort(arr.begin(),arr.end());
        int p = 0,cnt = 0;
        for(ll i = 1; i <= V;)
        {
            if(p < D && arr[p] <= i)
            {
                i += arr[p]*C;
                p++;
            }
            else
            {
                cnt++;
                i += i*C;
            }
        }

        cout<<"Case #"<<X<<": ";
        cout<<cnt<<endl;
    }

    return 0;
}
