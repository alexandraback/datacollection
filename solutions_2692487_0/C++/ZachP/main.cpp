#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX 100
#define test(a) cout << "TEST " << a << endl;
#define go(a,b) for(int a=0; a<b; a++)
#define case(a) fout << "Case #"<< a << ": " <<
using namespace std;


int total(int s, int n, vector<int> v){
    if(n==0){
        return 0;
    }
    if(s<=1){
        return n;
    }
    if(s>v[0]){
        s+=v[0];
        v.erase(v.begin());
        return total(s, n-1, v);
    }
    return min(n, total(2*s-1, n, v)+1);

}

int main()
{
    ofstream fout ("output.txt");
    ifstream fin ("input.txt");
    int cases, size, vsize, blah;
    vector<int> sizes(0,0);
    fin >> cases;
    for(int a=1; a<=cases; a++){
        sizes.resize(0);
        fin>>size;
        fin>>vsize;
        go(b, vsize){
            fin >> blah;
            sizes.push_back(blah);
        }
        sort(sizes.begin(), sizes.end());
        case(a) total(size, vsize, sizes) << endl;
    }
    return 0;
}
