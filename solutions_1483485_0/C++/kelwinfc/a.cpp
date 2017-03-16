#include <iostream>
#include <cstring>

using namespace std;

string inp[3] = { "ejp mysljylc kd kxveddknmc re jsicpdrysi",
                  "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                  "de kr kd eoya kw aej tysr re ujdr lkgc jv qz"};

string out[3] = { "our language is impossible to understand",
                  "there are twenty six factorial possibilities",
                  "so it is okay if you want to just give up zq"};

int main(){
    int abc[26];
    
    memset(abc,-1,sizeof abc);
    
    for (int i=0; i<3; i++){
        int n = inp[i].size();
        for (int k=0; k<n; k++){
            abc[ inp[i][k] - 'a' ] = out[i][k] - 'a';
        }
    }
    
    int T;
    cin >> T;
    
    string line;
    getline(cin, line);
    for (int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        
        string line;
        getline(cin, line);
        int n = line.size();
        for (int i=0; i<n; i++){
            if ( line[i] == ' '){
                cout << ' ';
            } else {
                cout << (char)(abc[ line[i] - 'a'] + 'a');
            }
        }
        cout << endl;
    }
    return 0;
}