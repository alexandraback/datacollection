#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#define enter printf("\n");
#define ull unsigned long long
#define ll long long
#define sort(a) sort(a.begin(), a.end())

using namespace std;
int INF = 1000000007;
vector<int> a;
int n, x, y;
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

void writeln(vector<int> &f)
{
    int x;
    for (int i = 0; i < f.size(); i++)
        printf("%d%c", f[i], i == f.size() - 1 ? '\n' : ' ');
}

double test()
{
    readln(n, x, y);
    x = abs(x);
    y = abs(y);
    a.resize(1);
    a[0] = 1;
    for (int i = 1; a[i - 1] < 1000000;i++)
        a.push_back((2 * i + 1) * (i + 1));
    int i = 0;
    while (n > a[i])
        i++;
    int count = a[i] - n;
    if (count == 0)
        return (int) (x + y <= 2 * i);
    if (x + y < 2 * i)
        return 1;
    if (x + y > 2 * i)
        return 0;
    double s = 0.5, g = 0;
    for (int j = 0; j < (count + 1) / 2 - y; j++)
        g += s,
        s /= 2;
    return g;
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
        printf("%f\n", test());
    }
    return 0;
}
