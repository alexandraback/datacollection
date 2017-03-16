#include<bits/stdc++.h>
using namespace std;

long long	int	N,M,K;

inline long long int gcd(long long int a,long long int b)
{
		return (!b) ? (a) : gcd(b,a%b);
}

void oku ()
{
		scanf(" %lld",&K);
//		printf("%lld",K);
		char ka;
		for(int i=1 ; i<=K ;i++)
		{
				scanf(" %lld %c %lld",&N,&ka,&M);
			//	printf(" %lld %lld\n",N,M);
				if(N>M || N==0)
				{
					printf("Case #%d: impossible\n",i);
				}
				else{
					long long int bol=gcd(N,M);
					N/=bol;
					M/=bol;
					int kont=0,tut,tut2;
					for(int j=0,k=1 ; j<=55  ;j++,k*=2)
							if(k & M)
							{tut=j;	kont++;}
				//	printf("asdasd %lld\n",tut);
					if(kont==1)
					{
							for(int j=0, k=1; j<=55 ;j++,k*=2)
								if(k & N)
									tut2=j;
				//				printf("%d\n",tut2);
								printf("Case #%d: %d\n",i,tut-tut2);
					}
					else
							printf("Case #%d: impossible\n",i);
				}
		}
		

	
}


int main ()
{
		oku ();
		return 0;
}
