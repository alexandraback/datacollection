//Dan Johnson
//Google Code Jam
//Qualifying Round 2012
//Problem C
//Recycled Numbers
#include <stdio.h>
#include <math.h>

int num_digits(int x) {
	int count = 0;
	while(x) {
		x /= 10;
		++count;
	}
	return count;
}

int count_recycleds(int num, int A, int B) {
	int count = 0;
	int offset = 1;
	int factor = 10;
	int digits = num_digits(num);
	while (1) {
		int head = num / factor;
		if (head == 0) break;
		int tail = num % factor;
		int invfactor = (int)(pow(10, digits - offset) + 0.1); //don't you dare round down if it's 0.9999999999
		int temp = tail * invfactor + head;
		if (num == temp) break;
		if (temp > num && temp <= B) {
			++count;
		}
		factor *= 10;
		++offset;
	}
	return count;
}
int num_recycled(int A, int B) {
	int count = 0;
	int x;
	for(x = A; x < B; x++) {
		count += count_recycleds(x, A, B);
	}
	return count;
}
int main() {
	int num, i;
	scanf("%d", &num);
	for(i = 0; i < num; ++i) {
		int A, B;
		scanf("%d %d", &A, &B);
		int result;
		result = num_recycled(A, B);
		printf("Case #%d: %d\n", i + 1, result);
	}
}
