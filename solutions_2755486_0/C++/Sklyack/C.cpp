#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXX=300;
const int MAXTOT=100;
int H[2*MAXX+1];
struct attack
{
	int day;
	int w, e;
	int s;
} A[MAXTOT];
int tot;

bool operator <(const attack& a, const attack& b)
{
	return a.day<b.day;
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T, t;
	int N;
	int i, i0, j, k, x, d, n, w, e, s, delta_d, delta_p, delta_s;
	int ans;

	scanf("%d", &T);
	for(t=1; t<=T; ++t)
	{
		memset(H, 0, sizeof(H));
		tot=0;

		scanf("%d", &N);
		for(i=0; i<N; ++i)
		{
			scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &delta_d, &delta_p, &delta_s);
			w+=MAXX;
			e+=MAXX;
			for(k=0; k<n; ++k)
			{
				A[tot].day=d;
				A[tot].e=e;
				A[tot].w=w;
				A[tot].s=s;
				++tot;
				d+=delta_d;
				e+=delta_p;
				w+=delta_p;
				s+=delta_s;
			}
		}

		sort(A, A+tot);
		ans=0;
		for(i0=i=0; i<tot; ++i)
		{
			s=A[i].s;
			for(x=A[i].w; x<A[i].e; ++x)
				if(H[x]<s)
				{
					++ans;
					break;
				}
			if(i+1<tot && A[i].day!=A[i+1].day)
			{
				for(j=i0; j<=i; ++j)
				{
					s=A[j].s;
					for(x=A[j].w; x<A[j].e; ++x)
						if(H[x]<s)
							H[x]=s;
				}
				i0=i+1;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
