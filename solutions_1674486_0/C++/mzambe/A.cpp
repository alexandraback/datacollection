#include <cstdio>
#include <cstdlib>
#define MAXN 2000
using namespace std;

struct treenode;
struct adjlist;

typedef struct adjlist * trlist;
typedef struct treenode Tree;

struct adjlist{
    Tree * node;
    trlist next;
};

struct treenode{
    int nodenum;
    int visit;
    bool back;
    trlist nodelist;
};

Tree mytree[MAXN];
int parent[MAXN];
bool answer;

int find(int u){
  return u == parent[u] ? u : parent[u] = find(parent[u]);
}

bool join(int u,int v){
    if ( find(u) == find(v) ){
        return true;
    }
    parent[u] = v;
    return false;
}

bool dfs(Tree * curnode, int vis){
    trlist p;
    for( p = curnode->nodelist; p != NULL; p = p->next ){
        curnode->back = true;
        //printf("\n from : %d, to : %d, withvisfr : %d, visto : %d \n", curnode->nodenum, p->node->nodenum, curnode->visit, p->node->visit);
        //if (p->next != NULL)
            //printf("\n comming : %d \n", p->next->node->nodenum);
            //
        if ( (p->node->visit == vis) && (!(p->node-> back)) ){
            //printf("\n @@@@: %d %d", p->node->nodenum, curnode->nodenum);
            return true;
        }
        if ( (p -> node -> visit != vis) ){
            p->node->visit = vis;
            if (dfs(p->node, vis))
                return true;
        }
    }

    curnode->back = false;
    return false;
}

void solve(){
    int N, M, from, to;
    trlist insrt = NULL;
    scanf("%d", &N);
    bool answer = false;
    for( int i = 1; i <= N; i++ ){
        mytree[i].nodenum = i;
        mytree[i].nodelist = NULL;
        mytree[i].visit = 0;
        mytree[i].back = false;
    }

    for( int i = 1; i <= N; i++ ){
        scanf("%d", &M);
        from = i;
        for( int j = 0; j < M; j++ ){
            scanf("%d", &to);
            insrt = (trlist) malloc(sizeof(struct adjlist));
            insrt->node = &(mytree[to]);
            insrt->next = mytree[from].nodelist;
            mytree[from].nodelist = insrt;
        }
    }

    for ( int i = 1; i <= N; i++ ){
        if ((mytree[i].visit == 0))
            answer = answer || dfs(&mytree[i], i);
        if (answer){
            //printf("\n%d\n", i);
            break;
        }
    }

    if (answer)
        printf("Yes");
    else
        printf("No");
}

int main(){
    int T;
    scanf("%d", &T);
    for( int i = 1; i <= T; i++ ){
        printf("Case #%d: ", i);
        solve();
        printf("\n");
    }
    return 0;
}
