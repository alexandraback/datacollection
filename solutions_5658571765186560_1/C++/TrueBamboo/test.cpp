//Discuss by case for x<=6
//no solution for x>6 since hole exists in one or more ominos
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstring>
#include <queue>
using namespace std;

FILE *fin=freopen("in.txt","r",stdin);
FILE *fout=freopen("out.txt","w",stdout);

int main() {
    int T,t,x,r,c;
    cin>>T;
    for (t=1;t<=T;t++) {
        cin>>x>>r>>c;
        printf("Case #%d: ",t);
        if (r<c)
        swap(r,c);
        if (x==1)
        printf("GABRIEL\n");
        else if (x==2)
                if (r*c%2==0)
                printf("GABRIEL\n");
                else printf("RICHARD\n");
        else if (x==3)
                if (r>=3 && r*c%x==0 && c>1)
                printf("GABRIEL\n");
                else printf("RICHARD\n");
        else if (x==4)
             if (r>=4 && r*c%x==0 && c>2)
             printf("GABRIEL\n");
             else printf("RICHARD\n");
        else if (x==5)
             if (r>=5 && r*c%x==0 && (c>3 || (c==3 && r>=10)))
                printf("GABRIEL\n");
                else printf("RICHARD\n");
        else if (x==6)
             if (r>=6 && r*c%x==0 && c>3)
                printf("GABRIEL\n");
                else printf("RICHARD\n");
        else printf("RICHARD\n");
    }
    return 0;
}
