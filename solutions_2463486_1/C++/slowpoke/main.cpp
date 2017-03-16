#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

static vector<long long> dp;

bool isPalindrome(long long val){
    ostringstream oss;
    oss << val;
    string str = oss.str();
    size_t len = str.size()/2;
    for(size_t i=0, j=str.size()-1; i<len; ++i,--j){
        if(str[i] != str[j])
            return false;
    }
    return true;
}

void generate(){
    for(long long i=1; i<=10000000; ++i){
        if(isPalindrome(i) && isPalindrome(i*i)){
            dp.push_back(i*i);
        }
    }
}

int main(int argc, const char * argv[])
{
    int T;
    cin >> T;
    
    generate();
        
    for(int t=1; t<=T; ++t){
        long long A, B;
        cin >> A >> B;
        
        auto lower = lower_bound(dp.begin(), dp.end(), A);
        auto upper = upper_bound(dp.begin(), dp.end(), B);
        
        auto num = upper - lower;
        cout << "Case #" << t << ": " << num << endl;
        
    }
    
    return 0;
}

