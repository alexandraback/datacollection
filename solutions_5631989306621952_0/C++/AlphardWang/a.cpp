#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char str[2000];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i)
    {
        scanf("%s", str);
        printf("Case #%d: ", i);
        string fans, bans;
        fans += str[0];
        for (int j = 1; str[j]; ++ j)
        {
            if (str[j] >= fans.back())
            {
                fans.push_back(str[j]);
            }
            else
            {
                bans.push_back(str[j]);
            }
        }
        
        reverse(fans.begin(), fans.end());
        
        printf("%s%s\n", fans.c_str(), bans.c_str());
    }
    
}