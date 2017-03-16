#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tw = 1; tw <= t; tw++){
    string a;
    cin >> a;
    string s(1, a[0]);
    for(int i = 1; i < a.length(); i++){
        if(s[0] <= a[i]){
            s = string(1, a[i]) + s;
        }
        else{
            s.push_back(a[i]);
        }
    }
    cout << "Case #" << tw << ": " << s << endl;
    }
}
