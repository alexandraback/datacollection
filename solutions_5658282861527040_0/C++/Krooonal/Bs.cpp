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
	
	int A , B , K;
	int i , j , k , ans;
	for(int _i = 1 ; _i <= __A ; _i++)
	{
		printf("Case #%d: " , _i);
		scanf("%d %d %d" , &A , &B , &K);
		ans = 0;
		for(i=0 ; i<A ; i++)
		{
			for(j=0 ; j<B ; j++)
			{
				k = i & j;
				if(k < K)
					ans++;
			}
		}
		printf("%d\n" , ans);
	}
	return 0;
}
