#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
using namespace std;

bool buscar(int vec[], string s){
//    cout << "buscar " << s << endl;
    int ant[200];
    for(int i = 0; i < 200; i++)
        ant[i] = vec[i];
    for(int i = 0; i < s.size(); i++){
        if(ant[s[i]] <= 0){
            return false;
        }
        else
            ant[s[i]]--;
    }
    for(int i = 0; i < s.size(); i++){
        vec[s[i]]--;
    }
    return true;
}

string solve(string s){
    string v[] = {"ZERO", "TWO", "SIX", "EIGHT", "THREE", "FOUR",
    "FIVE", "SEVEN", "ONE", "NINE"};
    /*(Z, 0), (2, W), (6, X), (8, G)
    (H, 3), (4, R), (5, F), (7, V), (o, 1), (N, 9)*/
    string t = "";
    int vec[200] = {0};
    for(int i = 0; i < s.size(); i++){
        vec[s[i]]++;
    }
    int resp[] = {0, 2, 6, 8, 3, 4, 5, 7, 1, 9};
    for(int i = 0; i < 10; i++){
        while(buscar(vec, v[i])){
            t+=char(resp[i]+'0');
        }
    }
    for(int i = 0; i < 200; i++)
        if(vec[i] > 0)
            while(true);
    sort(t.begin(), t.end());
    return t;
}

int main(){
    int casos;
    string s;
    cin >> casos;
    for(int i = 1; i <= casos; i++){
        cin >> s;
        printf("Case #%d: %s\n", i, solve(s).c_str());
    }
    return 0;
}
