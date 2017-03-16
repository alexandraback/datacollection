#include <bits/stdc++.h>

using namespace std;

long long pows[18];

int dig[18];

void digitilize(int n, long long t)
{
    string s = to_string(t);

    while (s.length() < n)
        s = "0" + s;

    for (int i = 0; i < n; ++i)
        dig[i] = s[i]-'0';

    pows[n-1] = 1;
    for (int i = n-2; i >= 0; --i)
        pows[i] = pows[i+1]*10;
}

long long fill_max_up_to(int n, char* p, long long v)
{
    digitilize(n, v);
    long long r = 0;

    for (int i = 0; i < n; ++i)
    {
        if (p[i] != '?')
            r += (p[i]-'0')*pows[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (p[i] == '?' && r < v) 
        {
            int j = 0;
            while (j < 9 && r+(j+1)*pows[i] <= v) ++j;
            r += j*pows[i];
        }
    }
    return r;
}

long long fill_min_down_to(int n, char* p, long long v)
{
    digitilize(n, v);
    long long r = 0;

    for (int i = 0; i < n; ++i)
    {
        if (p[i] != '?')
            r += (p[i]-'0')*pows[i];
    }
    for (int i = 0; i < n; ++i)
    {
        if (p[i] == '?' && r < v)
        {
            int j = 9;
            while (j > 0 && r+(j-1)*pows[i] >= v) --j;
            r += j*pows[i];
        }
    }

    return r;
}

long long best_diff, bx, by;

void check(long long x, long long y)
{
    long long diff = abs(x-y);

    if (diff < best_diff || diff == best_diff && x < bx) 
    {
        best_diff = diff;
        bx = x;
        by = y;
    }
}

void solve(int n, char* c, char *j) 
{
    best_diff = 1e18;

    long long x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    for (int i = 0; i < n; ++i) 
    {
        x1 *= 10;
        x2 *= 10;
       
        if (c[i] != '?') 
        {
            x1 += c[i]-'0';
            x2 += c[i]-'0';
        }
        else 
        {
            x2 += 9;
        }

        y1 *= 10;
        y2 *= 10;
        if (j[i] != '?')
        {
            y1 += j[i]-'0';
            y2 += j[i]-'0';
        }
        else 
        {
            y2 += 9;
        }
    }

    check(x1, y1);
    do 
    {
        long long px = x1, py = y1;

        //cout << x1 << " + " << y1 << endl;

        if (x1 < y1)
        {
            x1 = fill_max_up_to(n, c, y1);
            if (px == x1)
                x1 = fill_min_down_to(n, c, y1);
        }
        else
        {
            y1 = fill_max_up_to(n, j, x1);
            if (py == y1)
                y1 = fill_min_down_to(n, j, x1);
        }

        if (px == x1 && py == y1)
            break;
        else
            check(x1, y1);
    }
    while (true);

    /*check(x2, y2);
    check(x1, y2);
    check(x2, y1);

    long long x = fill_max_up_to(n, c, y1);
    check(x, y1);
    x = fill_min_down_to(n, c, y1);
    check(x, y1);

    x = fill_max_up_to(n, c, y2);
    check(x, y2);
    x = fill_min_down_to(n, c, y2);
    check(x, y2);

    long long y = fill_max_up_to(n, j, x1);
    check(x1, y);
    y = fill_min_down_to(n, j, x1);
    check(x1, y);

    y = fill_max_up_to(n, j, x2);
    check(x2, y);
    y = fill_min_down_to(n, j, x2);
    check(x2, y);
    */

    string s1 = to_string(bx), s2 = to_string(by);
    while (s1.length() < n)
        s1 = "0" + s1;
    while (s2.length() < n)
        s2 = "0" + s2;
    cout << s1 << " " << s2;
}

void check(int n, char* c, char* j, int x, int y)
{
    string s1 = to_string(x), s2 = to_string(y);
    if (s1.length() <= n && s2.length() <= n)
    {
        while (s1.length() < n)
            s1 = "0" + s1;
        while (s2.length() < n)
            s2 = "0" + s2;

        for (int i = 0; i < n; ++i)
            if (c[i] != '?' && c[i] != s1[i] || j[i] != '?' && j[i] != s2[i])
                return;

        check(x, y);
    }
}

void brute(int n, char* c, char* j)
{
    best_diff = 1e18;
    for (int x = 0; x < 1000; ++x)
        for (int y = 0; y < 1000; ++y)
            check(n, c, j, x, y);

    string s1 = to_string(bx), s2 = to_string(by);
    while (s1.length() < n)
        s1 = "0" + s1;
    while (s2.length() < n)
        s2 = "0" + s2;
    cout << s1 << " " << s2 << endl;
}

int main()
{
    //freopen("sample.in", "r", stdin);
    freopen("B-small-attempt3.in", "r", stdin);
    //freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n_tests;
    scanf("%d", &n_tests);

    for (int test_id = 1; test_id <= n_tests; ++test_id)
    {
        char c[22], j[22];
        scanf("%s %s", c, j);
                
        printf("Case #%d: ", test_id);

        solve(strlen(c), c, j);
        printf("\n");
    }

    return 0;
}
