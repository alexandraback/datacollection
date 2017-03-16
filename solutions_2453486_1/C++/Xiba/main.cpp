#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>


using namespace std;

string arr[4];
int n;

int initx[] = {0, 0, 0, 0, 0, 0, 0, 1, 2, 3};
int inity[] = {0, 3, 0, 1, 2, 3, 0, 0, 0, 0};
int dx[]    = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
int dy[]    = {1,-1, 0, 0, 0, 0, 1, 1, 1, 1};

string xwon ("X won"), ywon ("O won"), draw("Draw"), still("Game has not completed");


string calc()
{
    bool underway = false;
    for(int i=0; i < 10; i++)
    {
        int scx = 0, scy = 0;
        int cx = initx[i], cy = inity[i];
        for(int j=0; j < 4; j++, cx+=dx[i], cy+=dy[i])
        {
            char c = arr[cx][cy];
            underway = underway || c == '.';
            scx += c == 'T' || c=='X' ? 1 : 0;
            scy += c == 'T' || c=='O' ? 1 : 0;
        }
        if(scx == 4)
            return xwon;
        else if(scy == 4)
            return ywon;
    }
    if(underway)
        return still;
    else
        return draw;
}

int main()
{
    freopen("../lab_algorithms/A-large.in","r",stdin);
    freopen("../lab_algorithms/A-large.out","wt",stdout);

    int tc;
    cin >> tc;
    for(int tt=1; tt <= tc; tt++)
    {
        for(int i=0; i < 4; i++)
            cin >> arr[i];

        cout << "Case #"<< tt << ": " << calc() << endl;
    }
    return 0;
}
