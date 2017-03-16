#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int calculate(int N){
    int nb_found = 0;
    set<char> found;
    long long curr = 0;
    while(nb_found < 10){
        curr += N;
        stringstream ss;
        ss << curr;
        string s;
        ss >> s;
        for(string::iterator it = s.begin(); it != s.end(); ++it){
            if(found.count(*it))
                continue;
            ++nb_found;
            found.insert(*it);
        }
    }
    return curr;
}

int main(){
	std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int current_case_nb = 1; current_case_nb <= T; ++current_case_nb){
        int N;
        cin >> N;
        cout << "Case #"<<current_case_nb<<": ";
        if(N == 0)
            cout << "INSOMNIA";
        else
            cout << calculate(N);
        cout << endl;
    }
    return 0;
}
