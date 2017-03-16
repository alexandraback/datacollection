#include <iostream>
#include <algorithm>

using namespace std;

const int A = 26 + 2;
const int S = 4000 + 10;

class Node
{
public:
    bool word;
    Node *lnk[A];
    
    Node();
    void load(char *str);
};

int tc, res;

int dyn[S][6];

char str[S];

Node tree;

Node::Node()
{
    char i;
    
    word = false;
    
    for(i = 'a'; i <= 'z'; i++)
    {
        lnk[i - 'a'] = NULL;
    }
}

void Node::load(char *str)
{
    if(*str == '\0')
    {
        word = true;
        return;
    }
    if(lnk[*str - 'a'] == NULL)
    {
        lnk[*str - 'a'] = new Node;
    }
    lnk[*str - 'a']->load(str + 1);
}

void load()
{
    int i;
    FILE *fdb = fopen("/Users/protos37/Downloads/garbled_email_dictionary.txt", "r");
    
    for(i = 0; i < 521196; i++)
    {
        fscanf(fdb, "%s\n", str);
        tree.load(str);
    }
    fclose(fdb);
}

void input()
{
    scanf("%s\n", str);
}

void calc(Node *node, int i, int j, int d)
{
    char c;
    
    if(node->word)
    {
        dyn[i][min(j, 5)] = min(dyn[i][min(j, 5)], d);
    }
    if(str[i] == '\0')
    {
        return;
    }
    
    for(c = 'a'; c <= 'z'; c++)
    {
        if(node->lnk[c - 'a'] != NULL)
        {
            if(c == str[i])
            {
                calc(node->lnk[c - 'a'], i + 1, j + 1, d);
            }
            else if(5 <= j)
            {
                calc(node->lnk[c - 'a'], i + 1, 1, d + 1);
            }
        }
    }
}

void process()
{
    int i, j, n = (int)strlen(str);
    
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            dyn[i][j] = n;
        }
    }
    
    dyn[0][5] = 0;
    for(i = 0; i < n; i++)
    {
        for(j = 1; j <= 5; j++)
        {
            calc(&tree, i, j, dyn[i][j]);
        }
    }
    
    res = n;
    for(j = 1; j <= 5; j++)
    {
        res = min(res, dyn[n][j]);
    }
}

void output()
{
    printf("Case #%d: %d\n", tc, res);
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/C-small-attempt0.in", "r", stdin);
    freopen("/Users/protos37/Downloads/C-small-attempt0.out", "w", stdout);
    
    scanf("%d\n", &t);
    
    load();
    for(tc = 1; tc <= t; tc++)
    {
        input();
        process();
        output();
    }
    
    return 0;
}