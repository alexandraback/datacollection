#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int good_size(string s){
    int nb_good = 0;
    for(string::reverse_iterator it = s.rbegin(); it != s.rend(); ++it){
        if(*it == '-')
            break;
        ++nb_good;
    }
    return nb_good;
}

struct state{
    string s;
    int steps;
    state(string s, int steps){
        this->s = s;
        this->steps = steps;
    }
    bool operator<(const state &s2)const{
        if(steps != s2.steps)
            return s2.steps < steps;
        return good_size(s) < good_size(s2.s);
    }
};

char anti(char s){
    if(s == '+')
        return '-';
    return '+';
}

string flip(string s, int length){
    for(int i = 0; i < length / 2; ++i){
        char tmp = anti(s[length-i-1]);
        s[length-i-1] = anti(s[i]);
        s[i] = tmp;
    }
    if(length % 2){
        s[length/2] = anti(s[length/2]);
    }
    return s;
}

int first_min(string s){
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == '-')
            return i;
    }
    return -1;
}

int main(){
	std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int current_case_nb = 1; current_case_nb <= T; ++current_case_nb){
        string line;
        cin >> line;
        priority_queue<state> pq;
        pq.push(state(line, 0));
        set<string> visited;
        cout << "Case #" << current_case_nb << ": ";
        while(!pq.empty()){
            state s = pq.top();
            pq.pop();
            if(visited.count(s.s))
                continue;
            visited.insert(s.s);
            int good_index = s.s.length() - good_size(s.s);
            if(good_index == 0){
                cout << s.steps;
                break;
            }
            pq.push(state(flip(s.s, good_index), s.steps + 1));
//            cout << "Flipped not-final region of " << s.s << ": " << flip(s.s, good_index) << endl;
            if(s.s[0] == '+'){
//                cout << "Flipped top region of " << s.s << ": " << flip(s.s, first_min(s.s)) << endl;
                pq.push(state(flip(s.s, first_min(s.s)), s.steps + 1));
            }
            //indices.first = starting index of last bad sequence
            //indices.second = startign index of good sequence
            /*
             * if top is -:
             *  just flip
             * if top is +:
             *  flip top bad region
             *  flip whole stack
             */
        }
        cout << endl;
    }
    return 0;
}
