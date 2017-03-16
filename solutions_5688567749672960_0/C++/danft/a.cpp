#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<bool> vb;

char num[100];
ll x;
int dist[9000001];

int rev(int a) {
        int r = 0;
        int pot = 10000000, pot2=1;
        while( pot >= 1 )
        {
                //cout << pot << ' ' << a << "\n";
                r += (a/pot)*pot2;
                if ( r > 0 )
                        pot2*=10;
                a %= pot;
                pot /=10;
        }
        return r;
}

int f( int y ) {

        queue<int> q;
        q.push(y);
        memset( dist, INF, sizeof dist );
        dist[y] = 1;

        while( !q.empty() )
        {
                int u = q.front();
                q.pop();
                //cout << u << endl;
                if( u == 1 ) return dist[u];
                if( dist[u-1] > dist[u]+1 )
                {
                        dist[u-1] = dist[u]+1;
                        q.push(u-1);
                }
                if( u%10!=0 && dist[rev(u)] > dist[u]+1 )
                {
                        dist[rev(u)] = dist[u]+1;
                        q.push(rev(u));
                }
        }
        return INF;
}

int main(){
        int t,ca=1;
        cin >> t;

        while(t--)
        {
                cin >> x;
                cout << "Case #" << ca++ << ": ";
                cout << f(x) << endl;
        }
        return 0;
}
