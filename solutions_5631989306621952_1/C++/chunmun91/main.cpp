#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

int main(){

    int T;
    ifstream din;
    ofstream dout;

    din.open("A-large.in", ifstream::in);
    dout.open("A-large.out", ofstream::out);

    din>>T;
    din.ignore();
    cout<<T<<endl;
    for(int t=0; t<T; t++){
        string s;
        din>>s;
        din.ignore();
        string out;
        out += s[0];
        for(int j=1; j<s.length(); j++){
            string after = out+s[j];
            string temp;
            temp += s[j];
            string before = temp+out;
            if(after > before)
                out = after;
            else
                out = before;
        }
        dout<<"Case #"<<(t+1)<<": "<<out<<endl;
    }

    din.close();
    dout.close();
    return 0;
}
