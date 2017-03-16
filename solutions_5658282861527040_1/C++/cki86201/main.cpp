#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;

ll S(int A,int B,int K,int bit)
{
	if(bit==0){
		return (A&B) + A + B + 1 - (A&&B&&!K);
	}
	int bt = 1<<bit;
	if(A == bt*2-1 && B == bt*2-1 && K == bt*2-1)return (ll)(A+1)*(B+1);
	ll res = 0;
	if((A&B&K)&bt)res += S(A-(A&bt), B-(B&bt), K-(K&bt), bit-1);
	if(A&bt)res += S(A-(A&bt), (B&bt)?bt-1:A, (K&bt)?bt-1:K, bit-1);
	if(B&bt)res += S((A&bt)?bt-1:A, B-(B&bt), (K&bt)?bt-1:K, bit-1);
	res += S((A&bt)?bt-1:A, (B&bt)?bt-1:B, (K&bt)?bt-1:K, bit-1);
	return res;
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int Tc;
	scanf("%d",&Tc);
	for(int tt=1;tt<=Tc;tt++){
		printf("Case #%d: ", tt);
		int a, b, c;
		scanf("%d%d%d",&a,&b,&c);
		printf("%lld\n",DFS(a-1,b-1,c-1,29));
	}
	return 0;
}
