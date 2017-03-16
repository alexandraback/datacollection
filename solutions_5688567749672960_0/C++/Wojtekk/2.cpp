#include<algorithm>
#include<vector>
#include<queue>
#include<cstdio>

using namespace std;

const int max_n = 1e7+6, inf =1e9, NN=10000000;
int dist[max_n], n;

void solve(int casee)
{
    int x;
    scanf("%d", &x);
    printf("Case #%d: %d\n", casee, dist[x]);
}

queue<int> Q;
int dzies[9];

int rev( int x)
{
    vector<int>cyfry;
    while( x>0 )
    {
        if(x%10!=0) cyfry.push_back(x%10);
        else if(cyfry.size()!=0 )cyfry.push_back(x%10);
        x/=10;
    }
    int y=0;
    for( int i=0; i<cyfry.size(); ++i)
        y+= cyfry[cyfry.size()-1-i]*dzies[i];
    return y;
}

void preproces()
{
    dzies[0]=1;
    for( int i=1; i<9; ++i)
        dzies[i] = dzies[i-1]*10;
    for( int i=0; i<max_n; ++i)
        dist[i]=inf;
    dist[1]=1;

    Q.push(1);
    while(!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        if(x+1<=NN and dist[x+1] > dist[x]+1)
        {
            dist[x+1] = dist[x] +1;
            Q.push(x+1);
        }
        int y = rev(x);
        if(y<=NN and dist[y] > dist[x]+1)
        {
            dist[y] = dist[x]+1;
            Q.push(y);
        }
    }
    return ;

}

int main()
{
    preproces();
   int testy;
   scanf("%d", &testy);
   for( int i=1; i<=testy; ++i)
        solve(i);
}
