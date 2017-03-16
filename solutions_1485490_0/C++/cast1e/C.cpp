#include <cstdio>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


typedef  long long int				UUL;
typedef pair<int,UUL>				ITEM_CNT;
typedef vector<ITEM_CNT>			ITEM_ORDER;
typedef vector<ITEM_CNT>::iterator	ITEM_ORDER_ITR;

int N,M;
ITEM_ORDER	order0;
ITEM_ORDER	order1;
UUL			scoreMatrix[102][102];

bool checkScore(int idx0, UUL last0,
				int idx1, UUL last1,
				UUL count)
{
	UUL oldScore	= scoreMatrix[idx0][idx1];
	if(count < oldScore) return false;
	if(		order0[idx0].second == last0 
		&&	order1[idx1].second == last1)
	{
		UUL newScoreCand		= count;
		scoreMatrix[idx0][idx1] = max(newScoreCand,oldScore);
	}
	return true;
}
UUL check(	int idx0, UUL last0,
			int idx1, UUL last1,
			UUL count)
{

	if(idx0>=N && last0<=0) return count;
	if(idx1>=M && last1<=0) return count;

	if(checkScore(idx0,last0,idx1,last1,count)==false){
		return count;
	}

	if(order0[idx0].first==order1[idx1].first){
		int newIdx0, newIdx1;
		UUL  newLast0, newLast1, newCount;
		if(last0==last1){
			newIdx0		=idx0+1;
			newLast0	=order0[newIdx0].second;
			newIdx1		=idx1+1;
			newLast1	=order1[newIdx1].second;
			newCount	=count + last0;
		}else if(last0<last1){
			newIdx0		=idx0+1;
			newLast0	=order0[newIdx0].second;
			newIdx1		=idx1;
			newLast1	=last1 - last0;
			newCount	=count + last0;
		}else{
			newIdx0		=idx0;
			newLast0	=last0 - last1;
			newIdx1		=idx1+1;
			newLast1	=order1[newIdx1].second ;
			newCount	=count + last1;
		}

		return (check(newIdx0,newLast0 ,newIdx1	 ,newLast1 ,newCount) );

	}else{
		///use 0
		UUL case0 = check(idx0+1,order0[idx0+1].second ,idx1	 ,last1 ,count);

		///use 1
		UUL case1 = check(idx0,	last0,					idx1+1	 ,order1[idx1+1].second  ,count);

		return max(case0,case1);
	}
	
	return 0;
}

int solve(){

	cin >> N >> M;


	
	ITEM_CNT	itemCount;
	order0.resize(N+2);
	order1.resize(M+2);
	for(int i=1;i<=N;++i){
		cin >> itemCount.second;
		cin >> itemCount.first;
		order0[i]	=itemCount;
	}
	for(int i=1;i<=M;++i){
		cin >> itemCount.second;
		cin >> itemCount.first;
		order1[i]	=itemCount;
	}
	order0[N+1].first	=0;
	order0[N+1].second	=0;
	order1[M+1].first	=0;
	order1[M+1].second	=0;
	for(int i=0;i<=101;++i){
		for(int j=0;j<=101;++j){
			scoreMatrix[i][j]=0;
		}
	}
	return 	check(1,order0[1].second, 1, order1[1].second,0);
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
		printf("Case #%d: %lu\n", t, solve());
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
