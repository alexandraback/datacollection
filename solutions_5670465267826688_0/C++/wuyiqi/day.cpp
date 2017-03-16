#include <cstdio>
#include <map>
#include <string>
#include <queue>
#include<algorithm>
#include <cstring>
#include <vector>
using namespace std;
char str[10010];
char s[10010];
int mp[256];
char mat[4][5] = {
        "1ijk", "i1kj", "jk1i", "kji1"
};
int fuhao[4][4] = {
        {1,1,1,1},{1,-1,1,-1},{1,-1,-1,1},{1,1,-1,-1}
};
char go(int &sgn, char A, char B)
{
        sgn *= fuhao[mp[A]][mp[B]];
        return mat[mp[A]][mp[B]];
}
int find(int front, int end, char target)
{
        char ch = s[front];
        int sign = 1;
        if(ch == target && sign == 1) {
                return front+1;
        }
        for(int i = front +1; i < end; i++) {
                if(ch == target && sign == 1) {
                        return i;
                }
                ch = go(sign, ch, s[i]);
        }
        if(ch == target && sign == 1) {
                return end;
        }
        return -1;
}
bool gao(int len)
{
        int p = find(0, len, 'i');
        if(p == -1) return false;
        int q = find(p, len, 'j');
        if(q == -1) return false;
        int x = find(q, len, 'k');
       // printf("p=%d q=%d\n", p, x);
        if(x == -1) return false;
        if(x < len) {
                char ch = s[x];
                int sign = 1;
                for(int i = x + 1; i < len; i++) {
                        ch = go(sign, ch, s[i]);
                }
                return ch == '1' && sign == 1;
        }
        return true;
}
int main()
{
     freopen("C-small-attempt2.in","r", stdin);
     freopen("C-small-attempt2.out","w",stdout);
        mp['1'] = 0;
        mp['i'] = 1;
        mp['j'] = 2;
        mp['k'] = 3;
        int t, ca = 1;
        scanf("%d", &t);
        while(t--) {
                int X, L;
                scanf("%d%d", &X, &L);
                scanf("%s", str);
                int len = 0;
                for(int i = 0; i < L; i++) {
                        strcpy(s + len, str);
                        len += X;
                }
                printf("Case #%d: ", ca++);
                if(gao(len)){
                        puts("YES");
                } else {
                        puts("NO");
                }
        }
        return 0;
}
