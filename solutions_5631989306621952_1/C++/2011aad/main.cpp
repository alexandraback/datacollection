#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream infile("A-large.in");
    ofstream outfile("A-large.out");

    int T;
    string s, ss;

    infile>>T;
    for(int t=1;t<=T;t++){
        infile>>s;
        ss = s[0];
        for(int i=1;i<s.length();i++){
            if(s[i]>=ss[0]) ss = s[i] + ss;
            else ss = ss + s[i];
        }
        outfile<<"Case #"<<t<<": "<<ss<<endl;
    }

    infile.close();
    outfile.close();
    return 0;
}
