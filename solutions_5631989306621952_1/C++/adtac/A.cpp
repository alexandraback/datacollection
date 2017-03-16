/* Author: hypothesist */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <ctime>

using namespace std;

#define all(c) (c).begin(), (c).end()

template <typename T> class __cl
{
	public:
		std::vector<T> values;
		void operator()(const T& value)
		{
			if (std::find(all(values), value) == values.end())
				values.push_back(value);
		}
};

typedef istringstream is;
typedef ostringstream os;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;

#define eps 1e-8
#define inf 1e8

#define tr(container, it) for(typeof((container).begin()) it = (container).begin(); it != (container).end(); it++)

#define ex_set(container, element) ((container).find((element)) != (container).end())
#define ex_vec(container, element) (find(all(container), (element)) != (container).end())

#define rm_dupl_s(container) set<typeof(*((container).begin()))> __s(all(container)); (container) = vector<typeof(*((container).begin()))>(all(__s))
#define rm_dupl_us(container) (container) = for_each(all(container), __cl<int>()).values

char str[1009];
char lans[1009], rans[1009];

int main() {
    int test;
    scanf("%d\n", &test);

    for(int t = 1; t <= test; t++) {
        scanf("%s", str);
        char l, r;
        int lc = 0, rc = 1;
        l = r = str[0];
        rans[0] = str[0];
        for(int i = 1; str[i]; i++) {
            if(str[i] >= l) {
                lans[lc++] = str[i];
                l = str[i];
            }
            else {
                rans[rc++] = str[i];
                r = str[i];
            }
        }
        printf("Case #%d: ", t);
        for(int i = lc - 1; i >= 0; i--)
            printf("%c", lans[i]);
        for(int i = 0; i < rc; i++)
            printf("%c", rans[i]);
        printf("\n");
    }
}
