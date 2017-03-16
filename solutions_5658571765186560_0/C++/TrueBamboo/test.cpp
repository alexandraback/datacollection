//For small case, calculate using hand...
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
        if (x==1)
        printf("GABRIEL\n");
        else if (x==2)
                if (r*c%2==0)
                printf("GABRIEL\n");
                else printf("RICHARD\n");
        else if (x==3)
                if ((r<3 && c<3) || r==1 || c==1 || r*c%3!=0)
                printf("RICHARD\n");
                else printf("GABRIEL\n");
        else if (r+c<7)
             printf("RICHARD\n");
             else printf("GABRIEL\n");
    }
    return 0;
}
