#include <cstdio>

using namespace std;

int main()
{
	int T , E , R , N , v[10] , max , sum , result;
	scanf("%d" , &T);
	for(int a = 1 ; a <=T ; a++)
	{
		printf("Case #%d: " , a);
		scanf("%d %d %d" , &E , &R , &N);
		max = 0;
		sum = 0;
		for(int i=0 ; i<N ; i++)
		{
			scanf("%d" , &v[i]);
			if(v[i] > max)
				max = v[i];
			sum += v[i];
		}
		if(R > E)
			R = E;
		result = max * E;
		sum -= max;
		result += sum * R;
		printf("%d\n" , result);
	}
	return 0;
}
