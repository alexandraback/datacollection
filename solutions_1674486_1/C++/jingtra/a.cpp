#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool bfs(int start, vector<vector<int> >& graph){
    queue<int> q;
    q.push(start);
    vector<int> ways(graph.size(), 0);
    ways[start]=1;
    while(!q.empty()){
        int top = q.front();
        q.pop();

        for(int i=0; i<graph[top].size(); ++i){
            int next = graph[top][i];
            if(++ways[next]==2) 
                return true;
            q.push(next);
        }
    }
    return false;


}

int main(){
    int T; cin >> T;
    for(int t=0; t<T; ++t){
        int N; cin >> N;
        vector<vector<int> > graph(N, vector<int>(0,0));
        for(int i=0; i<N; ++i){
            int m; cin >> m;
            for(int j=0; j<m; ++j){
                int x; cin >> x;
                graph[i].push_back(x-1);
            }

        }

        bool found= false;
        for(int i=0; i<N&&!found; ++i){
            if(bfs(i, graph)){
                cout << "Case #" << t+1 << ": Yes" << endl;
                found =true;
            }

        }
        if(!found) 
            cout << "Case #" << t+1 << ": No" << endl;

    }

}
