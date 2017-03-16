#include <cstdio>
#include <algorithm>
#include <queue>
#include <unordered_map>

using namespace std;



class cmp{
public:
    bool operator()(const pair<int,int> & A, const pair<int,int> & B)
    {
        if(A.first < B.first)
            return true;
        if(A.first > B.first)
            return false;
        return A.second > B.second;
    }
};
queue<pair<int,long long> > Q;
long long N;
unordered_map<long long,bool> used;

void Read()
{
    scanf("%d",&N);
}

int invers(int k)
{
    int v = 0;
    while(k)
    {
        v = v * 10 + k % 10;
        k/=10;
    }
    return v;
}

int BFS()
{
    Q.push(make_pair(1,1));
    used[1] = true;
    int k;
    long long val,v1,v2;
    while(!Q.empty())
    {
        k = Q.front().first;/// nr de pasi
        val = Q.front().second; /// valoare
        Q.pop();
        if(val == N)
        {
            while(!Q.empty())
                Q.pop();
            return k;
        }
        v1 = val + 1;
        v2 = invers(val);
        if(v1 <= N && used[v1] == false)
        {
            used[v1] = true;
            Q.push(make_pair(k+1,v1));
        }
        if(v2 <= N && used[v2] == false)
        {
            used[v2] = true;
            Q.push(make_pair(k+1,v2));
        }
    }
}

void clean()
{
    used.clear();

}

int main()
{

    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);

    int T;
    scanf("%d",&T);

    for(int tst = 1; tst <= T; ++tst)
    {
        Read();
        printf("Case #%d: %d\n",tst,BFS());
        clean();
    }

    return 0;
}
