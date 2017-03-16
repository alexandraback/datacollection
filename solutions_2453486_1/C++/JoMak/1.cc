#include <iostream>
#include <fstream>

using namespace std;

int main(){
	ifstream inp("A-large.in");
	ofstream out("1_large_out.txt");
	string trash;
	int N;
	inp>>N;
	for(int AA =0;AA<N;AA++){
		if (AA!=0){getline(inp,trash);}
		out<<"Case #"<<AA+1<<": ";
		char a[4][4];
		bool ex=true;
		bool oh=true;
		bool done = true;
		for (int i=0;i<4;i++){
			ex=true;
			oh=true;
			for (int j=0;j<4;j++){
				inp>>a[i][j];
				//cout<<a[i][j];
				// horizontal
				ex &=(a[i][j]=='X' or a[i][j]=='T');
				oh &=(a[i][j]=='O' or a[i][j]=='T');
				done &=(a[i][j]!='.');
			}
			getline(inp,trash);
			//cout<<endl;
			if (ex or oh){
				for (int j=i+1;j<4;j++)getline(inp,trash);
				break;
			}
		}
		//cout<<endl;
		//cout<<done<<endl;
		if (ex){
			out<<"X won\n";continue;
		}
		else if (oh){
			out<<"O won\n";continue;
		}
		for (int j=0;j<4;j++){
			ex=true;
			oh=true;
			for (int i=0;i<4;i++){
				// vertical
				ex &=(a[i][j]=='X' or a[i][j]=='T');
				oh &=(a[i][j]=='O' or a[i][j]=='T');
			}
			if (ex or oh)break;
		}
		if (ex){
			out<<"X won\n";continue;
		}
		else if (oh){
			out<<"O won\n";continue;
		}
		ex=true;
		oh=true;
		for (int i=0;i<4;i++){
			ex&=(a[i][i]=='X' or a[i][i]=='T');
			oh&=(a[i][i]=='O' or a[i][i]=='T');
		}
		if (ex){
			out<<"X won\n";continue;
		}
		else if (oh){
			out<<"O won\n";continue;
		}
		ex=true;
		oh=true;
		for (int i=0;i<4;i++){
			ex&=(a[i][3-i]=='X' or a[i][3-i]=='T');
			oh&=(a[i][3-i]=='O' or a[i][3-i]=='T');
		}
		if (ex){
			out<<"X won\n";
		}
		else if (oh){
			out<<"O won\n";
		}
		else if (done){
			out<<"Draw\n";
		}
		else{
			out<<"Game has not completed\n";
		}
	}
	inp.close();
	out.close();
	
	return 0;
}
