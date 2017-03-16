#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <string>
#include <cstring>
#include <limits.h>

using namespace std;

#define push_back pb
#define fi first
#define se second
#define M_PI		3.14159265358979323846
#define forn(i, n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef long double ld;
typedef pair<int, double> pid;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;

ifstream fin("in.in");
ofstream fout("out.out");
template<class T>
void printVec(vector<T> v){
    for(auto x : v)
        cout << x << ' ';
    cout << endl;
}
template<class T>
void print2DVec(vector<vector<T> > V){
    for(auto v : V)
        printVec<T> (v);
}
struct cmp{
    bool operator () (const pid &p1, const pid &p2){
        return p1.second > p2.second;
    }
};

string Keys;
string Tar;
int tar_len;
int tL;

int max_ba;
int sum_ba;

int compute(const string &str,const string &tar){
    int sum=0;
    for(int i=0;i<=tar_len-tL;i++){
        bool ok=true;
        for(int j=0;j<tL;j++){
            if(str[j+i]!=tar[j]){
                ok=false;
                break;
            }
        }
        if(ok){sum++;}
    }
    return sum;
}
int dfs(int depth,int *arr){
    if(depth==tar_len){
        string tt="";
        for(int i=0;i<tar_len;i++){tt.pb(arr[i]);}
        int tmp = compute(tt, Tar);
        if(tmp>max_ba){max_ba=tmp;}
        sum_ba += tmp;
        return 1;
    }

    for(int i=0;i<Keys.size();i++){
        arr[depth]=Keys[i];
        dfs(depth+1,arr);
    }
}


ld solve(){
    sum_ba = max_ba = 0;
    int K,L,S;
    fin>>K>>L>>S;
    tar_len=S;
    tL=L;

    fin>>Keys;
    string target;
    fin>>target;
    Tar=target;

    int ty[10];
    for(int i=0;i<Keys.size();i++){
        ty[i]=Keys[i];
    }

    dfs(0,ty);
    double Br=max_ba;
    double Bc=sum_ba;
    Bc/=(double)pow((double)K,(double)S);
    return Br - Bc;
}

int main(){
    int T;
    fin >> T;
    for(int tc = 1;tc <= T; ++tc){
        fout << "Case #" << tc << ": " << solve() << endl;
    }
}
