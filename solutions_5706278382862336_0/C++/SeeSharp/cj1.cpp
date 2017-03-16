#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        string str = "";
        int p,q;
        int num = 0;
        _if >> str;
        string str1,str2;

        for(int j=0;j<str.length();j++){
            if(str[j]=='/'){
                str1 = str.substr(0,j);
                str2 = str.substr(j+1);
            }
        }
        p=atoi(str1.c_str());
        q=atoi(str2.c_str());
        cout << p << " - " << q << endl;

        if(floor(log2(q)) != log2(q))
        {
            _of << "Case #" << i+1 << ": impossible" << endl;
            continue;
        }
        for(int j=0;;j++){
            p*=2;
            if(p>=q){
                num = j+1;
                break;
            }
        }
        _of << "Case #" << i+1 << ": " << num << endl;
    }
}
