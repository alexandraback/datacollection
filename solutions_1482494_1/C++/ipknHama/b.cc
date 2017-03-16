#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int tn;
	cin >> tn;
	for(int loop = 0 ; loop < tn; loop++)
	{
		cout << "Case #" << loop+1<<": ";
		int N;
		cin >> N;
		vector<int> a(N), b(N), u(N);
		for(int i = 0; i < N; i ++)
			cin >> a[i] >> b[i];

		int current = 0;
		int turn = 0;
		while(current < 2*N)
		{
			while(current < 2*N)
			{
				int lastturn = turn;
				for(int i = 0; i < N; i ++)
				{
					if (b[i] <= current && u[i] < 2)
					{
						current += 2-u[i];
						u[i] = 2;
						turn ++;
					}
				}
				if (lastturn == turn)
					break;
			}
			if (current == 2*N)
				break;
			int maxbindex = -1;
			for(int i = 0; i < N; i ++)
				if (!u[i] && a[i] <= current)  
				{
					if (maxbindex == -1)
						maxbindex = i;
					else if (b[maxbindex] < b[i])
						maxbindex = i;
				}
			if (maxbindex < 0)
				break;
			u[maxbindex] = 1;
			current ++;
			turn++;
		}
		if (current == 2*N)
		{
			cout << turn;
		}
		else
		{
			cout << "Too Bad";
		}
		cout << endl;

	}
	return 0;
}

