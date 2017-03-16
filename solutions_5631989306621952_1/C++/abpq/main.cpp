#include <cstdio>
#include <list>
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
    ofstream output;
    ifstream fcin;
    fcin.open("in.in");
    output.open("outout.out");
    string s;
    list<char> c;
    int T;
    long len;
    char temp;
    fcin>>T;
    for(int i=0;i<T;i++){
        fcin>>s;
        len=s.length();
        temp=s[0];
        for(int j=0;j<len;j++){
            if(s[j]>=temp){
                c.push_front(s[j]);
                temp=s[j];
            }
            else{
                c.push_back(s[j]);
            }
        }
        list<char>::iterator it;
        output<<"Case #"<<i+1<<": ";
        for(it=c.begin();it!=c.end();it++){
            output<<*it;
        }
        output<<"\n";
        c.clear();
    }
    return 0;
}
