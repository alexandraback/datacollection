#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

#define FOR(i, A, B) for(int i=(A); i<(B); i++)
#define REP(i, N) for(int i=0; i<(N); i++)
#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort(ALL(v))
#define MP make_pair
#define PB push_back
#define VI vector<int>
#define VS vector<string>
#define PII pair<int, int>
#define X first
#define Y second

int aabs(int a) { return (a<0)?-a:a; }
int mmax(int a, int b) { return (a>b)?a:b; }
int mmin(int a, int b) { return (a<b)?a:b; }

#define INF 1000000000

vector<string> dic;
vector<string> words[20];
string S;

int mem[51][5];

int mycompare(int iS, int idic, int cant) {
    for(int i=0; i<cant; i++) {
        if(S[iS+i] < dic[idic][i]) return -1;
        if(S[iS+i] > dic[idic][i]) return 1;
    }
    return 0;
}

int go(int idx, int rights) {
    if(idx == SZ(S)) return 0;
    int & aux = mem[idx][rights];
    if(aux < 0) {
        //cout << idx << " " << rights << endl;
        //cout << S.substr(idx) << endl;
        int fst = 0, lst = SZ(dic)-1;
        /*
        if(rights > 0) {
            int a=0, b=SZ(dic)-1;
            //cout << "start1\n";
            while(a < b) {
                int x = (a+b)/2;
                if(mycompare(idx, x, mmin(SZ(S)-idx, mmin(rights, SZ(dic[x])))) < 1) {
                    b = x;
                } else {
                    a = x+1;
                }
            }
            //cout << "end1\n";
            fst = a;
            
            a=0, b=SZ(dic)-1;
            //cout << "start2\n";
            while(a < b) {
                //cout << a << " " << b << endl;
                int x = (a+b)/2;
                if(mycompare(idx, x, mmin(SZ(S)-idx, mmin(rights, SZ(dic[x])))) > -1) {
                    a = x+1;
                } else {
                    b = x;
                }
            }
            //cout << "end2\n";
            lst = a-1;
        }
        */
        aux = INF;
        //cout << "indexes " << fst << " " << lst << endl;
        //cout << "words " << dic[fst] << " " << dic[lst] << endl;
        //FOR(id, mmax(fst-10, 0), mmin(lst+10, SZ(dic))) {
        FOR(id, fst, lst+1) {
            //if(idx >= 40) cout << fst << " " << dic[id] << endl;
            
            if(SZ(dic[id]) > SZ(S)-idx) continue;
            int err = -1, count = 0;
            bool ok = true;
            REP(i, SZ(dic[id])) {
                if(dic[id][i] != S[idx+i]) {
                    if(i < rights) {
                        ok = false;
                        break;
                    }
                    if(err >=0 and i-err < 5) {
                        ok = false;
                        break;
                    }
                    
                    err = i;
                    count++;
                }
            }
            
            if(ok) {
                if(count > 0) {
                    aux = mmin(aux, count + go(idx+SZ(dic[id]), mmax(0, 4-(SZ(dic[id])-err-1))));
                } else {
                    aux = mmin(aux, go(idx+SZ(dic[id]), mmax(rights-SZ(dic[id]), 0)));
                }
            }
        }
        
    }
    return aux;
}


int main()
{   
    ifstream dicf;
    dicf.open("garbled_email_dictionary.txt");
    
    string auxs;
    while(dicf >> auxs) {
        dic.PB(auxs);
        words[auxs.size()].PB(auxs);
    }
    
    SORT(dic);
    
    int T = 0;
    cin >> T;
    REP(caso, T) {
        cin >> S;
        memset(mem, -1, sizeof(mem));
        cout << "Case #" << caso+1 << ": " << go(0, 0) << endl;
    }
}
