#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

#define nDict 521196
#define oo 1000000000
#define MAXTRIE 2000000

using namespace std;

string dict[nDict+1];
int dlen[nDict+1];
string corrS;
int f[4001];
int n;

int trie[MAXTRIE][26];
int isWord[MAXTRIE];
int nTrie;

void insert_word(int a, int k, int ind)
{
    if (ind < 0)
    {
        isWord[a] = k;
        return ;
    }
    int c = dict[k][ind] - 'a';
    if (trie[a][c] == 0)
        trie[a][c] = ++nTrie;
    insert_word(trie[a][c], k, ind-1);
}

void build_trie()
{
    nTrie = 0;
    memset(trie, 0, sizeof(trie));
    memset(isWord, 0, sizeof(isWord));
    for (int i=1; i<=nDict; i++)
    {
        //cout << dict[i] << endl;
        insert_word(0, i, (int)(dict[i].length()) - 1);
    }
}

void init()
{
    cin >> corrS;
    n = corrS.length();
    corrS = " " + corrS;
}

int get_cnt(int st, const string& tar, int lim)
{
    int res = 0;
    for (int i=0; i<tar.length(); i++)
    {
        if (corrS[st+i] != tar[i])
        {
            res ++;
        }
        if (res >= lim)
        {
            return oo;
        }
    }
    return res;
}

int work()
{
    f[0] = 0;
    for (int i=1; i<=n; i++)
    {
        f[i] = f[i-1] + 1;
//        int cur = 0;
//        for (int j=i-1; i>=0; j--)
//        {
//            cur = trie[cur][corrS[j]-'a'];
//            if (cur == 0)
//                break;
//            if (isWord[cur])
//                f[i] = f[j];
//        }
        
        for (int k=1; k<=nDict; k++)
        {
            int len = dict[k].length();
            if (len > i)
                continue;
            int j = i - len;
            if (f[i] <= f[j])
                continue;
            int upd = f[j] + get_cnt(j+1, dict[k], f[i]-f[j]);
            if (upd < f[i])
            {
                f[i] = upd;
                //cout << i << " " << j << endl;
                //cout << dict[k] << endl;
            }
        }
    }
    return f[n];
}


int main()
{
    freopen("garbled_email_dictionary.txt", "r", stdin);
    int maxlen = 0;
    for (int i=1; i<=nDict; i++)
    {
        cin >> dict[i];
    }
    cout << "loading done" << endl;
    build_trie();
    cout << "build done" << endl;
    cout << nTrie << endl;
    
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small-attempt1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int tim=1; tim<=T; tim++)
    {
        init();
        printf("Case #%d: %d\n", tim, work());
    }
}
