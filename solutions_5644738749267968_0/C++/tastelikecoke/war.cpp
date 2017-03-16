#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
	int cases  = 0;
	cin >> cases;
	for(int c=0;c<cases;c++){
		int weights = 0;
		cin  >> weights;
		vector<double> naomi;
		vector<double> ken;
		for(int i=0;i<weights;i++){
			double temp;
			cin >> temp;
			naomi.push_back(temp);
		}
		for(int i=0;i<weights;i++){
			double temp;
			cin >> temp;
			ken.push_back(temp);
		}
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(), ken.end());
		/*for(int i=0;i<weights;i++){
			cout << naomi[i] << " "; 
		}
		cout << endl;
		for(int i=0;i<weights;i++){
			cout << ken[i] << " "; 
		}
		cout << endl;*/
		
		int kenj=0;
		int wins = 0;
		for(int i=0;i<weights;i++){
			if(ken[kenj] > naomi[i]){
				continue;
			}
			else{
				wins++;
				kenj += 1;
			}
		}
		cout <<"Case #"<<c+1<<": "<< wins << " ";
		for(int i=0;i<weights;i++){
			if(ken.size() == 0){
				cout << weights-i << endl;
				goto hasscore;
			}
			while(naomi[i] > *ken.begin() and ken.size() != 0){
				ken.erase(ken.begin());
			}
			if(ken.size() == 0){
				cout << weights-i << endl;
				goto hasscore;
			}
			ken.erase(ken.begin());
		}
		cout << 0 << endl;
		hasscore:;	
	}
}