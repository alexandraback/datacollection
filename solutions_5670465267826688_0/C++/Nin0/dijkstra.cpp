#include <cstdio>
#include <cstring>
#include <map>
#include <tuple>
using namespace std;

/* g++ -std=c++11 dijkstra.cpp */

const int MAX_LEN = 10000;
const char baza[] = {'1', 'i', 'j', 'k'};
const char tabela[][4] = {
    {'1', 'i', 'j', 'k'},
    {'i', '-', 'k', 'J'},
    {'j', 'K', '-', 'i'},
    {'k', 'j', 'I', '-'},
};

typedef tuple<char, char> c2t;

map<c2t, char> quater;

char neg(char c)
{
    switch (c)
    {
        case '1': return '-';
        case 'i': return 'I';
        case 'j': return 'J';
        case 'k': return 'K';
        case '-': return '1';
        case 'I': return 'i';
        case 'J': return 'j';
        case 'K': return 'k';
    }
}

char evaluate(const char *niz, int b, int e)
{
    char ans = '1';
    for (int i=b; i<e; i++)
    {
        ans = quater[c2t(ans, niz[i])];
    }
    return ans;
}

char good;

bool can_claim(char *niz, int l, int x)
{
    
    char napis[MAX_LEN+1];
    napis[0] = '\0';
    for (int i=0; i<x; i++) strcat(napis, niz);
    // printf("%c %c\n", good, evaluate(napis, 0, l*x));
    if (evaluate(napis, 0, l*x) != good) return false;
    
    int i = 0;
    char p = '1';
    while ((p != 'i') && (i < l*x))
    {
        p = quater[c2t(p, napis[i])];
        i++;
    }
    if (p != 'i') return false;
    
    p = '1';
    while ((p != 'j') && (i < l*x))
    {
        p = quater[c2t(p, napis[i])];
        i++;
    }
    if (p != 'j') return false;
    return true;
}

int main()
{
    int t, l, x;
    char niz[MAX_LEN+1];
    bool ans;
    
    /* Build multiplication table */
    for (int a=0; a<4; a++)
    {
        for (int b=0; b<4; b++)
        {
            quater[c2t(baza[a], baza[b])] = tabela[a][b];
            quater[c2t(neg(baza[a]), baza[b])] = neg(tabela[a][b]);
            quater[c2t(baza[a], neg(baza[b]))] = neg(tabela[a][b]);
            quater[c2t(neg(baza[a]), neg(baza[b]))] = tabela[a][b];
        }
    }
    
    good = evaluate("ijk", 0, 3);
    
    scanf("%d", &t);
    for (int caseNum=1; caseNum<=t; caseNum++)
    {
        scanf("%d %d", &l, &x);
        scanf("%s", niz);
        ans = can_claim(niz, l, x);
        printf("Case #%d: %s\n", caseNum, (ans)?"YES":"NO");
        // printf("%d, %d, '%s'\n", l, x, niz);
    }
    
    /*
    for (auto it=quater.begin(); it!=quater.end(); ++it)
    {
        char a = get<0>(it->first);
        char b = get<1>(it->first);
        printf("%c * %c => %c\n", a, b, it->second);
    }
    */
    
    return 0;
}
