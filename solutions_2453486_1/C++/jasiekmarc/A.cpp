#include<cstdio>

void testcase() {
    bool over = true;
    char B[4][4];
    for(int i = 0; i < 4; i ++)
        for(int j = 0; j < 4; j ++)
            scanf(" %c", &B[i][j]);

    // rows
    for(int r = 0; r < 4; r ++) {
        int x = 0, o = 0, t = 0;
        for(int i = 0; i < 4; i ++)
            switch(B[r][i]) {
                case 'X' :
                    x ++;
                    break;
                case 'O' :
                    o ++;
                    break;
                case 'T' :
                    t ++;
                    break;
                case '.' :
                    over = false;
            }
        // o won?
        if(o == 4 || (o == 3 && t == 1)) {
            printf("O won");
            return;
        }
        // x won?
        if(x == 4 || (x == 3 && t == 1)) {
            printf("X won");
            return;
        }
    }

    // columns
    for(int c = 0; c < 4; c ++) {
        int x = 0, o = 0, t = 0;
        for(int i = 0; i < 4; i ++)
            switch(B[i][c]) {
                case 'X' :
                    x ++;
                    break;
                case 'O' :
                    o ++;
                    break;
                case 'T' :
                    t ++;
                    break;
            }
            // o won?
            if(o == 4 || (o == 3 && t == 1)) {
                printf("O won");
                return;
            }
            // x won?
            if(x == 4 || (x == 3 && t == 1)) {
                printf("X won");
                return;
            }
    }

    // / diagonal
    int x = 0, o = 0, t = 0;
    for(int i = 0; i < 4; i ++)
        switch(B[i][3 - i]) {
            case 'X' :
                x ++;
                break;
            case 'O' :
                o ++;
                break;
            case 'T' :
                t ++;
                break;
        }
        // o won?
        if(o == 4 || (o == 3 && t == 1)) {
            printf("O won");
            return;
        }
        // x won?
        if(x == 4 || (x == 3 && t == 1)) {
            printf("X won");
            return;
        }

    // \ diagonal
    x = 0; o = 0; t = 0;
    for(int i = 0; i < 4; i ++)
        switch(B[i][i]) {
            case 'X' :
                x ++;
                break;
            case 'O' :
                o ++;
                break;
            case 'T' :
                t ++;
                break;
        }
        // o won?
        if(o == 4 || (o == 3 && t == 1)) {
            printf("O won");
            return;
        }
        // x won?
        if(x == 4 || (x == 3 && t == 1)) {
            printf("X won");
            return;
        }

    // else
    if(over) {
        printf("Draw");
        return;
    }
    printf("Game has not completed");
}

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; i ++) {
        printf("Case #%d: ", i + 1);
        testcase();
        printf("\n");
    }
}