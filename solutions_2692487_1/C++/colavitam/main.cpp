#include <iostream>
#include <fstream>

using namespace std;

int minval = 0;
void candreset() {
    minval = 2147483647;
}

void cand(int value) {
    if(value<minval)
        minval=value;
}

int retcand() {
    return minval;
}

int main() {
    ifstream in("p1.in");
    ofstream out("p1.out");
    int T;
    in>>T;
    for(int cases=1;cases<=T;cases++) {
        candreset();
        int arminMote,N;
        in>>arminMote>>N;
        int otherMotes[100];
        int minOps=0;
        for(int i=0;i<N;i++)
            in>>otherMotes[i];
        sort(&otherMotes[0],&otherMotes[N]);
        int start = 0;
        int incs = 0;
        while(incs<retcand()) {
            while(otherMotes[start]<arminMote && start<N) {
                arminMote+=otherMotes[start++];
            }
            cand(N-start+incs);
            arminMote+=arminMote-1;
            incs++;
        }
        out<<"Case #"<<cases<<": "<<retcand()<<"\n";
    }
}