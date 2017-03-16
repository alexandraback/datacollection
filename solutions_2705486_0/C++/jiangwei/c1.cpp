#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 4001;
string S;

struct Node {
    Node* children[26];
    bool is_word;
} *root;

int total_nodes;

int dp[MAX_N][5];

void build_tree(const char *path)
{
    FILE *file = fopen(path, "r");
    char buf[256];
    root = new Node;
    root->is_word = false;
    memset(root->children, 0, sizeof(root->children));
    total_nodes = 1;
    while ( fscanf(file, "%s", buf) != EOF )
    {
        int len = strlen(buf);
        Node *node = root;

        //++counter;
        //cout << "start " << counter << " with " << buf << " (" << counter << ")" << endl;

        for (int i = 0; i < len; i++)
        {
            Node *child = node->children[buf[i] - 'a'];
            if (child == NULL)
            {
                ++total_nodes;
                child = new Node;
                child->is_word = false;
                memset(child->children, 0, sizeof(child->children));
                node->children[buf[i] - 'a'] = child;
            }
            node = child;
        }
        node->is_word = true;
        //cout << "finished " << counter << endl;
    }
    fclose(file);

    //cout << total_nodes << " nodes in trie." << endl;
}

int solve(int i, int d);

void discrepency_search(int i, int d, int &ret, Node *node, int changed)
{
    if (d > 4) d = 4;
    if (node == NULL) return;
    if (ret > -1 && changed >= ret) return;

    if (node->is_word)
    {
        int temp = changed + solve(i, d);
        if (temp >= changed && (ret < 0 || temp < ret))
        {
            ret = temp;
            //cout << "(" << i << "," << d << "): " << changed << " -> " << temp << endl;
        }
    }
    if (i >= S.size()) return;

    Node *next = node->children[S[i] - 'a'];
    if (next != NULL)
    {
        discrepency_search(i + 1, d + 1, ret, next, changed);
    }
    if (d >= 4)
    {
        for (int ch = 0; ch < 26; ch++)
            if (node->children[ch] != NULL && 'a' + ch != S[i])
            {
                discrepency_search(i + 1, 0, ret, node->children[ch], changed + 1);
            }
    }
}

int solve(int i, int d)
{
    if (i >= S.size())
    {
        return 0;
    }
    int &ret = dp[i][d];
    if (ret > -1) return ret;
    //cout << "updating (" << i << "," << d << ")" << endl;
    discrepency_search(i, d, ret, root, 0);
    return ret;
}

int main()
{
    build_tree("dict.txt");

    int task, T;
    cin >> T;
    for (int task = 1; task <= T; task++)
    {
        cin >> S;
        memset(dp, 0xff, sizeof(dp));
        cout << "Case #" << task << ": " << solve(0, 4) << endl;
    }
    return 0;
}
