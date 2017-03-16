#include <bits/stdc++.h>

using namespace std;

int y, n;
int t[32];



int main()
{
    freopen("3.out","w",stdout);
    cout << "Case #1:" << endl;
    for(int i=0;i<500;i++) {
        for(int j=0;j<32;j++) t[j]=0;
        t[0]=t[31]=1;
        for(int ii=i,j=1;ii>0;j+=2,ii/=2) {
            if(ii%2) t[j]=t[j+1]=1;
        }
        for(int j=0;j<32;j++) cout << t[j];
        cout << " 3 4 5 6 7 8 9 10 11" << endl;
    }
    return 0;
}
