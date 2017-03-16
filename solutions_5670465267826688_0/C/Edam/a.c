#include <stdio.h>
#include <stdlib.h>
#define _i 2
#define _j 3
#define _k 4

int quaternion(int para1, int para2)
{
    int sig;
    int a, b;
    
    if(para1 * para2 >= 0)
        sig = 1;
    else
        sig = -1;
    
    a = abs(para1);
    b = abs(para2);
    
    if (a == 1 || b == 1)
        return (sig * a * b);
    if (a == b && a != 1)
        return ((-1) * sig);
    if (a == _i && b == _j)
        return (sig * _k);
    if (a == _j && b == _i)
        return (sig * (-1) * _k);
    if (a == _i && b == _k)
        return (sig * (-1) * _j);
    if (a == _k && b == _i)
        return (sig * _j);
    if (a == _j && b == _k)
        return (sig * _i);
    if (a == _k && b == _j)
        return (sig * (-1) * _i);
    
    return 255;
}


int main(void)
{
    int T, execTime;
    int Flag;
    int L, X, length;
    int tmp;
    char tmpChar;
    int data[10005], all[10005];
    int j, k;
    freopen("C-small-attempt1.in.txt", "r", stdin);
    //freopen("in.txt", "r", stdin);
    scanf("%d", &T);
    freopen("Result.txt", "w", stdout);
    for(execTime = 0; execTime < T; execTime++) {
        Flag = 0;
        scanf("%d %d ", &L, &X);
        length = X * L;
        for(j = 0; j < L; j++) {
            scanf("%c", &tmpChar);
            //putchar(tmpChar);
            for (k = 0; k < X; k++)
                all[k*L+j] = (tmpChar-'i'+2);
        }
        
        if(length > 3) {
            
            tmp = all[0];
            k = 1;
            
            do {
                if (k >= length)
                    goto END;
                tmp = quaternion(tmp, all[k++]);
            } while (tmp != _i);
            
            tmp = all[k++];
            do {
                if (k >= length)
                    goto END;
                tmp = quaternion(tmp, all[k++]);
            } while (tmp != _j);
            
            if (k >= length)
            	goto END;
            tmp = all[k++];
            while(k < length) {
                tmp = quaternion(tmp, all[k++]);
            }
            
            if (tmp == _k)
	            Flag = 1;
            
        } else if(length == 3) {
            if (all[0] == _i && all[1] == _j && all[2] == _k)
                Flag = 1;
        }
END:
        if(Flag)
            printf("Case #%d: YES\n", execTime+1);
        else
            printf("Case #%d: NO\n", execTime+1);
    }
    return 0;
}