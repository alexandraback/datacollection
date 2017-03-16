#include <iostream>
#include <set>
#include <utility>
#include <algorithm>
#include <utility>
#include <sstream>
#include <boost/lexical_cast.hpp>

#define log false && cerr

using namespace std;

// 
// for precomputing
//
long MAX_N = 1e7+100;
//long MAX_N = 100;

set<long> fs;

bool isPalindrome(string s) {
    for (int l = 0, r = s.length() - 1; l < r; l++, r--)
        if (s[l] != s[r])
            return false;

    return true;
}

void addSqPalindrome(string palindrome) {
    log << "addPalin: " << palindrome << endl;
    long palVal = boost::lexical_cast<long>(palindrome);
    long sqVal = palVal * palVal;
    string sqStr = boost::lexical_cast<string>(sqVal);

    if (isPalindrome(sqStr)) {
        fs.insert(sqVal);
        log << "Found: " << sqVal << endl;
    }
}

void checkFS(int seed) {
    string s = boost::lexical_cast<std::string>(seed);
    string rev = s;
    reverse(rev.begin(), rev.end());
    
    string palindrome = s + rev;
    addSqPalindrome(palindrome);

    for (int i = 0; i <= 9; ++i) {
        palindrome = s + string(1, char('0' + i)) + rev;
        addSqPalindrome(palindrome);
    }
}

void precompute() {
    fs.insert(0);
    fs.insert(1);
    fs.insert(4);
    fs.insert(9);

    for (int i = 1; i < MAX_N; ++i)
        checkFS(i);
}

void print_Precomp() {
    for (set<long>::iterator it = fs.begin(); it != fs.end(); ++it)
        cout << *it << "," << endl;
}

long tab[] = {
0LL,
1LL,
4LL,
9LL,
121LL,
484LL,
10201LL,
12321LL,
14641LL,
40804LL,
44944LL,
1002001LL,
1234321LL,
4008004LL,
100020001LL,
102030201LL,
104060401LL,
121242121LL,
123454321LL,
125686521LL,
400080004LL,
404090404LL,
10000200001LL,
10221412201LL,
12102420121LL,
12345654321LL,
40000800004LL,
1000002000001LL,
1002003002001LL,
1004006004001LL,
1020304030201LL,
1022325232201LL,
1024348434201LL,
1210024200121LL,
1212225222121LL,
1214428244121LL,
1232346432321LL,
1234567654321LL,
4000008000004LL,
4004009004004LL,
100000020000001LL,
100220141022001LL,
102012040210201LL,
102234363432201LL,
121000242000121LL,
121242363242121LL,
123212464212321LL,
123456787654321LL,
400000080000004LL,
10000000200000001LL,
10002000300020001LL,
10004000600040001LL,
10020210401202001LL,
10022212521222001LL,
10024214841242001LL,
10201020402010201LL,
10203040504030201LL,
10205060806050201LL,
10221432623412201LL,
10223454745432201LL,
12100002420000121LL,
12102202520220121LL,
12104402820440121LL,
12122232623222121LL,
12124434743442121LL,
12321024642012321LL,
12323244744232321LL,
12343456865434321LL,
12345678987654321LL,
40000000800000004LL,
40004000900040004LL,
};

int solve(long a, long b) {
    int tabSize = sizeof(tab) / sizeof(tab[0]);
    long* lb = lower_bound(tab, tab + tabSize, a);
    long* ub = upper_bound(tab, tab + tabSize, b);
    return ub - lb;
}

int main() {
    
//  precompute();
//  print_Precomp();

    int T;
    long A, B;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> A >> B;
        int res = solve(A, B);
        cout << "Case #" << t << ": " << res  << endl;
    }

    return 0;
}

