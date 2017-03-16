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

string mp[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

int main()  {
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    //INP;OUT;
    //BOOST;
    //cout << "hi\n";
    //map<int , string> mp;

    int tc;
    cin >> tc;
    FOR(tt, 1, tc)   {
        string str;
        cin >> str;
        int ara[200];
        MEM(ara, 0);
        int len = str.size();
        FOR(i, 0, len - 1)   {
            ara[str[i]]++;
        }
        int num[20];
        MEM(num, 0);


        if(ara['Z'])    {
            int kom = ara['Z'];
            ara['Z'] -= kom;
            ara['E'] -= kom;
            ara['R'] -= kom;
            ara['O'] -= kom;
            num[0] += kom;
        }
        if(ara['W'])    {
            int kom = ara['W'];
            ara['T'] -= kom;
            ara['W'] -= kom;
            ara['O'] -= kom;
            num[2] += kom;
        }
        if(ara['U'])    {
            int kom = ara['U'];
            ara['F'] -= kom;
            ara['O'] -= kom;
            ara['U'] -= kom;
            ara['R'] -= kom;
            num[4] += kom;
        }
        if(ara['X'])    {
            int kom = ara['X'];
            ara['S'] -= kom;
            ara['I'] -= kom;
            ara['X'] -= kom;
            num[6] += kom;
        }
         if(ara['G'])    {
            int kom = ara['G'];
            ara['E'] -= kom;
            ara['I'] -= kom;
            ara['G'] -= kom;
            ara['H'] -= kom;
            ara['T'] -= kom;
            num[8] += kom;
        }


        FOR(i, 0, 9)   {
            if(i == 0 || i == 2 || i == 4 || i == 6 ||i == 8)   {
                continue;
            }
            string tmp = mp[i];
            int tmpl = tmp.size();
            int mn = INF;
            FOR(j, 0, tmpl - 1)   {
                if((i == 9) && (tmp[j] == 'N'))  {
                    mn = min(mn, ara[tmp[j]] / 2);
                }
                else if((i == 3) && (tmp[j] == 'E'))  {
                    mn = min(mn, ara[tmp[j]] / 2);
                }
                else if((i == 7) && (tmp[j] == 'E'))  {
                    mn = min(mn, ara[tmp[j]] / 2);
                }
                else    {
                    mn = min(mn, ara[tmp[j]]);
                }

            }
            num[i] += mn;

            FOR(j, 0, tmpl - 1)   {
                //mn = min(mn, tmp[i]);
                ara[tmp[j]] -= mn;
            }
        }
        cout << "Case #" << tt << ": ";
        FOR(i, 0, 9)   {
            FOR(j, 0, num[i] - 1)   {
                cout << i;
            }
        }
        cout << "\n";

    }

    return 0;
}
/*
4
OZONETOWER
WEIGHFOXTOURIST
OURNEONFOE
ETHER

1
NIE
*/


/*
        if(ara['Z'])    {
            int kom = ara['Z'];
            ara['Z'] = 0;
            ara['E'] -= kom;
            ara['R'] -= kom;
            ara['O'] -= kom;
            num[0] += kom;
        }
        else if(ara['W'])    {
            int kom = ara['W'];
            ara['T'] -= kom;
            ara['W'] -= kom;
            ara['O'] -= kom;
            num[2] += kom;
        }
        else if(ara['U'])    {
            int kom = ara['U'];
            ara['F'] -= kom;
            ara['O'] -= kom;
            ara['U'] -= kom;
            ara['R'] -= kom;
            num[4] += kom;
        }
        else if(ara['X'])    {
            int kom = ara['X'];
            ara['S'] -= kom;
            ara['I'] -= kom;
            ara['X'] -= kom;
            num[6] += kom;
        }
        else if(ara['G'])    {
            int kom = ara['G'];
            ara['E'] -= kom;
            ara['I'] -= kom;
            ara['G'] -= kom;
            ara['H'] -= kom;
            ara['T'] -= kom;
            num[8] += kom;
        }
        */
