#include <stdio.h>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <map>
#include<vector>

using namespace std;


int GO(  FILE* FIn, FILE* FOut , unsigned uCase);

int Test(int argc, char* argv[]);



int main(int argc, char* argv[])
{

	Test(argc,argv);
	
	return 0;
}



char sInFile[FILENAME_MAX] = 
	//"A-sample.in";
	"C-small-attempt0.in";
	//"A-large.in";

char sOutFile[FILENAME_MAX] = 
	//"A-sample.out";
	"C-small.out";
	//"A-large.out";

int Test(int argc, char* argv[])
{
	FILE* FIn = fopen(sInFile, "r");
	FILE* FOut = fopen(sOutFile, "w");
	
	if( !FIn ){
		cerr<<"Cannot open input"<<endl;
		return -1;
	}
	if( !FOut ){
		cerr<<"Cannot open output"<<endl;
		fclose( FIn);
		return -1;
	}
	unsigned N;
	fscanf(FIn,"%d\n",&N);
	int iErr = 0;
	for(unsigned uCase=0 ; uCase < N ; ++uCase){
		cout <<"case:"<<uCase+1<<endl;
		int iInErr = GO( FIn, FOut, uCase+1 );
		if( iInErr != 0 ){
			iErr = iInErr;
			cerr << "Something wrong for case "<<uCase+1;
		}
	}

	fclose(FOut);
	fclose(FIn);

	return iErr;
}

int s[501];

class t{
public:
	int b;
	int sum;
};

int __cdecl intcmp(const void*p1, const void*p2){
	return ((int)(*(int*)p1))-(int)(*(int*)p2);
}


int GO(  FILE* FIn, FILE* FOut , unsigned uCase)
{
	int N;
	fscanf(FIn,"%d",&N);

	for(int i=0;i<N;++i){
		fscanf(FIn,"%d",&(s[i]));
	}


		multimap<int, pair<int,int>> sums;
	vector<int> psum;
	
	bool bPossible = false;
	for( int i=0 ; i<N ; ++i){
		auto it = sums.find( s[i] );
		int n = 0;
		if( it == sums.end() ){
			psum.clear();
			for( auto it = sums.begin() ; it!=sums.end() ; ++it ){
				psum.push_back( it->first );
			}
			bool bFound = false;
			for( auto it = psum.begin() ; it!=psum.end() ; ++it ){

				auto it1 = sums.find( s[i]+*it );
				if( it1 == sums.end() ){
					sums.insert( pair<int, pair<int,int>>(s[i]+*it, pair<int,int>( s[i],*it) ));
				}
				else{
					fprintf(FOut, "Case #%d:\n",uCase);
					
					fprintf(FOut, "%d",it1->second.first);
					while( it1->second.second >= 0 ){
						it1 = sums.find( it1->second.second );
						fprintf(FOut, " %d",it1->second.first);
					}
					fprintf(FOut, "\n",s[i]);

					
					auto it2 = sums.find( *it );
					fprintf(FOut, "%d",it2->second.first);
					while( it2->second.second >= 0 ){
						it2 = sums.find( it2->second.second );
						fprintf(FOut, " %d",it2->second.first);
					}
					fprintf(FOut, " %d\n",s[i]);
					
					bFound = true;
					break;
				}
			}
			if( bFound){
				bPossible = true;
				break;
			}
			sums.insert( pair<int, pair<int,int>>(s[i], pair<int,int>( s[i],-1) ));
		}
		else{
			fprintf(FOut, "Case #%d:\n",uCase);
			fprintf(FOut, "%d",it->second.first);
			while( it->second.second >= 0 ){
				it = sums.find( it->second.second );
				fprintf(FOut, " %d",it->second.first);
			}
			fprintf(FOut, "\n%d\n",s[i]);
			bPossible = true;
			break;
		}
	}
	if( ! bPossible){
		fprintf(FOut, "Case #%d:\n",uCase);
		fprintf(FOut, "Impossible\n",uCase);
	}
	

	//fprintf(FOut, "Case #%d: %s",uCase,sInLine);
	return 0;
}


