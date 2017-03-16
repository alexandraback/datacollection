#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int TEST;
    scanf("%d", &TEST);
    for (int i = 1; i <= TEST; ++i)
    {
        string str;
        int x;
        cin >> x;
        cin >> str;
        int sum = 0;
        int plus = 0;
        for (int j = 0; j < str.size(); ++j)
        {
            if (sum >= j)
            {
                sum += int(str[j] - '0');
            }
            else
            {
                plus += j - sum;
                sum += j - sum + int(str[j] - '0');
            }

        }
        printf("Case #%d: %d\n", i, plus);
    }

}
