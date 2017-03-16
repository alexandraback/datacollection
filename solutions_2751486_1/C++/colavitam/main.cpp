#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
bool isCon(char c) {
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return false;
    return true;
}
int main() {
    ifstream in("str.in");
    ofstream out("str.out");
    int T;
    in>>T;
    for(int cases=1;cases<=T;cases++) {
        long long found=-1;
        string st;
        in>>st;
        int nval;
        in>>nval;
        int enc=0;
        long long total=0;
        for(int i=0;i<st.length();i++) {
            if(isCon(st.at(i)))
                enc++;
            else
                enc=0;
            if(enc>nval)
                enc=nval;
            if(enc==nval) {
                long long before=i-enc+2;
                long long after=(int)st.length()-i;
                total+=before*after;
                total-=(long long)(found+1)*after;
                found=i-enc+1;
            }
        }
        out<<"Case #"<<cases<<": "<<total<<"\n";
    }
    out.close();
    return 0;
}