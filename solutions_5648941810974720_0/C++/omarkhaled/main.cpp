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

string s;
string WORDS [10] = {"ZERO", "ONE","TWO","THREE","FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
bool flag = true;


void rec(int index , vector < int > v, vector <int> res){


    if(index  > s.size()) return;
    if(index == s.size()){

        for(int i = 0; i < 10; i++){

            for(int j = 0; j < res[i]; j++){

                cout << i;
            }
        }

        cout << "\n";
        flag = true;
        return;
    }

    for(int i = 0; i <= 9 && !flag; i++){

        vector < int > tmp = v;
        bool found = true;

        for(int j = 0; j < WORDS[i].size() && !flag; j++){

            if(tmp[ WORDS[i][j] - 'A' ] == 0) { found = false; break;}
            tmp[ WORDS[i][j] - 'A' ]--;
        }

        if(found) { res[i]++; rec(index + WORDS[i].size(), tmp, res); res[i]--;}
    }
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);
    freopen ("A-small-attempt2 (1).in", "r", stdin);
    freopen ("ans.txt","w",stdout);

    int n , m  , k , d , t , tem1 , tem2 , tem3 , tem4 , y = 1, sum = 0 , ans = 0;
    string c;


    cin >>        t        ;

    while(t--){

        cin >> s;
        cs(y++);

        flag = false;
        vector < int > arr;

        for(int i = 0; i < 26; i++){

            arr.push_back(0);
        }

        for(int i = 0; i < s.size(); i++){

            arr[s[i] - 'A']++;
        }

        vector <int> res;

        for(int i = 0; i < 10; i++) res.push_back(0);

        rec(0, arr, res);


    }

    return 0;
}
