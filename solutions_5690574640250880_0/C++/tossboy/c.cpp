#include <iostream>
using namespace std;

#define N 7
int b[2][N][N],vis[N][N];
int r,c,m,rem;
bool fnd;


int nbit(int st){
    int res=0;
    while(st>0){
        res++;
        st -= (st&-st);
    }
    return res;
}

int dfs(int i, int j){
    int res=1;
    vis[i][j]=1;
    for(int ni=max(0,i-1); ni<=min(r-1,i+1); ni++)
        for(int nj=max(0,j-1); nj<=min(c-1,j+1); nj++)
            if(!b[1][ni][nj]){
                if(!vis[ni][nj])
                    res += dfs(ni,nj);
            }
            else
                b[1][ni][nj]++;
    return res;
}

void print(int zi, int zj){
    char board[N][N];
    memset(board, 0, sizeof(board));
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            board[i][j] = b[0][i][j]?'*':'.';
    board[zi][zj] = 'c';
    for(int i=0; i<r; i++)
        cout<<board[i]<<endl;
}

int main(int argc, const char * argv[])
{
    ios::sync_with_stdio(false);
    int nCase; cin>>nCase;
    for(int ca=1; ca<=nCase; ca++){
        cin>>r>>c>>m;
        fnd=false;
        
        cout<<"Case #"<<ca<<":"<<endl;
        if(r*c-m==1){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++)
                    cout<<(i+j==0?'c':'*');
                cout<<endl;
            }
            continue;
        }
        for(int st=0; !fnd && st<(1<<(r*c)); st++)
            if(nbit(st) == m){
                memset(b, 0, sizeof(b));
                for(int i=0,cur=0; i<r; i++)
                    for(int j=0; j<c; j++,cur++)
                        if(st & (1<<cur))
                            b[0][i][j] = 1;
                for(int i=0; i<r; i++)
                    for(int j=0; j<c; j++) if(b[0][i][j])
                        for(int ni=max(i-1,0);ni<=min(r-1,i+1); ni++)
                            for(int nj=max(j-1,0); nj<=min(c-1,j+1); nj++)
                                    b[1][ni][nj] =  1;
                int zi=-1, zj=-1, nz=0;
                for(int i=0; i<r; i++)
                    for(int j=0; j<c; j++)
                        if(!b[1][i][j]){
                            if(nz==0) zi=i,zj=j;
                            nz++;
                        }
                
                memset(vis, 0, sizeof(vis));
                if(nz>0 && dfs(zi, zj)==nz){
                    fnd=true;
                    for(int i=0; fnd&&i<r; i++)
                        for(int j=0; fnd&&j<c; j++)
                            if(!b[0][i][j] && b[1][i][j]==1)
                                fnd=false;
                    if(fnd)
                        print(zi, zj);
                }
            }
        if(!fnd)
            cout<<"Impossible"<<endl;
    }
    return 0;
}

