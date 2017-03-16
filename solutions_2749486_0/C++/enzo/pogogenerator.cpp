#include <iostream>
#include <queue>
#include <string> 

using namespace std;

#define MAXVAL 500 //0,0 starts at half of this

int minsteps [MAXVAL][MAXVAL];
string path [MAXVAL][MAXVAL];

struct XY{
	int x;
	int y;
	int power;
	string path;
	XY(int a, int b, int c, string p){
		x=a;
		y=b;
		power=c;
		path = p;
	};
};

queue<XY> XYvec;

int main(){
	for(int i=0;i<MAXVAL;++i){
		for(int j=0;j<MAXVAL;++j){
			minsteps [i][j] = -1;
		}
	}
	
	XYvec.push(XY(MAXVAL/2, MAXVAL/2, 1, ""));
	
	while(!XYvec.empty()){
		XY t = XYvec.front();
		XYvec.pop();
		
		if(t.x<0 || t.y <0 || t.x>=MAXVAL || t.y>=MAXVAL) continue;
		//if(t.power > MAXVAL) continue;
		if(minsteps[t.x][t.y] == -1){
			minsteps[t.x][t.y] = t.power-1;
			path[t.x][t.y] = t.path;
			
			XYvec.push(XY(t.x-t.power,t.y,t.power+1, t.path+"W"));
			XYvec.push(XY(t.x+t.power,t.y,t.power+1, t.path+"E"));
			XYvec.push(XY(t.x,t.y-t.power,t.power+1, t.path+"S"));
			XYvec.push(XY(t.x,t.y+t.power,t.power+1, t.path+"N"));
		}
	}
	for(int i=0;i<MAXVAL;++i){
		for(int j=0;j<MAXVAL;++j){
			cout << i << " " << j << " " << minsteps [i][j] << " " << path[i][j] << endl;
		}
	}
}