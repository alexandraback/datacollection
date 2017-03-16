#include <iostream>
#include <string>
using namespace std;
char bo[4][4];

bool cek_emp()
{
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            if(bo[i][j]=='.')
                return 1;
    return 0;
}

bool cek_line(int r, int c, int ar, int ac, char C)
{
    bool val=1;
    //cout << r << " " << c << " " << ar << " " << ac << endl;
    for(int _r=r, _c=c; _r>=0 && _r<=3 && _c>=0 && _c<=3; _r += ar, _c += ac)
    {
//        cout << "bo[_r][_c]: " << bo[_r][_c] << endl; 
        //cout << "C : " << C << endl;
        if(bo[_r][_c] != C && bo[_r][_c] != 'T')
        {
            val = 0;
            break;
        }
    }
    return val;
}

bool cek(char c)
{
    for(int i=0; i<4; i++)
    {
    //    cout << "a" << endl;
        if(cek_line(i,0,0,1,c)) return 1;
    //    cout << "b" << endl;
        if(cek_line(0,i,1,0,c)) return 1;
    }
    //cout << "c" << endl;
    if(cek_line(0,0,1,1,c)) return 1;
    //cout << "d" << endl;
    if(cek_line(0,3,1,-1,c)) return 1;
    return 0;
}

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int N;
    cin >> N;
    for(int n=1; n<=N; n++)
    {
        for(int i=0; i<4; i++) cin >> bo[i];
        cout << "Case #" << n << ": ";
        if(cek('X')) cout << "X won";
        else if(cek('O')) cout << "O won";
        else if(cek_emp()) cout << "Game has not completed";
        else cout << "Draw";
        cout << endl;
    }
}
