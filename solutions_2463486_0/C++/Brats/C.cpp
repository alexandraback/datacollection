#include<iostream>
using namespace std;

int main()
{
    int n[5] = {1, 4, 9, 121, 484}; 
	int T, C=0;
	cin >> T;
	int A, B, i, j;
	
	while (T--) {
	    C++;
		
		cin >> A >> B;
		for (i=0; i<5; i++) {
		    if (n[i] >= A) break;
		}
		
		for (j=0; j<5; j++) {
		    if (n[j] > B) break;
		}
		
		cout << "Case #"<<C<<": "<<j-i<<endl;
	}
	
	return 0;
}
