#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <fstream>
//#include <iostream>
//#include <vector>
//#include <set>
//#include <queue>
//#include <climits>
#include <sstream>
#include <ctime>
#include <stdlib.h>
#include <ctype.h>
#include <algorithm>
using namespace std;

struct Node {
    int match, deg, id;
    set<int> adj;

    bool operator<(const Node& rhs) const
    {
        if(deg == rhs.deg)
            return id > rhs.id;
        else
            return deg > rhs.deg;
    }
};

bool bfs(vector<Node>& U, vector<Node>& V, vector<int>& dist) {
    queue<int> Q;
    for(unsigned int i = 1; i < U.size(); i++) {
        if(U[i].match == 0) {
            dist[i] = 0;
            Q.push(i);
        } else {
            dist[i] = INT_MAX;
        }
    }
    dist[0] = INT_MAX;
    while(!Q.empty()) {
        int i = Q.front();
        Q.pop();
        if(dist[i] < dist[0]) {
            for(const int &j : U[i].adj) {
                if(dist[V[j].match] == INT_MAX) {
                    dist[V[j].match] = dist[i] + 1;
                    Q.push(V[j].match);
                }
            }
        }
    }
    return dist[0] != INT_MAX;
}

bool dfs(vector<Node>& U, vector<Node>& V, vector<int>& dist, int i) {
    if(i != 0) {
        for(const int &j : U[i].adj) {
            if(dist[V[j].match] == dist[i] + 1) {
                if(dfs(U, V, dist, V[j].match)) {
                    V[j].match = i;
                    U[i].match = j;
                    return true;
                }
            }
        }
        dist[i] = INT_MAX;
        return false;
    }
    return true;
}

int hopcroft_karp(vector<Node>& U, vector<Node>& V, vector<int>& dist) {
    int matching = 0;
    while(bfs(U, V, dist)) {
        for(unsigned int i = 1; i < U.size(); i++) {
            if(U[i].match == 0) {
                if(dfs(U, V, dist, i)) {
                    matching++;
                }
            }
        }
    }
    return matching;
}


int main()
{
    freopen("in.in","r",stdin);
    freopen("out4.txt","w",stdout);
    int T, cnt = 0;
    cin >> T;
    for(int g = 0; g < T; g++){
        //cout << "Readin" << endl;
        int n;
        cnt++;
        cin >> n;
        vector<Node> U(1), V(1);
        vector<int> dist(n + 1, INT_MAX);
        map<string, int> indexfir;
        map<string, int> indexsec;
        vector<pair<string,string> > words (n);
        int indexf = 1, indexs = 1;
        for(int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            words[i] = make_pair(a,b);
            //cout << a << " " << b << endl;
            if(indexfir[a] == 0) {
                U.push_back({0, 0, 0, set<int>()});
                indexfir[a] = indexf++;
            }
            if(indexsec[b] == 0){
                V.push_back({0, 0, 0, set<int>()});
                indexsec[b] = indexs++;
            }
            U[indexfir[a]].adj.insert(indexsec[b]);
            //cout << "one" << endl;
            U[indexfir[a]].deg = U[indexfir[a]].adj.size();
            //cout << "two" << endl;
            U[indexfir[a]].id = indexfir[a];
            //cout << "three" << endl;
            V[indexsec[b]].adj.insert(indexfir[a]);
        }
        vector<bool> done (n+1,0);
        //cout << "hopcrofting" << endl;
        //cout << "HEAD" << endl;
        int v = hopcroft_karp(U,V,dist);
        map<string,int> newfir;
        map<string,int> newsec;
        vector<bool> seen (words.size());
        int counter = 0;
        for(int i = 0; i < words.size(); i++){
            string a = words[i].first, b = words[i].second;
            if(U[indexfir[a]].match == indexsec[b]){
                newfir[a]++;
                newsec[b]++;
                seen[i] = true;
            }
        }
        for(int i = 0; i < words.size(); i++){
            string a = words[i].first, b = words[i].second;
            if(!seen[i]){
                if(newfir[a] && newsec[b]) counter++;
                newfir[a]++;
                newsec[b]++;
            }
        }
        cout << "Case #" << cnt << ": ";
        cout << counter << endl;
    }
    /*
    int T, cnt = 0;
    cin >> T;
    while(T--){
        cnt++;
        int N;
        cin >> N;
        vector<pair<string, string> > titles(N);
        map<string,int> fir;
        map<string,int> sec;
        int counter = 0;
        for(int i = 0 ; i < N; i++){
            string a, b;
            cin >> a >> b;
            fir[a]++;
            sec[b]++;
            titles[i] = make_pair(a,b);
            //cout << fir[a] << " " << sec[b]<< " " << a<< " " << b << endl;
        }
        vector<pair<string, string> > worst;
        vector<bool> seen (N);
        for(int i = 0; i < N; i++){
            if(fir[titles[i].first] == 1 || sec[titles[i].second] == 1){
                worst.push_back(titles[i]);
                counter++;
                seen[i] = true;
            }
        }
        //cout << "yo" << endl;
        while(worst.size() != N){
            //cout << worst.size() << endl;
            int maxi = 0, besti = 0;
            bool left = true;
            for(int i = 0; i < N; i++){
                if(!seen[i]){
                    int k = fir[titles[i].first] + sec[titles[i].second];
                    if(maxi < k){
                        maxi = k;
                        besti = i;
                    }
                }
            }
            seen[besti];
            worst.push_back(titles[besti]);
        }
        //cout << "hey" << endl;
        map<string,int> newfir;
        map<string,int> newsec;
        counter = 0;
        for(int i = 0; i < N; i++){
            string a = worst[i].first, b = worst[i].second;
            if(newfir[a] && newsec[b]) counter++;
            newfir[a]++;
            newsec[b]++;
        }
        cout << "Case #" << cnt << ": ";
        cout << counter << endl;
    }
    */
    return 0;
}
