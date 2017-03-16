#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	
	int nn;
	cin>>nn;
	
	for(int kk=0; kk<nn; kk++){
		
		double C, F, X;
		cin>>C>>F>>X;
		
		double cc = 0;		// current number of coockies
		double nf = 0;		// current number of farms
		double time = 0;
		
		
		while( true ){
			if( cc >= C ){
				
				double timeBuyFarm = ( X-cc+C ) / ( (nf+1)*F + 2 );
				double timeNoBuyFarm = ( X-cc ) / ( nf*F + 2 );
				
				if( timeNoBuyFarm <= timeBuyFarm ){
					
					time += timeNoBuyFarm;
					break;
					
				}
				else{
					
					cc = cc - C;
					nf++;
					
				}
				
			}
			else{
				
				if( X-cc <= C-cc){
					time += (X-cc) / (nf*F + 2);
					break;
				}
				
				double mini = C-cc;
				time += mini / (nf*F + 2);
				cc += mini;
				
			}
			
		}
		
		cout << fixed;
		cout << setprecision(7);
		cout << "Case #" << kk+1 << ": " << time << endl;
		
	}
	
}
