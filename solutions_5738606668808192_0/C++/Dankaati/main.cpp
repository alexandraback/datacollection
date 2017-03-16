#include <bits/stdc++.h>

using namespace std;

int y, n;
int t[32];



int main()
{
    freopen("3.out","w",stdout);
    cout << "Case #1:" << endl;
    for(int i=0;i<50;i++) {
        for(int j=0;j<32;j++) t[j]=0;
        t[0]=t[15]=1;
        int a=i/7,b=i%7;
        a=2*a+1;
        b=2*b+2;
        if(i==49) a=b=30;
        t[a]++;
        t[b]++;
        for(int j=0;j<16;j++) cout << t[j];
        cout << " 3 4 5 6 7 8 9 10 11" << endl;
    }
    return 0;
}
