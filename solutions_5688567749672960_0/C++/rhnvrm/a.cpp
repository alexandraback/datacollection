#include <bits/stdc++.h>

using namespace std;


long long swap(long long x){

	long long y = 0; 

	while(x!=0){

		y*=10;

		y+=x%10;

		x/=10;


	
	}

	return y;

}

int main()
{

	int T;
	cin >> T;
	int	t = T;

	long long solution;

	while(t--){

		long long n;

		scanf("%lld", &n);

		long long count = 1, solution = 0;

		//printf("|%lld|",swap(2300));

		while(count <= n){

			//cout << " " << count << " ";
			long long save = swap(count);
			if(save> count+1 && save <= n ){
				count = swap(count);
			}			
			else{
				count++;
			}

			solution++;
		}





		printf("Case #%d: %lld\n", T - t, solution);
	}


	return 0;
}