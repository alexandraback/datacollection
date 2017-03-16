#include <bits/stdc++.h>
using namespace std;

int N;

int n, m;
const int MX=209;
int A[MX];
int B[MX];

typedef unsigned int ui;

int solve2()
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
    freopen("C-small-attempt0.in", "r", stdin);
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
