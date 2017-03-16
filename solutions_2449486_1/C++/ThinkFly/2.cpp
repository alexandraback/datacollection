#include <stdio.h>
#include <iostream>

using namespace std;

class Lawnmower
{
public:
    Lawnmower();
#define MSIZE 200
#define COL_DIRECT 1
#define ROW_DIRECT 2
    bool is_ok();
private:
    int lawn[MSIZE][MSIZE];
    int row_max[MSIZE];
    int col_max[MSIZE];
    int row_size;
    int col_size;
};
Lawnmower::Lawnmower()
{
    scanf("%d %d", &row_size, &col_size);
    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j<col_size; j++)
        {
            scanf("%d", &lawn[i][j]);
        }
    }
    for (int i=0; i<row_size; i++)
    {
        row_max[i] = lawn[i][0];
    }
    for (int j=0; j<col_size; j++)
        col_max[j] = lawn[0][j];
    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j<col_size; j++)
        {
            row_max[i] = std::max(lawn[i][j], row_max[i]);
            col_max[j] = std::max(lawn[i][j], col_max[j]);
        }
    }
}
bool Lawnmower::is_ok()
{
    for (int i=0; i<row_size; i++)
    {
        for (int j=0; j<col_size; j++)
        {
            if (lawn[i][j]<row_max[i] && lawn[i][j] < col_max[j])
            {
                return false;
            }
        }
    }
}
int main()
{
    freopen("D:\\2.in", "r", stdin);
    freopen("D:\\2_ans.txt", "w+", stdout);
    int count;
    scanf("%d", &count);
    for (int i=1; i<=count; i++)
    {
        Lawnmower t;
        bool ans = t.is_ok();
        printf("Case #%d: %s\n",i, ans?"YES":"NO");
    }
    return 0;
}