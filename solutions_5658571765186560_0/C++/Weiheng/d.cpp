#include <iostream>
using namespace std;

int main() {
    int n,t,x,r,c;
    cin>>n;
    t = 1;
    bool mat[5][5][5];
    int i,j,k;
    for (i=0;i<5;i++)
        for (j=0;j<5;j++)
            for(k=0;k<5;k++)
                mat[i][j][k]=false;
    for (i=1;i<5;i++)
        for (j=1;j<5;j++)
            mat[1][i][j] = true;

    for (i=1;i<5;i++)
        for (j=1;j<5;j++)
            if ((i*j)%2==0)
                mat[2][i][j] = true;
    mat[3][3][3] = mat[3][2][3] = mat[3][4][3] = mat[3][3][2] = mat[3][3][4] = true;
    mat[4][4][4] = mat[4][4][3] = mat[4][3][4] = true;
    while(t<=n) {
        cin>>x>>r>>c;
        if (mat[x][r][c])
            cout<<"Case #"<<t<<": GABRIEL"<<endl;
        else
            cout<<"Case #"<<t<<": RICHARD"<<endl;
        t++;
    }
}
