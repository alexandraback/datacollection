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

long long gcd(long long a ,  long long b)
{
	if(b == 0)
		return a;
	return gcd(b , a%b);
}

int main()
{
	int __A;
	scanf("%d" , &__A);
	
	long long P , Q , tQ, G , cnt;
	int flag;
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		scanf("%lld/%lld" , &P , &Q);
		
		//printf("%lld %lld\n" , P , Q);
		
		G = gcd(P , Q);
		P /= G;
		Q /= G;
		
		tQ = Q;
		flag = 0;
		while(Q != 1)
		{
			if(Q % 2 != 0)
			{
				flag = 1;
				break;
			}
			Q /= 2;
		}
		
		if(flag)
		{
			printf("impossible\n");
			continue;
		}
		Q = tQ;
		cnt = 0;
		while(P < Q)
		{
			Q /= 2;
			cnt++;
		}
		if(cnt <= 40)
			printf("%lld\n" , cnt);
		else
			printf("impossible\n");
	}
	return 0;
}
