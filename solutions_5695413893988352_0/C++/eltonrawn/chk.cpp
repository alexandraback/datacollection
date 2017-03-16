#include<bits/stdc++.h>

using namespace std;

#define PF           printf
#define SF(n)        scanf("%d", &n)
#define SFF(a,b)     scanf("%d %d", &a, &b)
#define SFFF(a,b,c)  scanf("%d %d %d", &a, &b, &c)
#define INF_I        2147483647    //max limit
#define INF          1999999999
#define PB           push_back
#define MEM(n, val)  memset((n), val, sizeof(n))
#define F            first
#define S            second
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define ROF(i, a, b) for(int i = a; i >= b; i--)
#define ALL(c)       c.begin(), c.end()
#define BOOST        std::ios_base::sync_with_stdio(false);
#define INP          freopen("in.txt", "r", stdin);
#define OUT          freopen("out.txt", "w", stdout);
#define MP           make_pair
#define INIT_RAND    srand(time(NULL))
#define MOD          1000000007
#define MX           10010
#define PI           acos(-1.0)

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef priority_queue<int> PQ;
typedef queue<int> Q;
typedef stringstream SS;

/*dir array
//8 moves
int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};
int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};
//4 moves
int fx[]={+1,-1,+0,+0};
int fy[]={+0,+0,+1,-1};
#define valid(nx,ny)  ((nx >= 0) && (nx < row) && (ny >= 0) && (ny < col))
*/

string a, b;
int len;

LL ans, ansa, ansb;

string pra, prb;


void bt(int pos, string sa, string sb)  {
    if(pos == len) {
        LL anum = atoll(sa.c_str());
        LL bnum = atoll(sb.c_str());
        LL tans = abs(anum - bnum);
        if(ans == -1)   {
            ans = tans;
            ansa = anum;ansb = bnum;

            pra = sa; prb = sb;
            return;
        }
        if(tans < ans)    {
            ans = tans;
            ansa = anum;ansb = bnum;

            pra = sa; prb = sb;
            return;
        }
        if(tans == ans) {
            if(anum == ansa)    {
                if(bnum < ansb)    {
                    ansb = bnum;

                    prb = sb;
                }

                //ansb = min(ansb, bnum);
            }
            else if(anum < ansa)    {
                ansa = anum;ansb = bnum;

                pra = sa; prb = sb;
            }
        }
        return;
    }
    vector<char> ta;
    vector<char> tb;
    if(a[pos] == '?')    {
        for(char i = '0'; i <= '9'; i++)   {
            ta.PB(i);
        }
    }
    else    {
        ta.PB(a[pos]);
    }
    if(b[pos] == '?')    {
        for(char i = '0'; i <= '9'; i++)   {
            tb.PB(i);
        }
    }
    else    {
        tb.PB(b[pos]);
    }
    FOR(i, 0, ta.size() - 1)   {
        FOR(j, 0, tb.size() - 1)   {
            bt(pos + 1, sa + ta[i], sb + tb[j]);
        }
    }
}

int main()  {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    //INP;OUT;
    BOOST;

    /*
    string pp = "999999999999999999";
    LL ppl = atoll(pp.c_str());
    cout << ppl << "\n";

    LL ff = abs(999999999999999999);
    cout << ff << "\n";

    */

    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        cin >> a >> b;
        len = a.size();
        ans = -1;ansa = -1;ansb = -1;
        bt(0, "", "");
        cout << "Case #" << tt << ": ";
        cout << pra << " " << prb << "\n";
    }
    return 0;
}
/*
1
??????????????????
??????????????????



4
1? 2?
?2? ??3
? ?
?5 ?0
*/
