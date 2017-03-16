#include <iostream>
using namespace std;

char name[9000000];
int cnt[9000000];

bool is_vowel(char c){
    switch(c){
        case 'a': return true;
        case 'e': return true;
        case 'i': return true;
        case 'o': return true;
        case 'u': return true;
    }
    return false;
}
int main()
{
    int T;
    scanf("%d", &T);

    for(int tcase=1; tcase <= T; ++tcase){
        int n=0;
        memset(name, 0, sizeof(name));
        scanf("%s", name);
        scanf("%d", &n);
        int tmp = 0;
        int len = strlen(name);
        /*for(int i=0; i < len; ++i){
            if(is_vowel(name[i]))
                tmp = 0;
            else
                tmp += 1;
            cnt[i] = tmp;
            printf("%d, ", cnt[i]);
        }
        printf("\n");
        long long ans = 0ll;
        for(int i=0; i < len; ++i){
            for(int j=i; j < len; ++j){
                if(cnt[i] == 0 && cnt[j] >= n)
                    ans += 1;
                else if(cnt[i] != 0  && cnt[j] - cnt[i] + 1 >= n){
                    ans += 1;
                }
            }
        }*/
        long long ans = 0ll;
        for(int i=0; i < len; ++i){
            int _m = 0;
            int _cnt = 0;
            for(int j=i; j < len; ++j){
                if( is_vowel(name[j]) ){
                    _cnt = 0;
                }
                else{
                    _cnt += 1 ;
                }
                _m = max(_m, _cnt);
                if(_m >= n)
                    ans += 1;
            }
        }
        printf("Case #%d: %lld\n", tcase, ans);
    }
    return 0;
}
