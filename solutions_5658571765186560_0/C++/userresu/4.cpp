#include <cstdio>
using namespace std;

int T;
int X,R,C;
int main () {
    freopen("4.in","r",stdin);
    freopen("4.out","w",stdout);
    scanf("%d",&T);
    for (int z=1;z<=T;++z) {
        scanf("%d %d %d",&X,&R,&C);
        printf("Case #%d: ",z);
        bool ok=1;
        if (X==1);
        else if (X==2) {
            if (R%2 && C%2) ok=0;
        }
        else if (X==3) {
            if (R%3 && C%3 || R<2 || C<2) ok=0;
        }
        else if (X==4) {
            if (R%4==0 || C%4==0) {
                if (R<3 || C<3) ok=0;
            }
            else if (R%2==0 && C%2==0) {
                if (R<6 || C<6) ok=0;
            }
            else ok=0;
        }
        else if (X==5) {
            if (R%5==0 || C%5==0) {
                if (R<3 || C<3) ok=0;
                else if ((R<4 || C<4) && R<10 && C<10) ok=0;
            }
            else ok=0;
        }
        else if (X==6) {
            if (R%6==0 || C%6==0) {
                if (R<3 || C<3) ok=0;
            }
            else if (R%3==0 && C%2==0) {
                if (C<8) ok=0;
            }
            else if (R%2==0 && C%3==0) {
                if (R<8) ok=0;
            }
            else ok=0;
        }
        else ok=0;
        if (ok) printf("GABRIEL\n");
        else printf("RICHARD\n");
    }
    return 0;
}
