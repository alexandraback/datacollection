#include <stdio.h>


__int64 box[101][2], toy[101][2];
__int64 queue[1000000][3][3];

int main() {
	int t;
	scanf("%d", &t);

	int i;
	for(i = 0; i < t; i++) {
		int n, m;
		scanf("%d %d", &n, &m);

		int j;
		for(j = 0; j < n; j++) {
			scanf("%I64d %I64d", &box[j][0], &box[j][1]);
		}

		for(j = 0; j < m; j++) {
			scanf("%I64d %I64d", &toy[j][0], &toy[j][1]);
		}

		int head = 0;
		int tail = 1;
		queue[0][0][0] = box[0][0];
		queue[0][0][1] = box[0][1];
		queue[0][0][2] = 0;
		queue[0][1][0] = toy[0][0];
		queue[0][1][1] = toy[0][1];
		queue[0][1][2] = 0;
		queue[0][2][0] = 0;

		__int64 max = 0;
		while(head < tail) {
			__int64 box_count = queue[head][0][0];
			__int64 box_type = queue[head][0][1];
			__int64 box_index = queue[head][0][2];
			__int64 toy_count = queue[head][1][0];
			__int64 toy_type = queue[head][1][1];
			__int64 toy_index = queue[head][1][2];
			__int64 sum = queue[head][2][0];
			head++;

			if(box_index < n && toy_index < m) {
				if(box_type == toy_type) {
					if(box_count == toy_count) {
						queue[tail][0][0] = box[box_index+1][0];
						queue[tail][0][1] = box[box_index+1][1];
						queue[tail][0][2] = box_index+1;
						queue[tail][1][0] = toy[toy_index+1][0];
						queue[tail][1][1] = toy[toy_index+1][1];
						queue[tail][1][2] = toy_index+1;
						queue[tail++][2][0] = sum + box_count;
					}
					else if(box_count < toy_count) {
						queue[tail][0][0] = box[box_index+1][0];
						queue[tail][0][1] = box[box_index+1][1];
						queue[tail][0][2] = box_index+1;
						queue[tail][1][0] = toy_count - box_count;
						queue[tail][1][1] = toy_type;
						queue[tail][1][2] = toy_index;
						queue[tail++][2][0] = sum + box_count;
					}
					else {
						queue[tail][0][0] = box_count - toy_count;
						queue[tail][0][1] = box_type;
						queue[tail][0][2] = box_index;
						queue[tail][1][0] = toy[toy_index+1][0];
						queue[tail][1][1] = toy[toy_index+1][1];
						queue[tail][1][2] = toy_index+1;
						queue[tail++][2][0] = sum + toy_count;
					}
				}
				else {
					queue[tail][0][0] = box[box_index+1][0];
					queue[tail][0][1] = box[box_index+1][1];
					queue[tail][0][2] = box_index+1;
					queue[tail][1][0] = toy_count;
					queue[tail][1][1] = toy_type;
					queue[tail][1][2] = toy_index;
					queue[tail++][2][0] = sum;

					queue[tail][0][0] = box_count;
					queue[tail][0][1] = box_type;
					queue[tail][0][2] = box_index;
					queue[tail][1][0] = toy[toy_index+1][0];
					queue[tail][1][1] = toy[toy_index+1][1];
					queue[tail][1][2] = toy_index+1;
					queue[tail++][2][0] = sum;
				}
			}
			else {
				if(max < sum)
					max = sum;
			}
		}

		printf("Case #%d: %I64d\n", i+1, max);
	}

	return 0;

}