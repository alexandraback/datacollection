#include <cstdio>
using namespace std;

int main()
{
	int test_num, s_max, buf, ans, temp;
	
	scanf("%d", &test_num);
	for (int i = 1; i <= test_num; i++){
		buf = ans = 0;
		scanf("%d", &s_max);
		for (int j = 0; j <= s_max; j++){
			scanf("%1d", &temp);
			if (temp != 0 && buf < j){
				ans += j - buf;
				buf = j;
			}
			buf += temp;
		}
		printf("Case #%d: %d\n", i, ans);
	}
	return 0;
}