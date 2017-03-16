#include<iostream>
#include<fstream>
#include<string>
#include<deque>
using namespace std;

int main () {
    ifstream inp;
    ofstream outp;
    inp.open("ai.txt");
    outp.open ("ao.txt");
    int T;
    string S;
    deque<char> ans;
    inp>>T;
    for(int i=1;i<=T;i++){
        inp>>S;
        ans.clear();
        outp<<"Case #"<<i<<": ";
        ans.push_back(S[0]);
        for(int j=1;j<=S.size()-1;j++){
            if(S[j]>=ans.front()){
                ans.push_front(S[j]);
            }
            else{
                ans.push_back(S[j]);
            }
        }
        for(int j=0;j<=S.size()-1;j++){
            outp<<ans[j];
        }
        outp<<endl;
    }
    return 0;
}

