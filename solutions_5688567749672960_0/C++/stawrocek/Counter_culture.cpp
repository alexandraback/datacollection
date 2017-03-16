#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

vector<vector<int> > v;
bool visited[1000005];

string int2String(int x){
    stringstream ss;
    ss << x;
    return ss.str();
}

int string2Int(string s){
    return atoi(s.c_str());
}

int _reverse(int x){
    string str = int2String(x);
    reverse(str.begin(), str.end());
    bool notZero = false;
    string result="";
    for(int i = 0; i < str.size(); i++){
        if(str[i] != '0'){
            notZero=true;
        }
        if(notZero)result+=str[i];
    }
    return string2Int(result);
}

void createConnections(){
    v.resize(1000001);
    for(int i = 1; i < 1000000; i++){
        v[i].push_back(i+1);
        v[i].push_back(_reverse(i));
    }
    v[1000000].push_back(1);
}

int policz(int n){
    for(int i = 1; i <= 1000000; i++){
        visited[i]=false;
    }
    queue<pair<int, int> > Q;
    Q.push(make_pair(1,1));
    visited[1]=true;
    int result = 10000000;
    while(!Q.empty()){
        int top = Q.front().first;
        int dist = Q.front().second;
        Q.pop();
        //cout << top << " " << dist << "\n";
        if(top==n){
            result = min(result, dist);
        }

        for(int i = 0; i < v[top].size(); i++){
            if(!visited[v[top][i]] && v[top][i] != i){
                Q.push(make_pair(v[top][i], dist+1));
                visited[v[top][i]]=true;
            }
        }
    }
    return result;
}

int main(){
    //ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    createConnections();
    //cout << "elo\n";
    for(int _q = 0; _q < t; _q++){
        int n;
        cin >> n;
        int wynik = policz(n);
        cout << "Case #" << _q + 1 << ": " << wynik << "\n";
    }
}

