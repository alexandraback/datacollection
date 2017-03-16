#include<bits/stdc++.h>
using namespace std;
ofstream out("Bout.txt");
ifstream in("B-large.in");
int main(){
    int T;
    in >> T;
    cout << T;
    for(int cas = 1; cas <= T; cas ++){
        cout << cas << endl;
        string line;
        in >> line;
        //cout << line << endl;
        char last = line[0];
        int x = 0;
        for(int i = 1; i < line.size(); i ++){
            if(line[i]!=last){
                //cout << i << endl;
                last=line[i];
                x++;
            }
        }
        if(line[line.size()-1]=='-') x++;
        out << "Case #"<<cas<<": " <<x<<endl;
    }
}
