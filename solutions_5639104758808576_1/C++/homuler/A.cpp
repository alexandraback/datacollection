#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solve(string str){
    int ret = 0;
    int sum = 0;
    for(int i = 0; i < str.size(); ++i){
        if(i > sum+ret){
            ret += i-sum-ret;
        }
        sum += str[i]-'0';
    }
    return ret;
}

int main(){
    int t;
    cin >> t;

    int smax;
    string auds;
    for(int i = 0; i < t; ++i){
        cin >> smax >> auds;
        cout << "Case #" << (i+1) << ": " << solve(auds) << endl;
    }

}
