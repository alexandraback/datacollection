#include<iostream>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<sstream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<functional>
#include<numeric>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include <cmath>
#include <unordered_map>

using namespace std;

const int MAXN = 10005;
struct topic {
    string topic1;
    string topic2;

} topics[MAXN];

int main() {
    int t,h,Case = 1;
    string s1,s2;
    
    cin>>t;
    while(t--)
    {
        int n, result = 0;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> s1>> s2;
            topics[i].topic1 = s1;
            topics[i].topic2 = s2;
        }
        
        for (int i = 0; i < 1 << n; i++) {
            unordered_map<string, long long > first_topic;
            unordered_map<string, long long > second_topic;
            
            for (int j = 0; j < n; j++) {
                if (!((i >> j) & 1)) {
                    first_topic[topics[j].topic1]++;
                    second_topic[topics[j].topic2]++;
                }
            }

            int j;
            for (j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    if (!first_topic.count(topics[j].topic1)
                    || !second_topic.count(topics[j].topic2)) {
                        break;
                    }
                }
            }
            if (j >= n) {
                result = max(result, __builtin_popcount(i));
            }
        }

        cout<<"Case #"<<Case++<<": "<<result<<endl;

    }
    return 0;
}
