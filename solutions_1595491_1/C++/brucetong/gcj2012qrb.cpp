//Problem: GCJ 2012 Qualification Round B
//Name: Dancing With the Googlers
//Author: Bruce K. B. Tong

#include <iostream>
#include <queue>
using namespace std;

//#define SMALL
#define LARGE

void init(int bestresult[][2]) {
	//t: total points
	//a: t / 3 (i.e. average point)
	//t % 3 == 0: a + a + a			or	(a-1) + a + (a+1)
	//t % 3 == 1: a + a + (a+1)		or	(a-1) + (a+1) + (a+1)
	//t % 3 == 2: a + (a+1) + (a+1)	or	a + a + (a+2)
	int a;
	for (int t = 0; t <= 30; t++) {
		a = t / 3;
		
		switch(t%3) {
			case 0:
				bestresult[t][0] = a;		//no surprising
				if (t <= 1) 
					bestresult[t][1] = -1;	//with surprising
				else
					bestresult[t][1] = a+1;	//with surprising
				break;
			case 1:
				bestresult[t][0] = a+1;		//no surprising
				if (t <= 1) 
					bestresult[t][1] = -1;	//with surprising
				else
					bestresult[t][1] = a+1;	//with surprising
				break;
			case 2:
				bestresult[t][0] = a+1;		//no surprising
				bestresult[t][1] = a+2;		//with surprising
		}
	}
	//examples:
	//points	no surpirsing	with surprising
	//0%3=0:	0 + 0 + 0
	//1%3=1:	0 + 0 + 1
	//2%3=2:	0 + 1 + 1	or	0 + 0 + 2
	//3%3=0:	1 + 1 + 1	or	0 + 1 + 2
	//4%3=1:	1 + 1 + 2	or	0 + 2 + 2
	//5%3=2:	1 + 2 + 2	or	1 + 1 + 3
	//6%3=0:	2 + 2 + 2	or	1 + 2 + 3
	//7%3=1:	2 + 2 + 3	or	1 + 3 + 3
	//8%3=2:	2 + 3 + 3	or	2 + 2 + 4
	//10%3=0:	3 + 3 + 3	or	2 + 3 + 4
	//11%3=1:	3 + 3 + 4	or	2 + 4 + 4
	//12%3=2:	3 + 4 + 4	or	3 + 3 + 5
	//...
}

void read(int &N, int &S, int &p, int t[]) {
	cin >> N;
	cin >> S;
	cin >> p;
	for (int i = 0; i < N; i++)
		cin >> t[i];
}

int compute(int N, int S, int p, int t[], int bestresult[][2]) {
	priority_queue<int> q;	//max heap
	int count = 0;
	int ti;
	for (int i = 0; i < N; i++)
		if (bestresult[t[i]][0] >= p)
			count++;
		else
			q.push(t[i]);
	for (int i = 0; i < S && !q.empty(); i++) {
		ti = q.top();
		q.pop();
		if (bestresult[ti][1] >= p)
			count++;
		else
			break;
	}
	return count;
}

int main() {
	freopen("B-sample.in", "rt", stdin);
	#ifdef SMALL
		freopen("B-small-attempt1.in", "rt", stdin);
		freopen("B-small-attempt1.out", "wt", stdout);
	#endif
	#ifdef LARGE
		freopen("B-large.in", "rt", stdin);
		freopen("B-large.out", "wt", stdout);
	#endif

	int T;			//1 <= T <= 100
	int N;			//1 <= N <= 3 (or 100)
	int S;			//0 <= S <= N
	int p;			//0 <= p <= 10
	int t[100];		//0 <= t[i] <= 30, N t[i]s
	int bestresult[30+1][2] = {0};
	
	init(bestresult);

	cin >> T;

	for (int i = 1; i <= T; i++) {
		read(N, S, p, t);
		cout << "Case #" << i << ": ";
		cout << compute(N, S, p, t, bestresult) << endl;
	}
	
	return 0;
}