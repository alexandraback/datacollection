#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;

int map[2008][2008],vis[2008],link[2008];
int nodecount;

int find(int x)
{
    int i;
    for(i=1;i<nodecount;i++)
    {
        if(map[x][i]&&!vis[i])//x->i有边,且节点i未被搜索
        {
            vis[i]=1;//标记节点已被搜索
            //如果i不属于前一个匹配M或被i匹配到的节点可以寻找到增广路
            if(link[i]==0||find(link[i]))
            {
                link[i]=x;//更新
                return 1;//匹配成功
            }
        }        
    }
    return 0;
}

void work() {
    string s1, s2;
    int n;
    scanf("%d", &n);
    vector<pair<string, string> > topic;
    unordered_map<string, int> nodemap1, nodemap2;
    nodecount = 1;
    set<string> firstset, secondset;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2;
        firstset.insert(s1);
        secondset.insert(s2);
        topic.push_back(make_pair(s1, s2));
    }
    for (auto &x: firstset) {
        nodemap1[x] = nodecount++;
    }
    for (auto &x: secondset) {
        nodemap2[x] = nodecount++;
    }
    memset(map, 0, sizeof map);
    memset(link, 0, sizeof link);
    for (int i = 0; i < n; i++) {
        map[nodemap1[topic[i].first]][nodemap2[topic[i].second]] = 1;
    }
    int s = 0;
    for(int i=1;i<nodecount;i++)
    {
        memset(vis,0,sizeof(vis));
        if(find(i))
            s++;
    }
    printf("%d\n", n - (firstset.size() + secondset.size() - s));
}



int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        work();
    }
}