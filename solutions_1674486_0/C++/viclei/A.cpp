#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>

using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");


const int MAXN = 1050;
vector<int> vert[MAXN];
bool seen[MAXN];
bool dI;

void dfs(int n) {
    if( seen[n] ) {
        dI = true;
        return;
    }

    seen[n] = true;
    for( int i=0; i<vert[n].size(); i++ ) {
        dfs(vert[n][i]);
    }

}

void res() {
    dI = false;
    for( int i=0; i<MAXN; i++ ) { vert[i].clear(); seen[i]=false; }
}

int main() {
    int T;
    in >> T;
    for( int test=1; test<=T; test++ ) {
        int M, N;
        in >> N;
        res();
        for( int i=0; i<N; i++ ) {
            in >> M;
            for( int j=0; j<M; j++ ) {
                int temp;
                in >> temp;
                vert[i].push_back(temp-1);
            }
        }

        out << "Case #" << test << ": ";

        for( int a=0; a<N; a++ ) {
            //starting point
            dfs(a);
            if( dI ) {
                out << "Yes" << endl;
                break;
            }
            else {
                dI = false;
                for( int i=0; i<MAXN; i++ ) seen[i] = false;
            }
        }

        if(!dI) out << "No" << endl;

    }

    return 0;
}
