#include <bits/stdc++.h>

using namespace std;

struct SNum
{
    char ch;
    int cnt;
    SNum(char ch_, int _cnt):ch(ch_), cnt(_cnt)
    {
    }
};

int main(int argc,char *argv[])
{
    vector<SNum> num[10];
    num[0].push_back(SNum('Z',1));
    num[0].push_back(SNum('E',1));
    num[0].push_back(SNum('R',1));
    num[0].push_back(SNum('O',1));
    num[1].push_back(SNum('O',1));
    num[1].push_back(SNum('N',1));
    num[1].push_back(SNum('E',1));
    num[2].push_back(SNum('T',1));
    num[2].push_back(SNum('W',1));
    num[2].push_back(SNum('O',1));
    num[3].push_back(SNum('T',1));
    num[3].push_back(SNum('H',1));
    num[3].push_back(SNum('R',1));
    num[3].push_back(SNum('E',2));
    num[4].push_back(SNum('F',1));
    num[4].push_back(SNum('O',1));
    num[4].push_back(SNum('U',1));
    num[4].push_back(SNum('R',1));
    num[5].push_back(SNum('F',1));
    num[5].push_back(SNum('I',1));
    num[5].push_back(SNum('V',1));
    num[5].push_back(SNum('E',1));
    num[6].push_back(SNum('S',1));
    num[6].push_back(SNum('I',1));
    num[6].push_back(SNum('X',1));
    num[7].push_back(SNum('S',1));
    num[7].push_back(SNum('E',2));
    num[7].push_back(SNum('V',1));
    num[7].push_back(SNum('N',1));
    num[8].push_back(SNum('E',1));
    num[8].push_back(SNum('I',1));
    num[8].push_back(SNum('G',1));
    num[8].push_back(SNum('H',1));
    num[8].push_back(SNum('T',1));
    num[9].push_back(SNum('N',2));
    num[9].push_back(SNum('I',1));
    num[9].push_back(SNum('E',1));

//"ZERO", "TWO","SIX", "EIGHT",  "SEVEN", "FIVE" "THREE",,"NINE" "FOUR"
//"ONE",  , , ,, ,
    int T;
    cin >> T;
    char buf[65536];
    cin.getline(buf,65536);
    for (int t=0;t<T;t++)
    {
        cin.getline(buf,65536);

        string s = buf;
        vector<int> ans;
        int freq[256] = {0};
        for (int i=0;i<s.length();i++)
        {
            freq[s[i]]++;
        }
        // zero
        while (freq['Z']>0)
        {
            ans.push_back(0);
            for (int k=0;k<num[0].size();k++)
                freq[num[0][k].ch] -= num[0][k].cnt;
        }
        // six
        while (freq['X']>0)
        {
            ans.push_back(6);
            for (int k=0;k<num[6].size();k++)
                freq[num[6][k].ch] -= num[6][k].cnt;
        }
        // two
        while (freq['W']>0)
        {
            ans.push_back(2);
            for (int k=0;k<num[2].size();k++)
                freq[num[2][k].ch] -= num[2][k].cnt;
        }
        // eight
        while (freq['G']>0)
        {
            ans.push_back(8);
            for (int k=0;k<num[8].size();k++)
                freq[num[8][k].ch] -= num[8][k].cnt;
        }
        // seven
        while (freq['S']>0)
        {
            ans.push_back(7);
            for (int k=0;k<num[7].size();k++)
                freq[num[7][k].ch] -= num[7][k].cnt;
        }
        // five
        while (freq['V']>0)
        {
            ans.push_back(5);
            for (int k=0;k<num[5].size();k++)
                freq[num[5][k].ch] -= num[5][k].cnt;
        }
        // three
        while (freq['T']>0)
        {
            ans.push_back(3);
            for (int k=0;k<num[3].size();k++)
                freq[num[3][k].ch] -= num[3][k].cnt;
        }
        // nine
        while (freq['I']>0)
        {
            ans.push_back(9);
            for (int k=0;k<num[9].size();k++)
                freq[num[9][k].ch] -= num[9][k].cnt;
        }

        // four
        while (freq['F']>0)
        {
            ans.push_back(4);
            for (int k=0;k<num[4].size();k++)
                freq[num[4][k].ch] -= num[4][k].cnt;
        }
        // one
        while (freq['O']>0)
        {
            ans.push_back(1);
            for (int k=0;k<num[1].size();k++)
                freq[num[1][k].ch] -= num[1][k].cnt;
        }
        sort(ans.begin(), ans.end());

        cout << "Case #" << t+1 << ": ";
        for (int i=0;i<ans.size();i++)
        {
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
