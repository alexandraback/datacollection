#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <set>
#include <string>

using namespace std;


string str1, str2;
int len;

unsigned long long bestDiff, bestScore1, bestScore2;

string ans1, ans2;



inline unsigned long long convert(const string &s)
{
    unsigned long long ret = 0;

    for (int i = 0; i < s.size(); i++)
    {
        ret *= 10;
        ret += s[i]-'0';
    }

    return ret;
}


void updateAns(string &s1, string &s2)
{
    unsigned long long ss1, ss2;
    ss1 = convert(s1);
    ss2 = convert(s2);

    unsigned long long diff;
    if (ss1 > ss2)
        diff = ss1-ss2;
    else
        diff = ss2-ss1;
    if (diff < bestDiff || (diff == bestDiff && ss1 < bestScore1))
    {
        bestDiff = diff;
        bestScore1 = ss1;
        bestScore2 = ss2;
        ans1 = s1;
        ans2 = s2;
    }
}



void recurs(int pos, string &prevS1, string &prevS2)
{
  //  cout << prevS1 << " vs " << prevS2 << endl;
    string s1 = prevS1, s2 = prevS2;
    while (true)
    {
        const int posPrev = pos;
        while (pos < len && s1[pos] == s2[pos] && s1[pos] != '?')
            pos++;
        while (pos < len-1)
        {
            if (s1[pos] == '?' && s2[pos] == '?' && s1[pos+1] == '?' && s2[pos+1] == '?')
            {
                s1[pos] = '0';
                s2[pos] = '0';
                pos++;
            }
            else
                break;
        }

        if (posPrev == pos)
            break;
    }

    if (pos == len)
    {
        updateAns(s1, s2);
        return;
    }

    if (s1[pos] == '?' && s2[pos] == '?')
    {
        s1[pos] = '0';
        s2[pos] = '0';
        recurs(pos+1, s1, s2);

        s2[pos] = '1';
        recurs(pos, s1, s2);

        s1[pos] = '1';
        s2[pos] = '0';
        recurs(pos, s1, s2);


    }

    else if (s1[pos] != '?' && s2[pos] != '?')
    {

        if (s1[pos] > s2[pos])
        {
            for (int i = pos+1; i < len; i++)
            {
                if (s1[i] == '?')
                    s1[i] = '0';
                if (s2[i] == '?')
                    s2[i] = '9';
            }

        }

        else
        {
            for (int i = pos+1; i < len; i++)
            {
                if (s1[i] == '?')
                    s1[i] = '9';
                if (s2[i] == '?')
                    s2[i] = '0';
            }

        }


        updateAns(s1, s2);
        return;
    }


    else if (s1[pos] == '?')
    {
        if (s2[pos] != '0')
        {
            s1[pos] = s2[pos]-1;
            recurs(pos, s1, s2);
        }
        if (s2[pos] != '9')
        {
            s1[pos] = s2[pos]+1;
            recurs(pos, s1, s2);
        }
        s1[pos] = s2[pos];
        recurs(pos+1, s1, s2);


    }



    else //(s2[pos] == '?')
    {
        if (s1[pos] != '0')
        {
            s2[pos] = s1[pos]-1;
            recurs(pos, s1, s2);
        }
        if (s1[pos] != '9')
        {
            s2[pos] = s1[pos]+1;
            recurs(pos, s1, s2);
        }
        s2[pos] = s1[pos];
        recurs(pos+1, s1, s2);

    }

}



int main()
{
    //cin.tie(0);
    //ios::sync_with_stdio(false);
    freopen("t.in", "r", stdin);
    freopen("t.out", "w", stdout);


    int nbT;
    cin >> nbT;




    for (int t = 1; t <= nbT; t++)
    {
        cin >> str1 >> str2;
        len = str1.size();

        //cout << str1 << " vs " << str2 << endl;


        bestDiff = 1000000000;
        bestDiff = bestDiff*bestDiff;
        bestDiff *= 10;
        //cout << bestDiff;

        recurs(0, str1, str2);

        cout << "Case #" << t << ": " << ans1 << ' ' << ans2 << '\n';
    }


    return 0;
}
