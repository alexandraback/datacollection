#include <iostream>
#include <fstream>
using namespace std;
fstream inputf("D-small-attempt0.in");
fstream outputf("output.txt");
int x,r,c,tot,cur;
int main() {
    inputf >> tot;
    for (int cur=1;cur<=tot;cur++)
    {
        inputf >> x >> r >> c;
        bool ans;
        switch (x) {
    case 1:
        ans = true;
        break;
    case 2:
        ans = true;
        break;
    case 3:
        ans = (r*c>5);
        break;
    default:
        ans = (r*c>11);
        }
    r = r*c;
    if ((r%x)>0) ans = false;
    if (ans)
        outputf << "Case #" << cur << ": GABRIEL" << endl;
    else
        outputf << "Case #" << cur << ": RICHARD" << endl;
    }
    inputf.close();
    outputf.close();
}
