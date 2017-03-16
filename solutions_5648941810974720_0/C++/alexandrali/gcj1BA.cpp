#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <complex>
#include <map>
using namespace std;
#define LL long long

const int MXL = 2010;

int T, n, cnt[35], equation, variable;
int Up[MXL], Down[MXL];  //Up 存储的是分子， Down存储的是分母
bool Free[MXL];
int A[35][15];
char w[15][MXL] = {
"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
};
char ch[MXL];
int Gauss() {
    int col=1, row=1;
    equation = 26, variable = 10; //
    for(; row<=equation && col<=variable; row++, col++)
    {
        int max_row=row;

        //找到 col 那列元素绝对值最大的那行与当前行交换，减小精度误差
        for(int i=row+1; i<=equation; i++)
            if(abs(A[i][col])>abs(A[max_row][col]))
                max_row=i;

        //如果 col 那列元素最大是 0，表明这一列全部是 0，处理下一列
        if(A[max_row][col]==0)
        {
            row--;
            continue;
        }

        //如果不是同一行，交换元素
        if(max_row!=row)
        {
            for(int i=col; i<=variable+1; i++)
                swap(A[max_row][i], A[row][i]);
        }

        //枚举要删去的行
        //for(int i=row+1; i<=equation; i++)
        for(int i=1; i<=equation; i++)
        {
            if(i==row) continue;
            if(A[i][col]==0) continue;
            int GCD=__gcd(abs(A[i][col]), abs(A[row][col]));
            int ta=abs(A[row][col]) / GCD;
            int tb=abs(A[i][col])   / GCD;

//            printf("ta=%d tb=%d\n",ta,tb);

            //如果异号，应该相加
            if((A[i][col]>0 && A[row][col]<0) || (A[i][col]<0 && A[row][col]>0)) tb=-tb;

            //对于 j 的起点问题，如果我是只把当前行后面的行的元素消掉，我可以是从 col 开始，
            //但如果是从第一行开始消掉，必须从 1 开始
            for(int j=1; j<=variable+1; j++)
                A[i][j]=A[i][j]*ta-A[row][j]*tb;
            //A[i][j]-=A[row][j]*tb/ta;
        }
//        printf("row=%d col=%d\n", row, col);
//        debug();
    }

//    debug();

    // 1、没有解的情况：
    for(int i=row; i<=equation; i++)
        if(A[i][variable+1]!=0) return -1; //表明无解

    // 2、无穷解的情况：
    if(row<variable+1)
    {
        for(int i=row-1; i>=1; i--)
        {
            int free_x_num=0, free_index=-1;
            for(int j=1; j<=variable; j++)
                if(Free[j] && A[i][j]!=0)
                {
                    free_x_num++;
                    free_index=j;
                }
            if(free_x_num>1) continue;

            Free[free_index]=false;
            int Up_temp=A[i][variable+1];
            int Down_temp=1;
            for(int j=1; j<=variable; j++)
                if(A[i][j]!=0 && j!=free_index)
                {
                    int GCD=__gcd(abs(Down[j]), abs(A[i][j]));
                    int U=Up[j]*A[i][j]/GCD;
                    int D=Down[j]/GCD;
                    GCD=__gcd(abs(D), abs(Down_temp));
                    int ta=D/GCD;
                    int tb=Down_temp/GCD;
                    Up_temp=Up_temp*ta-U*tb;
                    Down_temp*=ta;
                    GCD=__gcd(abs(Up_temp), abs(Down_temp));
                    Up_temp/=GCD;
                    Down_temp/=GCD;
                }
            if(Up_temp==0)
            {
                Up[free_index]=0;
                continue;
            }
            int GCD=__gcd(abs(Up_temp), abs(A[i][free_index]));
            Down[free_index]=A[i][free_index]/GCD*Down_temp;
            Up[free_index]=Up_temp/GCD;
        }
        return variable-row+1;
    }

    // 3、唯一解的情况：
    for(int i=variable; i>=1; i--)
    {
        int Up_temp=A[i][variable+1];
        int Down_temp=1;
        for(int j=i+1; j<=variable; j++)
            if(A[i][j]!=0)
            {
                int GCD=__gcd(abs(Down[j]), abs(A[i][j]));
                int U=Up[j]*A[i][j]/GCD;
                int D=Down[j]/GCD;
                GCD=__gcd(abs(D), abs(Down_temp));
                int ta=D/GCD;
                int tb=Down_temp/GCD;
                Up_temp=Up_temp*ta-U*tb;
                Down_temp*=ta;
                GCD=__gcd(abs(Up_temp), abs(Down_temp));
                Up_temp/=GCD;
                Down_temp/=GCD;
            }
        if(Up_temp==0)
        {
            Up[i]=0;
            continue;
        }
        int GCD=__gcd(abs(Up_temp), abs(A[i][i]));
        Down[i]=A[i][i]/GCD*Down_temp;
        Up[i]=Up_temp/GCD;
    }
    return 0;
}
inline void Prepare() {
	memset(A, 0, sizeof(A));
	for(int i = 0; i <= 9; i++) {
		int l = strlen(w[i]);
		// printf("%s\n", w[i]);
		for(int j = 0; j < l; j++) {
			A[w[i][j] - 'A' + 1][i + 1]++;
		}
	}
	for(int i = 0; i < 26; i++) A[i + 1][11] = cnt[i + 1]; //
}
inline void solve() {
	scanf("%d\n", &T);
	for(int ii = 1; ii <= T; ii++) {
		scanf("%s\n", ch);
		// printf("%s\n", ch);
		n = strlen(ch);
		for(int i = 1; i <= 26; i++) cnt[i] = 0;
		for(int i = 0; i < n; i++) cnt[ch[i] - 'A' + 1]++;
		Prepare();
		printf("Case #%d: ", ii);

		Gauss();

		// for(int i = 1; i < 26; i++) {
		// 	for(int j = 1; j <= 11; j++) printf("%d ", A[i][j]);
		// 	printf("\n");
		// }
		for(int i = 0; i <= 9; i++) {
			//printf("%d\n", a[i][M]);
			int tmp = A[i + 1][variable + 1] / A[i + 1][i + 1];
			//printf("%d %d %d\n", i, A[i + 1][variable + 1], A[i + 1][i + 1]);
			for(int j = 1; j <= tmp; j++) printf("%d", i);
		}
		printf("\n");
	}
}
int main() {
	freopen("gcj1BA.in","r",stdin);freopen("gcj1BA.out","w",stdout);
	solve();
	return 0;
}
