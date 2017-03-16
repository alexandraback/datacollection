#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int kase;
int a, b, len, mul;
int ansx, ansy;
char a1[20], a2[20];
char temp1[20], temp2[20];
bool legal(int a, int b) {
    for (int i=len-1; i>=0; i--) {
        if (temp1[i]!='?')
            if (temp1[i]-'0'!=a%10)
                return false;
        if (temp2[i]!='?')
            if (temp2[i]-'0'!=b%10)
                return false;
        a/=10;
        b/=10;
    }
    return true;
}
int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &kase);
    for (int cas=1; cas<=kase; cas++) {
        mul=1;
        scanf("%s%s", temp1, temp2);
        len=strlen(temp1);
        for (int i=0; i<len; i++)
            mul*=10;
        int mmin=INF;
        for (int i=0; i<mul; i++)
            for (int j=0; j<mul; j++)
                if (legal(i, j)) {
                    int temp=i-j>0?i-j:j-i;
                    if (temp<mmin) {
                        ansx=i;
                        ansy=j;
                        mmin=temp;
                    }
                }
        for (int i=0; i<len; i++)
            a1[i]=a2[i]='0';
        a1[len]=a2[len]=0;
        int ptr=len-1;
        while (ansx) {
            a1[ptr--]=ansx%10+'0';
            ansx/=10;
        }
        ptr=len-1;
        while (ansy) {
            a2[ptr--]=ansy%10+'0';
            ansy/=10;
        }
        printf("Case #%d: %s %s\n", cas, a1, a2);
    }
    return 0;
}
