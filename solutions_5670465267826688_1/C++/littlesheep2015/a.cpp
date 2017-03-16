#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int sign_table[300][300];
int number_table[300][300];

struct Number {
    char c;
    int sign;

    Number(int sign, char c) : c(c), sign(sign) { }

    Number(char c) : c(c), sign(1) { }

    Number operator * (const Number& rhs) {
        return Number(sign * rhs.sign * sign_table[c][rhs.c], number_table[c][rhs.c]);
    }
};

Number get_power(Number number, long long times) {
    Number result('1');
    for (; times; times /= 2) {
        if (times & 1LL) {
            result = result * number;
        }
        number = number * number;
    }
    return result;
}

void solve(int test_id) {
    int length;
    long long rep_times;
    cin >> length >> rep_times;
    vector<Number> number;
    string buffer;
    cin >> buffer;
    assert(buffer.size() == length);
    for (int i = 0; i < length; ++i) {
        number.push_back(Number(buffer[i]));
    }
    Number prod('1');
    for (int i = 0; i < number.size(); ++i) {
        prod = prod * number[i];
    }
    bool answer = true;
    do {
        prod = get_power(prod, rep_times);
        if (prod.c != '1' || prod.sign != -1) {
            answer = false;
            break;
        }
        long long first_position = -1, last_position = -1;
        prod = Number('1');
        for (long long i = 0; i < min(4LL, rep_times) * length; ++i) {
            prod = prod * number[i % length];
            if (prod.sign == 1 && prod.c == 'i') {
                first_position = i;
                break;
            }
        }
        prod = Number('1');
        for (long long i = rep_times * length - 1;
            i >= max(rep_times - 4, 0LL) * length; --i) {
            prod = number[i % length] * prod;
            if (prod.sign == 1 && prod.c == 'k') {
                last_position = i;
                break;
            }
        }
        if (first_position == -1 || last_position == -1 || first_position >= last_position) {
            answer = false;
            break;
        }
    } while (false);

    cout << "Case #" << test_id << ": " << (answer ? "YES" : "NO") << endl;
}

int main() {
    sign_table['1']['1'] = 1;
    sign_table['1']['i'] = 1;
    sign_table['1']['j'] = 1;
    sign_table['1']['k'] = 1;

    sign_table['i']['1'] = 1;
    sign_table['i']['i'] = -1;
    sign_table['i']['j'] = 1;
    sign_table['i']['k'] = -1;

    sign_table['j']['1'] = 1;
    sign_table['j']['i'] = -1;
    sign_table['j']['j'] = -1;
    sign_table['j']['k'] = 1;

    sign_table['k']['1'] = 1;
    sign_table['k']['i'] = 1;
    sign_table['k']['j'] = -1;
    sign_table['k']['k'] = -1;

    number_table['1']['1'] = '1';
    number_table['1']['i'] = 'i';
    number_table['1']['j'] = 'j';
    number_table['1']['k'] = 'k';

    number_table['i']['1'] = 'i';
    number_table['i']['i'] = '1';
    number_table['i']['j'] = 'k';
    number_table['i']['k'] = 'j';

    number_table['j']['1'] = 'j';
    number_table['j']['i'] = 'k';
    number_table['j']['j'] = '1';
    number_table['j']['k'] = 'i';

    number_table['k']['1'] = 'k';
    number_table['k']['i'] = 'j';
    number_table['k']['j'] = 'i';
    number_table['k']['k'] = '1';

    int num_testcase;
    cin >> num_testcase;
    for (int test_id = 1; test_id <= num_testcase; ++test_id) {
        solve(test_id);
    }
    return 0;
}