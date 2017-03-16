#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

string solve(string s){
    char c = 'A';
    if (s.length()==0) return "";
    string out;
    for(int i=0;i<s.size();i++) if ((s[i]-'A')>(c-'A')) c = s[i];
    int i=s.length()-1;
    while(s[i]!=c) i--;
    out = s[i]+solve(s.substr(0, i));
    i++;
    while(i<s.length()){
        out+=s[i];
        i++;
    }
    return out;
}


int main(){
	int T; cin>>T;
	for(int t=0;t<T;t++){
        string s; cin>>s;
        printf("Case #%d: ", t+1); cout<<solve(s)<<endl;
	}
}