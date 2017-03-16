#include <iostream>
#include <iomanip>
using namespace std;

double min(double *arr, int len)
{
	int min = 0;
	for(int i = 1; i < len; ++i)
		if(arr[i] < arr[min])
			min = i;
	return arr[min];
}

int main()
{
	int T, A, B;
	double *probs = new double[99999];
	double *prevs_right = new double[99999];
	double *keystrokes = new double[3];
	cin >> T;
	for(int t = 1; t <= T; ++t)
	{
		cin >> A >> B;
		for(int a = 0; a < A; ++a)
			cin >> probs[a];
		//
		// [0]: Keystrokes if I keep typing
		double p_right = 1.0;
		for(int a = 0; a < A; ++a)
		{
			prevs_right[a] = p_right;
			p_right *= probs[a];
		}
		keystrokes[0] = p_right*(B-A+1) + (1-p_right)*(B-A+1+B+1);
		//
		// [1]: Keystrokes if I press backspace X-times (keep the best)
		double tmp;
		for(int bs = A-1; bs >= 0; --bs)	// backspace
		{
			tmp = prevs_right[bs]*(A-bs+B-bs+1) + (1-prevs_right[bs])*(A-bs+B-bs+1+B+1);
			if(bs == (A-1))
				keystrokes[1] = tmp;
			else if(tmp < keystrokes[1])
				keystrokes[1] = tmp;
		}
		//keystrokes[1] = ;
		//
		// [2]: Keystrokes if I press enter right away
		if(A == B)
			keystrokes[2] = 1;
		else
			keystrokes[2] = 2+B;
		//
		// output
		cout << "Case #" << t << ": " << setprecision(7) << min(keystrokes, 3) << '\n';
	}
	delete [] keystrokes;
	delete [] prevs_right;
	delete [] probs;
	return 0;
}