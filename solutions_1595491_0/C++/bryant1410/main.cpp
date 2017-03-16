#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
		int N, S, p, y;
		cin >> N >> S >> p;
		int puntaje;
		y=0;
		for(int i=0;i<N;i++)
		{
			cin >> puntaje;
			int q = puntaje/3;
			int r = puntaje%3;
			switch(r)
			{
				case 0:
					if(q>=p)
						y++;
					else if(q!=0 && q!=10 && q+1>=p && S>0)
					{
						y++;
						S--;
					}
					break;
				case 1:
					if(q+1>=p)
						y++;
					break;
				case 2:
					if(q+1>=p)
						y++;
					else if(q+2>=p && S>0)
					{
						y++;
						S--;
					}
					break;
			}

		}

		cout << "Case #" << i << ": " << y << endl;
	}
	return 0;
}