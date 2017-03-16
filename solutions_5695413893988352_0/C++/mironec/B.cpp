#include <iostream>
#include <string>
#include <cmath>
#include <climits>

using namespace std;

long long int minDiff=LLONG_MAX;
long long int minC=0, minJ=0;
string minCs, minJs;

void inefficient(string C, string J){
    unsigned int qPos = C.find("?");
    if(qPos == string::npos){
        qPos = J.find("?");
        if(qPos == string::npos){
            long long int c = stoll(C);
            long long int j = stoll(J);
            if(abs(c-j)<minDiff){
                minDiff = abs(c-j);
                minC = c; minCs = string(C);
                minJ = j; minJs = string(J);
            }
            if(abs(c-j) == minDiff){
                if(c<minC){
                    minC=c; minCs = string(C);
                    minJ=j; minJs = string(J);
                }
                if(c==minC && j<minJ){
                    minJ=j; minJs = string(J);
                }
            }
        }
        else{
            for(int i=0;i<10;i++){
                string s(J);
                s[qPos] = '0'+i;
                inefficient(C,s);
            }
        }
    }
    
    else{
        for(int i=0;i<10;i++){
            string s(C);
            s[qPos] = '0'+i;
            inefficient(s,J);
        }
    }
}

void doStuff(int cas, string in){
    int spacePos = in.find(" ");
    string C = in.substr(0,spacePos);
    string J = in.substr(spacePos+1);
    
    minDiff=LLONG_MAX;
    minC=LLONG_MAX, minJ=LLONG_MAX;
    
    inefficient(C,J);
    
    cout << "Case #" << (cas) << ": ";
    
    cout << minCs << " " << minJs;
    
    cout << endl;
}

int main(){
    int T;
    string nothing;
    
    cin >> T;
    getline(cin, nothing);
    
    for(int i=0;i<T;i++){
        string in;
        
        getline(cin, in);
        
        doStuff(i+1, in);
    }
    
    return 0;
}