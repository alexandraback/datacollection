#include<cstdio>

#define MAX_LEN 10010

#define MATRIX_NUM 5
int MATRIX[MATRIX_NUM][MATRIX_NUM] = {{0,0,0,0,0},
                                      {0,1,2,3,4},
                                      {0,2,-1,4,-3},
                                      {0,3,-4,-1,2},
                                      {0,4,3,-2,-1}};
//return a*b
int multi(int a, int b)
{
    if(a > 0 && b > 0)
        return MATRIX[a][b];
    if(a < 0 && b > 0)
        return -1*MATRIX[-1*a][b];
    if(a > 0 && b < 0)
        return -1*MATRIX[a][-1*b];
    if(a < 0 && b < 0)
        return MATRIX[-1*a][-1*b];

    return 0;
}

//return pow(value, num)
int extPow(int value, int num)
{
    int result = 1;
    for(int i=0; i<num; i++)
        result = multi(result, value);
    return result;
}

// a*b = c;  get a
int divide1(int value, int item2)
{
    if(item2 == 1)
        return value;
    if(item2 == -1)
        return -1*value;

    //return c*b*-1;
    return -1*multi(value, item2);
}

// a*b = c;  get b
int divide2(int value, int item1)
{
    if(item1 == 1)
        return value;
    if(item1 == -1)
        return -1*value;

    //return a*c*-1;
    return -1*multi(item1, value);
}

// pow(value, x) == result; get x
int needPow(int value, int result)
{
    if(result == 1)
        return 0;

    if(result == value)
        return 1;

    if(result == -1)
    {
        if(value == 1)
            return -1;
        return 2;
    }

    if(result == -1*value)
    {
        if(value == 1)
            return -1;
        return 3;
    }

    return -1;
}

int convert(char value)
{
    if(value == '1')
        return 1;
    if(value == 'i')
        return 2;
    if(value == 'j')
        return 3;
    if(value == 'k')
        return 4;

    return 0;
}

class item
{
public:
    int value;
    int i_left;
    int k_right;
    int left_value;
    int right_value;
    int whole_value;
};


class Dijkstra
{
public:
    Dijkstra(){}
    int Input()
    {
        scanf("%d %d", &L, &K);

        char buffer[MAX_LEN+1];
        scanf("%s", buffer);

        for(int i=0; i<L; i++)
        {
            itemList[i].value = convert(buffer[i]);
        }
        return 0;
    }

    int Init()
    {
        int result = 1;
        int i=0;

        //compute the left_value
        for(; i<L; i++)
        {
            result = multi(result, itemList[i].value);
            itemList[i].left_value = result;

            //printf("index:%d left_value:%d\n", i, result);
        }

        //save the value of the length
        LenValue = result;
        //printf("LenValue:%d\n", LenValue);

        //compute the right_value
        for(i=0; i<L; i++)
        {
            int right_value = divide2(LenValue, itemList[i].left_value);
            itemList[i].right_value = multi(itemList[i].value, right_value);
            //printf("Fuck index:%d right:%d value:%d\n", i, right_value, itemList[i].value);
           // printf("index:%d right_value:%d\n", i, itemList[i].right_value);
        }

        //compute the whole_value
        for(i=0; i<L; i++)
        {
            if(i == L-1)
                itemList[i].whole_value = LenValue;
            else
                itemList[i].whole_value = multi(itemList[i+1].right_value, itemList[i].left_value);
        }

        //compute the i_left
        //pow(LenValue, i_left) * left_value == i
        for(i=0; i<L; i++)
        {
            int needResult = divide1(2, itemList[i].left_value);
            itemList[i].i_left = needPow(LenValue, needResult);
            //printf("index:%d left:%d\n", i, itemList[i].i_left);
        }

        //compute the k_right
        //pow(LenValue, k_right) * right_value == k
        for(i=0; i<L; i++)
        {
            int needResult = divide2(4, itemList[i].right_value);
            itemList[i].k_right = needPow(LenValue, needResult);
            //printf("index:%d right:%d\n", i, itemList[i].k_right);
        }

        return 0;
    }

    int Split()
    {
        for(int i=0; i<L; i++)
            for(int j=0; j<L; j++)
            {
                int left = itemList[i].i_left;
                int right = itemList[j].k_right;

                if(left == -1 || right == -1)
                    continue;

                if(left + right + 1 > K)
                    continue;

                int diff = (K - (left + right + 1)) % 4;

                if(i+1 < j)
                {
                    //printf("left:%d right:%d left_need:%d right_need:%d\n", i, j, left, right);
                    int value_i_j = divide1(itemList[i].right_value, itemList[j].right_value);
                    value_i_j = divide2(value_i_j, itemList[i].value);

                    int diff_value = extPow(itemList[i].whole_value, diff);
                    //printf("index:%d whole:%d diff:%d\n", i, itemList[i].whole_value, diff);
                    
                    int result = multi(diff_value, value_i_j);
                    //printf("value_i_j:%d diff_value:%d result:%d\n", value_i_j, diff_value, result);

                    //judge result is j
                    if(result == 3)
                        return 1;

                }
                else// if(i >= j)
                {
                    if(K == left + right + 1)
                        continue;

                    diff = (K - (left + right + 2)) % 4;
                    //printf("i:%d left:%d j:%d right:%d diff:%d\n", i, left, j, right, diff);

                    int value_1st, value_2nd, value_3rd;

                    if(i < L-1)
                        value_1st = itemList[i+1].right_value;
                    else
                        value_1st = 1;

                    value_2nd = extPow(LenValue, diff);

                    if(j > 0)
                        value_3rd = itemList[j-1].left_value;
                    else
                        value_3rd = 1;

                    int result = multi(value_1st, value_2nd);
                    result = multi(result, value_3rd);

                    //printf("1st:%d 2nd:%d 3rd:%d\n", value_1st, value_2nd, value_3rd);

                    //judege result is j
                    if(result == 3)
                        return 1;
                }

            }
        return 0;
    }

private:
    item itemList[MAX_LEN];
    int L, K;
    int LenValue;
};


Dijkstra test_obj;
int main(int argc, char* argv[])
{
    int T=0;
    scanf("%d", &T);

    for(int i=0; i<T; i++)
    {
        test_obj.Input();
        test_obj.Init();

        int ret = test_obj.Split();
        if(ret == 1)
            printf("Case #%d: YES\n", i+1);
        else
            printf("Case #%d: NO\n", i+1);
    }
    return 0;
}

