#include<stdio.h>

#define SIZE 1001

int Case;
int N;
int A[SIZE];
int Ans;
int Used[SIZE];

void initUsed()
{
	int i;
	for (i=1; i<=N; i++)
		Used[i] = 0;
}

void readCase()
{
	int i;
	scanf("%d", &N);
	for (i=1; i<=N; i++)
		scanf("%d", &A[i]);
}

int exist(int n)
{
	int i;
	for (i=1; i<=N; i++) if (!Used[i] && A[i] == n)
		return i;
	return 0;
}

int fill(int left, int right, int count)
{
	int i;
	while (1) {
		if (!Used[A[left]]) {
			Used[A[left]] = 1;
			left = A[left];
			count++;
		}
		else {
			left = exist(left);
			if (!left)
				break;
			Used[left] = 1;
			count++;
		}
	}
	while (right) {
		if (!Used[A[right]]) {
			Used[A[right]] = 1;
			right = A[right];
			count++;
		}
		else {
			right = exist(right);
			if (!right)
				break;
			Used[right] = 1;
			count++;
		}
	}
	return count;
}

void solveCase()
{
	int i, temp;
	Ans = 0;
	initUsed();
	for (i=1; i<=N; i++) if (!Used[i]) {
		Used[i] = Used[A[i]] = 1;
		temp = fill(i, A[i], 2);
		if (temp > Ans)
			Ans = temp;
	}
}

void printCase()
{
	int i;
	printf("Case #%d: %d\n", Case, Ans);
}

int main()
{
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (Case=1; Case<=T; Case++) {
		readCase();
		solveCase();
		printCase();
	}
	return 0;
}
