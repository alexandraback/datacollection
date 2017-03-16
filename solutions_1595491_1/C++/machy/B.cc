#include <string>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

template <class T>
void read_nums(istream& ist, vector<T>& nums, size_t cnt){
    for(size_t i = 0; i < cnt; i++){
        T val;
        ist >> val;
        nums.push_back(val);
    }
}

enum tag_Possibility {POSSIBLE_ANYWAY, POSSIBLE_WITH_SURPRISE, IMPOSSIBLE};
typedef enum tag_Possibility Possibility;
Possibility possibility(int score, int threshold){
    for(int i = threshold; i >= threshold-1 && i >= 0; i--){
        for(int j = threshold; j >= threshold-1 && j >= 0; j--){
            if(threshold + i + j <= score){
                return POSSIBLE_ANYWAY;
            }
        }
    }
    for(int i = threshold; i >= threshold-2 && i >= 0; i--){
        for(int j = threshold; j >= threshold-2 && j >= 0; j--){
            if(threshold + i + j <= score){
                return POSSIBLE_WITH_SURPRISE;
            }
        }
    }
    return IMPOSSIBLE;
}


int solve(int surprise, int threshold, const vector<int>& scores){
    int result = 0;
    int surprise_cnt = 0;
    for(size_t i = 0; i < scores.size(); i++){
        switch(possibility(scores[i], threshold)){
        case POSSIBLE_ANYWAY:
            result++;
            break;
        case POSSIBLE_WITH_SURPRISE:
            if(surprise_cnt < surprise){
                result++;
                surprise_cnt++;
            }
            break;
        case IMPOSSIBLE:
            break;
        }
    }
    return result;
}

int main(){
    size_t T = 0;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int N, S, p;
        cin >> N >> S >> p;
        vector<int> scores;
        read_nums(cin, scores, N);
        int result = solve(S, p, scores);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}

