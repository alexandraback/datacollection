//Catch me if you can!
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<deque>
#include<string>
#include<cctype>
#include<cmath>
#include<string>
#include<sstream>
#include<numeric>
#include<complex>
#include<queue>
using namespace std;

#define big long long
#define EPS 1e-9
#define s(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

const int SIZE = 2000;

int N;
double arr[2][SIZE];
bool vis[SIZE];

int solveWar(){
    int wars = 0;
    memset(vis, 0, sizeof vis);
    for(int i = 0 ; i < N ; i++){
        int j;
        for(j = 0 ; j < N ; j++)
            if(!vis[j] && arr[1][j] > arr[0][i])
                break;
        if(j < N)
            vis[j] = true;
        else
            wars++;
    }
    return wars;
}

int solveDWar(){
    int wars = 0;
    deque<double> deq;
    for(int i = 0 ; i < N ; i++)
        deq.push_back(arr[1][i]);
    
    for(int i = 0 ; i < N ; i++){
        if(arr[0][i] > deq.front()){
            wars++;
            deq.pop_front();
        } else {
            deq.pop_back();
        }
    }
    return wars;
}


int main() {
    
    //freopen("/Users/hibrahim/workspace/contest/app/1.in", "rt", stdin);
    //freopen("/Users/hibrahim/Downloads/D-small-attempt0.in", "rt", stdin);
    freopen("/Users/hibrahim/Downloads/D-large.in", "rt", stdin);
    freopen("/Users/hibrahim/workspace/contest/app/app/1.out", "wt", stdout);
    
    int tt; cin >> tt;
    for(int t = 1 ; t <= tt ; t++){
        
        cin >> N;
        cerr << t << " " << N << endl;
        
        for(int i = 0 ; i < 2 ; i++){
            for(int j = 0 ; j < N ; j++)
                cin >> arr[i][j];
            sort(arr[i], arr[i]+N);

            for(int j = 0 ; j < N ; j++)
                cerr << arr[i][j] << " ";
            cerr << endl;
        }
        
        cout << "Case #" << t << ": " << solveDWar() << " " << solveWar() << endl;
    }
    
    return 0;
}

