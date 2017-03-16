#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int start[123];
int starts[30];
int end[123];
int ends[30];
char word[123];
int seen[30];
bool mask[30];
int middles[30];
int oneletters[30];

void factorial(long long &combinations, int n) {
    for(int i=1; i<=n; i++) {
        combinations *= i;
        combinations %= 1000000007;
    }
}

int main() {
    int _t; scanf("%d", &_t);
    for(int _i=1; _i<=_t; _i++) {
        int n; scanf("%d", &n);
        bool broken = false;
        long long combinations = 1;
        printf("Case #%d: ", _i);
        for(int i=0; i<30; i++) {
            middles[i] = 0;
            mask[i] = false;
            oneletters[i] = 0;
            seen[i] = 0;
            ends[i] = starts[i] = 0;
        }
        for(int i=0; i<n; i++) {
            scanf("%s", word);
            start[i]=word[0]-'a';
            starts[start[i]]++;
            end[i] = word[strlen(word)-1]-'a';
            ends[end[i]]++;
            mask[start[i]] = mask[end[i]] = true;
            int j=0;
            for(; word[j] == word[0]; j++);
            if(word[j] == '\0') {
                starts[start[i]]--;
                ends[end[i]]--;
                oneletters[start[i]]++;
            } else {
                if(start[i] == end[i]) {
                    printf("0\n");
                    broken = true;
                    break;
                }
                char pre = word[0];
                for(; word[j]-'a' != end[i]; j++) {
                    if(middles[word[j]-'a'] == 1 and pre != word[j]) {
                        printf("0\n");
                        broken = true;
                        break;
                    }
                    middles[word[j]-'a'] = 1;
                    pre = word[j];
                }
                if(broken) break;
            }
            if(broken) break;
        }
        if(broken) continue;

        for(int i=0; i<n; i++) {
            if(middles[start[i]] == 1 or middles[end[i]] == 1) {
                printf("0\n");
                broken = true;
                break;
            }
        }
        if(broken) continue;

        for(int i=0; i<30; i++) {
            if(starts[i] > 1 or ends[i] > 1) {
                printf("0\n");
                broken = true;
                break;
            }
        }
        if(broken) continue;

        int components=0;
        for(int i=0; i<30; i++) {
            if(seen[i] == 0 and mask[i]) {
                components++;
                queue<int> q;
                q.push(i);
                while(not q.empty()) {
                    int x = q.front();
                    q.pop();
                    seen[x] = 1;
                    for(int j=0; j<123; j++) {
                        if(start[j] == x and seen[end[j]] == 0) q.push(end[j]);
                        if(end[j] == x and seen[start[j]] == 0) q.push(start[j]);
                    }
                }
            }
        }
        //printf("Components: %d\n", components);
        factorial(combinations, components);
        for(int i=0; i<30; i++) {
            if(oneletters[i] > 0) {
         //       printf("%d\n", oneletters[i]);
                factorial(combinations, oneletters[i]);
            }
        }
        printf("%lld\n", combinations);
    }
}
    
