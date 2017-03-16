#include <iostream>
#include <cstdio>
#include <cstring>

#define AT(tab, x, y) (tab[x + y * 100])

int n, m;
unsigned char tab[100 * 100];
unsigned char chk[100 * 100];

inline
int max_row(int i)
{
    unsigned char max = 0;
    for (int j = 0; j < m; j++)
        if (AT(tab, i, j) > max)
            max = AT(tab, i, j);
    return max;
}

inline
int max_col(int j)
{
    unsigned char max = 0;
    for (int i = 0; i < n; i++)
        if (AT(tab, i, j) > max)
            max = AT(tab, i, j);
    return max;
}

inline
unsigned char and_row(int i)
{
    unsigned char sum = 1;

    for (int j = 0; j < m; j++)
        sum &= AT(chk, i, j);
    return sum;
}

inline
unsigned char andtab()
{
    unsigned char sum = 1;

    for (int i = 0; i < n; i++)
        sum &= and_row(i);
    return sum;
}

inline
void fill_row(int i)
{
    unsigned char max = max_row(i);

    for (int j = 0; j < m; j++)
        if (AT(tab, i, j) == max)
            AT(chk, i, j) = 1;
}

inline
void fill_col(int j)
{
    unsigned char max = max_col(j);

    for (int i = 0; i < n; i++)
        if (AT(tab, i, j) == max)
            AT(chk, i, j) = 1;
}

bool compute()
{
    std::cin >> n;
    std::cin >> m;

    //Init chk tab
    memset(chk, 0, sizeof(chk));

    //Read lines
    int tmp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            std::cin >> tmp;
            AT(tab, i, j) = tmp; //0 < tmp < 255, so it's ok!
        }

    //Check lines & cols
    for (int i = 0; i < n; i++)
        fill_row(i);
    for (int j = 0; j < m; j++)
        fill_col(j);

    // std::cout << "\n----\n";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         std::cout << " " << (int)AT(chk, i, j);
    //     std::cout << std::endl;
    // }

    //Check if the tab is valid
    return (andtab() == 1);
}


int main(void)
{
    //Number of test case
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        bool st = compute();
        std::cout << "Case #" << (i + 1) << ": ";
        switch(st)
        {
        case true:
            std::cout << "YES";
            break;
        case false:
            std::cout << "NO";
            break;
        };
        std::cout << "\n";
    }
}
