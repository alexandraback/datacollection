#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>

using namespace std;

int map[100][100];

int main(){
	ifstream in("B-small-attempt3.in");
	ofstream out("B-small-attempt3.out");
	int Test,cnt;
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		int B,m;
		in>>B>>m;
		for (int i=0;i<B;i++){
			for (int j=0;j<B;j++){
				map[i][j]=0;
			}
		}
		out<<"Case #"<<cnt<<": ";
		int now=1;
		if (now==m)
			m=0;
		map[0][B-1]=1;
		for (int i=1;i<B-1;i++){
			if (m==0)
				break;
			now=now*2;
			if (now<=m){
				map[0][i]=1;
				map[i][B-1]=1;
				for (int j=1;j<i;j++){
					map[i][j]=1;
				}
			}else{
				now=now/2;
				m-=now;
				if (m>0)
					map[0][i]=1;
				int j=0;
				while (j<i-1){
					if (m & (1<<j))
						map[i][j+1]=1;
					j++;
				}
				m=0;
			}
		}
		if (now==m){
			m=0;
		}
		if (m==0){
			out<<"POSSIBLE"<<endl;
			for (int i=0;i<B;i++){
				for (int j=0;j<B;j++){
					out<<map[i][j];
				}
				out<<endl;
			}
		}else{
			out<<"IMPOSSIBLE"<<endl;
		}
	}
}
