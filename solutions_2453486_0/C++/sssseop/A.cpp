#include <fstream>

using namespace std;

ifstream in("input.txt");
ofstream out("output.txt");

char a[4][5];
int row[4][2];
int col[4][2];
int dig1[2], dig2[2];
bool flagX, flagO;
int main()
{
	int t;
	in >> t;
	int emptyCount;
	for(int i=0; i<t; i++){
		emptyCount = 0;
		flagX = false;
		flagO = false;
		dig1[0] = 0;
		dig1[1] = 0;
		dig2[0] = 0;
		dig2[1] = 0;
		for(int j=0; j<4; j++){
			in >> a[j];
			row[j][0] = 0;
			row[j][1] = 0;
			col[j][0] = 0;
			col[j][1] = 0;
		}
		for(int j=0; j<4; j++){
			for(int k=0; k<4; k++){
				if(a[j][k] == 'X' || a[j][k] =='T'){
					row[j][0]++;
					col[k][0]++;
					if(j == k)dig1[0]++;
					if(j+k == 3)dig2[0]++;
				}
				if(a[j][k] == 'O' || a[j][k] =='T'){
					row[j][1]++;
					col[k][1]++;
					if(j == k)dig1[1]++;
					if(j+k == 3)dig2[1]++;
				}
				if(a[j][k] == '.')emptyCount++;
			}
		}
		for(int j = 0; j<4; j++){
			if(row[j][0] == 4 || col[j][0] == 4)flagX = true;
			if(row[j][1] == 4 || col[j][1] == 4)flagO = true;
		}
		if(dig1[0] == 4 || dig2[0] == 4)flagX = true;
		if(dig1[1] == 4 || dig2[1] == 4)flagO = true;

		out << "Case #"<< i + 1 <<": ";
		if(flagX == true && flagO == false){
			out << "X won"<<endl;
		}else if(flagX == false && flagO == false)
		{
			if(emptyCount == 0)out << "Draw"<<endl;
			else out << "Game has not completed"<<endl;
		}else if(flagX == false && flagO == true)
		{
			out << "O won"<<endl;
		}

	}
	return 0;
}