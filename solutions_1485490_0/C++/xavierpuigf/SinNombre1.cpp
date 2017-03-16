#include <iostream>
#include <vector>
#include <map>
#include <fstream>
using namespace std;
 vector <pair <long long, long long> > b;
  vector <pair <long long, long long> > t;
long long rec (int box, int toy){
    // cout <<box<<" "<<toy<<endl;
     if (toy == t.size() or box == b.size()) return 0LL;
     long long cont = 0LL;
     if (t[toy].second == b[box].second){
        long long f1 = t[toy].first;
        long long f2 = b[box].first;               
        if (t[toy].first >= b[box].first){
           t[toy].first-=f2;
           cont = max (cont, b[box].first + rec(box+1,toy));
           
           t[toy].first=f1;
           b[box].first = f2;
        }
         if (t[toy].first <= b[box].first){
           b[box].first -= t[toy].first;
           
           cont = max (cont, t[toy].first + rec(box,toy+1));
           t[toy].first=f1;
           b[box].first = f2;              
        }
     } 
     else cont = max(rec(box+1,toy),rec(box,toy+1));
    // for (int i = 0; i <b.size(); i++) cout <<b[i].first<<" "<<b[i].second<<", ";
    // cout <<endl;
    // for (int i = 0; i <t.size(); i++) cout <<t[i].first<<" "<<t[i].second<<", ";
    // cout <<endl;
    // cout <<box<<" "<<toy<<" "<<cont<<endl;
     return cont;
}
int main (){
    ifstream fin ("C-small.in");
    ofstream fout ("C-small.out");
    int T;
    fin >>T;
    for (int it = 1; it <= T; it++){
        int N,M;
        fin >>N>>M;
        b.clear();
        t.clear();
        b.resize(N);
        t.resize(M);
        vector <vector <long long> > maxim (N, vector <long long> (M, 0LL));
        for (int i = 0; i < N; i++)  fin >>b[i].first>>b[i].second;
        for (int i = 0; i < M; i++)  fin >>t[i].first>>t[i].second;
        fout <<"Case #"<<it<<": "<<rec(0,0)<<endl;
    }
}
