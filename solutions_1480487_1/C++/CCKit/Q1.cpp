#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;



int main(void){
	int T, u, N, i, sum, nP;
	int cutoff;
	cin >> T;
	
	for(u=0; u<T; u++){
		int score[205];
		cin >> N;
		sum = 0;
		cutoff = 0;
		nP = 0;
		
		for(i=0; i<N; i++){
			cin >> score[i];
			sum += score[i];
		}
		
		for(i=0; i<N;i++){
			if((2*sum) > (score[i]*N)){
				cutoff+=score[i];
				nP++;	
			}
		}
		cutoff += sum;
		
		cout << "Case #" << (u+1) << ": ";
		for(i=0; i<N; i++){		
			if((2*sum) <= (score[i]*N) || (((double)cutoff)/nP-score[i])*100/sum <0){
				printf("0.000000 ");
			}else{
				printf("%f ", (((double)cutoff)/nP-score[i])*100/sum);
			}				
		}
		cout << endl;
	}
	
	return 0;
}
