#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    #ifndef DEBUG

    ifstream in("c_s1.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("c_s1.out");
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
        vector<int> val(V+1);
        val[0] = 1;
        for(int i = 0; i < D; i++)
        {
            for(int j = V - arr[i]; j >= 0; j--)
                if(val[j] == 1)
                    val[arr[i] + j] = 1;
        }
        int cnt = 0,pos = 0,nw = 0;
        vector<int> p(V+1);
        for(int i = 0; i < D;i++)
            p[arr[i]] = 1;
        for(int i = 1; i <= V; i++)
        {
            //cout<<val[i]<<" ";
            if(val[i] == 0)
            {
                for(int j = V - i; j >= 0; j--)
                    if(val[j] == 1)
                        val[i + j] = 1;
                cnt++;

            }
        }

        cout<<"Case #"<<X<<": ";
        cout<<cnt<<endl;
    }

    return 0;
}
