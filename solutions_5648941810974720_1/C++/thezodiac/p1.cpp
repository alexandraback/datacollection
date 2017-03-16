#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;


string s;
int tc;
bool solved = false;

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
vector <int> ans(10,0),cnt (300,0);

void update (int pos){
    fore(i,0,nums[pos].length())
        cnt[nums[pos][i]] -= ans[pos];
}

int main () {

    int t;
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    for(tc = 1;tc<=t;tc++){
        cin >> s;
        solved = false;
        cnt = vector <int> (300,0);
        ans = vector <int> (10,0);

        fore(i,0,s.length())
            cnt[s[i]] ++;


        ans[0] = cnt['Z'];
        update (0);

        ans[2] = cnt['W'];
        update(2);

        ans[6] = cnt['X'];
        update(6);

        ans[8] = cnt['G'];
        update(8);

        ans[4] = cnt['U'];
        update(4);

        ans[1] = cnt['O'];
        update(1);

        ans[3] = cnt['H'];
        update(3);

        ans[5] = cnt['F'];
        update(5);

        ans[7] = cnt['S'];
        update(7);

        ans[9] = cnt['I'];
        update(9);
        cout << "case #" << tc << ": ";

        fore(i,0,10)
            fore(j,0,ans[i])
                cout << i;

        cout << endl;
    }
}


/// flaw = orders are indeed not in order
