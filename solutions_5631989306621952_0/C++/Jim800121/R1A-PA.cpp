#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void solve(char str[]);
int main()
{
    int T;
    int cnt=1;
    scanf("%d", &T);
    while (cnt <= T)
    {
        char str[3000];
        scanf("%s", str);
        solve(str);
        printf("Case #%d: %s\n", cnt, str);
        cnt++;
    }

    return 0;
}
void solve(char str[])
{
    char out[3000]={0};
    int len = strlen(str);
    out[1500] = str[0];
    int left, right;
    left = right = 1500;
    for(int i=1; i<len; i++)
    {
        if(str[i]<out[left])
        {
            right++;
            out[right] = str[i];
        }
        else
        {
            left--;
            out[left] = str[i];
        }
    }
    for(int i=left, j=0; i<=right; i++,j++)
    {
        str[j] = out[i];
    }
    str[len] = '\0';
}
