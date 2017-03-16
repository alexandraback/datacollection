#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

queue< pair<string,int> > q;
unordered_map<string, bool> m;

string flip(string a, int b){

    string res = "";
    for (int i = b; i >= 0; i--){
        if ( a[i] == '+')
            res += '-';
        else 
            res += '+';
    }
    for (int i = b+1; i < a.size(); i++){
        res += a[i];
    }
    return res;
}

int check(string str){

    m.clear();
    while(!q.empty())
        q.pop();
    q.push(make_pair(str,0));
    while (!q.empty()){
        pair<string,int> current = q.front();
        q.pop();
        string currentStr = current.first;
        int currentFlip = current.second;
        if ( m.find(currentStr) != m.end())
            continue;
        else
            m[currentStr] = true;
        bool found = true;
        for (int i = 0; i <= currentStr.size(); i++){
            if ( currentStr[i] == '-'){
                found = false;
                break;
            }
        }

        if (found)
            return currentFlip;

        for (int i = 0; i <= currentStr.size(); i++){
            string newStr = flip(currentStr,i);   
            q.push(make_pair(newStr, currentFlip+1));
        }
    }

}

int main(){
    int k;
    cin >> k;

    for (int i = 1; i <= k; i++){
        string str;
        cin >> str;
        cout << "Case #"<< i <<": " << check(str) << endl;
       
    }
    return 0;   
}
