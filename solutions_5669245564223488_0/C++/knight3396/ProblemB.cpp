#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

long long unsigned modval = 1000000007;

struct StrShort
{
    char _s;
    char _e;
    StrShort(char s, char e) : _s(s), _e(e){};
};

unordered_map<char, unordered_set<char> > g_Start;
unordered_map<int, int> g_mapClosed;
unordered_set<int> g_setClosed;
int nNum = 0;
long long unsigned singlenum = 0;

int getMapKey(char s, char e)
{
    return (s - 'a') * 30 + (e - 'a');
}

void CheckStr(string &str)
{
    int mapkey = getMapKey(str[0], str[1]);
    if (g_mapClosed.find(mapkey) != g_mapClosed.end())
    {
        g_mapClosed[mapkey]++;
        return;
    }
    if(str[0] == str[1])
    {
        if (g_Start[str[0]].find(str[1]) != g_Start[str[0]].end())
        {
            g_Start[str[0]].erase(str[1]);
            g_mapClosed[mapkey] = 2;
            nNum--;
            return;
        }
    }
    g_Start[str[0]].insert(str[1]);
    nNum++;
    return;
}

bool DFS(char e, int depth)
{
    if (depth >= nNum)
    {
        singlenum++;
        return true;
    }
    if (e == ' ')
    {
        for (unordered_map<char, unordered_set<char> >::iterator it = g_Start.begin();
            it != g_Start.end(); it++)
        {
            unordered_set<char> &strset = it->second;
            for (unordered_set<char>::iterator itset = strset.begin();
                itset != strset.end(); itset++)
            {
                char ctmp = *itset;
                int mapkey = getMapKey(it->first, ctmp);
                g_setClosed.insert(mapkey);
                DFS(ctmp, depth+1);
                g_setClosed.erase(mapkey);
            }
        }
    }else
    {
        if (g_Start.find(e) == g_Start.end())
        {
            return false;
        }
        unordered_set<char> &strset = g_Start[e];
        for (unordered_set<char>::iterator itset = strset.begin();
            itset != strset.end(); itset++)
        {
            char ctmp = *itset;
            int mapkey = getMapKey(e, ctmp);
            if (g_setClosed.find(mapkey) != g_setClosed.end())
            {
                continue;
            }
            g_setClosed.insert(mapkey);
            DFS(ctmp, depth+1);
            g_setClosed.erase(mapkey);
        }
    }
    return false;
}

long long unsigned jiecheng(int n)
{
    long long unsigned tmp = 1;
    while (n > 1)
    {
        tmp *= n;
        tmp %= modval;
        n--;
    }
    return tmp;
}

long long unsigned calret()
{
    DFS(' ', 0);
    int numtmp = 1;
    long long unsigned ret = 1;
    for (unordered_map<int, int>::iterator it = g_mapClosed.begin();
        it != g_mapClosed.end(); it++)
    {
        ret *= jiecheng(it->second);
        ret %= modval;
        numtmp++;
    }
    ret *= singlenum;
    ret %= modval;
    ret *= jiecheng(numtmp);
    ret %= modval;
    return ret;
}

int main()
{
    int _T, idx = 0;
    int N;
    cin >> _T;
    while(idx < _T)
    {
        idx++;
        cin >> N;
        int idxn = 0;
        char s, e;
        nNum = 0;
        singlenum = 0;
        g_Start.clear();
        g_mapClosed.clear();
        g_setClosed.clear();
        while(idxn < N)
        {
            scanf("%c", &s);
            while (s == '\n')
            {
                scanf("%c", &s);
            }
            if(s == ' ')
                continue;
            char tmp = s;
            do 
            {
                e = tmp;
                scanf("%c", &tmp);
            } while (tmp != ' ' && tmp != '\n');
            string str;
            str.append(1, s);
            str.append(1, e);
            CheckStr(str);
            idxn++;
        }
        cout << "Case #" << idx << ": ";
        cout << calret();
        // output result
        cout << endl;
    }
    return 0;
}