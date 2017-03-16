#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF=1000LL*1000LL*1000LL*1000LL*1000LL*1000LL*2LL;

ll min_diff;
ll ans_C;
ll ans_J;

string str_C;
string str_J;

ll str_to_ll(string s)
{
    ll res=0LL;
    for(const auto& it: s)
    {
        res=res*10+(it-'0');
    }
    return res;
}

enum which
{
    FIRST, SECOND, NONE
};

which ww(int c, int j)
{
    if(c > j) return FIRST;
    else if(c==j) return NONE;
    return SECOND;
}

int N;


void solve_rec(string C, string J, int pos, which bigger)
{
    //cout << C << ' ' << J << ' ' << pos << endl;

    if(bigger == FIRST)
    {
        for(int i=0; i<N; i++) if(C[i]=='?') C[i]='0';
        for(int i=0; i<N; i++) if(J[i]=='?') J[i]='9';
        pos=N;
    }
    else if(bigger == SECOND)
    {
        for(int i=0; i<N; i++) if(C[i]=='?') C[i]='9';
        for(int i=0; i<N; i++) if(J[i]=='?') J[i]='0';
        pos=N;
    }

    if(pos >= N)
    {
        ll cc=str_to_ll(C), jj=str_to_ll(J);
        if(abs(cc-jj)<min_diff)
        {
            ans_C=cc;
            ans_J=jj;
            min_diff=abs(cc-jj);

            str_C=C;
            str_J=J;
        }
        else if(abs(cc-jj)==min_diff && cc < ans_C)
        {
            ans_C=cc;
            ans_J=jj;

            str_C=C;
            str_J=J;
        }
        else if(abs(cc-jj)==min_diff && cc==ans_C && jj<ans_J)
        {
            ans_J=jj;

            str_J=J;
        }

        return;
    }

    if(C[pos]=='?' && J[pos]=='?')
    {
        char choice_C[3]={'0','0', '1'};
        char choice_J[3]={'0','1', '0'};
        which w[3]={NONE, SECOND, FIRST};

        for(int i=0; i<3; i++)
        {
            string Cn=C, Jn=J;
            Cn[pos]=choice_C[i];
            Jn[pos]=choice_J[i];

            solve_rec(Cn, Jn, pos+1, w[i]);
        }
    }
    else if(C[pos]=='?')
    {
        int jj=J[pos]-'0';
        for(int cc=jj-1; cc<=jj+1; cc++)
        {
            if(0<=cc && cc<=9)
            {
                string Cn=C;
                Cn[pos]=cc+'0';
                solve_rec(Cn, J, pos+1, ww(cc, jj));
            }
        }
    }
    else if(J[pos]=='?')
    {
        int cc=C[pos]-'0';
        for(int jj=cc-1; jj<=cc+1; jj++)
        {
            if(0<=jj && jj<=9)
            {
                string Jn=J;
                Jn[pos]=jj+'0';
                solve_rec(C, Jn, pos+1, ww(cc, jj));
            }
        }
    }
    else
    {
        solve_rec(C, J, pos+1, ww(C[pos], J[pos]) );
    }
}

void solve(string C, string J)
{
    min_diff=INF;
    N=C.size();
    assert(N==(int)J.size());

    solve_rec(C, J, 0, NONE);
    assert(min_diff < INF);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    //cout << str_to_ll("231");

    int T;
    cin >> T;
    for(int t=1; t<=T; t++)
    {
        string C, J;
        cin >> C >> J;
        solve(C, J);
        cout << "Case #" << t << ": " << str_C << ' ' << str_J << endl;
    }
    return 0;
}
