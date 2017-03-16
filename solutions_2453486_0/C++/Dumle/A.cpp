#include <iostream>
#include <string>

using namespace std;

bool flag;
int r[2][4], c[2][4], d1[2], d2[2];
char a[4][4];

inline void Read(){
	string t;
	for(int k=0;k<4;k++){
		cin >> t;
		for(int j=0;j<4;j++)
			a[k][j] = t[j];
	}
	scanf("\n");
	flag = false;
	for(int k=0;k<2;k++)
		for(int j=0;j<4;j++)
			r[k][j] = c[k][j] = d1[k] = d2[k] = 0;
}

inline void ini(int t, int x, int y){
	r[t][x]++;
	c[t][y]++;
	if(x == y) d1[t]++;
	if(x+y == 3) d2[t]++;
}

string makeAns(){
	for(int t=0;t<2;t++)
		for(int i=0;i<4;i++)
			if(r[t][i] == 4 || c[t][i] == 4 || d1[t] == 4 || d2[t] == 4)
				return t ? "X won" : "O won";
	return flag ? "Game has not completed" : "Draw";
}

int main()
{
    freopen("A-small.in","r",stdin);
    freopen("A-small.out","w",stdout);
    int T;
 	scanf("%d\n", &T);
 	for(int i=1;i<=T;i++){
		Read();
		for(int j=0;j<4;j++)
			for(int k=0;k<4;k++){
				if(a[j][k] == 'T' || a[j][k] == 'X')
					ini(1, j, k);
				if(a[j][k] == 'T' || a[j][k] == 'O')
					ini(0, j, k);
				if(a[j][k] == '.')
					flag = true;	
			}
        printf("Case #%d: %s\n", i, makeAns().c_str());		
	}
	return 0;
}
