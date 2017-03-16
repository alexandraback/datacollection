#include <bits/stdc++.h>

using namespace std;

typedef long long     LL;
typedef pair<int,int> pii;

double PI  = acos(-1);
double EPS = 1e-7;
int INF    = 1000000000;
LL INFLL   = 1000000000000000000LL;

#define fi            first
#define se            second
#define mp            make_pair
#define pb            push_back

#define input(in)     freopen(in,"r",stdin)
#define output(out)   freopen(out,"w",stdout)

#define MIN(a, b)     (a) = min((a), (b))
#define MAX(a, b)     (a) = max((a), (b))

#define RESET(a, b)   memset(a,b,sizeof(a))
#define ALL(a)        (a).begin(), (a).end()
#define SIZE(a)       (int)a.size()
#define SORT(a)       sort(ALL(a))
#define UNIQUE(a)     (a).erase( unique( ALL(a) ), (a).end() )
#define FOR(a, b, c)  for (int (a)=(b); (a)<=(c); (a)++)
#define FORD(a, b, c) for (int (a)=(b); (a)>=(c); (a)--)
#define FORIT(a, b)   for (__typeof((b).begin()) a=(b).begin(); a!=(b).end(); a++)

int mx[8] = {-1,1,0,0,-1,-1,1,1};
int my[8] = {0,0,-1,1,-1,1,-1,1};

// ----- //

char adj[500][500];
bool sign[500][500];

char s[10005];

char prec[10005];
bool pres[10005];

char sufc[10005];
bool sufs[10005];

int main() {
	adj['1']['1'] = '1';
	adj['1']['i'] = 'i';
	adj['1']['j'] = 'j';
	adj['1']['k'] = 'k';
	adj['i']['1'] = 'i';
	adj['i']['i'] = '1';
	adj['i']['j'] = 'k';
	adj['i']['k'] = 'j';
	adj['j']['1'] = 'j';
	adj['j']['i'] = 'k';
	adj['j']['j'] = '1';
	adj['j']['k'] = 'i';
	adj['k']['1'] = 'k';
	adj['k']['i'] = 'j';
	adj['k']['j'] = 'i';
	adj['k']['k'] = '1';

	sign['1']['1'] = 0;
	sign['1']['i'] = 0;
	sign['1']['j'] = 0;
	sign['1']['k'] = 0;
	sign['i']['1'] = 0;
	sign['i']['i'] = 1;
	sign['i']['j'] = 0;
	sign['i']['k'] = 1;
	sign['j']['1'] = 0;
	sign['j']['i'] = 1;
	sign['j']['j'] = 1;
	sign['j']['k'] = 0;
	sign['k']['1'] = 0;
	sign['k']['i'] = 0;
	sign['k']['j'] = 1;
	sign['k']['k'] = 1;
	
	int tc;
	scanf("%d",&tc);
	FOR(T,1,tc) {
		RESET(prec,0);
		RESET(pres,0);
		RESET(sufc,0);
		RESET(sufs,0);
		
		printf("Case #%d: ",T);
		int L;
		long long X;
		scanf("%d%lld",&L,&X);
		scanf("%s",s);
		prec[0] = s[0];
		pres[0] = 0;
		sufc[L-1] = s[L-1];
		sufs[L-1] = 0;
		FOR(a,1,L-1) {
			prec[a] = adj[prec[a-1]][s[a]];
			pres[a] = pres[a-1]^sign[prec[a-1]][s[a]];
			
		}
		FORD(a,L-2,0) {
			sufc[a] = adj[s[a]][sufc[a+1]];
			sufs[a] = sufs[a+1]^sign[s[a]][sufc[a+1]];
			//cout << a << "c->" << sufc[a] << " s->" << s[a] << " suf->" << sufc[a+1] << endl;
		}
		
		//cout << prec[L-1] << " " << pres[L-1] << endl;
		//cout << sufc[0] << " " << sufs[0] << endl;
		if (sufc[0] == '1' && sufs[0] == 1) { // -1
			if (X%2==1) {
				long long stblock = -1;
				long long enblock = -1;
				int stidx = -1;
				int enidx = -1;
				{
					char c = '1';
					bool s = 0;
					FOR(b,0,3) {
						FOR(a,0,L-1) {
							if (stblock == -1 && adj[c][prec[a]] == 'i' && (pres[a]^sign[c][prec[a]]^s) == 0) {
								stblock = b;
								stidx = a;
							}
						}
						s ^=  (sign[c][sufc[0]]^sufs[0]);
						c = adj[c][sufc[0]];
						
					}
				}
				{
					char c = '1';
					bool s = 0;
					FOR(b,0,3) {
						FORD(a,L-1,0) {
							if (enblock == -1 && adj[sufc[a]][c] == 'k' && (sufs[a]^sign[sufc[a]][c]^s) == 0) {
								enblock = X-b-1;
								enidx = a;
							}
						}
						s ^=  (sign[sufc[0]][c]^sufs[0]);
						c = adj[sufc[0]][c];
						
					}
				}
				//cout << stblock << " " << enblock << endl;
				if (stblock < 0 || stblock >= X || enblock < 0 || enblock >= X || stblock > enblock || (stblock == enblock && enidx-stidx<=1)) {
					puts("NO");
				}
				else {
					puts("YES");
				}
			}
			else {
				puts("NO");
			}
		}
		else if (sufc[0] != '1') {
			if (X%4==2) {
				long long stblock = -1;
				long long enblock = -1;
				int stidx = -1;
				int enidx = -1;
				{
					char c = '1';
					bool s = 0;
					FOR(b,0,3) {
						//cout << "B " << b << " " << c << " " << s << endl;
						FOR(a,0,L-1) {
							//cout << "ST " << b << " " << a << " " << adj[c][prec[a]]  << " " << (pres[a]^sign[c][prec[a]]^s) << " " << (stblock == -1 && adj[c][prec[a]] == 'i' && (pres[a]^sign[c][prec[a]]^s) == 0) << endl;
							//cout << c << " " << prec[a] << " -> " <<pres[a] << " " << sign[c][prec[a]] << " " << s << endl;
							if (stblock == -1 && adj[c][prec[a]] == 'i' && (pres[a]^sign[c][prec[a]]^s) == 0) {
								stblock = b;
								stidx = a;
							}
						}
						
						s ^=  (sign[c][sufc[0]]^sufs[0]);
						c = adj[c][sufc[0]];
					}
				}
				{
					char c = '1';
					bool s = 0;
					FOR(b,0,3) {
						FORD(a,L-1,0) {
							if (enblock == -1 && adj[sufc[a]][c] == 'k' && (sufs[a]^sign[sufc[a]][c]^s) == 0) {
								enblock = X-b-1;
								enidx = a;
							}
						}
						s ^=  (sign[sufc[0]][c]^sufs[0]);
						c = adj[sufc[0]][c];
						
					}
				}
				//cout << stblock << " " << stidx << " & " << enblock << " " << enidx << endl;
				if (stblock < 0 || stblock >= X || enblock < 0 || enblock >= X || stblock > enblock || (stblock == enblock && enidx-stidx<=1)) {
					puts("NO");
				}
				else {
					puts("YES");
				}
			}
			else {
				puts("NO");
			}
		}
		else {
			puts("NO");
		}
	}
}
