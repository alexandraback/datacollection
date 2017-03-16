#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int r, c, t, m;
char board[200][200];
int cnt[200][200];
bool can;
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {0, 1, -1, 0, 1, -1, 1, -1};

bool click(int i, int j)
{
    bool visited[200][200];
    for(int a=1; a<=r; ++a)
        for(int b=1; b<=c; ++b)
            visited[a][b] = false;
    visited[i][j] = true;
    queue<pair<int, int> > q;
    q.push(make_pair(i, j));
    int e=1;
    while(!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        if(cnt[p.first][p.second] != 0) continue;
        for(int k=0; k<8; ++k)
        {
            int ii = p.first + dx[k];
            int jj = p.second + dy[k];
            if(ii>0 && ii<=r && jj>0 && jj<=c && board[ii][jj]=='.' && !visited[ii][jj])
            {
                q.push(make_pair(ii, jj));
                visited[ii][jj] = true;
                ++e;
            }
        }
    }
    return e == r*c-m;
}

bool judge()
{
    for(int i=1; i<=r; ++i)
        for(int j=1; j<=c; ++j)
        {
            cnt[i][j] = 0;
            for(int k=0; k<8; ++k)
            {
                int ii = i + dx[k], jj = j + dy[k];
                if(ii>0 && ii<=r && jj>0 && jj <=c && board[ii][jj]=='*')
                {
                    ++cnt[i][j];
                }
            }
        }
    /*for(int i=1; i<=r; ++i)
    {
        for(int j=1; j<=c; ++j)
            cout<<board[i][j];
        cout<<endl;
    }
    cout<<endl;
    for(int i=1; i<=r; ++i)
    {
        for(int j=1; j<=c; ++j)
            cout<<cnt[i][j];
        cout<<endl;
    }
    cout<<endl;*/
    for(int i=1; i<=r; ++i)
        for(int j=1; j<=c; ++j)
            if(board[i][j] == '.' && click(i, j))
            {
                board[i][j] = 'c';
                return true;
            }
    return false;
}

void search(int i, int j, int k)
{
    if(can) return;
    if(i == r + 1)
    {
        if(judge())
        {
            can = true;
            for(int a = 1; a <= r; ++a)
            {
                for(int b = 1; b <= c; ++b)
                    cout<<board[a][b];
                cout<<endl;
            }
        }
        return;
    }
    if(j == c + 1)
    {
        search(i + 1, 1, k);
        return;
    }
    if(k != 0)
    {
        board[i][j] = '.';
        search(i, j + 1, k - 1);
    }
    board[i][j] = '*';
    search(i, j + 1, k);
}

int main()
{
    cin>>t;
    for(int i=1; i<=t; ++i)
    {
        cin>>r>>c>>m;
        cout<<"Case #"<<i<<":"<<endl;
        can = false;
        search(1, 1, r * c - m);
        if(!can) cout<<"Impossible"<<endl;
    }
    return 0;
}
