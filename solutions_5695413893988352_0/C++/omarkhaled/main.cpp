#include <bits/stdc++.h>

using namespace std;

#define mem0(arr) memset(arr , 0 , sizeof arr)
#define memf(arr) memset(arr , false , sizeof arr)
#define memdp(arr) memset(arr , -1 , sizeof arr)
#define rep(i , n) for(int i = 1; i <= n; i++)
#define loop(i , n) for(int i = 0; i < n; i++)
#define pb push_back
#define fi first
#define se second
#define cs(y) cout << "Case #" << y << ": "
#define cs2(y) cout << "Case " << y << ":" << "\n"

typedef long long ll;

string res1, res2;
pair < string , string  > f;
pair <long long , long long> las;
long long maxi = 2e18;

void rec (int index, string s){

    if(index == s.size()){

        int i = 0;

        res1 = "";
        res2 = "";

        for(i = 0; i < s.size() / 2; i++){

            res1 += s[i];
        }

        for(i; i < s.size(); i++){

            res2 += s[i];
        }

        long long sol1 = 0, sol2 = 0;

        for(int i = 0; i < res1.size(); i++){

            sol1 *= 10;
            sol1 += res1[i] - '0';

            sol2 *= 10;
            sol2 += res2[i] - '0';
        }

        if( (abs(sol1 - sol2) < maxi) || (abs(sol1 - sol2) == maxi && sol1 < las.first) ){

            las = {sol1, sol2};
            f = {res1, res2};
            maxi = abs(sol1 - sol2);
        }

        return;
    }

    if(s[index] == '?'){

        for(int i = 0; i <= 9; i++){

            s[index] = i + '0';
            rec(index + 1, s);
        }

    } else rec(index + 1, s);

}


int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    freopen ("B-small-attempt0 (3).in", "r", stdin);
    freopen ("ans.txt","w",stdout);

    int n , m  , k , d , t , tem1 , tem2 , tem3 , tem4 , y = 1, sum = 0 , ans = 0;
    string s , c;

    las = {2e18, 2e18};

    cin >>        t        ;

    while(t--){

        maxi = 2e18;
         las = {2e18, 2e18};
        cin >> s >> c;
        cs(y++);
        s = s + c;

        rec(0 , s);
        cout << f.first << " " << f.second << "\n";

    }

    return 0;
}
