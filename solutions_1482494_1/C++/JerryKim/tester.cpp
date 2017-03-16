#include<iostream>
#include<fstream>
#include<string>

#include<sstream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

int main(){
	int testcase;
	ifstream infile;
	ofstream outfile;
	infile.open("B-large.in"); //filename//
	outfile.open("result.txt");
	
	infile>>testcase;

	for(int i=0;i<testcase;i++){
		int lvl;
		infile>> lvl;
		vector<int> mins;
		vector<int> mins_lv1;
		vector<int> mins_lv2;
		vector<int> passed;

		int l2remain = lvl;
		int l2min = 2002;
		int l1min = 2002;
		for(int j=0;j<lvl;j++){
			int temp;
			infile>>temp;
			if(l1min>temp)
				l1min = temp;
			mins_lv1.push_back(temp);
			infile>>temp;
			if(l2min>temp)
				l2min = temp;
			mins_lv2.push_back(temp);
			passed.push_back(0);
		}

		int stars = 0;
		int steps = 0;
		while(1){
			if(l2remain ==0){
				outfile<<"Case #"<<i+1<<": "<<steps<<"\n";
				break;
			}
			else if(l2min<=stars){
				for(int j=0;j<lvl;j++){
					if(mins_lv2[j]==l2min){
						if(passed[j]!=2){
							if(passed[j]==1) stars--;
							passed[j]=2;
							break;
						}
					}
				}
				l1min = 2002;
				l2min = 2002;
				for(int j=0;j<lvl;j++){
					if(passed[j]==0){
						if(l1min>mins_lv1[j])
							l1min=mins_lv1[j];
						if(l2min>mins_lv2[j])
							l2min=mins_lv2[j];
					}
					if(passed[j]==1){
						if(l2min>mins_lv2[j])
							l2min=mins_lv2[j];
					}
				}

				stars=stars+2;
				steps++;
				l2remain--;
			}
			else if(l1min<=stars){
				int l2val=-1;
				int idx;
				for(int j=0;j<lvl;j++){	
					if(mins_lv1[j]<=stars){
						if(passed[j]==0){
							if(l2val<mins_lv2[j]){
								l2val=mins_lv2[j];
								idx = j;
							}
						}
					}
				}
				passed[idx]=1;
				l1min =2002;
				for(int j=0;j<lvl;j++){
					if(passed[j]==0){
						if(l1min>mins_lv1[j])
							l1min=mins_lv1[j];
					}
				}
				stars++;
				steps++;
			}
			else{
				outfile<<"Case #"<<i+1<<": "<<"Too Bad"<<"\n";
				break;
			}
		}
		


		
		

		

		//do something end
		
	//	outfile<<"Case #"<<i+1<<": "<<ksmin<<"\n";
	}
	infile.close();
	outfile.close();
	return 0;
}