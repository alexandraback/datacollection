#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

//short hand for loops
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//quick print for answer cases
int case_number;
#define gout case_number++, printf("Case #%d: ",case_number), cout
#define INF (1<<29)

//define necessary arrays here 
float a[100] = {0};
float b[100] = {0};

float ad[100] = {0};
float bd[100] = {0};

void main2(void){
	int N,i,j,k, kc;
	float temp=0;
	int nam=0;
	int namD=0;
	
	//data	
	cin >> N;
	REP(i,N) cin >> a[i];
	REP(i,N) cin >> b[i];
		
	//sort the arrays
	int swap=1;
	while(swap==1){
		swap=0;
		REP(i,N-1){
			if(a[i]<a[i+1]){
				//swap
				temp = a[i+1];
				a[i+1] = a[i];
				a[i] = temp;		
				swap=1;
			}
		}
	}	
	swap=1;
	while(swap==1){
		swap=0;
		REP(i,N-1){
			if(b[i]<b[i+1]){
				//swap
				temp = b[i+1];
				b[i+1] = b[i];
				b[i] = temp;		
				swap=1;
			}
		}
	}
	
	//copy 
	REP(i,N) ad[i] = a[i];
	REP(i,N) bd[i] = b[i];
	
	
	//begin war game
	int diff = INF;
	REP(i,N){
	    //cout << "a-loop running" << endl; //
		for(j=0;j<N;j++){
			if(b[j]!=0 and a[i]!=0){
				//cout << "a[i] " << a[i] << endl << "b[j] " << b[j] << endl; // 
				if( a[i] > b[j] ){
					for(k=N-1;k>=0;k--){
						if(b[k]==0){
							//pass over it
						}else{
							//cout << "eliminated " << b[k] << endl; //
							b[k] = 0;
							break;
						}
					}
					nam++;
					a[i] = 0;
				
				}else{ // check for closest winning ken value
					REP(k,N){
						if(b[k]>a[i]){
							if(b[k]-a[i]<diff){
								kc = k;
								diff = b[k]-a[i];
							}	
						}
					}
					//cout << "eliminated " << b[kc] << endl; //
					b[kc] = 0; //eliminate closest of kens choices
					diff = INF;
					break;
				}
			}	
		}
	}
	
	//gout << nam << endl; //correct results
	
	//play D-war with ad and bd
	int beat=0;
	for(i=N-1;i>=0;i--){
	/*
		cout << "print arrays" << endl;
		REP(k,N) cout << ad[k] << " "; //
		cout << endl;  //
		REP(k,N) cout << bd[k] << " "; //
		cout << endl; //
	*/
		if(ad[i]!=0){
				//search until you beat something
				REP(j,N){
					if(bd[j]!=0 and ad[i]!=0){
					//cout << "compair" << endl;
					//cout << "ad[i] " << ad[i] << endl << "bd[j] " << bd[j] << endl; //
					
						if(ad[i]>bd[j]){
							ad[i]=0;
							bd[j]=0;
							namD++;
							beat=1;	
						}
					}	
				}
				//if nothing beat then take out highest non-zero player
				if(beat==0){
					REP(j,N){
						if(bd[j]==0){
							//skip over it
						}else{
							bd[j]=0;
							ad[i]=0;
							break;
						}
					}
				}else{ //if something was beat
					beat=0; //reset beat
				}	
		}
	}

	gout << namD << " " << nam << endl; //correct results
	
	//check
	/*
	REP(i,N) cout << ad[i] << " "; //
	cout << endl;  //
	REP(i,N) cout << bd[i] << " "; //
	cout << endl; //	 
	*/


} // end main2

int main(void){
	int number_of_test_cases, i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
