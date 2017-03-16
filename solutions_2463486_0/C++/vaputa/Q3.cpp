#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

int judge(long long x){
    int d[1 << 5], len = -1;
    if (x == 0)
        return 1;
        
    while (x != 0){
        d[++len] = x % 10;
        x /= 10;
    }
    for (int i = 0; i <= len / 2; ++i)
        if (d[i] != d[len - i])
            return 0;
    return 1;
}

vector<int> vaild;
void generate(){
    for (long long i = 1; i <= 10000000; ++i)
        if (judge(i) && judge(i * i))
            vaild.push_back(i * i);
}

int solve(){
    int x, y;
    cin >> x >> y;
    int count = 0;
    for (int i = 0; i < vaild.size(); ++i)
        if (x <= vaild[i] && vaild[i] <= y)
            ++count;
    return count;
}

int main(){
    generate();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cout << "Case #" << i << ": " << solve() << endl;
    }
    return 0;
}
