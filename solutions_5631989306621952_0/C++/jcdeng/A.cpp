
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int main(int argc, const char * argv[]) {
        ofstream ofs;
        ifstream ifs;
        ofs.open("/Users/dengjc/Desktop/A-large");
        ifs.open("/Users/dengjc/Desktop/A-large.in");
        if (!ofs.is_open()||!ifs.is_open()) {
            cout<<"打开文件出错"<<endl;
            return 1;
        }
    
    int T;
    ifs>>T;
//    cin>>T;
    
    for (int i=1; i<=T; i++) {
        
        
        string s;
        ifs>>s;
        string result = string("")+s[0];
        size_t len = s.length();
        for(int j=1;j<len;j++)
        {
            if (s[j]>=result[0]) {
                result = s[j] + result;
            } else {
                result = result + s[j];
            }
        }
        ofs<<"Case #"<<i<<": "<<0<<endl;
//        cout<<"Case #"<<i<<": "<<result<<endl;
    }
    
    
}
