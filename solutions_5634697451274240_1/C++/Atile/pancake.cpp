#include <cstdio>
#include <cstring>

int main(){
    int T, res, j;
    char line[101];

    scanf("%d", &T);
    for(int caso=1;caso<=T;caso++){
        scanf("%s", &line);

        res = line[strlen(line)-1] == '+' ? -1 : 0;
        for(int i=0;i<strlen(line);i++){
            for(j=i+1; j<strlen(line) && line[i] == line[j] ;j++);
            res++;
            i = j - 1;
        }

        printf("Case #%d: %d\n", caso, res);
    }

    return 0;
}
