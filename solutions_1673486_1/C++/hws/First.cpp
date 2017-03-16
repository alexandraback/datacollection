#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


	double rate[100000];
	double pre[100000];
int main(){
	ifstream cin("A-large.in");
	ofstream cout("A-large.out");

	
	int time;
	int curType,maxType;
	double allRight;
	cin >> time;
	for(int i=0;i<time;i++){
		cin >> curType >> maxType;
		allRight=1;
		pre[0]=1;
		for(int j=0;j<curType;j++){
			cin >> rate[j];
			pre[j+1]=pre[j]*rate[j];
		}

		double min=pre[curType]*(maxType-curType+1)+(1-pre[curType])*(maxType+maxType-curType+2);
		//cout << "all right is:" << min << endl;
		double temp;
		for(int k=curType-1;k>0;k--){
			temp=pre[k]*(maxType-k+1+(curType-k))+(1-pre[k])*(maxType+maxType-k+2+(curType-k));
			//cout << curType-k << "all right is: " << temp << endl;
			if(temp<min){
				min=temp;
			}
		}
		temp=maxType+2;
		//cout << "give up type and the type is:" << temp << endl;
		if(temp<min){
			min=temp;
		}
		cout << "Case #" << i+1 << ": "<< setiosflags(ios::fixed)  << setprecision(6) << min << endl;


		
		
	}
}