#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

bool isPalindrome(long long a) {
    stringstream o;
    o << a;
    string as = o.str();
    for (int i = 0; i < as.size() / 2; i ++)
        if (as[i] != as[as.size() - 1 - i])
            return false;
    return true;
}

int main() {
    ifstream cin("/Users/mac/topcoder/C-small-attempt0.in.txt");
    ofstream cout("/Users/mac/topcoder/res.txt");
    
    vector<long long> p;
    
    for (long long i = 1; i * i < 100000000000000ll; i ++) {
        if (isPalindrome(i))
            if (isPalindrome(i * i))
                p.push_back(i * i);
    }
    
    int N;
    cin >> N;
    
    for (int CT = 0; CT < N; CT ++) {
        cout << "Case #" << (CT + 1) << ": ";
        
        long long a, b;
        cin >> a >> b;
        
        int r = 0;
        for (int i = 0; i < p.size(); i ++)
            if (a <= p[i] && p[i] <= b)
                r ++;
        
        cout << r << endl;
    }
    return 0;
}