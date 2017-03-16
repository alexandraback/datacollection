#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
fstream inputf("C-small-attempt0.in");
fstream outputf("output.txt");
string tt;
bool geti,getk,ans;//0=1 1=i 2=j 3=k
int cs,cd,n,m,i,j,k,cur,tot;
void muli() {
    int ncd;
switch (cd) {
case 0:
    ncd = 1;
    break;
case 1:
    ncd = 0;cs = -cs;
    break;
case 2:
    ncd = 3;cs = -cs;
    break;
default:
    ncd = 2;
    break;}
cd = ncd;
}
void mulj() {
    int ncd;
switch (cd) {
case 0:
    ncd = 2;
    break;
case 1:
    ncd = 3;
    break;
case 2:
    ncd = 0;cs = -cs;
    break;
default:
    ncd = 1;cs = -cs;
    break;}
cd = ncd;
}
void mulk() {
    int ncd;
switch (cd) {
case 0:
    ncd = 3;
    break;
case 1:
    ncd = 2;cs = -cs;
    break;
case 2:
    ncd = 1;
    break;
default:
    ncd = 0;cs = -cs;
    break;}
cd = ncd;
}
int main()
{
    inputf >> tot;
    for (int cur=1; cur <= tot; cur++) {
        inputf >> n >> m;
        if (m>11) m = 8+m%4;
        cs = 1;cd = 0;geti = 0; getk = 0;
        inputf >> tt;
        for (int cm = 0; cm < m; cm++)
            for (int i = 0; i < n; i++)
            {
                if (tt[i]=='i') muli();
                else if (tt[i]=='j') mulj();
                else if (tt[i]=='k') mulk();
                if (cs == 1) {
                    if (cd == 1) geti = true;
                    if ((geti)&&(cd == 3)) getk = true;
                }
            }
        if ((cs == -1) && (cd == 0)) ans = getk; else ans = false;
        if (ans)
            outputf << "Case #" << cur << ": YES" << endl;
        else
            outputf << "Case #" << cur << ": NO" << endl;
    }
    inputf.close();
    outputf.close();
}
