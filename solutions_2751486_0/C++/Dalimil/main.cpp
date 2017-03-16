#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool ok(string m, int k){
    int j = 0;
    for(int i=0;i<m.length();i++){
        if(m[i] != 'a' && m[i] != 'e' && m[i] != 'i' && m[i] != 'o' && m[i] != 'u'){
            j++;
        }
        else{
            j = 0;
        }
        if(j == k) return true;
    }
    return false;
}
int main(){
    ifstream in;
    ofstream out;
    out.open("vystup.out");
    in.open("vstup.in");
    int t;
    in >> t;
    for(int cas=1;cas<=t;cas++){
        string s;
        int n;
        in >> s;
        in >> n;
        long long num = 0;
        for(int i=0;i<s.length();i++){
            //cout << i << "i\n";
            for(int j=0;j<s.length()-i;j++){
                //cout << j << "j";
                //cout << s.substr(i, j+1) << "\n";
                if(ok(s.substr(i, j+1), n)){
                    num++;
                }
            }
        }
        out << "Case #" << cas << ": " << num << "\n";
    }
    in.close();
    return 0;
}
