#include <iostream>
#include <cstdio>
using namespace std;

int z,e,o,n,t,w,r,f,u,i,v,s,x,g,h;

void answer() {
    int x0,x1,x2,x3,x4,x5,x6,x7,x8,x9;

    x0=z;
    x2=w;
    x4=u;
    x6=x;
    x8=g;
    x5=f-x4;
    x7=s-x6;
    x3=h-x8;
    x1=o-x0-x2-x4;
    x9=i-x5-x6-x8;

    for (int q = 0; q<x0; q++) printf("0");
    for (int q = 0; q<x1; q++) printf("1");
    for (int q = 0; q<x2; q++) printf("2");
    for (int q = 0; q<x3; q++) printf("3");
    for (int q = 0; q<x4; q++) printf("4");
    for (int q = 0; q<x5; q++) printf("5");
    for (int q = 0; q<x6; q++) printf("6");
    for (int q = 0; q<x7; q++) printf("7");
    for (int q = 0; q<x8; q++) printf("8");
    for (int q = 0; q<x9; q++) printf("9");

    printf("\n");
}

int main()
{
    int ncount; scanf("%d", &ncount);
    int cas = 1;
    char c;
    scanf("%c", &c);
    while (cas <= ncount) {
        scanf("%c", &c);

        if (c == 'Z') z++;
        else if (c == 'E') e++;
        else if (c == 'R') r++;
        else if (c == 'O') o++;
        else if (c == 'N') n++;
        else if (c == 'T') t++;
        else if (c == 'W') w++;
        else if (c == 'F') f++;
        else if (c == 'U') u++;
        else if (c == 'I') i++;
        else if (c == 'V') v++;
        else if (c == 'S') s++;
        else if (c == 'X') x++;
        else if (c == 'G') g++;
        else if (c == 'H') h++;
        else {
            printf("Case #%d: ", cas);
            answer();
            cas++;
            z=0;e=0;r=0;o=0;n=0;t=0;w=0;f=0;u=0;i=0;v=0;s=0;x=0;g=0;h=0;
        }
    }


    return 0;
}
