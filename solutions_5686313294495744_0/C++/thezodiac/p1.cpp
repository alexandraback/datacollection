#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;


int main () {

    int t;
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    for(int tc = 1;tc<=t;tc++){
        set <string> s1,s2;
        cout << "case #" << tc << ": ";

        int n;
        cin >> n;

        fore(i,0,n){
            string ss1,ss2;
            cin >> ss1 >> ss2;
            s1.insert(ss1);
            s2.insert(ss2);

        }

            int ans = n - max (s1.size(),s2.size());
            cout << ans << endl;


    }
}


/// flaw = orders are indeed not in order
