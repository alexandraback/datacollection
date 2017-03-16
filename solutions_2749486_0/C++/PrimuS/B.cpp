#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

pair<int, int> field[300][300][300];
int was_in[300][300][300];
char buf [1000];

int x, y;

//int nums[600];

void bfs()
{
    queue<pair<int, int> > q;
    q.push(make_pair<int, int>(150 * 1000 + 150, 0));

    int c = 0;
    while (!q.empty())
    {
        //printf("processing %d\n", c);
        //++c;
        int t = q.front().first;
        int step = q.front().second;
        q.pop();

        int x_1 = t / 1000;
        int y_1 = t % 1000;

        if (x_1 - 150 == x && y_1 - 150 == y)
            return;

        step++;

        if (x_1 - step > 0 && !was_in[x_1 - step][y_1][step])
        {
            field[x_1 - step][y_1][step].first = step;
            field[x_1 - step][y_1][step].second = t;
            was_in[x_1 - step][y_1][step] = 1;
            q.push(make_pair<int, int>((x_1 - step) * 1000 + y_1, step));
        }
        if (x_1 + step < 300 && !was_in[x_1 + step][y_1][step])
        {
            field[x_1 + step][y_1][step].first = step;
            field[x_1 + step][y_1][step].second = t;
            was_in[x_1 + step][y_1][step] = 1;
            q.push(make_pair<int, int>((x_1 + step) * 1000 + y_1, step));
        }
        if (y_1 - step > 0 && !was_in[x_1][y_1 - step][step])
        {
            field[x_1][y_1 - step][step].first = step;
            field[x_1][y_1 - step][step].second = t;
            was_in[x_1][y_1 - step][step] = 1;
            q.push(make_pair<int, int>((x_1) * 1000 + y_1 - step, step));
        }
        if (y_1 + step < 300 && !was_in[x_1][y_1 + step][step])
        {
            field[x_1][y_1 + step][step].first = step;
            field[x_1][y_1 + step][step].second = t;
            was_in[x_1][y_1 + step][step] = 1;
            q.push(make_pair<int, int>((x_1) * 1000 + y_1+ step, step));
        }
    }
}

int main()
{
    //freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\a-big.in", "r", stdin);
    freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\B-small-attempt2.in", "r", stdin);
    //freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\b-small.in", "r", stdin);
    freopen("d:\\dev\\acm\\CodeJam2013_1C\\CodeJam2013_1C\\b_small.out", "w", stdout);

    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; ++t)
    {
        scanf("%d%d", &x, &y);

        memset(field, 0, sizeof(field));
        memset(was_in, 0, sizeof(was_in));
        memset(buf, 0, sizeof(buf));
        //memset(nums, 0, sizeof(nums));

        //field[150][150].first = 1;
        bfs();
        printf("Case #%d: ", t + 1);

        int cur_x = x + 150;
        int cur_y = y + 150;

        int last_step = -1;
        for (int i = 0; i < 300; ++i)
        {
            if (field[cur_x][cur_y][i].first != 0)
            {
                last_step = i;
                break;
            }
        }

        int step = last_step;

        while (step != 0)
        {
            int u = field[cur_x][cur_y][step].second;

            int prev_x = u / 1000;
            int prev_y = u % 1000;

            char dir = '\n';
            if (prev_x < cur_x)
            {
                cur_x = prev_x;
                dir = 'E';
            }
            else if (prev_x > cur_x)
            {
                cur_x = prev_x;
                dir = 'W';
            }
            else if (prev_y > cur_y)
            {
                cur_y = prev_y;
                dir = 'S';
            }
            else 
            {
                cur_y = prev_y;
                dir = 'N';
            }

            buf[step - 1] = dir;
            //printf("%c", dir);
            step --;
        }

        buf[last_step] = '\0';

        printf("%s\n", buf);

        //bool f= false;
        //for (int i = 0; i <= 500 && !f; ++i)
        //{
        //    memset(nums, 0, sizeof(nums));

        //    if (i == 9)
        //        int yoi = 9;

        //    int cur_x = abs(x);
        //    int cur_y = abs(y);

        //    for (int j = i; j >= 1; --j)
        //    {
        //        if (cur_x >= j)
        //        {
        //            cur_x -= j;
        //            nums[j] = 1;
        //        }
        //        else if (cur_y >= j)
        //        {
        //            cur_y -=j;
        //            nums[j] = 3;
        //        }
        //        else if (cur_x != 0)
        //        {
        //            cur_x += j;
        //            nums[j] = 2;
        //        }
        //        else
        //        {
        //            cur_y += j;
        //                nums[j] = 4;
        //        }
        //    }

        //    if (cur_x == 0 && cur_y == 0)
        //        f = true;
        //}

        //for (int i = 1; nums[i] != 0; ++i)
        //{
        //    if (nums[i] == 1 && x >= 0 || nums[i] == 2 && x <= 0)
        //        printf("E");
        //    else if (nums[i] == 1 && x < 0 || nums[i] == 2 && x > 0)
        //        printf("W");
        //    else if (nums[i] == 3 && y < 0 || nums[i] == 4 && y > 0) 
        //        printf("S");
        //    else
        //        printf("N");
        //}

        //printf("\n");

        fflush(stdout);
    }
    return 0;
}