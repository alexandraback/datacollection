#include <cstring>
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
char s[10050];
bool lef[24][8], righ[24][8], left2[8][8];
int matrix[5][5], multi1[10050], multi2[10050];
inline int multiply(int x, int y){
    int cnt = 0, ans;
    if (x>3){
        x-=4;
        cnt^=1;
    }
    if (y>3){
        y-=4;
        cnt^=1;
    }
    ans = matrix[x][y];
    if (!cnt) return ans;
    if (ans>3) return ans-4;
    return ans+4;
}
int main(void){
    int t, ys = 0, l, x;
    matrix[0][0] = 0, matrix[0][1] = 1, matrix[0][2] = 2, matrix[0][3] = 3;
    matrix[1][0] = 1, matrix[1][1] = 4, matrix[1][2] = 3, matrix[1][3] = 6;
    matrix[2][0] = 2, matrix[2][1] = 7, matrix[2][2] = 4, matrix[2][3] = 1;
    matrix[3][0] = 3, matrix[3][1] = 2, matrix[3][2] = 5, matrix[3][3] = 4;
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    //scanf("%d", &t);
    cin>>t;
    while (t--){
        cin>>l>>x;
        cin>>s;
        //scanf("%s", s);
        if (x>12){
            x = x%4 + 12;
        }
        
        memset(lef, false, sizeof(lef));
        memset(left2, false, sizeof(left2));
        memset(righ, false, sizeof(righ));
        multi1[0] = multi2[l+1] = 0;
        for (int i = 0; i<l; i++){
            int x = 3;
            if (s[i]=='i') x = 1;
            else if (s[i]=='j') x = 2;
            multi1[i+1] = multiply(multi1[i], x);
        }
        for (int i = l-1; i>=0; i--){
            int x = 3;
            if (s[i]=='i') x = 1;
            else if (s[i]=='j') x = 2;
            multi2[i+1] = multiply(x, multi2[i+2]);
        }
        //cout<<"fuck:"<<multiply(1,2)<<endl;
        for (int i = 0; i<l; i++){
            int now = 0;
            for (int j = i+1; j<l; j++){
                int x = 3;
                if (s[j]=='i') x = 1;
                else if (s[j]=='j') x = 2;
                now = multiply(now, x);
                //cout<<i<<"  "<<j<<"  "<<now<<endl;
                if (now==2) left2[multi1[i+1]][multi2[j+2]] = true;
            }
        }
        
        int mul = multi1[l];
        for (int i = 1; i<=l; i++){
            int now = multi1[i];
            for (int j = 0; j<4; j++){
                if (now==1) lef[j+1][multi2[i+1]] = true;
                now = multiply(mul, now);
            }
            now = multi2[i];
            //if (i==1) cout<<"fuck2:"<<now<<endl;
            for (int j = 0; j<4; j++){
                if (now==3) righ[j+1][multi1[i-1]] = true;
                now = multiply(now, mul);
            }
        }
        //cout<<"fuck:"<<lef[2][1]<<"  "<<righ[3][0]<<endl;
        bool ans = false;
        for (int num1 = 0; num1<8; num1++)
            for (int num2 = 0; num2<8; num2++)
                if (left2[num1][num2]){
                    //cout<<"fuck:"<<num1<<"  "<<num2<<endl;
                    for (int i = 0; i<x; i++){
                        int now1 = num1;
                        //cout<<"fuck2:"<<i<<"  "<<x-1-i<<endl;
                        for (int k = 1; k<=i; k++)
                            now1 = multiply(mul, now1);
                        int now2 = num2;
                        for (int k = 1; k<=x-1-i; k++)
                            now2 = multiply(now2, mul);
                        if (now1==1 && now2==3) ans = true;
                    }
                }
        for (int i = 1; i<=x; i++)
            for (int num1 = 0; num1<8; num1++)
                if (lef[i][num1])
                    for (int j = 1; j<=x-i;j++)
                        for (int num2 = 0; num2<8; num2++)
                            if (righ[j][num2]){
                                int now = num1;
                                for (int k = 1; k<=x-i-j; k++)
                                    now = multiply(now, mul);
                                now = multiply(now, num2);
                                if (now==2) ans = true;
                            }
        
        if (ans)
            printf("Case #%d: YES\n", ++ys);
        else printf("Case #%d: NO\n", ++ys);
    }
    return 0;
}
