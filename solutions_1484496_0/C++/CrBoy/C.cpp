#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

set<long long> all_sum;
set<long long> s1;
set<long long> s2;
long long S[512];
int N;

long long find_sum(int cur_n, long long cur_sum)
{
	long long equal;
	if(cur_n==N) return -1;
	if(all_sum.insert(cur_sum+S[cur_n]).second==false){
		s1.insert(S[cur_n]);
		return cur_sum+S[cur_n];
	}
	equal = find_sum(cur_n+1, cur_sum);
	if(equal != -1){
		return equal;
	}else{
		equal = find_sum(cur_n+1, cur_sum+S[cur_n]);
		if(equal != -1){
			s1.insert(S[cur_n]);
			return equal;
		}else{
			return -1;
		}
	}
}

long long find_sum_target(int cur_n, long long cur_sum, long long target)
{
	long long equal;
	if(cur_n==N) return -1;
	if(cur_sum+S[cur_n] == target){
		s2.insert(S[cur_n]);
		return cur_sum+S[cur_n];
	}
	equal = find_sum_target(cur_n+1, cur_sum, target);
	if(equal != -1){
		return equal;
	}else{
		equal = find_sum_target(cur_n+1, cur_sum+S[cur_n], target);
		if(equal != -1){
			s2.insert(S[cur_n]);
			return equal;
		}else{
			return -1;
		}
	}
}

int main(int argc, const char *argv[])
{
	int cases, casen=0;
	long long result;
	int i;

	scanf("%d", &cases);
	while(casen<cases){
		scanf("%d", &N);
		for(i = 0; i < N; i++){
			scanf("%lld", &S[i]);
		}
		all_sum.clear();
		s1.clear();
		s2.clear();

		result = find_sum(0,0);
		if(result==-1){
			++casen;
			printf("Case #%d:\nImpossible\n", casen);
		}else{
			find_sum_target(0,0,result);

			++casen;
			printf("Case #%d:\n", casen);
			copy(s1.begin(), s1.end(), ostream_iterator<int>(cout, " ")), cout << endl;
			copy(s2.begin(), s2.end(), ostream_iterator<int>(cout, " ")), cout << endl;
		}
	}
	return 0;
}
