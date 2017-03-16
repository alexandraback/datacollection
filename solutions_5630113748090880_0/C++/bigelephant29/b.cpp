#include<cstdio>
#include<set>
#include<cstring>
using namespace std;

const int MAX = 2500 + 10;

set<int> s;
int cnt[MAX];

int main(){
    int TN;
    scanf("%d", &TN);
    for(int casen = 1 ; casen <= TN ; casen++){
        memset(cnt, 0, sizeof(cnt));
        printf("Case #%d: ", casen);
        s.clear();
        int n;
        scanf("%d", &n);
        for(int i = 0 ; i < 2*n-1 ; i++){
            for(int j = 0 ; j < n ; j++){
                int t;
                scanf("%d", &t);
                cnt[t]++;
                if(cnt[t]%2 == 0){
                    s.erase(t);
                }else{
                    s.insert(t);
                }
            }
        }
        bool space = false;
        for(auto itr : s){
            if(space) putchar(' ');
            space = true;
            printf("%d", itr);
        }
        puts("");
    }
    return 0;
}
