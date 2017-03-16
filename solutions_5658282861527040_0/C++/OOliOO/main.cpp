#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <fstream>

#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#define ll long long
#define life false

using namespace std;

ifstream fin("in.txt");
ofstream fout("out.txt");

int main(){
    int t;
    fin>>t;
    for(int asdasd=0; asdasd<t; asdasd++){
        int A,B,K;
        fin>>A>>B>>K;
        int v=0;
        for(int i=0; i<A; i++)
            for(int e=0; e<B; e++)
                if((e&i)<K)
                    v++;
        fout<<"Case #"<<asdasd+1<<": "<<v<<endl;
    }
    return 0;
}
