#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
#include <fstream>
#define DEBUG
#ifdef DEBUG
ifstream fin("C.in");
ofstream fout("C.out");
#endif
void redirect(){
#ifdef DEBUG
	std::streambuf *cinbuf = std::cin.rdbuf(); 
	std::cin.rdbuf(fin.rdbuf()); 
	std::streambuf *coutbuf = std::cout.rdbuf(); 
	std::cout.rdbuf(fout.rdbuf()); 
#endif
}
int R,C,M,T,fc,fr,mines,counter;
char m[50][50];
bool used[50][50];
int movement[8][2]={{0,-1},{0,1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
bool found;
class Cor{
public:
	int r;
	int c;
	Cor(int r,int c):r(r),c(c){}
};
bool inRange(int r,int c){
	return 0<=r&&r<R&&0<=c&&c<C;
}
void output(){
	m[0][0]='c';
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			cout<<m[i][j];
		cout<<endl;
	}
}
vector<Cor> setNeighbour(int r,int c,int &count){
	int rr,cc;
	count=0;
	vector<Cor> v;
	if(m[r][c]=='*'){
		v.push_back(Cor(r,c));
		count++;
		m[r][c]='.';
	}
	for(int i=0;i<8;i++){
		rr=r+movement[i][0];
		cc=c+movement[i][1];
		if(inRange(rr,cc)&&m[rr][cc]=='*'){
			v.push_back(Cor(rr,cc));
			count++;
			m[rr][cc]='.';
		}
	}
	return v;
}
void resetNeighbour(vector<Cor> v){
	for(int i=0;i<v.size();i++){
		m[v[i].r][v[i].c]='*';
	}
}
void search(int r,int c,int remain){
	if(found)
		return;
	if(remain<0)
		return;
	if(remain==0){
		output();
		found=true;
		return;
	}
	int rr,cc;
	used[r][c]=true;
	int newEle;
	vector<Cor> v=setNeighbour(r,c,newEle);
	for(int i=0;i<8;i++){
		rr=r+movement[i][0];
		cc=c+movement[i][1];
		if(inRange(rr,cc)&&!used[rr][cc]){
			search(rr,cc,remain-newEle);
		}
	}
	resetNeighbour(v);
}
int main(){
	redirect();
	cin>>T;
	for(int i=0;i<T;i++){
		cout<<"Case #"<<i+1<<":"<<endl;
		cin>>R>>C>>M;
		//cout<<R<<" "<<C<<" "<<M<<endl;
		counter=R*C-M;
		found=false;
		memset(used,false,sizeof(used));
		for(int i=0;i<R;i++)
			for(int j=0;j<C;j++)
				m[i][j]='*';
		search(0,0,counter);
		if(!found)
			cout<<"Impossible"<<endl;
	}

	return 0;
}