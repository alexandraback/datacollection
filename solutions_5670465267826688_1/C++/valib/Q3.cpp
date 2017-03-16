// Q3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


vector<vector<int> > table(5,vector<int>(5,0));


int multi(int x, int y){
	if(x<0 && y<0){
		return table[-x][-y];
	}
	else{
		if(x<0) return -table[-x][y];
		else if(y<0) return -table[x][-y];
		else return table[x][y];;
	}
}

bool ijk_feasible(int L, long long X, string& str, map<char, int>& lut){
	vector<int> v1(L), v2(X<4?X:4);
	int k1=-1, k2=-1;
	//cout<<"L="<<L<<" X="<<X<<endl;
	v1[0]=lut[str[0]];
	if(v1[0]==2) k1=0;
	for(int i=1; i<L; i++){
		v1[i]=multi(v1[i-1],lut[str[i]]);
		if(v1[i]==2 && k1==-1) k1=i;
	}
	
	v2[0]=v1[L-1];
	//cout<<v2[0]<<' ';
	for(int i=1; i<X && i<4; i++){
		v2[i]=multi(v2[i-1],v1[L-1]);
		//cout<<v2[i]<<' ';
	}
	//cout<<endl;
	//cout<<v2[0]<<endl;
	if(!(v2[0]==-1 || v2[0]!=1&&X%4==2)) return false;
	
	vector<int> v3(L);
	v3[L-1]=lut[str[L-1]];
	if(v3[L-1]==4) k2=X*L-1;
	//cout<<v3[L-1]<<' ';
	for(int i=L-2; i>=0; i--){
		v3[i]=multi(lut[str[i]],v3[i+1]);
		//cout<<v3[i]<<' ';
		if(v3[i]==4 && k2==-1) k2=(X-1)*L+i;
	}
	//cout<<endl;
	//cout<<k1<<' '<<k2<<endl;

	if(k1==-1){
		int tmp=0;
		for(int i=0; i<4 && i<X; i++){
			for(int j=0; j<L; j++){
				tmp=multi(v2[i],v1[j]);
				if(tmp==2){
					k1=(1+i)*L+j;
					break;
				}
			}
			if(k1!=-1) break;
		}
	}

	if(k2==-1){
		int tmp=0;
		for(int i=0; i<4 && i<X; i++){
			for(int j=L-1; j>=0; j--){
				tmp=multi(v3[j],v2[i]);
				//cout<<tmp<<' ';
				if(tmp==4){
					k2=(X-i-2)*L+j;
					break;
				}
			}
			//cout<<endl;
			if(k2!=-1) break;
		}
	}
	//cout<<k1<<' '<<k2<<endl;
	if(k1!=-1 && k2!=-1 && k1<k2) return true;
	else return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	map<char, int> lut;
	lut['1']=1, lut['i']=2,lut['j']=3,lut['k']=4;

	table[1][1]=1,table[1][2]=2,table[1][3]=3,table[1][4]=4;
	table[2][1]=2,table[2][2]=-1,table[2][3]=4,table[2][4]=-3;
	table[3][1]=3,table[3][2]=-4,table[3][3]=-1,table[3][4]=2;
	table[4][1]=4,table[4][2]=3,table[4][3]=-2,table[4][4]=-1;

	freopen("D://Practice//C-large.in", "r", stdin);
    freopen("D://Practice//C-large.out", "w", stdout);
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		string str;
		int L;
		long long	X;
		cin>>L>>X;
		cin>>str;
		if(ijk_feasible(L,X, str,lut)){
			cout<<"Case #"<<i+1<<": "<<"YES"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": "<<"NO"<<endl;
		}

	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

