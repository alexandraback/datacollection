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

int		startCand[1001];
vector<int>	graph[1001];
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
int		checkBuf[1001];

bool check(int idx)
{

	startCand[idx]=0;
	if((++checkBuf[idx]) >1){
		return  true;
	}

	vector<int>::iterator itr=graph[idx].begin();
	for(;itr!=graph[idx].end();++itr)
	{
		if(check(*itr)){
			return true;
		}
	}
	return false;
}

void solve(){
    int N;
	cin >> N;

	for(int i=0;i<=N;++i){
		startCand[i]=0;
		graph[i].clear();
	}


	for(int i=1;i<=N;++i){
		int dstSize; 
		cin >> dstSize;
		for(int j=0;j<dstSize;++j){
			int dst;
			cin >> dst;
			graph[i].push_back(dst);
			startCand[i]++;
		}
	}

	for(int i=1;i<=N;++i){
		if(startCand[i]>1){
			memset(checkBuf,0,sizeof(int)*1001);
			if(check(i)){
				printf("Yes\n");
				return ;
			}
		}
	}

	printf("No\n");
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
		printf("Case #%d: ", t);
		solve();
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
