#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

#define LL long long

int T, tt = 0;
LL p, q;

LL gcd(LL a, LL b)
{
	if (b == 0) return a;
	else return(gcd(b, a % b));
	}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	while (T--)
	{
		scanf("%I64d/%I64d", &p, &q);
		LL g = gcd(p, q);
		p /= g;
		q /= g;
		bool can = true;
		int sp = 0, sq = 0;
		while (q > 1){
			if (q % 2) can = false;
			sq ++;
			q /= 2;
			}
		while (p){
			sp ++;
			p /= 2;
			}
//		printf("%d %d\n", sq, sp);
		printf("Case #%d: ", (++tt));
		if (can){
			printf("%d\n", sq-sp+1);
			}else{
				printf("impossible\n");
				}
		}
	return 0;
	}
