#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#define enter printf("\n");
#define E 0
#define N 1
#define S 2
#define W 3


using namespace std;
int INF = 1000000007;
vector<int> a;
void writeln(int a){printf("%d\n", a);}void writeln(int a, int b){printf("%d %d\n", a, b);}void writeln(int a, int b, int c){printf("%d %d %d\n", a, b, c);}void writeln(int a, int b, int c, int d){printf("%d %d %d %d\n", a, b, c, d);}void write(int a){printf("%d", a);}void write(int a, int b){printf("%d %d", a, b);}void write(int a, int b, int c){printf("%d %d %d", a, b, c);}void write(int a, int b, int c, int d){printf("%d %d %d %d", a, b, c, d);}void read(int &a){scanf("%d", &a);}void read(int &a, int &b){scanf("%d %d", &a, &b);}void read(int &a, int &b, int &c){scanf("%d %d %d", &a, &b, &c);}void read(int &a, int &b, int &c, int &d){scanf("%d %d %d %d", &a, &b, &c, &d);}void readln(int &a){scanf("%d\n", &a);}void readln(int &a, int &b){scanf("%d %d\n", &a, &b);}void readln(int &a, int &b, int &c){scanf("%d %d %d\n", &a, &b, &c);}void readln(int &a, int &b, int &c, int &d){scanf("%d %d %d %d\n", &a, &b, &c, &d);}

void readln(vector<int> &f, int n)
{
    int x;
    for (int i = 1; i <= n; i++)
    {
        read(x);
        f.push_back(x);
    }
}

char co[4] = {'E', 'N', 'S', 'W'};

void writeln(vector<int> &f)
{
    if (f.size() >= 500)
        printf("ты все равно тупая лошара!\n");
    int x;
    for (int i = 0; i < f.size(); i++)
        printf("%c", co[f[i]]);
    enter;
}

vector<int>& test()
{
    int n, m;
    readln(n, m);
    a.clear();
    int s = 0;
    for (;;)
    {
    if (m > 0)
    {
        int t = 0;
        while (t < m)
            t += ++s,
            a.push_back(N);
        if (t == m)
            break;
        t -= m;
        for (int i = 0; i < t; i++)
            a.push_back(N),
            s += 2,
            a.push_back(S);
    }
    if (m < 0)
    {
        int t = 0;
        m = abs(m);
        while (t < m)
            t += ++s,
            a.push_back(S);
        if (t == m)
            break;
        t -= m;
        for (int i = 0; i < t; i++)
            a.push_back(S),
            s += 2,
            a.push_back(N);
    }
        break;
    }
    if (n == 0)
        return a;
    for (;;)
    {
    if (n > 0)
    {
        int t = 0;
        while (t < n)
            t += ++s,
            a.push_back(E);
        if (t == n)
            break;
        t -= n;
        for (int i = 0; i < t; i++)
            a.push_back(E),
            a.push_back(W);
    } else
    if (n < 0)
    {
        n = abs(n);
        int t = 0;
        while (t < n)
            t += ++s,
            a.push_back(W);
        if (t == n)
            break;
        t -= n;
        for (int i = 0; i < t; i++)
            a.push_back(W),
            a.push_back(E);
    }
    break;
    }
    return a;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w+", stdout);
    int T;
    readln(T);
    for (int tttt = 0; tttt < T; tttt++)
    {
        printf("Case #%d: ", tttt + 1);
        writeln(test());
    }
    return 0;
}
