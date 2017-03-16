#include<stdio.h>
#include<vector>
using namespace std;

const int N1 = 100;
const int N2 = 100;
const int N3 = 100;
const int N4 = 100;

vector<vector<int> > haha;
vector<bool> in;
vector<bool> hehe;
int n;

void tiesuo()
{
    scanf("%d",&n);
    haha.assign(n+1,vector<int>());
    in.assign(n+1,true);
    int x,y;
    for(int i = 1; i <= n; i++)
    {
scanf("%d",&x);
for(int j = 0; j < x; j++)
{
scanf("%d",&y);
            haha[i].push_back(y);
            in[y] = false;
        }
    }
}
bool sha(int x)
{
    if(hehe[x]) return true;
    hehe[x] = true;
    for(int i = 0,y; i < haha[x].size(); i++)
    {
        y = haha[x][i];
        if(sha(y))
            return true;
    }
    return false;
}
bool shan()
{
    for(int i = 1; i <= n; i++)
    {
        if(in[i])
        {
            hehe.assign(n+1,false);
            if(sha(i))
                return true;
        }
    }
    return false;
}
int main()
{
    int t,tao;

    scanf("%d",&t);
    tao = 0;
    while(t--)
    {
        printf("Case #%d: ",++tao);
        tiesuo();
        if(shan()) puts("Yes");
        else puts("No");
    }
    return 0;
}
