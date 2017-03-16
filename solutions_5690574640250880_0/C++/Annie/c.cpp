#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

//#define cin fin
//#define cout fout
//
//ifstream fin("c.in");
//ofstream fout("c.out");

int main()
{
	int nCase;
	cin >>nCase;
	for(int t = 0; t < nCase; ++ t){
		int h, w, m, empty;
		cin >> h >> w >> m;
		cout << "Case #"<<t+1<<": "<<endl;

		empty = h*w  - m;
		string line = "" ;
		if(empty == 1 || h == 1 || w == 1){
			line.assign(empty+m, '*');
			for(int i = 0; i < empty; ++ i) line[i] = '.';
		}		
		else if(empty < 4 || empty == 5 || empty == 7) line="";
		else if(h==2){
			if(empty%2 == 1) line ="";
			else{
				line.assign(empty+m, '*');
				for(int i = 0; i< empty/2; ++ i)
					line[i] = line[i+w] = '.';
			}
		}
		else if(w == 2){
			if(empty%2 == 1) line="";
			else{
				line.assign(empty+m, '*');
				for(int i = 0; i < empty; ++ i)
					line[i] = '.';
			}
		}
		//h >=3 && w >=3
		else if(empty >= 2*w){
			if(empty%w == 1){
				if(empty == 2*w+1){
					line.assign(empty+m, '*');
					for(int i = 0; i < empty+2; ++ i)
						line[i] = '.';
					line[w-1]= line[2*w-1] = '*';
				}
				else{
					line.assign(empty+m, '*');
					for(int i = 0; i < empty+1; ++ i)
						line[i] = '.';
					line[empty-2] = '*';
				}
			}
			else{
				line.assign(empty+m, '*');
				for(int i = 0; i < empty; ++ i)
					line[i] = '.';
			}
		}

		else if(empty >= 2*h){
			if(empty%h == 1){
				if(empty == 2*h+1){
					line.assign(empty+m, '*');
					for(int i = 0; i < empty+2; ++ i)
						line[(i/h) + (i%h)*w] = '.';
					line[(h-1)*w] = line[(h-1)*w+1] = '*';
				}
				else{
					line.assign(empty+m, '*');
					for(int i = 0; i < empty-1; ++ i)
						line[(i/h) + (i%h)*w] = '.';
					for(int i = empty; i < empty+1; ++ i)
						line[(i/h) + (i%h)*w] = '.';
				}
			}
			else{
				line.assign(empty+m, '*');
				for(int i = 0; i < empty; ++ i)
					line[(i/h) + (i%h)*w] = '.';
			}
		}

		else{
			if(empty%2 == 0){
				line.assign(empty+m, '*');
				for(int i = 0; i < empty/2; ++ i){
					line[i] =  line[i+w] = '.';
				}
			}
			else{
				line.assign(empty+m, '*');
				for(int i = 0; i < 3; ++ i)
					line[i] = line[i+w] = line[i+w+w] = '.';
				for(int i = 0; i < (empty-9)/2; ++ i)
					line[i+3] = line[i+3+w] = '.';
			}
		}
		
		if(line.length() == 0) cout<<"Impossible"<<endl;
		else{
			line[0] = 'c';
			for(int i = 0; i < h; ++ i){
				cout<<line.substr(i*w, w)<<endl;
			}
		}
	}
	return 0;
}
