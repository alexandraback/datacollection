
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>


using namespace std; 

char Gary[4][4];



long transfer(){
	int i,j;
	long res=0;

	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			if(Gary[i][j]=='.')
				res=4;
		}
	}

	for(i=0;i<4;i++){
		if((Gary[i][0]=='X'||Gary[i][0]=='T')
			&&(Gary[i][1]=='X'||Gary[i][1]=='T')
			&&(Gary[i][2]=='X'||Gary[i][2]=='T')
			&&(Gary[i][3]=='X'||Gary[i][3]=='T'))
			res=1;
		if((Gary[0][i]=='X'||Gary[0][i]=='T')
			&&(Gary[1][i]=='X'||Gary[1][i]=='T')
			&&(Gary[2][i]=='X'||Gary[2][i]=='T')
			&&(Gary[3][i]=='X'||Gary[3][i]=='T'))
			res=1;
	}
	if((Gary[0][0]=='X'||Gary[0][0]=='T')
		&&(Gary[1][1]=='X'||Gary[1][1]=='T')
		&&(Gary[2][2]=='X'||Gary[2][2]=='T')
		&&(Gary[3][3]=='X'||Gary[3][3]=='T'))
		res=1;
	if((Gary[0][3]=='X'||Gary[0][3]=='T')
		&&(Gary[1][2]=='X'||Gary[1][2]=='T')
		&&(Gary[2][1]=='X'||Gary[2][1]=='T')
		&&(Gary[3][0]=='X'||Gary[3][0]=='T'))
		res=1;

	for(i=0;i<4;i++){
		if((Gary[i][0]=='O'||Gary[i][0]=='T')
			&&(Gary[i][1]=='O'||Gary[i][1]=='T')
			&&(Gary[i][2]=='O'||Gary[i][2]=='T')
			&&(Gary[i][3]=='O'||Gary[i][3]=='T'))
			res=2;
		if((Gary[0][i]=='O'||Gary[0][i]=='T')
			&&(Gary[1][i]=='O'||Gary[1][i]=='T')
			&&(Gary[2][i]=='O'||Gary[2][i]=='T')
			&&(Gary[3][i]=='O'||Gary[3][i]=='T'))
			res=2;
	}
	if((Gary[0][0]=='O'||Gary[0][0]=='T')
		&&(Gary[1][1]=='O'||Gary[1][1]=='T')
		&&(Gary[2][2]=='O'||Gary[2][2]=='T')
		&&(Gary[3][3]=='O'||Gary[3][3]=='T'))
		res=2;
	if((Gary[0][3]=='O'||Gary[0][3]=='T')
		&&(Gary[1][2]=='O'||Gary[1][2]=='T')
		&&(Gary[2][1]=='O'||Gary[2][1]=='T')
		&&(Gary[3][0]=='O'||Gary[3][0]=='T'))
		res=2;

	if(res==0)
		res=3;

	return res;
}

int main() {
	int T;
	long res;
	char str[1024];

	fstream fin("A-large.in", ios::in);
	fstream fout("result.txt", ios::out);

	fin >> T;
	fin.getline(str,1024);

	for (int i=0;i<T;i++){
		memset(str,0,1024);

		for(int j=0;j<4;j++){
			fin>>Gary[j][0];
			fin>>Gary[j][1];
			fin>>Gary[j][2];
			fin>>Gary[j][3];
			fin.getline(str,1024);
		}

		res=transfer();
//		fin >> str;
		if(res==1)
			fout << "Case #" << i+1 << ": " << "X won" << endl;
		else if(res==2)
			fout << "Case #" << i+1 << ": " << "O won" << endl;
		else if(res==3)
			fout << "Case #" << i+1 << ": " << "Draw" << endl;
		else if(res==4)
			fout << "Case #" << i+1 << ": " << "Game has not completed" << endl;

		fin.getline(str,1024);
	}



	return 0;
}
