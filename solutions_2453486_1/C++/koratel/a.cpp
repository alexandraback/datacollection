#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define x first
#define y second

const int INF = 1 << 30;
const double EPS = 1e-13;

char p[4][4];

int solve()
{
    int dix=0, dio=0; // przekatna 1
    int dix2=0, dio2=0; // przekatna 2
    for(int i=0; i<4; i++)
    {
        int x=0, o=0; // poziom
        int px=0, po=0; // pion
        if(p[i][i]=='X') dix++;
        if(p[i][i]=='O') dio++;
        if(p[i][i]=='T')
        {
            dix++;
            dio++;
        }
        if(p[i][3-i]=='X') dix2++;
        if(p[i][3-i]=='O') dio2++;
        if(p[i][3-i]=='T')
        {
            dix2++;
            dio2++;
        }
        for(int j=0; j<4; j++)
        {
            if(p[i][j]=='X') x++;
            if(p[i][j]=='O') o++;
            if(p[i][j]=='T')
            {
                x++;
                o++;
            }
            if(p[j][i]=='X') px++;
            if(p[j][i]=='O') po++;
            if(p[j][i]=='T')
            {
                px++;
                po++;
            }

        }
        if(x==4 || px==4) return 1;
        if(o==4 || po==4) return 2;
    }
    if(dix==4 || dix2==4) return 1;
    if(dio==4 || dio2==4) return 2;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int zajete=0;
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                cin>>p[i][j];
                if(p[i][j]!='.') zajete++;
            }
        }
        int result=solve();
        cout<<"Case #"<<t<<": ";
        if(result==1) cout<<"X won\n";
        else if(result==2) cout<<"O won\n";
        else if(zajete==16) cout<<"Draw\n";
        else cout<<"Game has not completed\n";
    }
}
