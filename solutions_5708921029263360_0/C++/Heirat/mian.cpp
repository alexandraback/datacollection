#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
int max(int a, int b){return (a>b)?a:b;}
bool fashion(std::istream *in, std::ostream *out){
	int combo[1000][3];
	int pairJP[10][10];
	int pairJS[10][10];
	int pairPS[10][10];
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			pairJP[i][j]=pairJS[i][j]=pairPS[i][j]=0;
		}
	}
	int J,P,S,K;
	*in>>J;//jackets
	*in>>P;//pants
	*in>>S;//shirts
	*in>>K;//two-garment max
	int days=0;//max days;
	for(int j=0;j<J;++j){
		for(int p=0;p<P;++p){
			for(int s=p+j;s<S+p+j;++s){
				if(pairJP[j][p]<K&&pairJS[j][s%S]<K&&pairPS[p][s%S]<K){
					combo[days][0]=j+1;
					combo[days][1]=p+1;
					combo[days++][2]=s%S+1;
					++pairJP[j][p];
					++pairJS[j][s%S];
					++pairPS[p][s%S];
				}
			}
		}
	}
	*out<<days<<'\n';
	for(int i=0;i<days;++i){
		*out<<combo[i][0]<<' '<<combo[i][1]<<' '<<combo[i][2]<<'\n';
	}
	if(days>J*S*P||(K>=S&&days<J*S*P))
	{
		std::cout<<J<<' '<<S<<' '<<P<<' '<<K<<" error here\n";
	}
	return true;
}
bool runProg(std::istream *in, std::ostream *out){
	int T;
	*in>>T;
	for(int i=0;i<T;++i){
		*out<<"Case #"<<i+1<<": ";
		fashion(in, out);
		//*out<<'\n';
	}
	return true;
}
int main(int argc, char* argv[]){
	std::istream* iPut;
	std::ostream* oPut;
	std::ifstream iFile;
	std::ofstream oFile;
	
	iPut=&std::cin;
	oPut=&std::cout;
	if(argc==1){
		std::cout<<"This program requires arguments.  "<<argv[0]<<" ifile [0file]\nRunning in debug mode\n";
	}
	if(argc==2){
		iFile.open(argv[1],std::ios::in);
		iPut=&iFile;
	}
	if(argc==3){
		iFile.open(argv[1],std::ios::in);
		oFile.open(argv[2],std::ios::out);
		iPut=&iFile;
		oPut=&oFile;
	}
	if(argc>3){
		std::cerr<<"Too many arguments\n";
		return 1;

	}
	//actual program stuff happens in here
	runProg(iPut, oPut);
	//end program stuff
	if(argc>1){
		iFile.close();

	}
	if(argc>2){
		oFile.close();
	}
	return 0;
}
