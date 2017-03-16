
#include <vector>
#include <set>
#include <list>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <functional>
#include <math.h>

using namespace::std;

template <class T>
static inline T check_max(T& dst, T src) { if (dst < src) dst = src; return dst; }

template <class T>
static inline T check_min(T& dst, T src) { if (dst > src) dst = src; return dst; }

/*
double p[1000000];

double solve1()
{
	 int A, B;
	scanf("%d%d", &A, &B);
	for (int i =0 ;i < A; i++) {
	  scanf("%lf", &p[i]);
	}

	double p1 = 1;
	for (int i = 0; i < A; i++) {
	  p1 *= p[i];
	}

	int redo_count = B+1;
	double e1 = p1 * ( redo_count - A) + (1-p1) * (2*redo_count - A);

	double p2 = 1;
	double e2 = B+2;
	for (int i =1 ;i <= A; i++) {
		p2 *= p[i - 1];
		check_min(e2, p2 * (redo_count - A + 2*(A-i)) + (1-p2) *(2*redo_count - A + 2*(A-i)));
	}
	check_min(e1, e2);
	check_min(e1, (double) (B + 2));
	return e1;

}
*/
struct Index {
	int value;
	int index;
	bool operator < (const Index& other) const {
	   return value < other.value;
	}
};

struct Index1{
	int value;
	int value2;
	int index;
	bool operator < (const Index1& other) const {
	   return value2 > other.value2;
	}
};

void solve()
{
	int n;
	Index1 a[1024]; Index b[1024];
	scanf("%d", &n);
	for (int i =0 ;i < n;i++) {
	  scanf("%d%d", &a[i].value, &b[i].value);
	  a[i].index = b[i].index = i;
	  a[i].value2 = b[i].value;
	}
	
	sort(a, a+n);
	sort(b, b+n);
	 
	int mask[1024];
	memset(mask, 0, sizeof(mask));

	int cur_star = 0;
	int count = 0;
	list <Index1> la (a, a+n);
	list <Index> lb (b, b+n);
	//printf("%d %d\n", la.size(), lb.size());
	while (!lb.empty()) {
	  Index i = lb.front();
	  //printf("%d-%d ", count, i.value);
	  int target = i.value;
	  if (target <= cur_star) {
		  cur_star += mask[i.index]? 1:2;
		  mask[i.index] = 1;
		  lb.pop_front();
	      count++;
	  } else {
		  while (cur_star < target && !la.empty()) {
			  bool flag = false;
			  for (list<Index1>::iterator it = la.begin(); it != la.end(); ++it) {
			     if (cur_star >= it->value && !mask[it->index]) {
				   cur_star++;
			       mask[it->index] = 1;
				   la.erase(it);
				   flag = true;
				   count++;
				   break;
				 }
			  }
			  if (!flag) break;
		  }
		  if (cur_star < target) {
		    printf("Too Bad");
			return ;
		  }
	  }
	}
	if (cur_star > 2 * n) printf("???\n");
	printf("%d", count);
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		//printf("%f", solve1());
	    solve();
		printf("\n");
	}
	return 0;
}