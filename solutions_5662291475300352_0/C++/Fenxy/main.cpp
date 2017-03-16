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

ifstream fin("C-small-1-attempt0.in");
ofstream fout("out1.out");

int ans;
int n, m, k;
double d1, d2;
double s1, s2;

int calc(){

    fin >> n;
    if(n == 2){
        fin >> d1 >> k >> s1;
        fin >> d2 >> k >> s2;
    }
    else{
        fin >> d1 >> k >> s1;
        if(k == 2)
            n = 2, s2 = s1 + 1;
    }
    if(n == 1){
        return 0;
    }
    int t1 = 0 , t2 = 0;
    if(s1/s2 > 2 - d2 / 360 || s1/s2 < 1 - d2 / 360){
        t1 = 1;
    }
    if(s2/s1 > 2 - d1/360 || s2/ s2 < 1 - d1 /  360){
        t2 = 1;
    }

    return max(t1, t2);
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
