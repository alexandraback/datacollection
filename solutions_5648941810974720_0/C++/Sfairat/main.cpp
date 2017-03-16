#include <iostream>
#include <iomanip>
#include <cstdio>
#include <bitset>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <wchar.h>
#include <wctype.h>
#include <cmath>
#include <queue>
#include <ctime>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template<typename T> T mabs(const T &a){ return a<0?-a:a;}
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQR(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;

// Z-Zero
// G-Eight
// W-Two
// X-Six
// H-Three
// R-Four
// F-Five
// O-One
// I-Nine
// Seven


void init() {
	//return;
}

void test() {
    char buf[100500];
    scanf(" %s", buf);

    std::vector<std::string> strs = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
    std::vector<char> keyLetters = { 'Z', 'G', 'W', 'X', 'H', 'R', 'F', 'O', 'I', 'S' };
    std::vector<int>  keyWords = { 0, 8, 2, 6, 3, 4, 5, 1, 9, 7 };
    std::string result;
    int counts[200] = { 0 };
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        counts[buf[i]]++;
    }
    for (int i = 0; i < keyLetters.size(); i++) {
        while (1) {
            if (counts[keyLetters[i]] == 0) {
                break;
            }
            result.push_back('0' + keyWords[i]);
            auto &word = strs[keyWords[i]];
            for (auto symb : word) {
                counts[symb]--;
            }
        }
    }

    for (int i = 0; i < 200; i++) {
        if (counts[i] != 0)
            fprintf(stderr, "BIDA!!\n");
    }

    sort(all(result));
    printf("%s\n", result.c_str());
}

void run()
{
	init();
	int tc;
	scanf("%d", &tc);
	rep(i, 0, tc) {
		printf("Case #%d: ", i + 1);
		test();
	}
}

//#define prob "fence"

int main()
{
#ifdef LOCAL_DEBUG
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    time_t st=clock();
#else 
#ifdef prob
    freopen(prob".in","r",stdin);
    freopen(prob".out","w",stdout);
#endif
#endif

    run();

#ifdef LOCAL_DEBUG
    fprintf(stderr, "\n=============\n");
    fprintf(stderr, "Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif
    
    return 0;
}