#include "iostream"
#include "cstring"
#include "cstdio"
using namespace std;
char s[1010];
int main(void)
{
    int T;
    scanf("%d", &T);
    int g = 0, n;
    while(T--){
        printf("Case #%d: ", ++g);
        scanf("%s", s);
        int len = strlen(s);
        string str = "";
        str += s[0];
        for(int i = 1; i < len; ++ i){
            if(s[i] >= str[0]) {
                string tmp = "";
                str = tmp + s[i] + str;
            }else{
                str = str + s[i];
            }
        }
        cout << str << endl;
    }
    return 0;
}