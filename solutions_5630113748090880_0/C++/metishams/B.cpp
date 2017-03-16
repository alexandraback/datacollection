#include <iostream>
#include <string>


using namespace std;

int c[2502];


int main()
{
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		
		for(int j=0;j<2*n-1;j++) {
			for(int k=0;k<n;k++) {
				int f;
				cin >> f;
				c[f]++;
			}

		}

		cout << "Case #" << i+1 << ": ";

		for(int k=1;k<=2500;k++) {
			if(c[k]%2==1)
				cout << k << " ";
			c[k]=0;
		}
		cout << endl;
	}

	return 0;
}