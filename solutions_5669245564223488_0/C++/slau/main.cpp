#include <iostream>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#define LL long long

using namespace std;

string words[100];
vector<string> newWords;

int numTrans(string s)
{
    char ch = s[0];
    int numTrans = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i]!=ch)
        {
            numTrans++;
            ch = s[i];
        }
    }
    return numTrans;
}

int run(int n)
{
    //if (n==1) return 1;
    LL ans = 0;
    int nT[100];

    for (int i = 0; i < n; i++)
    {
        nT[i] = numTrans(words[i]);

    }

    return ans%1000000007;
}

bool valid(string s)
{
    bool seen[27];
    fill(seen, seen+27, false);
    char prev = s[0];
    seen[prev-'a'] = true;
    //cout << s << endl;
    for (int i = 1; i < s.length(); i++)
    {
        //cout << prev << s[i] << endl;
        if (s[i]==prev)
        {

        }else
        {
            if (seen[s[i]-'a'])
            {
                //cout << "OPPS" << endl;
                return false;
            }


            seen[s[i]-'a'] = true;
            prev = s[i];
        }
    }
    return true;
}

int run2(int n)
{
    int nums[10];
    for (int i = 0; i < 10; i++)
    {
        nums[i] = i;
    }

    LL ans = 0;
    do
    {
        bool good = true;
        string Word = "";
        stringstream ss;
        for (int i = 0; i < n; i++)
        {
            int curNum = nums[i];
            ss << words[curNum];
        }
        //cout << ss.str() << endl;
        Word = ss.str();

        if (valid(Word))
        {
            ans++;
        }


        ans%=1000000007;
    }while(next_permutation(nums,nums+n));
    return ans%1000000007;
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    cin >> T;
    for (int Case = 1; Case <= T; Case++)
    {
        int n; cin >> n;

        for (int j = 0; j < n; j++)
        {
            cin >> words[j];
        }
        //sort(words, words+n);
        LL ans = run2(n);

        cout << "Case #" << Case << ": " << ans << endl;

    }
    return 0;
}
