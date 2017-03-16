#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t, r, c, mines, e;
char a[100][100];

int solve()
{
    for(int i=1; i<=r; i++)
        for(int j=1; j<=c; j++)
            a[i][j] = '*';
    a[1][1] = 'c';
    e = r*c - mines;
    if(e == 1) return 1;
    else if(e <= 0) return 0;
    else if(r == 1){
        e--;
        for(int j=2; e; j++){
            a[1][j] = '.';
            e--;
        }
        return 1;
    }
    else if(c == 1){
        e--;
        for(int i=2; e; i++){
            a[i][1] = '.';
            e--;
        }
        return 1;
    }
    else{
        if(e==2 || e==3 || e==5 || e==7)
            return 0;
        a[2][1] = a[1][2] = a[2][2] = '.';
        e-=4;
        if(e == 0) return 1;
        int crth=3, crtv=4;
        if(r > 2){
            a[3][1] =  a[3][2] = '.';
            e-=2;
        }
        else if(e%2==1)
            return 0;
        if(e==0) return 1;

        if(c==2 && e%2==1) return 0;

        while(e >= 2 && crth<=c){
            a[1][crth] = a[2][crth] = '.';
            e -= 2;
            crth++;
        }
        if(e == 0) return 1;
        if(e == 1){
            a[3][3] = '.';
            return 1;
        }
        while(e >=2 && crtv<=r){
            a[crtv][1] = a[crtv][2] = '.';
            e -=2;
            crtv++;
        }
        if(e == 0) return 1;
        if(e == 1){
            a[3][3] = '.';
            return 1;
        }
        for(int i=3; i<=r && e; i++)
            for(int j=3; j<=c && e; j++){
                a[i][j] = '.';
                e--;
            }
        if(e) return 0;
        else return 1;
    }
}

void afisare()
{
    for(int i=1; i<=r; i++){
        for(int j=1; j<=c; j++)
            printf("%c", a[i][j]);
        printf("\n");
    }
}

int main()
{
    freopen("Input", "r", stdin);
    freopen("Output", "w", stdout);

    scanf("%d", &t);
    for(int i=1; i<=t; i++){
        scanf("%d %d %d", &r, &c, &mines);
        printf("Case #%d:\n", i);
        if(solve())
            afisare();
        else{
            printf("Impossible\n");
            //cerr << r*c - mines << "\t" << i <<"\n";
        }
    }
    return 0;
}
