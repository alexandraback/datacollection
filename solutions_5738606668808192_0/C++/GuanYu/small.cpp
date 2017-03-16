#include <cstdio>
typedef long long int llint;
using namespace std;


// Binary
void binary(int num){
	if(num){
		binary(num/2);
		if(num&1) putchar('1');
		else putchar('0');
	}
	return;
}

// Main
int main(void)
{
	int tc, cs, N, J, i, bit, cnt, base, tmp;
	llint mul, val, div, lis[10];

	// Test case
	scanf("%d", &tc);
	for(cs = 1; cs <= tc; cs++){
		printf("Case #%d:\n", cs);
		scanf("%d%d", &N, &J);
		for(i = cnt = 0; cnt < J && i < (1<<(N-2)); i++){
			bit = (1<<(N-1)) + (i<<1) + 1;
			for(base = 2; base < 11; base++){
				tmp = bit, val = 0, mul = 1;
				while(tmp){
					if(tmp & 1) val += mul;
					mul *= base;
					tmp >>= 1;
				}
				for(div = 2; div * div <= val && val%div; div++);
				if(div * div > val) break;
				lis[base-2] = div;
			}
			if(base == 11){
				binary(bit);
				for(base = 2; base < 11; base++)
					printf(" %lld", lis[base-2]);
				printf("\n");
				cnt++;
			}
		}
	}

	return 0;
}
