#include <iostream>
#include <cstring>

using namespace std;

int getbit(int x)
{
    return 1<<x;
}

void dfs(int cur, bool visit[], int V, int dom[], int D, int curused)
{
    if(visit[cur]) return;
    if(cur>V) return;
    visit[cur] = true;
    for(int i=0; i<D; i++) {
        if((curused & getbit(i))) continue;
        dfs(cur+dom[i], visit, V, dom, D, (curused | getbit(i)));
    }
}

void update(bool visit[], int V, int d)
{
    bool *newvisit = new bool[V+1];
    memcpy(newvisit, visit, sizeof(bool)*(V+1));
    for(int i=1; i<=V; i++) {
        if(visit[i] && i+d <= V) {
            newvisit[i+d] = true;
        }
    }
    memcpy(visit, newvisit, sizeof(bool)*(V+1));
    delete[] newvisit;
}

int main()
{
    int T, Tcnt=1;
    cin>>T;
    for(; T; T--,Tcnt++) {
        int C, D, V;
        cin>>C>>D>>V;
        int *dom = new int[V+1];
        bool *visit = new bool[V+1];
        memset(visit, 0, sizeof(bool)*(V+1));
        for(int i=0; i<D; i++) {
            cin>>dom[i];
        }
        dfs(0, visit, V, dom, D, 0);
        int newD = D;
        for(int i=1; i<=V; i++) {
            if(visit[i]) {
                continue;
            } else {
                dom[newD++] = i;
                update(visit, V, i);
            }
        }
        cout<<"Case #"<<Tcnt<<": "<<newD-D<<endl;
    }
    return 0;
}

