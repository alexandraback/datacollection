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

int pair_count(int A, int B, int shift_up, int n){
    int next = n;
    int count = 0;
    while(true){
        next = (next / 10) + (next % 10 * shift_up);
        if(next == n) break;
        if(A <= next && next <= B && next < n) count++;
    }
    return count;
}

int solve(int A, int B){
    int shift_up = 1;
    while(shift_up * 10 <= A){
        shift_up *= 10;
    }
    int result = 0;
    for(int n = A; n <= B; n++){
        result += pair_count(A, B, shift_up, n);
    }
    return result;
}

int main(){
    size_t T = 0;
    cin >> T;
    for(size_t t = 1; t <= T; t++){
        int A, B;
        cin >> A >> B;
        int result = solve(A, B);
        cout << "Case #" << t << ": " << result << endl;
    }
    return 0;
}

