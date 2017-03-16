#include<iostream>
#include<fstream>
char arr[1024];
int main(){
	std::ifstream fin;

	std::ofstream fout;
	fin.open("D-small-attempt3.in", std::ios_base::in);
	fout.open("Dout_3.txt", std::ios_base::trunc);
	int T;
	fin >> T;

	for (int times = 1; times <= T; times++){
		int X, R, C;
		fin >> X >> R >> C;

		bool ans=false;
		switch (X){
		case 1:
			ans = true;
			break;
		case 2:
			if (((R*C)%2)==0)
				ans = true;
			else ans = false;
			break;
		case 3:
			if ((R>=2) && ((C % 3) == 0))
				ans = true;
			else if (((R % 3) == 0) && (C>=2))
				ans = true;
			else ans = false;
			break;
		case 4:
			if (((R*C) % 4) != 0)
				ans = false;
			else if ((R <= 2) || (C <= 2))ans = false;
			else ans = true;
			break;
		case 5:
			if ((R >= 2) && ((C % 5) == 0))
				ans = true;
			else if (((R % 5) == 0) && (C >= 2))
				ans = true;
			else ans = false;
			break;
		case 6:
			if (((R*C) % 6) != 0)
				ans = false;
			else if ((R <= 3) || (C <= 3))ans = false;
			else ans = true;
			break;
		default:
			ans = false;
			break;
		}
		//check for 
		if (ans){
			fout << "Case #" << times << ": GABRIEL\n";
		}
		else{
			fout << "Case #" << times << ": RICHARD\n";
		}
		std::cout << ans << std::endl;
	}
	fin.close();
	fout.close();
	system("PAUSE");
	return EXIT_SUCCESS;
}