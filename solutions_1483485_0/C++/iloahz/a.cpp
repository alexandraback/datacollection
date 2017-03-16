#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

char* plain[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
char* cipher[] = {"our language is impossible to understand",
                 "there are twenty six factorial possibilities",
                 "so it is okay if you want to just give up"};
map<char, char> mp;

void init(){
    int n = 3;
    mp.clear();
    for (int i = 0;i < n;i++){
        for (int j = 0;j < strlen(plain[i]);j++){
            mp[plain[i][j]] = cipher[i][j];
        }
    }
    mp['z'] = 'q';
    mp['q'] = 'z';
//    int s = 0;
//    for (char i = 'a';i <= 'z';i++){
//        printf("%c %c\n", i, mp[i]);
//        s += i;
//        if (mp.count(i)) s -= mp[i];
//    }
//    printf("_%c_", s);
}

void proc(){
    int T, t = 0;
    scanf("%d\n", &T);
    while (T--){
        printf("Case #%d: ", ++t);
        char c;
        while (c = getchar()){
            if (c == 10 || c < 0) break;
            //printf("%c", c);
            printf("%c", mp[c]);
        }
        printf("\n");
    }
}

int main(){
#ifdef ILOAHZ
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
#endif
    init();
    proc();
    return 0;
}
