#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nTests;
	cin>>nTests;
	for(int te=1; te<=nTests; te++) {

		int nMotes;
		int sizeMote[100];
		int mySize;
		
		cin>>mySize>>nMotes;
		for(int m=0; m<nMotes; m++)
			cin>>sizeMote[m];
		sort(sizeMote, sizeMote+nMotes);

		int minNumOp;

		//0»Ìºˆ, n¡¶∞≈
		minNumOp = nMotes;

		//x»Ìºˆ, n-x¡¶∞≈
		int nAddOp = 0;
		for(int nAb=0; nAb<nMotes; nAb++) {
			if( mySize == 1 )
				break;
			if( nAddOp >= minNumOp )
				break;

			while( mySize <= sizeMote[nAb] ) {
				nAddOp++;
				mySize += mySize-1;
				
				if( nAddOp >= minNumOp )
					break;
			}
			mySize += sizeMote[nAb];

			minNumOp = min(minNumOp, nAddOp + nMotes-(nAb+1));
		}

		cout<<"Case #"<<te<<": "<<minNumOp<<endl;
	}

	return 0;
}