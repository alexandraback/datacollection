#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_map>


const int SIZE = 1000002;
bool visited[SIZE];


int reverse(int num)
{
    int result = 0;
    int digit;
    while(num)
    {
        digit = num % 10;
        result = result * 10 + digit;
        num /= 10;
    }
    return result;
}


int main()
{
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/round-1-B/A-small-attempt0.in","r",stdin);
    //freopen("/Users/guanxiong/Documents/documents/google_code_jam/round-1-B/A-small-attempt0.out","w",stdout);
    int cases;
    int target;
    scanf("%d", &cases);
    for(int case_num = 1; case_num <= cases; case_num ++)
    {
        scanf("%d", &target);
        std::queue<int> que;
        que.push(1);
        que.push(-1);
        int count = 1;
        memset(visited, false, sizeof(visited));
        visited[1] = true;
        while(!que.empty())
        {
            int curr = que.front();
            que.pop();
            if(curr == -1)
            {
                if(!que.empty())
                {
                    count ++;
                    que.push(-1);
                }
            }
            else
            {
                if(curr == target)
                {
                    printf("Case #%d: %d\n", case_num, count);
                    break;
                }
                else
                {
                    if(!visited[curr+1])
                    {
                        que.push(curr+1);
                        visited[curr+1] = true;
                    }
                    int rev = reverse(curr);
                    if(!visited[rev])
                    {
                        que.push(rev);
                        visited[rev] = true;
                    }
                }
            }
        }
    }
    return 0;
}

