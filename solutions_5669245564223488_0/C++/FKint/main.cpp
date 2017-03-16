/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <bitset>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

#define PI atan2(0,-1)

using namespace std;
#define MOD 1000000007
#define MAXN 100
bool used[MAXN];
int letters_used[255];
int N;
bool good_train(string t){
    bitset<256> letter_used;
    letter_used[t[0]]=true;
    for(int i = 1; i < t.size(); ++i){
        if(t[i] == t[i-1])
            continue;
        if(letter_used[t[i]]){
            return false;
        }
        letter_used[t[i]]=true;
    }
    return true;
}
struct train{
    train(string t){
        this->start = t[0];
        this->end = t[t.size()-1];
        for(int i = 1; i < t.size()-1; ++i){
            if(t[i]==t[i-1]){
                continue;
            }
            this->letters_in_between.push_back(t[i]);
        }
    }
    char start, end;
    vector<char> letters_in_between;
};
vector<train> trains;
long long count(int index, char last_letter){
    if(index == N){
        return 1;
    }   
    long long total = 0;
    for(int i = 0; i < N; ++i){
        if(used[i]){
            continue;
        }
        if(last_letter == trains[i].start || letters_used[trains[i].start] == 0){
            if(letters_used[trains[i].end] == 0 || trains[i].start == trains[i].end){
                bool good = true;
                for(vector<char>::iterator it = trains[i].letters_in_between.begin(); it != trains[i].letters_in_between.end(); ++it){
                    if(letters_used[*it] > 0){
                        good = false;
                        break;
                    }
                }
                if(!good)
                    continue;
                used[i]=true;
                letters_used[trains[i].start]++;
                letters_used[trains[i].end]++;
                for(vector<char>::iterator it = trains[i].letters_in_between.begin(); it != trains[i].letters_in_between.end(); ++it){
                    letters_used[*it]++;
                }
                total += count(index+1, trains[i].end);
                total %= MOD;
                for(vector<char>::iterator it = trains[i].letters_in_between.begin(); it != trains[i].letters_in_between.end(); ++it){
                    letters_used[*it]--;
                }
                letters_used[trains[i].end]--;
                letters_used[trains[i].start]--;
                used[i]=false;
            }
        }
    }
    return total;
}

int main(){
	int T;
	//scanf("%d", &T);
	cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
        cin >> N;
        trains.clear();
        bool good = true;
        for(int i = 0; i < N; ++i){
            string t;
            cin >> t;
            if(!good_train(t)){
                good = false;
            }
            trains.push_back(train(t));

        }
		//process
        long long total = 0;
        if(good){
            total = count(0, 0);
        }



		//printf("Case #%d:", current_case);
		cout << "Case #" << current_case << ":";
        cout << " " << total;



		//output answer
		//printf("\n");
		cout << endl;
	}
    return 0;
}
