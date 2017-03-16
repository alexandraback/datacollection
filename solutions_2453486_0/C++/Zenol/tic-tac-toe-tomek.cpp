#include <iostream>


#define IS_OK(t, c) (t == c || t == 'T')
unsigned char tab[4][5];

enum state
{
    xwin,
    owin,
    draw,
    not_completed,
};

bool check_row(int i, char c)
{
    return IS_OK(tab[i][0], c)
        && IS_OK(tab[i][1], c)
        && IS_OK(tab[i][2], c)
        && IS_OK(tab[i][3], c);
}

bool check_col(int i, char c)
{
    return IS_OK(tab[0][i], c)
        && IS_OK(tab[1][i], c)
        && IS_OK(tab[2][i], c)
        && IS_OK(tab[3][i], c);
}

bool check_diag(char c)
{
    return IS_OK(tab[0][0], c)
        && IS_OK(tab[1][1], c)
        && IS_OK(tab[2][2], c)
        && IS_OK(tab[3][3], c);
}
bool check_adiag(char c)
{
    return IS_OK(tab[0][3], c)
        && IS_OK(tab[1][2], c)
        && IS_OK(tab[2][1], c)
        && IS_OK(tab[3][0], c);
}

state compute()
{
    //Read lines quickly
    for (int i = 0; i < 4; i++)
        std::cin >> tab[i];

    bool game_can_continue = false;
    for (int i = 0; i < 4; i++)
    {
        for (int y = 0; !game_can_continue && y < 4; y++)
        {
            if (tab[i][y] == '.')
                game_can_continue = true;
        }
        //Check line
        if (check_row(i, 'X'))
            return xwin;
        if (check_row(i, 'O'))
            return owin;
        if (check_col(i, 'X'))
            return xwin;
        if (check_col(i, 'O'))
            return owin;
    }
    if (check_diag('X'))
        return xwin;
    if (check_diag('O'))
        return owin;
    if (check_adiag('X'))
        return xwin;
    if (check_adiag('O'))
        return owin;
    if (game_can_continue)
        return not_completed;
    else
        return draw;
}

int main(void)
{
    //Number of test case
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        state st = compute();
        std::cout << "Case #" << (i + 1) << ": ";
        switch(st)
        {
        case xwin:
            std::cout << "X won";
            break;
        case owin:
            std::cout << "O won";
            break;
        case draw:
            std::cout << "Draw";
            break;
        case not_completed:
            std::cout << "Game has not completed";
            break;
        };
        std::cout << "\n";
    }
}
