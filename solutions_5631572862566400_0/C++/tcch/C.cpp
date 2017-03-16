#include <algorithm>
#include <stdio.h>
#include <vector>
#include <set>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int res;

void help(vector<int> before, vector<int> BFF){
	int end = *(before.end()-1);
	//cout<<end;
	for(int i=0; i<BFF.size(); i++){
		if(BFF[i]==end && find(before.begin(),before.end(),i+1)==before.end()){
			before.push_back(i+1);
			help(before,BFF);
			before.pop_back();
		}
	}
	int N = before.size();
	//cout<<N;
	res = max(res,N);
	/*if(res==4){
		for(int i=0; i<before.size(); i++){
			cout<<before[i];
		}
		cout<<endl;
	}*/
}


int main(){
	ifstream input;
	input.open("C-small-attempt3.in");
	freopen("out","w",stdout);
	int T,N,next,cur,count;
	input>>T;

	for(int t=0; t<T; t++){
		printf("Case #%d: ",t+1);
		input>>N;
		vector<int> BFF;
		set<int> finish;
		for(int i=0; i<N; i++){
			input>>next;
			BFF.push_back(next);
		}
		res = 0;
		for(int i=0; i<N; i++){
			if(finish.find(i)==finish.end()){
				vector<int> seq;
				count = 0;
				finish.insert(i);
				seq.push_back(i+1);
				count++;
				cur = i+1;
				while(true){
					auto p = find(seq.begin(),seq.end(),BFF[cur-1]);
					//cout<<cur<<' ';
					//cout<<p-seq.begin()<<seq.end()-seq.begin()<<endl;
					if(p==seq.end()){
						//cout<<BFF[cur-1];
						cur = BFF[cur-1];
						//int temp = BFF[cur-1];
						//cur = temp;
						//cout<<cur;
						seq.push_back(cur);
						finish.insert(cur-1);
						count++;
					}
					else{
						if(p == seq.end()-2){
							help(seq,BFF);
							break;
						}
						else{
							count = seq.end()-p;

							res = max(res,count);
							/*if(res==4){
								for(int i=0; i<seq.size(); i++){
									cout<<seq[i];
								}
								cout<<endl;
							}*/
							break;
						}
					}

				}
			}
		}
		cout<<res<<endl;
	}
}