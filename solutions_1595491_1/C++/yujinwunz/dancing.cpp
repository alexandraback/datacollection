#include <fstream>
using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

int surprising, total, score, cases, googlers, limit;

int main(){
	in>>cases;
	for(int i = 0; i < cases; i++){
		total = 0;
		in>>googlers>>surprising>>limit;
		for(int j = 0; j < googlers; j++){
			in>>score;
			if(score>=limit+max(limit-1,0)*2) total++;
			else if(score<limit+max(limit-2,0)*2);
			else if(surprising){
				surprising--;
				total++;
			}
		}
		out<<"Case #"<<i+1<<": "<<total<<"\n";
	}
}
