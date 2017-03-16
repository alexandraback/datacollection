#include <iostream>
#include <math.h>
#include <vector>
using namespace std;


int dig[20];

vector<long long> stor;

int fair(long long test) {
	//determine the number of digits
	int n = 0;
	long long testt=test;

	int i;
	long long d = 0;

	for ( i=1;;i++ ){
		if ((long long)(test/pow(10.0,i-1))<10) {
			break;
		}
	}
	
	

	d = pow(10.0,i-1);
	for (int j=0; j<i; j++) {
		dig[j] = test%10;
		test-=dig[j];
		test/=10;
		
	}

	for (int j=0; j<i; j++) {
		if (dig[j] != dig[i-j-1])
			return 0;
	}
	int kk=0;
	kk=kk;

//	delete[] dig;
	return 1;
}


int main() {
	freopen("debug\\C-large-practice-1.in","r",stdin);
	freopen("debug\\out.txt","w",stdout);

	for (long long i=1; i<1e+7+1000; i++) {
		
		if (fair(pow((double)i,2)) && fair(i) ) {
			stor.push_back(pow((double)i,2));
//			cout<<pow((double)i,2)<<endl;
		}
	}

//	cout<<stor.size()<<endl;

	int testcases;
	cin>>testcases;
	double ntemp;
	int temp;
	int tot;


	int a = 0;
	int b = 0;;
	int flag = 0;
	long long lb, ub;

	int ii,jj;
	double sp;

	for (int i=0; i<testcases; i++) {
		if (i == 13) {
			i=i;
		}
		cin>>lb;
		cin>>ub;

		tot = 0;
		flag = 0;
		/*
		for (int j=lb; j<=ub; j++) {
			if (j==121){
				j=j;
			}
			//determine square
			ntemp = sqrt((double)j);
//			temp = (int)(ntemp*1000000);
//			if ( temp%1000000 == 0 && fair(int(ntemp)) && fair(j) ) {
			if ((int)ntemp==ntemp && fair(int(ntemp)) && fair(j) ) {
				tot++;
			} //end if sqrtable
		}
		*/
		sp = sqrt((double)lb);
		if (sp!=int(sp))
			sp = (int)sp+1;


/*		
		for (int j=sp; j<=sqrt((double)ub); j++) {
			if (j==121){
				j=j;
			}
			//determine square
//			temp = (int)(ntemp*1000000);
//			if ( temp%1000000 == 0 && fair(int(ntemp)) && fair(j) ) {
			if (fair(j) && fair(pow((double)j,2)) ) {
				tot++;
			} //end if sqrtable
		}
*/

		for (int i=0; i<stor.size(); i++){
			if(lb<=stor[i]){
				a=i;
				break;
			}
		}
		
		for (int i=a; i<stor.size(); i++){
			if(ub<stor[i]) {
				b=i;
				break;
			}
		}

		cout<<"Case #"<<i+1<<": "<<b-a<<endl;
	} //end for testcaases


	return 0;
}