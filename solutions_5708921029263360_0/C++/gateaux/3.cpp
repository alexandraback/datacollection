#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<string>
#include<cmath>
#include<climits>
#include<fstream>
#include<sstream>

#define forn(i,n) for(int i=0;i<n;i++)
#define forv(it,v,type) for(vector<type>::iterator it=v.begin();it!=v.end();it++)

using namespace std;
ifstream fin ("C-small-attempt0.in");
ofstream fout ("output.out");

struct triple {
int j;
int p;
int s;
triple(int a,int b,int c):j(a),p(b),s(c) {}
};
typedef struct triple triple;
long solve(int J,int P,int S,int K){
vector<triple> combi;
int js[10][10]={{0}};
int jp[10][10]={{0}};
int ps[10][10]={{0}};
forn(i,J){
    forn(l,P){
        forn(h,S){
            if(js[i][h]<K&&jp[i][l]<K&&ps[l][h]<K){
                combi.push_back({i,l,h});
                js[i][h]++;
                jp[i][l]++;
                ps[l][h]++;
            }
        }
    }
}
fout << combi.size() << endl;
for(vector<triple>::iterator it=combi.begin();it!=combi.end();it++){
    fout << (it->j) + 1 << " " << (it->p) + 1 << " " << (it->s) + 1 << endl;
}
}
int main(){
int T;
fin >> T;
forn(i,T){
int J,P,K,S;
fin >> J >> P >> S >> K;
fout << "Case #" << i+1 << ": ";
solve(J,P,S,K);
}
}
