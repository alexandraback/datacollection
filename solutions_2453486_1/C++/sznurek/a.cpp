#include <cstdio>

using namespace std;

char input[16][16];

int count_marks(char mark);
bool has_won(char mark);
bool winning_row(int row, char mark);
bool winning_col(int col, char mark);

int main() {
    int t;

    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        scanf("%s %s %s %s", input[0], input[1], input[2], input[3]);
        printf("Case #%d: ", i);

        if(has_won('X')) {
            printf("X won\n");
            continue;
        }

        if(has_won('O')) {
            printf("O won\n");
            continue;
        }

        if(count_marks('.') != 0) {
            printf("Game has not completed\n");
            continue;
        }

        printf("Draw\n");
    }

    return 0;
}

bool winning_row(int row, char mark) {
    int t_cnt = 0;
    int m_cnt = 0;

    for(int i = 0; i < 4; i++) {
        if(input[row][i] == 'T') t_cnt++;
        if(input[row][i] == mark) m_cnt++;
    }

    return m_cnt == 4 || (m_cnt == 3 && t_cnt == 1);
}

bool winning_col(int col, char mark) {
    int t_cnt = 0;
    int m_cnt = 0;

    for(int i = 0; i < 4; i++) {
        if(input[i][col] == 'T') t_cnt++;
        if(input[i][col] == mark) m_cnt++;
    }

    return m_cnt == 4 || (m_cnt == 3 && t_cnt == 1);
}

bool has_won(char mark) {
    for(int i = 0; i < 4; i++) {
        if(winning_row(i, mark) || winning_col(i, mark))
            return true;
    }

    int t_cnt = 0;
    int m_cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(input[i][i] == 'T') t_cnt++;
        if(input[i][i] == mark) m_cnt++;
    }

    if(m_cnt == 4 || (m_cnt == 3 && t_cnt == 1))
        return true;

    t_cnt = 0;
    m_cnt = 0;
    for(int i = 0; i < 4; i++) {
        if(input[i][3 - i] == 'T') t_cnt++;
        if(input[i][3 - i] == mark) m_cnt++;
    }

    if(m_cnt == 4 || (m_cnt == 3 && t_cnt == 1))
        return true;

    return false;
}

int count_marks(char mark) {
    int result = 0;

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            if(input[i][j] != mark) continue;

            result++;
        }
    }

    return result;
}
