#include <cstdio>
#include <algorithm>

using namespace std;

const int POINT_SIZE_MAX = 200;

struct Point
{
    int data;
    int seq;
};
Point point[POINT_SIZE_MAX + 100];
double result[POINT_SIZE_MAX + 100];

bool comp(const Point&lhs, const Point& rhs)
{
    return lhs.data < rhs.data;
}

void print(int i, char *p)
{
    printf("%s : %d\n", p, i);
}

int main()
{
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);

    int case_total;
    scanf("%d", &case_total);
    for (int case_i = 1; case_i <= case_total; case_i++)
    {
        int size;
        scanf("%d", &size);
        for (int i = 0; i < size; i++)
        {
            point[i].seq = i;
            scanf("%d", &point[i].data);
        }

        sort(point, &point[size], comp);

        int sum = 0;
        for (int i = 0; i < size; i++)
            sum += point[i].data;
//        printf("sum : %d\n", sum);

        for (int i = 0; i < size; i++)
        {
            for (int j = i; j < size; j++)
            {
                int cur_sum = sum;
                for (int k = 0; k < j; k++)
                    cur_sum = cur_sum - (point[j].data - point[k].data);
//                print(cur_sum, "cur_sum");
                if (cur_sum < 0)
                {
                    result[ point[i].seq ] = 0.0;
                    break;
                }
                double avg = point[j].data + (double)cur_sum / (j+1);
//                print(avg, "avg");
                if (j == size - 1 || avg <= point[j+1].data)
                {
//                    print(j, "j");
//                    print(avg, "avg");
//                    print(point[i].seq  , "point[i].seq  ");
//                    print(result[ point[i].seq ] , "result[ point[i].seq ] ");
//                    print(((double)avg - point[i].data) * 100 / sum, "((double)avg - point[i].data) * 100 / sum");
                    result[ point[i].seq ] = ((double)avg - point[i].data) * 100 / sum;
//                    print(result[ point[i].seq ] , "result[ point[i].seq ] ");
//                    printf("\n");
                    break;
                }
            }
        }

        printf("Case #%d:", case_i);
        for (int i = 0; i < size; i++)
            printf(" %6f", result[i]);
        printf("\n");
    }

    return 0;
}

