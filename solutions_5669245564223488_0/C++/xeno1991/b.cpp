#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<sstream>
#include<set>
using namespace std;

constexpr long MOD = 1000000007;

//solver
struct Solver{

};

bool isvalid(const vector<string>& v){
    stringstream ss;

    for(auto& s : v){
        ss << s;
    }
    
    set<char> s;
    string str = ss.str();

    for(char c : str){
        s.insert(c);
    }

    //連結かどうかのチェック
    for(auto it=s.begin();it!=s.end();it++){
        char c = *it;

        auto start = str.find(c);
        auto rstart = str.rfind(c);

        for(int i=start;i<=rstart;i++){
            if(c != str[i]){
                return false;
            }
        }
    }
    return true;
}

template<typename T>
void show(const T& list){
    for(auto s : list){
        // cout << s << " ";
    }
    // cout << endl;
}

long solve_small(vector<string>& v){
    sort(v.begin(), v.end());
    long res=0;
    do{
        bool is = isvalid(v);
        show(v);
        // cout << is << endl;

        res = (res + is) %  MOD;
    }while(next_permutation(v.begin(),v.end()));
    return res;
}


template<typename T>
T fact(T n){
    T res=1;
    while(n){
        res *= n;
        n--;
    }
    return res;
}

int main(){
    int CASE;
    cin >> CASE;
    for(int tcase=1;tcase<=CASE;tcase++){
        vector<string> v;
        int N;
        
        //input
        cin >> N;
        unsigned long long mul=1;
        map<string,long> m;
        while(N--){
            string s;
            cin >> s;
            v.push_back(s);
            
            //既にある
            if(m.find(s) != m.end()){
                m[s]++;
            }
            else{
                m[s]=1;
            }
        }


        //solve 
        auto ans = solve_small(v);

        //重複の計算
        for(auto it=m.begin();it!=m.end();it++){
            ans = (ans * fact(it->second))%MOD;

            // cout << it->first << ":" << it->second << endl;
        }


        cout << "Case #" << tcase << ": " << ans << endl;
    }

    return 0;
}
