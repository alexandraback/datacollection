#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;




enum Unit {
    ONE, I, J, K,
};

typedef pair<bool, Unit> Val;


Val mult(const Val & lhs, const Val & rhs) {
    static vector<vector<Val>> matrix = {
        { {true, ONE}, {true, I}, {true, J}, {true, K} },
        { {true, I}, {false, ONE}, {true, K}, {false, J} },
        { {true, J}, {false, K}, {false, ONE}, {true, I} },
        { {true, K}, {true, J}, {false, I}, {false, ONE} }
    };
    
    Val ret = matrix[lhs.second][rhs.second];
    bool flag = !(lhs.first ^ rhs.first);
    ret.first = !(flag ^ ret.first);
    
    return ret;
}

Val makeVal(char c) {
    if(c == 'i') {
        return make_pair(true, I);
    } else if(c == 'j') {
        return make_pair(true, J);
    } else if(c == 'k') {
        return make_pair(true, K);
    } else {
        return make_pair(true, ONE);
    }
}

string getValStr(const Val & v) {
    static vector<string> str = {"1", "i", "j", "k"};
    if(v.first){
        return str[v.second];
    } else {
        return "-" + str[v.second];
    }
}

bool preCheck(const vector<long> & count) {
    long sum = 0;
    for(auto & c : count) {
        sum += c;
    }
    
    if(sum < 3) {
        return false;
    }
    
    if(count[I] != 0 && count[J] != 0 && count[K] != 0) {
        return true;
    } else if((count[I] >= 2 && count[J] >= 2) || (count[I] >=2 && count[K] >= 2) || (count[J] >= 2 && count[K] >= 2)) {
        return true;
    } else {
        return false;
    }
}

bool checkI(const string & str, long X) {
    Val prod = makeVal('1');
    long L = str.size();
    
    for(long i=0; i<X; ++i) {
        for(long j=0; j<L; ++j) {
            char c = str[j];
            Val v = makeVal(c);
            prod = mult(prod, v);
            if(prod.second == I && prod.first == true) {
                return L*X - (i*X+j+1) >= 2;
            }
        }
    }
    
    return false;
}

bool checkVal(const string & str, long X, pair<long, long> & pos, Val target) {
    long & x = pos.first;
    long & i = pos.second;
    
    Val prod = makeVal('1');
    
    for(; i<str.size(); ++i) {
        Val v = makeVal(str[i]);
        prod = mult(prod, v);
        
        if(prod == target) {
            i++;
            return true;
        }
    }
    
    i=0;
    x++;
    
    for(; x<X; ++x) {
        for(i=0; i<str.size(); ++i) {
            Val v = makeVal(str[i]);
            prod = mult(prod, v);
            if(prod == target) {
                i++;
                return true;
            }
        }
    }
    
    return false;
}

Val calc(const string & str, long X, pair<long, long> & pos) {
    long & x = pos.first;
    long & i = pos.second;
    
    Val prod = makeVal('1');
    
    for(; i<str.size(); ++i) {
        Val v = makeVal(str[i]);
        prod = mult(prod, v);
    }
    
    i=0;
    x++;
    
    for(; x<X; ++x) {
        for(i=0; i<str.size(); ++i) {
            Val v = makeVal(str[i]);
            prod = mult(prod, v);
        }
    }
    
    return prod;
}

bool postCheck(const string & str, long X) {
    pair<long, long> pos(0, 0);
    
    if(checkVal(str, X, pos, makeVal('i'))) {
        if(checkVal(str, X, pos, makeVal('j'))) {
            if(checkVal(str, X, pos, makeVal('k'))) {
                return true;
            }
        }
    }
    
    return false;
    
}




int main(int argc, const char* argv[]){
    ifstream infile;
    long testcasenum;
    ofstream outfile;
   
    infile.open("C-large.in");
    outfile.open("C-large.out");
    
    infile >> testcasenum;
    for(long i=0; i< testcasenum; ++i) {
        long L=0, X=0;
        infile >> L>> X;
        char C = '1';
        
        Val prod = makeVal('1');
        vector<long> count(4, 0);
        string str(L, '1');
        
        for(long j=0; j<L; ++j) {
            infile >> C;
            Val v = makeVal(C);
            count[v.second]++;
            prod = mult(prod, v);
            
            str[j] = C;
        }
        
        //cout << "Prod #" << i+1 << ": " << getValStr(prod) << " " << X << endl;
        
        for(long & c : count) {
            c = c * X;
        }
        
        outfile << "Case #" << i+1 << ": " ;
        
        bool yes = false;
        
        if(preCheck(count)) {
            if(prod.second == ONE) {
                if(prod.first) {
                    yes = false;
                } else {
                    yes = (X % 2 == 1);
                }
            } else {
                if(X % 2 == 1) {
                    yes = false;
                } else {
                    long half = X/2;
                    yes = (half % 2 == 1);
                }
            }
        } else {
            yes = false;
        }
        
        if(yes) {
            yes = postCheck(str, X);
        }
        
        if(yes) {
            outfile << "YES";
        } else {
            outfile << "NO";
        }
        
        outfile << endl;
        
    }
    
    infile.close();
    outfile.close();
    return 0;
}


