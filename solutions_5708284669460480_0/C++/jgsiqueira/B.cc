#include <bits/stdc++.h>

using namespace std;

string key, pattern;
int k,l,s;
double freq[0x100];
char text[10];
double ans, maximo;

#define MAXN 100001 //tamanho maximo da string
int pi[MAXN], res[MAXN], nres;
void kmp ()
{
    nres = 0;
    pi[0] = -1;
    for (int i = 1; i < pattern.size(); ++i)
    {
        pi[i] = pi[i-1];
        while (pi[i] >= 0 && pattern[pi[i] + 1] != pattern[i])
            pi[i] = pi[pi[i]];
        if (pattern[pi[i] + 1] == pattern[i])
            ++pi[i];
    }
    int k = -1;  //k + 1 eh o tamanho do match atual
    for (int i = 0; i < s; ++i)
    {
        while (k >= 0 && pattern[k + 1] != text[i])
            k = pi[k];
        if (pattern[k + 1] == text[i])
            ++k;
        if (k + 1 == pattern.size())
        {
            res[nres++] = i - k;
            k = pi[k];
        }
    }
}

void solve(int p, double prob)
{
    if(p == s)
    {
        kmp();
        maximo = max(maximo, (double)nres);
        ans += prob*((double)nres);
        return;
    }
    for(int i='A'; i<='Z'; i++)
    {
        if(freq[i] > 0)
        {
            text[p] = i;
            solve(p+1, prob*(freq[i]/(double)k));
        }
    }
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);

    for(int caso=1; caso<=t; caso++)
    {
        scanf("%d%d%d",&k,&l,&s);

        cin >> key >> pattern;

        memset(freq,0,sizeof(freq));
        for(int i=0; i<k; i++) freq[key[i]]++;

        ans = 0;
        maximo = 0;
        solve(0,1.0);
        printf("Case #%d: %lf\n",caso, maximo - ans);
    }

    return 0;
}
