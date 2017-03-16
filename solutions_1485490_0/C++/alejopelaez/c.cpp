#include <cstdio>
#include <vector>

using namespace std;

struct Pair {
	long long type;
	long long num;
	Pair(long long t = 0, long long n = 0){
		type = t;
		num = n;
	}
};

vector<Pair> boxes;
vector<Pair> toys;

long long min(long long a, long long b){
	return (a < b)? a : b;
}

long long max(long long a, long long b){
	return (a > b)? a : b;
}

long long solve(long long b_start, long long t_start, long long curr, vector<Pair> boxes, vector<Pair> toys){

	if(b_start >= boxes.size() or t_start >= toys.size())
		return curr;

	if(boxes[b_start].type == toys[t_start].type){

		long long tmp = min(boxes[b_start].num, toys[t_start].num);
		boxes[b_start].num -= tmp;
		toys[t_start].num -= tmp;

		if(boxes[b_start].num == 0)
			return solve(b_start + 1, t_start, tmp + curr, boxes, toys);
		else
			return solve(b_start, t_start + 1, tmp + curr, boxes, toys);
	}


	if(b_start == boxes.size() - 1)
		return solve(b_start, t_start + 1, curr, boxes, toys);
	if(t_start == toys.size() - 1)
		return solve(b_start + 1, t_start, curr, boxes, toys);

	long long t2 = solve(b_start + 1, t_start, curr, boxes, toys);
	long long t1 = solve(b_start, t_start + 1, curr, boxes, toys);

	return max(t1,t2);
}

int main(int argc, char *argv[])
{
	long long t;
	long long kase = 1;
	scanf("%lld", &t);
	while(t--){
		boxes = vector<Pair>();
		toys = vector<Pair>();
		long long n,m;
		scanf("%lld %lld", &n, &m);
		for(long long i = 0; i < n; ++i){
			long long num, type;
			scanf("%lld %lld", &num, &type);
			boxes.push_back(Pair(type, num));
		}
		for(long long i = 0; i < m; ++i){
			long long num, type;
			scanf("%lld %lld", &num, &type);
			toys.push_back(Pair(type, num));
		}
		printf("Case #%lld: %lld\n", kase++, solve(0,0, 0, boxes, toys));
	}
	return 0;
}
