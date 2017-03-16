#include<iostream>
#include<fstream>
#include<string>

#include<sstream>
#include<vector>
#include<set>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;

__int64 minv(__int64 a, __int64 b){
	if(a>b) return b;
	else return a;
}
__int64 maxv(__int64 a, __int64 b){
	if(a>b) return a;
	else return b;
}
__int64 success(vector<__int64> bT, vector<__int64> bTy, vector<__int64> tT, vector<__int64> tTy){
	
	__int64 bidx= 0;
	__int64 tidx= 0;
	__int64 bidxmax = bT.size();
	__int64 tidxmax = tT.size();
	while(bT[bidx]<=0){
		bidx++;
		if(bidx>=bidxmax) return 0;
	}
	while(tT[tidx]<=0){
		tidx++;
		if(tidx>=tidxmax) return 0;
	}
	if(bTy[bidx]==tTy[tidx]){
		__int64 succ = minv(bT[bidx], tT[tidx]);
		bT[bidx]-=succ;
		tT[tidx]-=succ;
		return succ + success(bT, bTy, tT, tTy);
	}
	else{
		__int64 currToy = tTy[tidx];
		__int64 currBox = bTy[bidx];
		bool ToyPass = false;
		bool BoxPass = false;
		for(int j=bidx;j<bidxmax;j++){
			if(bTy[j]==currToy){
				BoxPass = true;
				break;
			}
		}
		for(int j=tidx;j<tidxmax;j++){
			if(tTy[j]==currBox){
				ToyPass = true;
				break;
			}
		}
		__int64 a=0,b=0;
		__int64 temp=0;
		if(BoxPass){
			temp = bT[bidx];
			bT[bidx]=-1;
			a = success(bT, bTy, tT, tTy);
			bT[bidx] = temp;
		}
		if(ToyPass){
			tT[tidx]=-1;
			 b = success(bT, bTy, tT, tTy);
		}
		return maxv(a,b);
	}
}

int main(){
	__int64 testcase;
	ifstream infile;
	ofstream outfile;
	infile.open("C-small-attempt2.in"); //filename//
	outfile.open("result.txt");
	
	infile>>testcase;

	for(__int64 i=0;i<testcase;i++){
		//do something end
		__int64 n, m;
		infile>>n>>m;
		vector<__int64> boxTime;
		vector<__int64> boxType;
		vector<__int64> toyTime;
		vector<__int64> toyType;
		for(__int64 j=0;j<n;j++){
			__int64 temp;
			infile>>temp;
			boxTime.push_back(temp);
			infile>>temp;
			boxType.push_back(temp);
		}
		for(__int64 j=0;j<m;j++){
			__int64 temp;
			infile>>temp;
			toyTime.push_back(temp);
			infile>>temp;
			toyType.push_back(temp);
		}
		__int64 res = success(boxTime, boxType, toyTime, toyType);
		
		

		outfile<<"Case #"<<i+1<<": "<<res<<"\n";

	}
	infile.close();
	outfile.close();
	return 0;
}