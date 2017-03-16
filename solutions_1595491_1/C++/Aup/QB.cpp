#include<iostream>
#include<fstream>
#include<vector>

std::ifstream file;
std::ofstream ofile;

int n;
int s;
int p;

int problem(){
	file >> n >> s >> p;

	int ok = p * 3;
	int needS = ok - 4;
	int getP = ok - 2;

	int count = 0;
	for( int i=0;i<n;i++ ){
		int score = 0;
		file >> score;
		if( score >= ok )
			count ++ ;
		else if( score >= getP && score > 0 )
			count ++;
		else if( score >= needS && score > 1){
			if( s > 0 ){
				count ++ ;
				s -- ;
			}
		}
	}

	return count;
}


int main(){
	file.open("B-large.in");
	ofile.open("B-large.out");
	if( file.fail() || ofile.fail() )
		return 0;

	int n;
	file >> n;

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 << ": " << problem() << std::endl;
	}

	return 0;
}

