#include <stdint.h>
#include <iostream>

using namespace std;

int main()
{
	int num_test_cases;
	
	cin >> num_test_cases;
	
	for(int test_index = 1; test_index <= num_test_cases; test_index++)
	{
		int K, C, S;
		
		cin >> K >> C >> S;
		
		printf("Case #%d:", test_index);
		
		if(C * S < K)
		{
			printf(" IMPOSSIBLE\n");
		}
		else
		{
			// We need to account for all K
			int remaining_K = K;
			int64_t curr_K_index = 0;
			
			while(remaining_K > 0)
			{
				int64_t tile_index = 1;
				int64_t curr_tile_base = 1;
			
				// Each tile reveals the presence of C tiles in the underlying artwork
				for(int c_index = 0; c_index < C && remaining_K > 0; c_index++, remaining_K--)
				{
					tile_index += curr_K_index * curr_tile_base;
					curr_K_index++;
					curr_tile_base *= (int64_t) K;
				}
				
				printf(" %lld", tile_index);
			}
			
			printf("\n");
		}
	}
	
	return 0;
}
