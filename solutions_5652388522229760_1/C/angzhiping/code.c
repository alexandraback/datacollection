#include <stdint.h>
#include <iostream>

using namespace std;

int return_bitmask
	(int64_t d)
{
	int bitmask = 0;
	
	while(d)
	{
		bitmask |= (1 << (d % 10));
		d /= 10;
	}
	
	return bitmask;
}

int main()
{
	int n;
	
	cin >> n;
	
	const int target_bitmask = (1 << 10) - 1;
	
	for(int i = 1; i <= n; i++)
	{
		int64_t d;
		int64_t d_accum = 0;
		
		cin >> d;
		
		if(d == 0)
		{
			cout << "Case #" << i << ": INSOMNIA" << endl;
			continue;
		}
		
		int bitmask = 0;
		
		while(true)
		{
			d_accum += d;
			
			bitmask |= return_bitmask(d_accum);
			
			if(bitmask == target_bitmask)
				break;
		}
		
		cout << "Case #" << i << ": " << d_accum << endl;
	}
	
	return 0;
}