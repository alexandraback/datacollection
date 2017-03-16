#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<iterator>
#include<fstream>
using namespace std;
//#define DEBUG

#ifdef DEBUG
#define ifs cin
#define ofs cout
#endif

vector<long long> tType,bType,tQuan,bQuan;
int N,M;

void CountBox(int tId,int bId,long long& total,vector<long long> tQuants,vector<long long> bQuants)
{
	if(tId>=M || bId>=N) return;
	if(tType[tId]==bType[bId])
	{
		long long newBox=min(tQuants[tId],bQuants[bId]);
		total+=newBox;
		long long leftToys=tQuants[tId]-newBox;
		long long leftBoxes=bQuants[bId]-newBox;
		tQuants[tId]=leftToys;
		bQuants[bId]=leftBoxes;
		if(leftToys==0)
			tId++;
		if(leftBoxes==0)
			bId++;
		CountBox(tId,bId,total,tQuants,bQuants);
	}
	else
	{
		long long newTotal1=total,newTotal2=total;
		//vector<double> newTQuants=tQuants;
		//vector<double> newBQuants=bQuants;
		CountBox(tId+1,bId,newTotal1,tQuants,bQuants);
		//newTQuants=tQuants;
		//newBQuants=bQuants;
		CountBox(tId,bId+1,newTotal2,tQuants,bQuants);
		total=max(newTotal1,newTotal2);
	}
}

int main()
{
#ifndef DEBUG
	ifstream ifs("C-small-attempt3.in");
	ofstream ofs("C-small-attempt3.out");
#endif

	int testNum;
	ifs>>testNum;
	int cnt=1;
	while(cnt<=testNum)
	{

		ifs>>N>>M;
		tType.clear();bType.clear();
		tType.resize(M);bType.resize(N);
		tQuan.clear();bQuan.clear();
		tQuan.resize(M);bQuan.resize(N);
		for(int i=0;i<N;i++)
		{
			ifs>>bQuan[i]>>bType[i];
		}
		for(int i=0;i<M;i++)
		{
			ifs>>tQuan[i]>>tType[i];
		}
		/*vector<vector<long long>> res(N);
		for(int i=0;i<N;i++)
		{
			res[i].resize(M);
		}
		
		res[N-1][M-1]*/
		long long total=0;
		CountBox(0,0,total,tQuan,bQuan);
		ofs<<fixed;
		ofs<<setprecision(0);
		ofs<<"Case #"<<cnt<<": "<<total<<endl;
		cnt++;
	}


#ifndef DEBUG
ifs.close();
ofs.close();
#endif

}