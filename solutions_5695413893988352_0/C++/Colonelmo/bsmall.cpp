#include <bits/stdc++.h>

using namespace std;

string fil(int a, int num){
    stringstream ss;
    ss << a;
    string str;
    ss >> str;
    while(str.size() < num){
        str = "0" + str;
    }
    return str;
}

int calc(string aa, string bb){
    int a, b;
    stringstream sa(aa);
    sa >> a;
    stringstream sb(bb);
    sb >> b;
    return abs(b - a);
}

pair <int, pair < string, string> > solve(string a, string b){
    pair<int, pair<string, string> > ret = {100000, {":D" , ":D"}};
    int numqu = std::count(a.begin(), a.end(), '?') + std::count(b.begin(), b.end(), '?');
    int too = 1;
    for(int i = 0 ; i <numqu ; i++){
        too *= 10; 
    }
    for(int i = 0 ;i < too; i++){
        auto choose = fil(i, numqu); 
        choose += "0000";
        string aa = a;
        string bb = b;
        int ind = 0;
        for(auto& it : aa){
            if(it == '?'){
                it = choose[ind];
                ind ++;
            }
        }
        for(auto& it : bb){
            if(it == '?'){
                it = choose[ind];
                ind ++;
            }
        }
        ret = min(ret, {calc(aa, bb),{aa, bb}}); 
    }
    return ret;
}

int main(){
    int test;
    cin >> test;
    for(int t= 1 ; t <= test ;t++){
        string a, b;
        cin >>a >> b;
        auto ans = solve(a, b);
        cout << "Case #" << t << ": " << ans.second.first <<  " " << ans.second.second<< endl;
    }
    return 0;
}
