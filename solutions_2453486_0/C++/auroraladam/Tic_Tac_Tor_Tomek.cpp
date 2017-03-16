#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main(int argc, const char **argv){
	ifstream input;
	ofstream output;
	input.open(argv[1]);
	output.open(argv[2]);
	if(!input.is_open() || !output.is_open()){
		exit(0);	
	}
	int numcase;
	input >> numcase;
	for(int i = 0; i < numcase; i ++){
		int emptycount = 0;
		bool Xwin = false;
		bool Owin = false;
		char Xrowcount[4] = {0, 0, 0, 0};
		char Orowcount[4] = {0, 0, 0, 0};
		char Xcolcount[4] = {0, 0, 0, 0};
		char Ocolcount[4] = {0, 0, 0, 0};
		char Xdiagcount[2] = {0, 0};
		char Odiagcount[2] = {0, 0};
		for(int j = 0; j < 4; j ++){
			for(int k = 0; k < 4; k ++){
				char temp;
				input >> temp;
				if(temp == '.'){
					emptycount ++;				
				}
				else{
					if(temp == 'X' || temp == 'T'){
						Xrowcount[j] ++;
						Xcolcount[k] ++;
						if(k == j){
							Xdiagcount[0] ++;	
						}
						else if(k == 3 - j){
							Xdiagcount[1] ++;					
						}	
					}
					if(temp == 'O' || temp == 'T'){
						Orowcount[j] ++;
						Ocolcount[k] ++;
						if(k == j){
							Odiagcount[0] ++;	
						}
						else if(k == 3 - j){
							Odiagcount[1] ++;					
						}	
					}
				}
			}
		}
		for(int j = 0; j < 4; j ++){
			if(Xrowcount[j] == 4 || Xcolcount[j] == 4){
				Xwin = true;			
			}
			if(Orowcount[j] == 4 || Ocolcount[j] == 4){
				Owin = true;			
			}		
		}
		if(Xdiagcount[0] == 4 || Xdiagcount[1] == 4){
				Xwin = true;
		}
		if(Odiagcount[0] == 4 || Odiagcount[1] == 4){
				Owin = true;
		}
		string result;
		if(Owin){
			result = "O won";		
		}
		else if(Xwin){
			result = "X won";		
		}
		else if(emptycount != 0){
			result = "Game has not completed";		
		}
		else{
			result = "Draw";		
		}
		output << "Case #" << i + 1 << ": " << result << endl;
	}
	input.close();
	output.close();
	return 0;
}
