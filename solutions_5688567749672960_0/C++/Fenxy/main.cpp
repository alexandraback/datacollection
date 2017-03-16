#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;


template<class T>
void printVec(vector<T> v){

    for(auto x : v)
    {
        cout << x << ' ';
    }
    cout << endl;
}

template<class T>
void print2DVec(vector<vector<T> > V){
    for(auto v : V){
        printVec<T> (v);
    }
}

ifstream fin("A-small-attempt3.in");
ofstream fout("in2.out");

unordered_map<int, int> Map;

int rev(int n){
    int ans = 0;
    while(n != 0){
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans;
}

int dfs(int n){
    if(Map.find(n) != Map.end()){
        return Map[n];
    }
    if(n <= 19){
        Map[n] = n;
        return n;
    }
    int t1 = 2147483647, t2 = t1;
    if(n % 10 != 0){
        int k = rev(n);
        if(k < n){
            t1 = dfs(k);
        }
    }
    t2 = dfs(n - 1);

    Map[n] = min(t2,t1) + 1;
    return Map[n];
}

int calc(){
    int n;
    fin >> n;
    dfs(n);
    return Map[n];


}

int main()
{

    int T;
    fin >> T;
    for(int C = 1; C <= T; ++C){
        fout << "Case #" << C << ": " << calc() << endl;
    }
    return 0;
}
