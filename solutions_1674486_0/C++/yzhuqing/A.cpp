#include <cstdio>
#include <stack>

struct Node
{
    int seq;
    Node *next;
    Node(int i, Node *n) :seq(i), next(n){}
};

Node* map[1001];
int size;
int visited[1001];

inline void init()
{
    for (int i = 0; i <= size; i++)
        map[i] = NULL;
}
inline void insert(int src, int dest)
{
    Node *p = new Node(dest, map[src]);
    map[src] = p;
}

void input()
{
    scanf("%d", &size);
    for (int i = 1; i <= size; i++)
    {
        int len;
        int src, dest;
        scanf("%d", &len);
        if (len == 0)
            continue;
        else
        {
            src = i;
            for (int i = 1; i <= len; i++)
            {
                scanf("%d", &dest);
                insert(src, dest);
            }
        }
    }
}

int dfs(int src)
{
    std::stack<Node *> s;
    if (map[src] == NULL)
        return 0;

    for (int j = 0; j <= size; j++)
        visited[j] = 0;
    Node *cur = map[src];
    while (cur != NULL)
    {
        visited[ cur->seq ]++;
        s.push(cur);
        cur = cur->next;
    }
    while (!s.empty())
    {
		cur = map[s.top()->seq];
        s.pop();
        while (cur != NULL)
        {
            visited[ cur->seq ]++;
            if (visited[ cur->seq ] >= 2)
                return 1;
            s.push(cur);
            cur = cur->next;
        }
    }
    return 0;
}

int solve()
{
    for (int i = 1; i <= size; i++)
    {
        if (dfs(i))
            return 1;
    }
	return 0;
}

int main()
{
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("A-small-attempt1.out", "w", stdout);
    int case_total;
    scanf("%d", &case_total);
    for (int case_i = 1; case_i <= case_total; case_i++)
    {
        init();
        input();
        if (solve())
            printf("Case #%d: Yes\n", case_i);
        else
            printf("Case #%d: No\n", case_i);
    }

    return 0;
}
