#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define iter(container,it) typeof(container.begin()) it
#define all(x) x.begin(),x.end()
#define fastin std::ios::sync_with_stdio(false);cin.tie(NULL)
#define cout_precision(x) cout<<std::fixed<<setprecision(x)
using namespace std;
#ifndef ONLINE_JUDGE
#include <debug.h>
#endif
int r,c,m;
vector<vector<char> > field(6,vector<char> (6));
void print_field()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cout<<field[i][j];
        }
        cout<<"\n";
    }
}
void empty_field()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            field[i][j]='.';
        }
    }
}
inline pair<int,int> convert(const int& pos)
{
    int x=pos/c;
    int y=pos%c;
    return mp(x,y);
}
inline void fill_field(const vector<int>& mine_coord)
{
    assert((int)mine_coord.size()==m);
    for(int i=0; i<(int)mine_coord.size(); i++)
    {
        pair<int,int> temp=convert(mine_coord[i]);
        field[temp.first][temp.second]='*';
    }
}
inline vector<int> process(int bitmask)
{
    int i=0;
    vector<int> ans;
    while(bitmask)
    {
        if(bitmask&1)
        {
            ans.pb(i);
        }
        bitmask>>=1;
        i++;
    }
    return ans;
}
inline void advance(int& i)
{
    int l = i&~(i-1);
    int z =(i+l)&~i;
    i|=z;
    i&=~(z-1);
    i|=(z/l/2)-1;
}

// BFS Part starts..
int dx[8]= {1,1,0,-1,-1,-1,0,1};
int dy[8]= {0,1,1,1,0,-1,-1,-1};
inline bool is_inside(const int& x,const int& y)
{
    return x>=0&&y>=0&&x<r&&y<c;
}
inline bool is_safe_neighbourhood(const int& x,const int& y)
{
    for(int i=0; i<8; i++)
    {
        int new_x=x+dx[i];
        int new_y=y+dy[i];
        if(is_inside(new_x,new_y)&&field[new_x][new_y]=='*')
            return false;
    }
    return true;
}
queue<pair<int,int> > cells_marked_during_bfs;
bool bfs(const int& s_x,const int& s_y)
{
    queue<pair<int,int> > q;
    field[s_x][s_y]='v';
    cells_marked_during_bfs.push(mp(s_x,s_y));
    q.push(mp(s_x,s_y));
    int cells_pushed=1;
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(is_safe_neighbourhood(x,y))
        {
            for(int i=0; i<8; i++)
            {
                int new_x=x+dx[i];
                int new_y=y+dy[i];
                if(is_inside(new_x,new_y)&&field[new_x][new_y]!='v')
                {
                    field[new_x][new_y]='v';
                    cells_marked_during_bfs.push(mp(new_x,new_y));
                    q.push(mp(new_x,new_y));
                    cells_pushed++;
                }
            }
        }
    }
    return (cells_pushed+m)==r*c;
}
inline void empty_queue()
{
    while(!cells_marked_during_bfs.empty())
    {
        int x=cells_marked_during_bfs.front().first;
        int y=cells_marked_during_bfs.front().second;
        field[x][y]='.';
        cells_marked_during_bfs.pop();
    }
}
// BFS part ends..
bool check_field()
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(field[i][j]=='.')
            {
                if(bfs(i,j))
                {
                    empty_queue();
                    field[i][j]='c';
                    return true;
                }
            }
            empty_queue();
        }
    }
    return false;
}
int main()
{
    int t,tc=1;
    fastin;
    cin>>t;
    while(t--)
    {
        cin>>r>>c>>m;
        cout<<"Case #"<<tc++<<":\n";
        empty_field();
        bool possible=false;
        int bitmask=(1<<m)-1;
        int size=r*c;
        while (!(bitmask&1<<size))
        {
            vector<int> mine_coord=process(bitmask);
            fill_field(mine_coord);
            if(check_field())
            {
                print_field();
                possible=true;
                break;
            }
            empty_field();
            advance(bitmask);
        }
        if(!possible)
        {
            cout<<"Impossible\n";
        }
    }
}
