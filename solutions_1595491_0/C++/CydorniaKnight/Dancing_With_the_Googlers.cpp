#include<iostream>
#include<string>
using namespace std;


int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);

	int T,N,S,p;
	int ti,i,m,nor,sur;
	int t[200],ans;

	scanf("%d",&T);

	for(ti=1; ti<=T; ++ti)
	{
		scanf("%d%d%d",&N,&S,&p);
		ans = 0;
		for(i=0;i<N;++i)
		{
			scanf("%d",&t[i]);
			m = t[i]%3;

			if(1 == m){
				nor = t[i]/3+1;
				if(nor>=p){
					++ans;
				}
			}else if(2 == m){
				nor = t[i]/3 + 1;
				
				if(nor>=p){
					++ans;
				}else{
					sur = t[i]/3 + 2;
					if(S&&sur>=p){
						++ans;
						--S;
					}
				}
			}else if(0 == m){
				nor = t[i]/3;

				if(nor>=p){
					++ans;
				}else if(nor){
					sur = nor+1;
					if(S&&sur>=p){
						++ans;
						--S;
					}
				}
			}
		}

		printf("Case #%d: %d\n", ti, ans);
	}

	//system("pause");
	return 0;
}