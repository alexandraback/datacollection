#include <iostream>
using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int tn;
	cin >> tn;
	for(int loop=0;loop<tn;loop++)
	{
		cout << "Case #" << loop+1<<": ";
		int C, N;
		cin >> C >> N;
		double minimum = -1;
		// right away
		minimum = N + 2; // N + enter + enter

		double noerror = 1;
		for(int i = 0; i < C; i ++)
		{
			double pc;
			cin >> pc;
			// noerror at <= i
			minimum = min(minimum, noerror * ((C-i)*2+N-C+1) + (1-noerror)*((C-i)*2+N-C+1+N+1));

			//cout << noerror <<'\t'<< ((C-i)*2+N-C+1) <<'\t'<< (1-noerror)<<'\t'<<((C-i)*2+N-C+1+N+1) << '\n';
			noerror *= pc;
		}
		// keep trying : noerror -> ok or retype
		minimum = min(minimum, noerror * (N-C+1) + (1-noerror) * (N-C+1+N+1));

		cout << minimum << endl;
	}
	return 0;
}
