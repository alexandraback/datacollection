#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <cassert>
#include <string>

#define mp make_pair
#define pb push_back

#define mod 1000000007

using namespace std;

vector<char *> v;

struct TRee26
{
    TRee26 * child[27];
} * root;

inline void clearTRee26()
{
    root = new TRee26();
    for(int i=1; i<=26; i++)
        root->child[i] = NULL;    
}

inline long long cntTRee26(char *str)
{
    int len = strlen(str);
    int idx = 0;
    if(root == NULL)
    {
        root = new TRee26();
        for(int i=1; i<=26; i++)
            root->child[i] = NULL;    
    }
    TRee26 * current = root;
    long long ret = 0;
    bool checkPrefix = false;
    for(int i=0; i<len; i++)
    {
        idx = str[i] - 'a' + 1;
        if(checkPrefix == false) ret++;
        if(current->child[idx] == NULL)
        {
            TRee26 * nextChild = new TRee26();
            current->child[idx] = new TRee26();
            checkPrefix = true;        
        }
        current = current->child[idx];
    }
    return ret;
}

int main()
{
    
	freopen("autocomplete.txt", "r", stdin);
	freopen("autoout22.txt", "w", stdout);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    char str[1000005]; int n, lvl = 0, cnt = 0, fin = 0, s = 0; bool cntTest = false;
    long long ans = 0LL;
    while(gets(str))
    {
        if(cntTest==false)
        {
            cntTest = true; continue;    
        }
        int len = strlen(str);
        if(str[0]>='0' && str[0]<='9')
        {
            cnt = 0;
            s = 0;
            ans = 0LL;
            //v.clear();
            clearTRee26();
            for(int i=0; i<len; i++)
            {
                s = s*10 + str[i] - 48;    
            }
            fin = s;
        }
        else
        {
            cnt++; 
            str[len] = '\0';
            //v.pb(str);
            ans += (long long)cntTRee26(str);
            if(cnt == fin)
            {
                int ll = 1;
                printf("Case #%d: %lld\n",++lvl,ans);
            }                
        }
    }
    return 0;    
}

