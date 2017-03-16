#include <bits/stdc++.h>
using namespace std;

int N;

int n, m;
const int MX=1009;
int A[MX];
int B[MX];

typedef unsigned int ui;

int solve22()
{
    int result=N;
    for(ui mask=0; mask<(1U<<N); mask++)
    {
        bool markeda[MX]={false};
        bool markedb[MX]={false};

        int curr_res=0;
        for(int i=0; i<N; i++)
        {
            if((mask>>i)&1)
            {
                curr_res++;
                markeda[A[i]]=true;
                markedb[B[i]]=true;
            }
        }

        bool ok=true;
        for(int i=0; i<n; i++) if(!markeda[i]) ok=false;
        for(int i=0; i<m; i++) if(!markedb[i]) ok=false;

        if(ok) result=min(result, curr_res);
    }
    return result;
}

//vector<int> first[MX];
//vector<int> second[MX]
vector<int> e[2*MX];
bool marked[2*MX];

int cnt[2];

void dfs(int from, int color)
{
    //cout << from << ":" << color << endl;
    cnt[color]++;

    for(const auto& to: e[from])
    {
        if(marked[to]) continue;
        marked[to]=true;
        dfs(to, color^1);
    }
}

int solve2()
{
    for(int i=0; i<n+m; i++) e[i].clear();

    for(int i=0; i<N; i++)
    {
        int aa=A[i];
        int bb=B[i]+n;

        //cout << A[i] << ' ' << B[i] << endl;
        //cout << aa << ' ' << bb << endl;

        e[aa].push_back(bb);
        e[bb].push_back(aa);
    }

    for(int i=0; i<n+m; i++) marked[i]=false;
    int result=0;

    for(int i=0; i<n+m; i++)
    {
        if(marked[i]) continue;
        cnt[0]=cnt[1]=0;

        marked[i]=true;
        dfs(i, 0);

        result+=max(cnt[0], cnt[1]);
    }
    return result;
}

string a[MX];
string b[MX];

//string a_sort[MX];
//string b_sort[MX];


int solve()
{
    set<string> as;
    set<string> bs;
    for(int i=0; i<N; i++)
    {
        as.insert(a[i]);
        bs.insert(b[i]);
    }

    n=as.size();
    m=bs.size();

    map<string, int> am, bm;
    int iter=0;
    for(const auto& it: as)
    {
        am[it]=iter++;
    }
    iter=0;
    for(const auto& it: bs)
    {
        bm[it]=iter++;
    }

    for(int i=0; i<N; i++)
    {
        A[i]=am[a[i]];
        B[i]=bm[b[i]];
    }

    //for(int i=0; i<N; i++) cout << A[i] << ' ' << B[i] << endl;

    return N-solve2();
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        cin >> N;
        for(int i=0; i<N; i++) cin >> a[i] >> b[i];
        cout << "Case #" << t << ": " << solve() << endl;
    }
    return 0;
}
