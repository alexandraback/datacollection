#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string.h>
#include <limits.h>

//#define MYDEBUG

#define REP(i, m, n) for (int i=(int)(m); i<(int)(n); ++i)

#ifdef MYDEBUG
#define p(_value) cout << "@" << #_value << ":" << _value << endl;
#define pv(_vec) { cout << "@" << #_vec << "--" << endl; REP(_vindex, 0, _vec.size()) cout << _vec[_vindex] << ", "; cout << endl; }
#else
#define p(_value) 
#define pv(_vec) 
#endif


using namespace std;

typedef vector<int> VI;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef unsigned long long ull;
typedef long long ll;

struct Trial{
    int k, m, s;
    string src, dst;
};

void ParseTrial(ifstream& ifs, Trial& t){    
    ifs >> t.k;
    ifs >> t.m;
    ifs >> t.s;
    ifs >> t.src;
    ifs >> t.dst;
}

set<char> SS;
string SRC;
string DST;
int S;
int ALL;
int NUM[10];

void solve(string s, string d){
    ALL++;

    p(s);
    
    int match=0;
    REP(i, 0, s.size()-DST.size()+1){
        string sub = s.substr(i, DST.size());
        if(sub.compare(DST) == 0){
            match++;
        }
    }
    
    NUM[match]++;
}

void dfs(int i, string& s){
    if(i==S){
        solve(s, DST);
        return;
    }

    for(char c : SRC){
        s.push_back(c);
        dfs(i+1, s);
        s.pop_back();
    }
}

string SolveTrial(const Trial& t){    
    int k=t.k, m=t.m, s=t.s;
    string src=t.src, dst=t.dst;
//    p(k);p(m);p(s);p(src);p(dst);

    S = s;
    SS = set<char>(src.begin(), src.end());
    DST = dst;
    SRC = src;
    ALL = 0;
    memset(NUM, 0, sizeof(NUM));

    string str;
    dfs(0, str);
    
    int ma=0;
    REP(i, 0, 10){
        if(NUM[i]>0)ma=max(ma, i);
    }

    p(ma);
    p(ALL);    

    double ex = 0;
    REP(i, 0, 10){
        if(NUM[i]==0) continue;
        p(NUM[i]);
        ex += (ma-i)*((double)NUM[i]/(double)ALL);
    }
    p(ex);
    return to_string(ex);
}

void ParseProblemFile(string inputFileName, vector<Trial>& trials){
    // Open input file.
    ifstream inputFileStream(inputFileName, ios::in);
    if(!inputFileStream){
        cerr << "can not open file (" << inputFileName << ")." << endl;
        exit(1);
    }

    // Read the number of test case.
    int testCaseNum;
    inputFileStream >> testCaseNum;

    // Read all the input
    REP(testCaseId, 0, testCaseNum){
        Trial t;
        ParseTrial(inputFileStream, t);
        trials.push_back(t);
    }
}

void OutputResult(ostream& out, int caseNum, string s){
    out << "Case #" << caseNum << ":" << " " << s << endl;
}

void OutputResult(vector<string> ans){
    int i=0;
    for(string s : ans){
        OutputResult(std::cout, ++i, s);
    }
}

int main(int argc, char** argv){
    string inputFileName;
    if(argc != 2){
        inputFileName = "as.in";
    }else{
        inputFileName = argv[1];
    }

    vector<Trial> trials;
    ParseProblemFile(inputFileName, trials);

    vector<string> ans;
    for(Trial t : trials){

        static int testCaseNum = 0;
        testCaseNum++;
        p(testCaseNum);

//        cout << "start: " << testCaseNum << endl;
        ans.push_back(SolveTrial(t));
    }
    
    OutputResult(ans);

    return 0;
}


