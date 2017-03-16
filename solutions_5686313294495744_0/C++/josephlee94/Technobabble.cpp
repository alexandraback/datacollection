#include <iostream>
#include <string.h>
using namespace std;

char str1[1005][20], str2[1005][20];
int num, T;
int fake[1005];

int main(){
	
	cin >> T;
	for (int i=1; i<=T; i++){
		cin >> num;
		cout << "Case #" << i << ": ";	
		for(int j=0; j<num; j++) fake[j]=0;
		for(int j=0; j<num; j++){
			cin >> str1[j] >> str2[j];
		}
		
		for(int j=0; j<num; j++){
			int pos = 0;
			for(int k=0; k<num; k++){
				if(k==j || fake[k]!=0){
				}
				else if(strcmp(str1[j],str1[k])==0){
					pos = 1;
				}
			}
			for(int k=0; k<num; k++){
				if(k==j || fake[k]!=0) continue;
				if(strcmp(str2[j],str2[k])==0){
					if(pos==1) pos = 2;
				}
			}
			if (pos==2){
				fake[j]++;
			}
			
		}
		int conut=0;
		for(int j=0; j<num; j++) if(fake[j]!=0) conut++;
	//	for(int j=0; j<num; j++) cout << fake[j] << " ";
		
		cout << conut << endl;
	}
	
	
}
