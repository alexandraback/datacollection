#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

double binomial(double n, double k)
{
    double num, den ;
    if ( n < k ) 
    {
       return(0) ; 
    }
    else 
    {
	den = 1;
	num = 1 ; 
	for (int i =  1  ; i <= k   ; i = i+1)
	    den =    den * i;
	for (int j = n-k+1; j<=n; j=j+1)	
	    num = num * j;
	return(num/den);
    } 
}

int main()
{

	int numCase, N, X, Y;
	long double probability;
	cin >> numCase;

	ofstream myfile;
  	myfile.open ("output.txt");

	for (int num = 0; num < numCase; num++)
	{

		// Read dimensions
		cin >> N;
		cin >> X;
		cin >> Y;
		
		// Find k such that T_k <= n < T_{k+2} where T_k is the kth triangular number, T_k = k(k+1)/2
		int k=1, Tk=1;
		while((k+2)*(k+3)/2 <= N) {k+=2; Tk=k*(k+1)/2;}
		
		// First check if this is a gimmie
		probability=-1.0; // For debugging
		if(X+Y<=k) {probability=1.0;}
		else {
			int nextK=k+2;
			int sizeOfBoxes=nextK-1;
			// Now consider the two boxes on either sideof the triangle that has been formed
			int numberOfDrops=N-Tk; // balls that are left to drop
		
			if(numberOfDrops==0) {probability=0.0;}
			else {
				int ballsInLeft=0;
				int ballsInRight=0;
				int dummy=0;
				while(numberOfDrops>sizeOfBoxes-dummy) { // Distribute one ball in each box, they have to slide
					ballsInLeft++;
					ballsInRight++;
					dummy++;
					numberOfDrops-=2;
				}
				if(ballsInLeft>=Y+1) {probability=1.0;}
				else if(ballsInLeft+numberOfDrops<Y+1) {probability=0.0;}
				else if(X==0) {probability=0.0;}
				else { // It is possible, compute the probability, that is neither 0 or 1
					probability=0.0;
					for(int i=Y+1-ballsInLeft;i<=numberOfDrops;i++) {
						probability+=binomial(numberOfDrops,i)*1.0/pow(2.0,numberOfDrops);
					}
				}
			}
		}
		
		// Print outcome
		myfile << "Case #" << (num+1) << ": " << probability << endl;
	}

  	myfile.close();
	return 0;
}
