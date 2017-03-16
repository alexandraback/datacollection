#include <iostream>
#include <unordered_map>
#include <map>
#include <iomanip>

using namespace std;

int k, l, s;
string target;
string keyboard;
int startpos;

bool docheck(int i)
{
    int len = l - i;

    for(int j = 0; j < len; j++)
    {
        if(target[i + j] != target[j])
            return false;
    }

    return true;
}

int check()
{
    for(int i = 1; i < l; i++)
    {
        if(docheck(i))
            return l - i;
    }

    return 0;
}

unordered_map<int, char> cache2;

bool match(int p, int j)
{
    int key = j + p * 101;

    if(cache2.count(key))
        return cache2[key];

    for(int i = 0; i < j; i++)
    {
        if(target[i] != target[p - j + i])
            return cache2[key] = false;
    }

    return cache2[key] = true;
}

unordered_map<int, double> cache;
double prop[255];

double calcex(int i, int p)
{
    double total = 0;
    int key = i + p * 101;

    if(p == l)
    {
        p = startpos;
        total = 1;
    }
    if(i == s)
        return total;

    if(cache.count(key))
        return cache[key];



    map<char, int> pos;

    for(int j = 0; j <= p; j++)
    {
        // take p - j + 1 .. p

        if(match(p, j))
        {
            char next = target[j];

            pos[next] = j + 1;
        }
    }

    double left = 1;

    for(auto pa : pos)
    {
        total += prop[pa.first] * calcex(i + 1, pa.second);
        left -= prop[pa.first];
    }

    total += left * calcex(i + 1, 0);

    return cache[key] = total;
}

double calcmax()
{
    int leftAfterFirst = s - l;

    if(leftAfterFirst < 0)
        return 0;

    int repeatLength = l - startpos;

    return 1 + (leftAfterFirst / repeatLength);
}

void solve()
{
    cin >> k >> l >> s;
    cin >> keyboard;
    cin >> target;

    for(int i = 0; i < 255; i++)
    {
        prop[i] = 0.0;
    }

    for(char c : keyboard)
    {
        prop[c] += 1.0 / keyboard.length();
    }

    for(char c : target)
    {
        if(prop[c] == 0.0)
        {
            cout << "0.0";
            return;
        }
    }

    startpos = check();

    cache.clear();
    cache2.clear();
    cout << fixed << setprecision(12) << calcmax() - calcex(0, 0);
}

int main()
{
    int t;
    cin >> t;

    for(int i = 1; i <= t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
