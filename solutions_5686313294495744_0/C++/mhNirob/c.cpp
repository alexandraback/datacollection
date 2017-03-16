#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<sstream>
#include<utility>
#include<climits>
#include<fstream>
#include<bitset>

using namespace std;

#define lli long long int
#define Max 1000005

char F[1024][32],S[1024][32],TC[32],TJ[32];
lli n,ans;
vector<lli>v1,v2;


lli Pow(lli p){
	lli ans=1;
	for(lli i=1;i<=p;i++){
		ans*=2;
	}
	return ans;
}

int main()
{
	freopen("input","r",stdin);
	freopen("output","w",stdout);

	lli n,t,i,j,k,l,bit,kase,len,tans;

	scanf("%lld",&kase);

	for(i=1;i<=kase;i++){
		scanf("%lld",&n);
		for(j=1;j<=n;j++){
			scanf("%s %s",F[j],S[j]);
		}
		printf("Case #%lld: ",i);
		if(n==1){ 
			printf("0\n");
			continue;
		}

		lli lim = Pow(n) - 1;
		ans=0;
		for(j=1;j<=lim;j++){
			v1.clear();
			v2.clear();
			bit=j;
			tans = k = 0;
			while(bit){
				if(bit%2){
					v1.push_back(n-k);
				}
				else{
					v2.push_back(n-k);
				}
				k++;
				bit/=2;
			}

			lli sz1 = v1.size();
			lli sz2 = v2.size();

			//cout<<sz2<<" "<<sz1<<'\n';
			lli br1,br2;
			for(k=0;k<sz1;k++){
				br1=br2=0;
				for(l=0;l<sz2;l++){
					if(strcmp(F[v1[l]],F[v2[k]])==0){
						br1++;
					}
					if(strcmp(S[v1[l]],S[v2[k]])==0){
						br2++;
					}
					if(br1==1 && br2==1) break;
				}
				if(l==sz2) break;
			}

			if(k==sz1){
				ans = max(ans,sz1);
			}


		}
	
		printf("%lld\n",ans);
	}
	return 0;
}