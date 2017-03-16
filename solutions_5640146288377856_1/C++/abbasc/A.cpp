#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    #ifndef DEBUG

    ifstream in("a_l.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("a_l.out");
    cout.rdbuf(out.rdbuf());

    #endif

    int T;
    cin>>T;
    for(int X = 1; X <= T; X++)
    {
        int R,C,W;
        cin>>R>>C>>W;
        int ans = (C/W)*R + W;
        if(C%W == 0)
            ans--;

        cout<<"Case #"<<X<<": ";
        cout<<ans<<endl;
    }

    return 0;
}
