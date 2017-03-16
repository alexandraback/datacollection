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

int arr [26 + 1];
string WORDS [10] = {"ZERO", "ONE","TWO","THREE","FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector <int> v;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    freopen ("A-large (2).in", "r", stdin);
    freopen ("ans.txt","w",stdout);

    int n , m  , k , d , t , tem1 , tem2 , tem3 , tem4 , y = 1, sum = 0 , ans = 0;
    string s , c;


    cin >>        t        ;

    while(t--){

        v.clear();
        memset(arr , 0 , sizeof arr);

        cin >> s;
        cs(y++);

        for(int i = 0; i < s.size(); i++){

            arr[s[i] - 'A']++;
        }

        for(int i = 0; i < 9; i++){

            int mini = 1e9;

            for(int j = 0; j < WORDS[i].size(); j++){

                if( (i == 3 || i == 7) && WORDS[i][j] == 'E'){

                    mini = min(arr[ WORDS[i][j] - 'A' ] / 2, mini);

                }
                else mini = min(arr[ WORDS[i][j] - 'A' ], mini);
            }

            for(int j = 0; j < WORDS[i].size(); j++){

                arr[ WORDS[i][j] - 'A' ] -= mini;
            }

            for(int j = 0; j < mini; j++){

                v.push_back(i);
            }
        }

        for(int i = 0; i < v.size(); i++) cout << v[i];
        cout << "\n";

    }

    return 0;
}
