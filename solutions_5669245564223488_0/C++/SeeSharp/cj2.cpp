#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

string removeNeighbour(string str){
    for(int i=0;i<str.length() - 1;i++){
        if(str[i] == str[i+1]){
            str.erase (str.begin()+i);
            i--;
        }
    }
    return str;
}

bool check(string str){
    for(int i=0;i<str.length();i++){
        for(int j=i+1;j<str.length();j++){
            if(str[i] == str[j] && str[i] != str[j-1]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    ifstream _if("in.txt");
    ofstream _of("out.txt");
    int n;
    _if >> n;
    for(int i=0;i < n; i++){
        int num = 0;
        int x;
        _if >> x;
        string str[x];
        for(int j=0;j<x;j++){
            _if >> str[j];
            str[j] = removeNeighbour(str[j]);
        }

        bool flag = false;
        for(int j=0;j<x && !flag;j++){
            int lngth = str[j].length();
            for(int k=1;k<lngth-1 && !flag;k++)
            {
                if(str[j][k]!=str[j][0] && str[j][k]!=str[j][lngth-1]){
                    for(int l=0;l<x && !flag;l++){
                        if(l==j) continue;
                        for(int e=0;e<str[l].length() && !flag;e++){
                            if(str[j][k] == str[l][e]){
                                flag = true;
                            }
                        }
                    }
                }
            }
        }
        if(flag){
            _of << "Case #" << i+1 << ": 0" << endl;
            continue;
        }

        int idx[x];
        for(int j=0;j<x;j++) idx[j]=j;
        do{
            string _str = "";
            for(int j=0;j<x;j++){
                _str+=str[idx[j]];
            }
            if(check(_str)) num++;
        }while ( next_permutation(idx,idx+x) );


        _of << "Case #" << i+1 << ": " << num << endl;
        cout << "Case #" << i+1 << ": " << num << endl;
    }
}
