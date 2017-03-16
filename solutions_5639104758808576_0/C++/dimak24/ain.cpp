#include <iostream>
#include <string>
#include <fstream>

using namespace std; 

int main() {
    ofstream fout("qqq.txt");
    ifstream fin("A-small-attempt1.in");
    int t, s;
    fin >> t;
    string str;
    for(int j=0; j<t; j++) {
            fin >> s;
            fin >> str;
            int ans=0;
            int standing=0;
            for(int i=0; i<str.size(); i++) {
                    int n=(int)str[i]-48;
                    if(n>0 && i>standing) {
                           ans+=(i-standing);
                           standing+=(i-standing);
                           }
                    standing+=n;
                    }
    fout << "Case #" << j+1 << ": " << ans << "\n";
    }
    return 0;
}
                    
