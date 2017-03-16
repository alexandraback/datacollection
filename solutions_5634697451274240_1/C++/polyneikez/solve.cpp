#include<bits\stdc++.h>

int solve(std::string str);

using namespace std;

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        string str;
        int ret;
        
        cin >> str;
        ret = solve(str);
        
        if (ret == -1){
            cout << "Case #" << i + 1 << ": " << "INSOMNIA" << endl;        
        }else{
            cout << "Case #" << i + 1 << ": " << ret << endl;
        }
    }
}

int solve( string str ){
    int l = str.length();
    
    int count = 0;
    char cur = '+';
    for (int i = l - 1; i >= 0; i--){
        if (str[i] != cur){
            count = count + 1;
            if (cur == '+'){
                cur = '-';
            }else{
                cur = '+';
            }
        } 
    }
    
    return count;
}