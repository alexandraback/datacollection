#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int T;
char num[10000];
int bucket[150];
int actualno[10];

int main(){
	
	cin >> T;
		
	for (int i=1; i<=T; i++){
		cin >> num;
		cout << "Case #" << i << ": ";
		for(int j=0; j<150; j++){
			bucket[j]=0;
		}
		for(int j=0; j<10; j++) actualno[j]=0;
		for(int j=0; j<strlen(num); j++){
			bucket[num[j]]++;
		//	cout << "bucket " << num[j] << " is " << bucket[num[j]] << endl;
		}
		
		//If there's a zero
			while(bucket['Z']>0){
		//		cout << "ZERO " << bucket['Z'] << " ";
				actualno[0]++;
				bucket['Z']--;
				bucket['E']--;
				bucket['R']--;
				bucket['O']--;
			}
			
			while(bucket['W']>0){
				actualno[2]++;
				bucket['T']--;
				bucket['W']--;
				bucket['O']--;
			}
			
			
			while(bucket['U']>0){
				actualno[4]++;
				bucket['F']--;
				bucket['O']--;
				bucket['U']--;
				bucket['R']--;
			}
			
			while(bucket['X']>0){
				actualno[6]++;
				bucket['S']--;
				bucket['I']--;
				bucket['X']--;
			}
			
			while(bucket['G']>0){
				actualno[8]++;
				bucket['E']--;
				bucket['I']--;
				bucket['G']--;
				bucket['H']--;
				bucket['T']--;
			}
			
			while(bucket['O']>0){
				actualno[1]++;
				bucket['O']--;
				bucket['N']--;
				bucket['E']--;
			}
			
			while(bucket['R']>0){
				actualno[3]++;
				bucket['T']--;
				bucket['H']--;
				bucket['R']--;
				bucket['E']-=2;
			}
			
			while(bucket['F']>0){
				actualno[5]++;
				bucket['F']--;
				bucket['I']--;
				bucket['V']--;
				bucket['E']--;
			}
	
			while(bucket['V']>0){
				actualno[7]++;
				bucket['S']--;
				bucket['V']--;
				bucket['N']--;
				bucket['E']-=2;
			}
			
			while(bucket['I']>0){
				actualno[9]++;
				bucket['N']-=2;
				bucket['I']--;
				bucket['E']--;
			}
			
			
		//	for(int j=0; j<=9; j++) cout << actualno[j] << " ";
		//	cout << endl;
				
			
			for(int j=0; j<=9; j++){
				
				for (int k=0; k<actualno[j]; k++){
					cout << j;
				}
			}
			cout << endl;
	
	}
}
