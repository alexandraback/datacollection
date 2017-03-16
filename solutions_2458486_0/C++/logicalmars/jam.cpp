#include <cstring>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <algorithm>
using namespace std;

int goal(int temp, int n)
{
    for (int i = 0;i<n;i++)
    {
        if ( ((1<<i) & temp) == 0)
            return 0;
    }

    return 1;
}

vector<int> get_keys(vector<int> &init, vector<int> chest[], vector<int> &need, int head, int n)
{
    vector<int> keys(210);
    vector<int>::iterator p;
    for (p = init.begin(); p!=init.end(); p++)
    {
        keys[*p]++;
    }

    for (int i = 0;i<n;i++)
    {
        if ((1<<i) & head)
        {
            keys[need[i]] --;
            for (p = chest[i].begin(); p != chest[i].end(); p++)
            {
                keys[*p] ++;
            }
        }
    }

    return keys;
}

void pr(int t, int parent[], int new_open[])
{
    vector<int> seq;

    while (t != 0)
    {
        seq.push_back(new_open[t]);
        t = parent[t];
    }

    reverse(seq.begin(), seq.end());
    for (vector<int>::iterator p = seq.begin(); p!=seq.end(); p++)
    {
        printf(" %d", *p + 1);
    }
    printf("\n");
}

const int maxn = 1048576 + 100;
int Q[maxn];
int parent[maxn];
int new_open[maxn];

void BFS(vector<int> &init, vector<int> chest[], vector<int> &need, int n)
{

    set<int> S;

    int h, t;
    h = t = 0;
    Q[0] = 0;  
    S.insert(0);  

    while (h<=t)
    {
        int head = Q[h];
        vector<int> keys = get_keys(init, chest, need, head, n);

        for (int i = 0;i<n;i++)
        {
            if (((1 << i) & head) == 0 && keys[need[i]] > 0)
            {
                int temp = head | (1<<i);
                if (S.find(temp) == S.end())
                {
                    t++;
                    Q[t] = temp;
                    parent[t] = h;
                    new_open[t] = i;
                    S.insert(temp);

                    if (goal(temp, n))
                    {
                        pr(t, parent, new_open);
                        return ;
                    }
                }
            }
        }        

        h++;
    }    

    printf(" IMPOSSIBLE\n");
}

void work()
{
    vector<int> chest[30];
    vector<int> init;
    vector<int> need(30);

    int k, n;
    scanf("%d%d", &k, &n);
    
    for (int i = 0;i<k;i++)
    {   
        int key;
        scanf("%d", &key);
        init.push_back(key);
    }

    for (int i = 0;i<n;i++)
    {
        scanf("%d", &need[i]);
        scanf("%d", &k);
        for (int j = 0;j<k;j++)
        {
            int key;
            scanf("%d", &key);
            chest[i].push_back(key);
        }
    }

    BFS(init, chest, need, n);
}
 
int main()
{
    freopen("D-small-attempt1.in", "r", stdin);
    // freopen("A-large-practice.in", "r", stdin);    
    // freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
 
    int cs, t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++)
    {
        printf("Case #%d:", cs);
        work();
    }
 
    return 0;
}