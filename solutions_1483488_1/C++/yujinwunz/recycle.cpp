#include <fstream>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");

int cases, a, b, power[8] = {1,10,100,1000,10000,100000,1000000,10000000}, seen[10], numseen;

int main(){
	in>>cases;
	for(int i = 1; i <= cases; i++){
		in>>a>>b;
		int total = 0;
		for(int j = a; j <= b; j++){
			//check how many j has. the conjugate of j must be higher than j, and not have a leading zero.
			//it must also not be seen before.
			int digits = -1;
			while(power[++digits]<=j);
			int counter = -1;
			numseen = 0;
			while(power[++counter+1] < j){
				int left = j/power[counter+1], right = j%power[counter+1];
				if(right<power[counter]) continue;
				int num = right*power[digits-counter-1]+left, used = 0;
				for(int i = 0; i < numseen; i++){
					if(seen[i] == num) used = true;
				}
				if(num<=j||used||num>b) continue;
				total++;
				seen[numseen++] = num;
			}
			
		}
		out<<"Case #"<<i<<": "<<total<<"\n";
	}
	return 0;
}
