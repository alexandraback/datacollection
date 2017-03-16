#include <cassert>
#include <iostream>
#include <list>
#include <vector>
#include <fstream>

using namespace std;

#define MAX_KEYS 10000
ofstream debug_stream("debug.txt");
#define debug debug_stream

int num_opened_chests;
int possessed_keys[MAX_KEYS];
int N;
list<int> solution;
bool hack_special_case = false;
bool hack_opened[MAX_KEYS];

struct Chest
{
    int number;
    int key_to_open;
    vector<int> content;
    bool opened;

    Chest(int n=-1) : number(n), key_to_open(-1), opened(false) {}

    void read()
    {
        cin >> key_to_open;
        int num_keys; cin >> num_keys;
        for (int i = 0; i < num_keys; i++)
        {
            int key; cin >> key;
            content.push_back(key);
        }
    }

    void print()
    {
        debug << "Chest #" << number;
        debug << " (opens with " << key_to_open << ")" << endl;
        for (auto key: content)
        {
            debug << "> " << key << endl;
        }
    }

    void open()
    {
        num_opened_chests++;
        opened = true;
        possessed_keys[key_to_open]--;
        for (auto key: content)
        {
            possessed_keys[key]++;
        }
        if (hack_special_case)
        {
            hack_opened[key_to_open] = true;
        }
    }

    void close()
    {
        num_opened_chests--;
        opened = false;
        possessed_keys[key_to_open]++;
        for (auto key: content)
        {
            possessed_keys[key]--;
        }
        if (hack_special_case)
        {
            hack_opened[key_to_open] = false;
        }
    }
};
vector<Chest> chests;

void init()
{
    for (int i = 0; i < MAX_KEYS; i++)
    {
        possessed_keys[i] = 0;
    }
    chests.clear();
    num_opened_chests = 0;
    solution.clear();

    hack_special_case = false;
    for (int i = 0; i < MAX_KEYS; i++)
    {
        hack_opened[i] = false;
    }
}

bool check_total_keys()
{
    int total_keys[MAX_KEYS];
    for (int i = 0; i < MAX_KEYS; i++)
    {
        total_keys[i] = possessed_keys[i];
    }
    for (auto chest: chests)
    {
        for (auto key: chest.content)
        {
            total_keys[key]++;
        }
    }
    for (auto chest: chests)
    {
        if (!total_keys[chest.key_to_open])
        {
            return false;
        }
        total_keys[chest.key_to_open]--;
    }
    return true;
}

bool check_special_case()
{
    bool chest_without_key[MAX_KEYS];
    bool chest_with_one_key[MAX_KEYS];
    for (int i = 0; i < MAX_KEYS; i++)
    {
        chest_without_key[i] = false;
        chest_with_one_key[i] = false;
    }
    for (auto chest: chests)
    {
        if (possessed_keys[chest.key_to_open] != 1)
        {
            return false;
        }
        if (chest.content.size() > 1)
        {
            return false;
        }
        if (chest.content.empty())
        {
            if (chest_without_key[chest.key_to_open])
            {
                return false;
            }
            chest_without_key[chest.key_to_open] = true;
            continue;
        }
        if (chest.content[0] != chest.key_to_open)
        {
            return false;
        }
        if (chest_with_one_key[chest.key_to_open])
        {
            return false;
        }
        chest_with_one_key[chest.key_to_open] = true;
    }
    for (auto chest: chests)
    {
        if (!chest_without_key[chest.key_to_open])
        {
            return false;
        }
        if (!chest_with_one_key[chest.key_to_open])
        {
            return false;
        }
    }
    return true;
}

bool solve_recursive()
{
    if (num_opened_chests == N)
    {
        // all chests are opened, problem is solved :-)
        return true;
    }

    for (auto & chest: chests)
    {
        if (chest.opened)
        {
            continue;
        }
        if (!possessed_keys[chest.key_to_open])
        {
            continue;
        }
        if (hack_special_case)
        {
            if (chest.content.empty() && !hack_opened[chest.key_to_open])
            {
                continue;
            }
        }

        chest.open();
        if (solve_recursive())
        {
            solution.push_front(chest.number);
            return true;
        }
        chest.close();
    }
    return false;
}

void solve()
{
    init();

    int K; cin >> K >> N;
    debug << endl;
    debug << "Starting keys: ";
    for (int i = 0; i < K; i++)
    {
        int key; cin >> key;
        assert(key < MAX_KEYS);
        debug << key << " ";
        possessed_keys[key]++;
    }
    debug << endl;
    for (int i = 0; i < N; i++)
    {
        Chest c(i+1);
        c.read();
        c.print();
        chests.push_back(c);
    }
    debug << endl;

    if (!check_total_keys())
    {
        debug << "IMPOSSIBLE (check_total_keys --> false)" << endl;
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    hack_special_case = check_special_case();
    debug << "hack_special_case: " << hack_special_case << endl;

    if (solve_recursive())
    {
        debug << "Found solution: ";
        for (auto c: solution)
        {
            debug << c << " ";
            cout << c << " ";
        }
        debug << endl;
        cout << endl;
    }
    else
    {
        debug << "IMPOSSIBLE (all combos checked)" << endl;
        cout << "IMPOSSIBLE" << endl;
    }
}

int main()
{
    int T; cin >> T;
    for (int t = 0; t < T; t++)
    {
        cout << "Case #" << (t+1) << ": ";
        debug << "Case #" << (t+1) << endl;
        solve();
    }
    return 0;
}

