#include <fstream>
using namespace std;
ifstream in("in.txt");
ofstream out("out.txt");

long long cases, toys, boxes, toy[100][2], box[100][2], best[100][100];

long long score(int t, int b, long long remaining, bool isToyRemaining){
	//returns the best way after using/not using toy t.
	//base case
	if(t==toys||b==boxes) return 0ll;
	long long ret = 0ll;
	if(remaining){
		if(isToyRemaining){
			//has remaining toys. deal with it.
			//find first matching box.
			for(int i = b; i < boxes; i++){
				if(toy[t][1]==box[i][1]){
					//found match. TODO
					if(remaining>box[i][0]){
						//still too many toys. 
						ret = score(t,i+1,remaining-box[i][0],true) + box[i][0];
					}else if(box[i][0]>remaining){
						//boxes remaining. 
						ret = score(t+1,i,box[i][0]-remaining,false) + remaining;
					}else{
						//both used up. 
						ret = score(t+1,i+1,0,false) + remaining;
					}
					i=boxes;
				}
			}
			ret = max(ret,score(t+1,b,0,false));
		}else{
			//has remaining boxes. deal with it.
			//find first matching toy.
			for(int i = t; i < toys; i++){
				if(toy[i][1]==box[b][1]){
					//found match. 
					if(remaining>toy[i][0]){
						//still too many boxes. 
						ret = score(i+1,b,remaining-toy[i][0],false) + toy[i][0];
					}else if(toy[i][0]>remaining){
						//toys remaining. 
						ret = score(i,b+1,toy[i][0]-remaining,true) + remaining;
					}else{
						//both used up. 
						ret = score(i+1,b+1,0ll,false) + remaining;
					}
					i=toys;
				}
			}
			ret = max(ret,score(t,b+1,0ll,false));
		}
		//output.
		return ret;
	}
	//no remainingness
	if(best[t][b]!=-1) return best[t][b];
	if(toy[t][1]==box[b][1]){
		if(toy[t][0]>box[b][0]){
			//fewer boxes, resulting in remaining toys
			ret = score(t,b+1,toy[t][0]-box[b][0],true) + min(toy[t][0],box[b][0]);
		}else if(box[b][0]>toy[t][0]){
			//fewer toys, resulting in remaining boxes.
			ret = score(t+1,b,box[b][0]-toy[t][0],false) + min(toy[t][0],box[b][0]);
		}else{
			//equal number, resulting in nexts.
			ret = score(t+1,b+1,0,false) + box[b][0];
		}
	}else{
		//different. easier.
		ret = max(score(t+1,b,0,false),score(t,b+1,0,false));
	}
	best[t][b] = ret;
	return ret;
}

int main(){
	in>>cases;
	for(int i = 1; i <= cases; i++){
		//init
		for(int k = 0; k < 100; k++) for(int l = 0; l < 100; l++) best[k][l] = -1;
		//input;
		in>>toys>>boxes;
		for(int j = 0; j < toys; j++){
			in>>toy[j][0]>>toy[j][1];
		}
		for(int j = 0; j < boxes; j++){
			in>>box[j][0]>>box[j][1];
		}
		//process;
		long long result = score(0,0,0,0);
		//output;
		out<<"Case #"<<i<<": "<<result<<"\n";
	}
}