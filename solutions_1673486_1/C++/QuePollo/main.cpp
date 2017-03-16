#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <cstring>

#define MAXA 100000
using namespace std;
typedef pair<int, int> pi;
typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for(int i = 0; i<(int)n; i++)
#define all(v) (v).begin(), (v).end()
#define dforn(i, n) for(int i= (int)n-1; i=>0; i--)

#define sz(a) int((a).size())
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())


using namespace std;

int enterAhora(int a, int b)
{
    return a+b;
}

int backspace(int a, int b, int n)
{
    return a+n+b;
}

int keeptyping(int a, int b)
{
    return 2*b;
}

double solucion(int a, int b, double probs[MAXA])
{
    double probTodoBien =1;
    forn(i,a)
        probTodoBien*=probs[i];
    double probTodoMal = 1-probTodoBien;

    double pagoEnterAhora = b+2;
    double pagoKeepTypingBien = (b-a+1)*probTodoBien;
    double pagoKeepTypingMal = (b-a+b+2)*probTodoMal;
    double pagoKeepTyping = pagoKeepTypingBien+pagoKeepTypingMal;

    double probacumulada = probTodoBien;
    double pagoBackspace = 100000000;
    for(int i=1; i<=a; i++)
    {
        double estaProb;
        if(i==a) estaProb=1;
        else estaProb = probacumulada/(probs[a-i]);
        pagoBackspace = min(pagoBackspace, ((estaProb*(b-a+i+i+1))+((1-estaProb)*(b-a+i+i+b+2))));
        probacumulada=estaProb;
    }

    return min(pagoEnterAhora,min(pagoKeepTyping,pagoBackspace)) ;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.in","r",stdin);
        freopen("output.out","w",stdout);
    #endif
    unsigned int n=1;
    cin >> n;
    double probs[MAXA];
    for(int i=0;i<n;i++)
    {
        int a, b;

        cin >> a >> b;
        forn(i,a) cin>> probs[i];



        double sol = solucion(a, b, probs);
        cout << "Case #" << i+1 << ": ";
        printf("%.6f\n", sol);
    }

    return 0;
}

