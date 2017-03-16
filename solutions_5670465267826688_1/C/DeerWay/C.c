#include <stdio.h>
#include <math.h>
#include <string.h>
#define LMAX 10000
int xValue, length;
typedef enum { PO = 1, PI = 2, PJ = 3, PK = 4, MO = -1, MI = -2, MJ = -3, MK = -4 } symbol_t;
typedef long long ll;
symbol_t symbolCal(symbol_t temp, char s)
{
	int sign = temp < 0 ? -1 : 1;
	symbol_t sb = (symbol_t)abs((int)temp);
	switch (sb) {

	case PO:
		if (s == 'i') return (symbol_t)(PI*sign);
		else if (s == 'j') return (symbol_t)(PJ*sign);
		else return (symbol_t)(PK*sign); // k

	case PI:
		if (s == 'i') return (symbol_t)(MO*sign);
		else if (s == 'j') return (symbol_t)(PK*sign);
		else return (symbol_t)(MJ*sign);

	case PJ:
		if (s == 'i') return (symbol_t)(MK*sign);
		else if (s == 'j') return (symbol_t)(MO*sign);
		else return (symbol_t)(PI*sign);

		//  case PK:
	default:
		if (s == 'i') return (symbol_t)(PJ*sign);
		else if (s == 'j') return (symbol_t)(MI*sign);
		else return (symbol_t)(MO*sign);
	}
}
symbol_t symbolPow(symbol_t cur, int cnt)
{
	int sign = cur < 0 ? -1 : 1;
	int resultsign = 1;
	int i;
	cur = (symbol_t)abs((int)cur);
	symbol_t result = PO;

	for (i = 0; i<cnt; i++) {

		if (result == PO) // FOR PO, MO
			result = cur;
		else if (result == cur) { // ELSE
			result = PO;
			resultsign *= (-1);
		}
		resultsign *= sign;
	}

	return (symbol_t)((int)result*resultsign);
}
int main()
{

	int T;
	int i, j, len, flag;
	char str[LMAX + 2];
	ll L, X;
	symbol_t current = PO, result;
	int count;

	scanf("%d", &T);
	for (i = 0; i<T; i++) {

		scanf("%lld%lld", &L, &X);
		scanf("%s", str);
		
		current = PO;
		flag = 0;
		count = X > 8 ? 8 : X;

		for (j = 0; j<L; j++) {
			current = symbolCal(current, str[j]);
		}
		result = symbolPow(current, (int)(X % (ll)4));
		
		printf("Case #%d: ", i + 1);
		if (result != MO){
			printf("No\n");
			continue;
		}

		current = PO;
		for (j = 0; j<count*L; j++) {

			current = symbolCal(current, str[j%L]);
			if (flag == 0 && current == PI) flag = 1;
			else if (flag == 1 && current == PK) { flag = 2; break; }
		}

		if (flag == 2)
			printf("Yes\n");
		else
			printf("No\n");

	}
	return 0;
}
