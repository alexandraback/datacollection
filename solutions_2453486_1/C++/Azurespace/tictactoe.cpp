#include<fstream>
#include<string>
#include<vector>
using namespace std;

int num_test_cases;
vector< vector<string> > cases;


void input(){
	ifstream in("tictactoe.in");
	in >> num_test_cases;
	
	cases.resize(num_test_cases);

	for(int i=0; i<num_test_cases; ++i){
		for(int j=0;j<4;++j){
			string line;
			in >> line;
			cases[i].push_back(line);
		}
		string emptyline;
		getline(in, emptyline);
	}
	
	in.close();
}

bool is_ended(vector<string> &state){
	auto i = state.begin();
	for(;i!=state.end();++i){		
		int j;
		for(j=0;j<4;++j){
			if((*i)[j] == '.') return false;
		}		
	}
	return true;
}

bool is_win(char mark, vector<string> &state){
	int i, j;
	bool flag;
	
	flag=true;
	for(i=0;i<4;++i){ if(state[i][i] != mark && state[i][i] != 'T') flag=false; } // \ diagonal check	
	if(flag) return flag;

	flag=true;
	for(i=0;i<4;++i){ if(state[i][3-i] != mark && state[i][3-i] != 'T') flag=false; } // / diagonal check
	if(flag) return flag;

	
	for(i=0;i<4;++i){
		flag=true;
		for(j=0;j<4;++j){
			if(state[i][j] != mark && state[i][j] != 'T') flag=false;
		}
		if(flag) return true;
	}	

	for(i=0;i<4;++i){
		flag=true;
		for(j=0;j<4;++j){
			if(state[j][i] != mark && state[j][i] != 'T') flag=false;
		}
		if(flag) return true;
	}	
	return false;
}

int main(){	
	input();

	ofstream out("tictactoe.out");
	for(int i=0;i < num_test_cases; ++i){
		out << "Case #" << i+1 << ": ";
		if(is_win('X', cases[i])){
			out << "X won";
		}
		else if(is_win('O', cases[i])){
			out << "O won";
		}
		else if(!is_ended(cases[i]) ){
			out << "Game has not completed";
		}
		else {
			out << "Draw";
		}
		out << endl;
	}
	out.close();

	return 0;
}