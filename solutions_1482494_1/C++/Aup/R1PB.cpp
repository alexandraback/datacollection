
#include<iostream>
#include<fstream>
#include<vector>
#include<string>

std::ifstream file;
std::ofstream ofile;

#define maxN = 1002;

int games;
int gamesRank[1002][3];

int select(int curRank ){
	for( int i=0;i< games ; i++ ){ // go the big level if we can
		if( gamesRank[i][2] == 0 ){ 
			if( gamesRank[i][1] <= curRank ){
				gamesRank[i][2] = 3;
				return 2;
			}
		}else if( gamesRank[i][2] == 1 ){
			if( gamesRank[i][1] <= curRank ){
				gamesRank[i][2] = 3;
				return 1;
			}
		}
			
	}
	// no big level, select small level where big level is diffcult
	int bigD = 3000;
	int idx = -1;
	for( int i=0;i<games;i++ ){
		if( gamesRank[i][2] == 0 ){
			if( (gamesRank[i][1] > bigD || idx == -1) && gamesRank[i][0] <= curRank ){
				bigD = gamesRank[i][1];
				idx = i;
			}
		}
	}
	if( idx == -1 )
		return -1;
	gamesRank[idx][2] = 1;
	return 1;
}

int problem(){
	std::cin >> games;

	for( int i=0;i<games;i++ ){
		std::cin >> gamesRank[i][0] >> gamesRank[i][1];
		gamesRank[i][2] = 0;
	}

	int rank = 0;
	int count = 0;

	while( 1 ){
		int exp = select(rank);
		++ count;
		if( exp < 0 ) return -1;
		rank = rank + exp;
		if( rank == games * 2 )
			break;
	}

	return count;
}


int main(){
	std::string filename = "pb.txt";
	std::string fileoutput = filename.append(".out.txt");
	file.open( filename.c_str() );
	ofile.open( fileoutput.c_str() );
	if( file.fail() || ofile.fail() )
		return 0;

	int n = 0;
	std::cin >> n;

	for( int i=0;i<n;i++ ){
		ofile << "Case #" << i+1 << ": " ;
		int ans = problem();
		if( ans < 0 )
			ofile << "Too Bad" << std::endl;
		else
			ofile << ans << std::endl;
	}

	return 0;
}

