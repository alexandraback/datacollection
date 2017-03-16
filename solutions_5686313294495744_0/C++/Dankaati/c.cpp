#include <bits/stdc++.h>

using namespace std;

int x, n1, n2, n, M, N;
map<string,int> m1, m2;
string s1, s2;
bool **t;

bool bpm(bool **bpGraph, int u, bool seen[], int matchR[])
{
    for (int v = 0; v < N; v++)
    {
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true;
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM(bool **bpGraph)
{
    int matchR[N];
    memset(matchR, -1, sizeof(matchR));
    int result = 0;
    for (int u = 0; u < M; u++)
    {
        bool seen[N];
        memset(seen, 0, sizeof(seen));
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);

t=new bool*[1001];
for(int i=0;i<=1000;i++) t[i]=new bool[1001];
cin >> x;
for(int y=1;y<=x;y++) {
    n1=n2=0;
    m1.clear();
    m2.clear();
    cin >> n;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) t[i][j]=false;
    for(int i=0;i<n;i++) {
        cin >> s1 >> s2;
        if(m1.find(s1)==m1.end()) m1[s1]=(n1++);
        if(m2.find(s2)==m2.end()) m2[s2]=(n2++);
        t[m1[s1]][m2[s2]]=true;
    }
    M=n1;
    N=n2;
    cout << "Case #" << y << ": ";
    cout << n-n1-n2+maxBPM(t);
    cout << endl;
}
    return 0;
}
