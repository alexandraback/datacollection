#include<cstdio>
const int SIZE = 4;

char S[SIZE][SIZE];

bool getWinner(int tc, int xc, int oc) {
    if ((tc == 1 && xc == 3) || xc == 4) {
        printf("X won\n");
        return true;
    }

    if ((tc == 1 && oc == 3) || oc == 4) {
        printf("O won\n");
        return true;
    }

    return false;
}

int main() {
    int t, test = 0; 
    scanf("%d", &t);

    while (t--) {
        test++;
        for (int i=0; i<SIZE; i++)
            scanf("%s", S[i]);

        printf("Case #%d: ", test);
        
        bool done = false, finished = true;
        for (int i=0; i<SIZE; i++) {
            int tc = 0, xc = 0, oc = 0;

            for (int j=0; j<SIZE; j++) {
                if (S[i][j] == 'T')
                    tc++;
                if (S[i][j] == 'X')
                    xc++;
                if (S[i][j] == 'O')
                    oc++;
                if (S[i][j] == '.')
                    finished = false;
            }

            if (getWinner(tc, xc, oc))
                done = true;
        }

        if (done)
            continue;

        for (int i=0; i<SIZE; i++) {
            int tc = 0, xc = 0, oc = 0;

            for (int j=0; j<SIZE; j++) {
                if (S[j][i] == 'T')
                    tc++;
                if (S[j][i] == 'X')
                    xc++;
                if (S[j][i] == 'O')
                    oc++;
            }

            if (getWinner(tc, xc, oc))
                done = true;
        }

        if (done)
            continue;
        
        int tc = 0, xc = 0, oc = 0;
        for (int i=0; i<SIZE; i++) {
            if (S[i][i] == 'T')
                tc++;
            if (S[i][i] == 'X')
                xc++;
            if (S[i][i] == 'O')
                oc++;
        }
        if (getWinner(tc, xc, oc))
            continue;
        
        tc = xc = oc = 0;
        for (int i=0; i<SIZE; i++) {
            if (S[i][3-i] == 'T')
                tc++;
            if (S[i][3-i] == 'X')
                xc++;
            if (S[i][3-i] == 'O')
                oc++;
        }
        if (getWinner(tc, xc, oc))
            continue;

        if (!finished)
            printf("Game has not completed\n");
        else
            printf("Draw\n");

    }
}
