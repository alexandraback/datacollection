#include <bits/stdc++.h>
#define fore(i,j,k) for(int i = j;i<k;i++)
#define forr(i,j,k) for(int i = j;i>k;i--)
#define LL long long

using namespace std;


string s;
int tc;
bool solved = false;

string nums[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void rec(int *cnt, int rem,vector <int> v){

    if(solved)
        return;

    if(!rem){
        cout << "case #" << tc+1 << ": ";
        sort(v.begin(),v.end());
        fore(i,0,v.size())
            cout << v[i];
        cout << endl;
        solved = true;
        return;
    }

    fore(i,0,10){
        if(solved)
            return;

        bool flag = true;
        fore(j,0,nums[i].length()){
            cnt[nums[i][j]]--;
            if(cnt[nums[i][j]] < 0)
                flag = false;
        }

        if(flag){
            v.push_back(i);
            rec(cnt,rem-nums[i].length(),v);
            v.pop_back();
        }

        fore(j,0,nums[i].length())
            cnt[nums[i][j]]++;


    }


}

int main () {

    int t;
    ios_base::sync_with_stdio(false);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> t;

    for(tc = 0;tc<t;tc++){
        cin >> s;
        solved = false;
        int cnt[266] = {0};

        fore(i,0,s.length())
            cnt[s[i]] ++;

        vector <int> v;

        rec(cnt,s.length(),v);

    }
}


/// flaw = orders are indeed not in order
