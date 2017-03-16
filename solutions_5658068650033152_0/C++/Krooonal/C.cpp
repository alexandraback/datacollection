#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#include <string>
#include <cstring>

using namespace std;

#define DEBUG 0
#define all(C) (C).begin() , (C).end()
#define tr(C , it) for(typeof((C).begin()) it = (C).begin() ; it != (C).end() ; it++)
#define present(C , key) ((C).find(key) != (C).end())
#define cpresent(C , key) (find(all(C) , key) != (C).end())
#define sz(a) int((a).size())
#define pb push_back
#define MOD 1000000007


typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int , int> PI;

int main()
{
	int __A;
	scanf("%d" , &__A);
	
	int N , M , K;
	int i , j , k;
	int cov[1000];
	memset(cov , 0 , sizeof(cov));
	cov[0] = 0;
	cov[1] = 1;
	cov[2] = 2;
	cov[3] = 3;
	for(i=4 ; i<=400 ; i++)
	{
		if(i % 2 == 0)
		{
			j = i/2;
			if(j % 2 == 0)
			{
				cov[i] = i + (j/2)*(j/2);
			}
			else
			{
				cov[i] = i + (j/2)*(j/2 + 1);
			}
		}
		else
		{
			cov[i] = cov[i-1] +1;
		}
	}
	
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		scanf("%d %d %d" , &N , &M , &K);
		if(N <= 2|| M <= 2 || K <= 4)
		{
			printf("%d\n" , K);
			continue;
		}
		if(N > M)
			swap(N , M);
			
		for(i=4 ; i<=400 ; i++)
		{
			if(i % 2 == 0)
			{
				j = i/2;
				cov[i] = i;
				for(k=0 ; k<=j/2 ; k++)
				{
					if(k + 2 <= N && j-k + 2 <= M)
					{
						cov[i] = max(cov[i] , i + k*(j-k));
					}
				}
			}
			else
			{
				cov[i] = cov[i-1] +1;
			}
		}
		
		if(K > cov[((N-2)+(M-2))*2])
		{
			printf("%d\n" , ((N-2)+(M-2))*2 + K - cov[((N-2)+(M-2))*2]);
			continue;
		}
		
		for(i = 4 ; i <= K ; i++)
		{
			if(cov[i] >= K)
			{
				printf("%d\n" , i);
				break;
			}
		}
	}
	return 0;
}
