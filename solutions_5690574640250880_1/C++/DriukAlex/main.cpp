#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

char field[50][50];

void solveCase(int t) {
	int R,C,M;
	cin>>R>>C>>M;
	int free=R*C-M;
	bool can=false;
	for (int i=0;i<R;i++)
		for (int j=0;j<C;j++)
			field[i][j]='*';
	printf("Case #%d:\n",t+1);
	if (M==0) {
		for (int i=0;i<R;i++)
			for (int j=0;j<C;j++)
				field[i][j]='.';
		field[0][0]='c';
		can=true;
	} else if (free==1) {
		field[0][0]='c';
		can=true;
	} else if (R==1) {
		for (int j=0;j<free;j++) {
			field[0][j]='.';
		}
		field[0][0]='c';
		can=true;
	} else if (C==1) {
		for (int i=0;i<free;i++) {
			field[i][0]='.';
		}
		field[0][0]='c';
		can=true;
	} else {
		for (int curcol=2;curcol<=C;++curcol) {
			int needrows=(free+curcol-1)/curcol;
			if (needrows>R||needrows<=1)
				continue;
			int lastrow=free%curcol;
			if (needrows<=2&&lastrow!=0)
				continue;
			if (lastrow!=1) {
				for (int ii=0;ii<free/curcol;++ii)
					for (int k=0;k<curcol;++k)
						field[ii][k]='.';
				for (int k=0;k<lastrow;++k)
					field[needrows-1][k]='.';
				field[0][0]='c';
				can=true;
				break;
			} else {
				if (needrows==3||curcol==2)
					continue;
				for (int ii=0;ii<free/curcol;++ii)
					for (int k=0;k<curcol;++k)
						field[ii][k]='.';
				field[free/curcol-1][curcol-1]='*';
				field[free/curcol][0]=field[free/curcol][1]='.';
				field[0][0]='c';
				can=true;
				break;
			}
		}
	}
	if (can) {
		for (int i=0;i<R;i++) {
			for (int j=0;j<C;j++)
				cout<<field[i][j];
			cout<<endl;
		}
	} else {
		cout<<"Impossible"<<endl;
	}
}

int main()
{
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
	int T;
	cin>>T;
	for (int i=0;i<T;i++) {
		solveCase(i);
	}
    return 0;
}