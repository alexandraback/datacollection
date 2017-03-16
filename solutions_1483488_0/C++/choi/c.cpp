#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;


int count(int Min, int Max)
{
	int n_digit=1+int(log10(Min));

	if (n_digit == 1)
		return 0;

	int h=1;
	for (int m=0; m<n_digit-1; m++)
		h*=10;

	int count=0;
	for (int j=Min; j<=Max; j++) {
		int r=j;
		for (int k=1; k<n_digit; k++) {
			r=r/10+(r%10)*h;
			if (r==j)
				break;
			if (r>=Min && r<=Max)
				count++;
		}
	}

	return count/2;
}

int main()
{
    int t;
    cin >> t;
    for(int i=0;i<t;i++) {
		int Min, Max;
		cin >> Min >> Max;
		cout << "Case #" << i+1 << ": " << count(Min, Max) << endl;
	}
}



