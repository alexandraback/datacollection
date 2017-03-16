#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>


using namespace std;

void solve(){
    int N;
	int S[201];
    int X=0;
	cin >> N;
	for(int i=0;i<N;++i){
		cin >> S[i];
		X += S[i];
	}
	
	bool flag	=true;
	double ave	= X*2.0/(double)N;
	int N_under, X_under;
	while(flag){
		N_under	= N;
		X_under	= X;
		flag=false;
		for(int i=0;i<N;++i){
			if(S[i]>ave){
				X_under -= S[i];
				N_under--;
			}	
		}
		double ave2= (X+X_under)/(double)N_under;
		if(ave2<ave){
			ave=ave2;
			flag=true;
		}
	}
	

	for(int i=0;i<N;++i){
		double y;
		y=(X+X_under-N_under*S[i])*100.0/double(X*N_under);
		y=max(y,0.0);
		y=min(y,100.0);
		printf(" %.6lf",y);
	}
	printf("\n");
    return ;
}

std::string splitPath(std::string path){
	path[path.find_last_of('.')]=' ';
	std::stringstream	strm(path);
	std::string			dstName;
	strm >> dstName;
	return dstName;
}


int main(int argc, char** argv)
{
    int T;
	std::string outPath	= splitPath(argv[1]) + "_out.txt";
    FILE* fp_in		= freopen(argv[1],			"r",	stdin);
	FILE* fp_out	= freopen(outPath.c_str(),	"w",	stdout);
	
 	cin >> T;
    for(int t=1; t<=T; t++)
    {
		printf("Case #%d:", t);
		solve();
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
