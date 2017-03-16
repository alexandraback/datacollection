#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <numeric>
#include <cstring>

typedef long long i64d;

using namespace std;

#define NUM 1000000007

int check(string ss)
{
    int a[26] = {0};
    int last = -1;
    for (int i = 0; i < ss.length(); i ++)
    {
        int k = ss[i]-'a';
        if (a[k] == 0)
        {
            if (last >= 0) a[last] = 2;
            a[k] = 1; last = k;
        }
        else if (k == last && a[k] == 1)
        {

        }
        else return 0;
    }
    return 1;
}

string zip(char *s)
{
    string res = "";
    int L = strlen(s);

    res += s[0];
    for (int i = 1; i < L; i ++)
    {
        if (s[i] != s[i-1]) res += s[i];
    }
    return res;
}

i64d pa(int n)
{
    i64d res = 1;
    for (int i = 2; i <= n; i ++)
    {
        res = (res * (i64d)i) % (i64d)NUM;
    }
    return res;
}

int main()
{
	freopen("B-large.in" , "r" , stdin);
	freopen("B-large.out" , "w" , stdout);
	int cas;
	scanf("%d" , &cas);
	for (int ca = 1; ca <= cas; ca ++)
	{
		printf("Case #%d: " , ca);
        int n;
        char s[110][105];
        scanf("%d" , &n);
        for (int i = 0; i < n; i ++)
        {
            scanf("%s" , s[i]);
        }
        i64d res = 0;
        vector<i64d> single;
        int ok = 1;
        for (int i = 0; i < n; i ++)
        {
            if (check((string)s[i]) == 0) {ok = 0; break;}
        }
        if (ok == 1)
        {
            string str[110];
            int used[110] = {0};
            for (int i = 0; i < n; i ++) str[i] = zip(s[i]);
            vector<string> ds;
            for (int i = 0; i < n; i ++)
            {
                int multi = 0;
                int a[26] = {0};
                for (int j = 0; j < str[i].length(); j ++)
                    a[str[i][j]-'a'] = 1;
                for (int j = 0; j < n; j ++)
                    if (used[i] == 0 && j != i)
                    {
                        for (int k = 0; k < str[j].length(); k ++)
                            if (a[str[j][k]-'a'] == 1)
                            {
                                multi = 1; break;
                            }
                        if (multi == 1) break;
                    }
                if (multi == 0)
                {
                    used[i] = 1;
                    ds.push_back(str[i]);
                }
            }

            // del one num string
            vector<string> str2;
            for (int i = 0; i < n; i ++)
                if (used[i] == 0)
                {
                    if (str[i].length() > 1)
                    {
                        str2.push_back(str[i]);
                        used[i] = 1;
                    }
                }

            while (1)
            {
                int a = -1;
                int num = 0;
                for (int i = 0; i < n; i ++)
                    if (used[i] == 0)
                    {
                        a = i;
                        num = 1; used[i] = 1;
                        break;
                    }
                if (a == -1) break;
                for (int i = 0; i < n; i ++)
                    if (used[i] == 0 && str[i][0] == str[a][0])
                    {
                        used[i] = 1; num ++;
                    }
                single.push_back(pa(num));
                str2.push_back(str[a]);
            }

            memset(used , 0 , sizeof(used));
            while (str2.size() > 0)
            {
                string s1 = str2[0];
                str2.erase(str2.begin());
                // first
                int has = 0;
                int num = 0;
                int x = -1;
                for (int i = 0; i < str2.size(); i ++)
                    if (str2[i].length() == 1 && str2[i][0] == s1[0])
                    {
                        x = i; break;
                    }
                if (x != -1) str2.erase(str2.begin() + x);
                x = -1;
                for (int i = 0; i < str2.size(); i ++)
                {
                    int L = str2[i].length();
                    if (L > 1 && str2[i][L-1] == s1[0])
                    {
                        x = i; num ++;
                    }
                }
                if (num > 1) {ok = 0; break;}
                else if (num == 1)
                {
                    s1 = str2[x] + s1;
                    str2.erase(str2.begin() + x);
                }
                else {has ++;}

                //last
                num = 0;
                x = -1;
                int s1L = s1.length();
                for (int i = 0; i < str2.size(); i ++)
                    if (str2[i].length() == 1 && str2[i][0] == s1[s1L-1])
                    {
                        x = i; break;
                    }
                if (x != -1) str2.erase(str2.begin() + x);
                x = -1;
                for (int i = 0; i < str2.size(); i ++)
                {
                    int L = str2[i].length();
                    if (L > 1 && str2[i][0] == s1[s1L-1])
                    {
                        x = i; num ++;
                    }
                }
                if (num > 1) {ok = 0; break;}
                else if (num == 1)
                {
                    s1 = s1 + str2[x];
                    str2.erase(str2.begin() + x);
                }
                else {has ++;}
                if (has == 2)
                {
                    if (check(s1) == 0) {ok = 0; break;}
                    ds.push_back(s1);
                }
                else str2.push_back(s1);
            }

            if (ok == 1)
            {
                string s1 = "";
                for (int i = 0; i < ds.size(); i ++) s1 += ds[i];
                if (check(s1) == 1)
                {
                    res = pa(ds.size());
                    for (int i = 0; i < single.size(); i ++)
                    {
                        res = (res * single[i]) % NUM;
                    }
                }
            }
        }

        printf("%I64d\n" , res);

    }
    return 0;
}