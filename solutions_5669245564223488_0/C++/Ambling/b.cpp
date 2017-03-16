#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

typedef long long lint;
const int mod = 1000000007;

class chartype 
{
public:
    int loc;
    char ch;
    int type;

    chartype(int l, char c, int t)
    :loc(l), ch(c), type(t)
    {}

    bool operator< (const chartype & rhs) const
    {
        if (ch < rhs.ch)
        {
            return true;
        }
        else if(ch == rhs.ch && type < rhs.type)
        {
            return true;
        }
        else if(type == rhs.type && ch == rhs.ch && loc < rhs.loc)
        {
            return true;
        }
        return false;
    }

    void print()
    {
        cout << "vtype: " << ch << " " << type << " " << loc << endl;
    }
};

int main(int argc, char const *argv[])
{
    int T;
    cin>>T;

    for (int tt = 0; tt < T; ++tt)
    {
        int N;
        // std::vector<string> v(100);
        std::vector<chartype> vtype;
        
        cin >> N;
        // v.resize(N);
        int find = 0;
        for (int i = 0; i < N; ++i)
        {
            string str;
            cin >> str;
            for (int j = 0; j < str.size(); )
            {
                // cout << "i " << i << " j " << j << endl;

                if (find)
                {
                    break;
                }
                char c = str[j];
                
                int type = 0;
                if (j == 0)
                {
                    while (j < str.size() && str[j] == c) j++;
                    if (j == str.size())
                    {
                        type = 0; // all char c
                        chartype cht(i, c, type);
                        vtype.push_back(cht);
                        continue;
                    }
                    else {
                        for (int s = j+1; s < str.size(); ++s)
                        {
                            if (str[s] == c)
                            {
                                find = 1;
                                // cout << "find chong: " << c << " " << str << endl;
                                break;
                            }
                        }
                        if (!find)
                        {
                            // cout << "i " << i << " j " << j << endl;
                            type = 1; // start with char c
                            chartype cht(i, c, type);
                            vtype.push_back(cht);
                            continue;
                        }
                    }
                }
                else
                {
                    while (j < str.size() && str[j] == c) j++;
                    if (j == str.size())
                    {
                        type = 2; // end with char c
                        chartype cht(i, c, type);
                        vtype.push_back(cht);
                        continue;
                    }
                    else {
                        for (int s = j+1; s < str.size(); ++s)
                        {
                            if (str[s] == c)
                            {
                                find = 1;
                                // cout << "find chong: " << c << " " << str << endl;
                                break;
                            }
                        }
                        if (!find)
                        {
                            type = 3; // in mid with char c
                            chartype cht(i, c, type);
                            vtype.push_back(cht);
                            continue;
                        }
                    }
                }
            }
        }

        lint sum = 1;
        int cnt = 1;
        if (!find)
        {
            sort(vtype.begin(), vtype.end());

            // cout << vtype.size()<<endl;
            char c = vtype[0].ch;
            int val = 0;
            bool find0 = false;
            bool find1 = false;
            bool find2 = false;
            bool find3 = false;
            for (int i = 0; i < vtype.size(); ++i)
            {
            // vtype[i].print();
            // cout << "sum : " << sum << " cnt: " << cnt << endl;
                if (find)
                {
                    break;
                }
                if (vtype[i].ch != c)
                {
                    ++cnt;
                    for (int j = 1; j <= val; ++j)
                    {
                        sum *= j;
                        sum %= mod;
                    }

                    c = vtype[i].ch;
                    val = 0;
                    find0 = false;
                    find1 = false;
                    find2 = false;
                    find3 = false;
                }

                switch(vtype[i].type)
                {
                    case 0:
                    {
                        find0 = true;
                        val ++;
                        break;
                    }
                    case 1:
                    {
                        if (find1)
                        {
                            find = 1;
                        }
                        else
                        {
                            find1 = true;
                        }
                        break;
                    }
                    case 2:
                    {
                        if (find2)
                        {
                            find = 1;
                        }
                        else
                        {
                            find2 = true;
                            --cnt;
                        }
                        break;
                    }
                    case 3:
                    {
                        if (find0 || find1 || find2 || find3)
                        {
                            find = 1;
                        // cout << "find mid :" << c << " " << vtype[i].loc << endl;
                        }
                        else
                        {
                            find3 = true;
                            --cnt;
                        }
                        break;
                    }
                }


            }
            for (int j = 1; j <= val; ++j)
            {
                sum *= j;
                sum %= mod;
            }
            for (int j = 1; j <= cnt; ++j)
            {
                sum *= j;
                sum %= mod;
            }
        }
        

        // cout << "sum : " << sum << " cnt: " << cnt << endl;
        cout << "Case #" << tt+1 << ": ";// << N << endl;
        switch (find)
        {
            case 0:
                cout << sum << endl;
                break;
            case 1:
                cout << 0 << endl;
                break;
            default:
                cout << 0 << endl;
                break;
        }
    }
    return 0;
}