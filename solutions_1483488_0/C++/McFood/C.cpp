#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

#define for0(i,n) for( int i = 0; i < (n); i++)

int e(int p)
{
	int r = 1;
	for0(i,p)
	{
		r = r*10;
	}
	return r;
}

int digits(int n)
{
	int d = 0;
	do
	{
		d++;
		n = n/10;
	} while(n != 0);
	return d;
}
void main()
{

	int T;
	cin >> T;

	for0( CASE, T)
	{
		int low;
		int high;
		cin >> low >> high;
		int count = 0;
		vector<bool> checked (high-low + 1,false);
		for( int l = low; l < high; ++l)
		{
			if(checked[l - low]) continue;
			int dl = digits(l);

			/*for( int h = l + 1; h < high; ++h)
			{
				int dh = digits(h);
				bool found = false;
				if(dl != dh) break;*/
			
			int numset = 1;
			for(int d = 1; d < 10; d++)
			{
				int ex = e(d);
				if(dl < d) break;
				int checking = l/ex + (l%ex)*e(dl-d);

				if (digits(checking) != dl || checking == l) continue;
				if(checking <= high && checking >= low )
				{
					if(checked[checking - low] == true) continue;
				//	found = true;
					numset++;
					checked[checking - low] = true;
				}

	
			}
			//if( numset != 1) cout << "L: " << l << " Matches:" << numset - 1 << endl;
			count = count + (numset*(numset-1))/2;
			//	if (found) continue;

			//}

		}


		
		cout << "Case #" << CASE + 1 << ": " << count << endl;
	}

}