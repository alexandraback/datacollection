#include <cstdio>
#include <map>
#include <string>
#include <cstring>

int main(){

    int t;
    scanf("%d" ,&t);

    for(int T = 1; T <= t; T++){
    
        std::map<std::string, int> map;

        int a, b, ans = 0;
        scanf("%d %d" ,&a ,&b);

        for(int i = a; i <= b; i++){

            char buf[100];
            sprintf(buf, "%d%d" ,i ,i);

            int min = 0, len = strlen(buf) / 2;
            for(int i = 1; i < len; i++){
                if(strncmp(buf + i, buf + min, len) < 0) min = i;
            }
            
            buf[min + len] = '\0';
            ans += map[std::string(buf + min)]++;
        }

        printf("Case #%d: %d\n" ,T ,ans);

    }

}
