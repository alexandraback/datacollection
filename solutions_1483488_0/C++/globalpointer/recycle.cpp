#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int test_cases, a, b, len;
bool seen[2000010];
ll ans;

int getlen(int i) {
    int r = 0;
    while (i > 0) {
        r++;
        i /= 10;
    }
    return r;
}

int rotate(int i) {
    return ((i * 10) % int(pow(10, len))) + (i / int(pow(10, len-1)));
}

vector<int> remove_invalid(vector<int> v) {
    vector<int> ret;
    if (v[0] >= a && v[0] <= b)
        ret.push_back(v[0]);
    for (int i = 1; i < (int)v.size(); i++)
        if (v[i] >= a && v[i] <= b && v[i] != v[i-1])
            ret.push_back(v[i]);
    return ret;
}

ll get_recycled(int num) {
    vector<int> possible;
    possible.push_back(num);
    for (int i = 1; i < len; i++) {
        num = rotate(num);
        possible.push_back(num);
    }
    
    sort(possible.begin(), possible.end());
    for (int i = 0; i < (int)possible.size(); i++)
        seen[possible[i]] = true;

    possible = remove_invalid(possible);
    
    return (ll(possible.size()) * ll(possible.size() - 1u)) / 2ll;
}

int main()
{
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
    
    scanf("%d", &test_cases);
    for (int test_num = 1; test_num <= test_cases; test_num++) {
        ans = 0ll;
        
        for (int i = 0; i < 2000010; i++)
            seen[i] = false;
        
        scanf("%d%d", &a, &b);
        len = getlen(a);
        
        for (int i = a; i <= b; i++)
            if (!seen[i])
                ans += get_recycled(i);
        
        printf("Case #%d: %lld\n", test_num, ans);
    }
}
