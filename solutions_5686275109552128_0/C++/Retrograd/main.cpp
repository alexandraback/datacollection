#include<fstream>
#include<queue>
#include<vector>

using namespace std;
typedef int var;

ifstream fin("debug.in");
ofstream fout("debug.out");

var V[5000];
var n;
var MAXV;
priority_queue<var> Q;

bool good(var sol) {

    for(var total_steps = 0; total_steps <= MAXV; total_steps ++ ) {
        var target = sol - total_steps;
        Q = priority_queue<var>();


        for(var i=1; i<=n; i++) {
            Q.push(V[i]);
        }

        for(var step=1; step<=total_steps; step++) {
            var top = Q.top();
            Q.pop();
            Q.push(top - target);
        }

        if(Q.top() <= target)
            return true;
    }

    return false;
}

int main() {


    var t;
    fin>>t;

    for(var tt=1; tt<=t; tt++) {
        fin>>n;

        MAXV = -1;

        for(var i=1; i<=n; i++) {
            fin>>V[i];
            MAXV = max(MAXV, V[i]);
        }

        var sol = 0, i=1;

        for(; i <= MAXV; i <<= 1);
        for(i >>= 1; i; i >>= 1) {
            if(sol+i <= MAXV && !good(sol+i)) {
                sol += i;
            }
        }

        fout<<"Case #"<<tt<<": "<<sol+1<<'\n';

    }

    return 0;
}
