#include<fstream>
#include<iostream>
using namespace std;
int main(){
	ifstream in("B-small-attempt0.in");
	ofstream out("b.output");
	int T;
	int n;
	int s;
	int p;
	int x;
	int y;
	int count;
	in>>T;
	for(int i=1;i<=T;++i){
		in>>n>>s>>p;
		count=0;
		for(int j=0;j<n;++j){
			in>>x;
			y=x/3;
			if(x%3)
				++y;
			if(y>=p){
				++count;
			}
			else if(s){
				y=x/3;
				if(x%3==0){
					if(y>0)
						++y;
					else
						continue;
				}
				else if(x%3==1){
					if(y>0)
						++y;
					else
						continue;
				}
				else{
					y+=2;
				}
				if(y>=p){
					++count;
					--s;
				}
			}
		}
		out<<"Case #"<<i<<": "<<count<<"\n";
	}



	for(int i=1;i<=T;++i){

	}
	return 0;
}
