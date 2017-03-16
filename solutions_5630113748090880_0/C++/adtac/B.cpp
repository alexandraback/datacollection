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

int oc[2509];
int l[109][59];
int starts[2509];

int main() {
    int test;
    scanf("%d", &test);

    for(int t = 1; t <= test; t++) {
        memset(oc, 0, sizeof(oc));
        memset(starts, 0, sizeof(starts));
        int n;
        scanf("%d", &n);
        for(int i = 0; i < 2 * n - 1; i++) {
            for(int j = 0; j < n; j++) {
                scanf("%d", &l[i][j]);
                oc[l[i][j]]++;
            }
        }
        int k = 0;
        for(int i = 0; i < 2509; i++) {
            if(oc[i] % 2)
                starts[k++] = i;
        }
        sort(starts, starts + k);
        printf("Case #%d: ", t);
        for(int i = 0; i < k; i++)
            printf("%d ", starts[i]);
        printf("\n");
    }
}
