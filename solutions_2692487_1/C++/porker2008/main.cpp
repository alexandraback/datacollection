#include <iostream>
#include <algorithm>
using namespace std;

int mote[100];

int main()
{
	int T;
	cin >> T;
	for(int c=1;c<=T;c++)
	{
		int op = -1;
		int current = 0;
		int A,N;
		cin >> A >> N;
		for(int i=0;i<N;i++)
			cin >> mote[i];
		sort(mote,mote+N);
		bool finish = false;
		for(int i=0;i<N;i++)
		{
			if(A > mote[i])
			{
				A += mote[i];
			}
			else
			{
				if(op == -1 || op > current + (N-i))
					op = current + (N-i);
				current++;
				if(A>1) A += A-1;
				else
					break;
				i--;
			}
			if(i==N-1) finish = true;
		}
		if(finish && (current < op || op == -1)) op = current;
		cout << "Case #" << c << ": " << op << endl;
	}
	return 0;
}