#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
int N;
long long* S	= NULL;
string		strS[500];
map<long long, vector<long long>> sumList;
void printSubset(vector<long long> subset)
{
	printf("%ld",subset[0]);
	for(int j=1;j<subset.size();++j){
		printf(" %ld",subset[j]);
	}
	printf("\n");
}

bool distinct(vector<long long> sub0,vector<long long> sub1)
{
	for(int i=0;i<sub0.size();++i){
		for(int j=0;j<sub1.size();++j){
			if(sub0[i]==sub1[j]){
				return false;
			}
		}
	}
	return true;
}

bool check(int idx,int SumCnt,long long sum,vector<long long> subset)
{
	for(int i=idx;i<N;++i){
		long long newSum	=	sum +	S[i];
		vector<long long> newSubset;
		newSubset.push_back(S[i]);
			
		if(SumCnt>1){
			if(check(idx+i,SumCnt-1,newSum,newSubset)){
				return true;
			}
		}else{	
			map<long long,  vector<long long>>::iterator itr;
			itr=sumList.find(newSum);  
			if(itr != sumList.end() && distinct(itr->second,newSubset)){
				printSubset(itr->second);
				printSubset(newSubset);
				return true;
			}else{
				sumList.insert(pair<long long,  vector<long long>>(newSum, newSubset));
			}
		}
	}
	return false;
}

void solve(){

	S= new long long[500];
	
	
	sumList.clear();
	

	cin >> N;
	for(int i=0;i<N;++i){
		cin >> S[i];
		vector<long long> sub;
		sub.push_back(S[i]);
		sumList.insert(pair<long long, vector<long long>>(S[i], sub));
	}

	for(int sumCnt=2;sumCnt<=N;++sumCnt){
		vector<long long> buf;
		if(check(0,sumCnt,0,buf)){
			delete [] S;	
			return;
		}
	}


	delete [] S;
	printf("Impossible\n");
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
		printf("Case #%d:\n", t);
		solve();
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
