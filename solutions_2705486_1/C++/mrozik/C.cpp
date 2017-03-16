#include <iostream>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

static const int DSIZE = 521196;
// string D[DSIZE];
vector<string> D;

int CHP0[] = { -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4 };
int CHP1[] = { -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1, 5, 6, 7, 8, 9 ,6, 7, 8, 9, 7, 8, 9, 8, 9, 9 };

void readDict() {
    assert(sizeof(CHP0)==sizeof(CHP1));
    
    ifstream f("garbled_email_dictionary.txt");
    for (int j=0; j<DSIZE; j++) {
        string s; f>>s;
        assert(s.length()<=10);
        
        for (int i=0; i<int(sizeof(CHP0)/sizeof(CHP0[0])); i++) {
            string ss = s;
            if (CHP1[i]>=int(s.length())) continue;
            if (CHP0[i]!=-1) ss[CHP0[i]]='_';
            if (CHP1[i]!=-1) ss[CHP1[i]]='_';
            D.push_back(ss);
        }
    }
    sort(D.begin(), D.end());
//     cout<<D.size()<<endl;
    D.erase(unique(D.begin(), D.end()), D.end());
//     cout<<D.size()<<endl;
}


bool exists(const string& s) {
    return binary_search(D.begin(), D.end(), s);
}


string S;;
int L;
int X[4096][16];

int main() {
    
    readDict();
    assert(exists("zymuznh"));
    
    int T; cin>>T;
    for (int t=1; t<=T; t++) {
        cin>>S;
        L = S.length();
        
        for (int ix=1; ix<=L; ix++)
            for (int w=0; w<=5; w++)
                X[ix][w]=0x7fffffff;
        for (int w=0; w<=5; w++)
            X[0][w]=0;
        
        for (int ix=0; ix<L; ix++) {
            for (int w=0; w<=5; w++) {
                if (X[ix][w]==0x7fffffff)
                    continue;
                
                for (int len=1; len<=10 && ix+len<=L; len++) {
                    string str = S.substr(ix, len);
                    
                    for (int i=0; i<int(sizeof(CHP0)/sizeof(CHP0[0])); i++) {
                        if (CHP1[i]>=len) continue;
                        if (CHP0[i]!=-1 && CHP0[i]+w<5)
                            continue;
                        string ss = str;
                        if (CHP0[i]!=-1) ss[CHP0[i]]='_';
                        if (CHP1[i]!=-1) ss[CHP1[i]]='_';
                        
//                         cout<<ss<<"?"<<endl;
                        if (!exists(ss))
                            continue;
                        
//                         cout<<ss<<endl;
                        
                        int lastChg = w+len;
                        if (CHP0[i]!=-1 && CHP1[i]==-1) lastChg = len-CHP0[i];
                        else if (CHP0[i]!=-1 && CHP1[i]!=-1) lastChg = len-CHP1[i];
                        lastChg = min(5, lastChg);
                        int newscore = X[ix][w] + int(CHP0[i]!=-1) + int(CHP1[i]!=-1);
//                         for (; lastChg<=5; lastChg++)
                            X[ix+len][lastChg] = min(X[ix+len][lastChg], newscore);
                    }
                }
            }
        }
        
        int result = 0x7fffffff;
        for (int w=0; w<=5; w++)
            result = min(result, X[L][w]);
        
        cout<<"Case #"<<t<<": "<<result<<endl;
    }
    
    return 0;
}
