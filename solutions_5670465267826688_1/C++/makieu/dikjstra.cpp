#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int TAB[5][5];

//1 2 3 4
int mult(int x, int y){
	int sign = 1;
	if(x < 0){
		x =-x;
		sign = - sign;
	}
	if(y < 0){
		y =-y;
		sign = - sign;
	}
	return sign * TAB[x][y];	
}

string testcase(){
	long long L, X;
	cin >>L >> X;
	string s;
	cin >> s;
	X = min ( X , 12+X%4);
	vector<int> curval(L*X);
	int t=1;
	for(int j=0; j<X; j++)
		for(int i=0; i<L; i++){
			curval[i+j*L]=t = mult(t,s[i]-'i'+2);
		}
	if(curval[X*L-1] != -1) return "NO";
	for(int i=0; i<X*L-2; i++){
		if(curval[i]!=2) continue;
		else{
			for(int j =i+1; j<X*L-1; j++){
				if(mult(-2, curval[j]) == 3)
					return "YES";
			}
		}
	}
	return "NO";
}


int main(){
	int nb;
	cin >>nb;
	TAB[1][1]=1; TAB[1][2]=2;  TAB[1][3]=3;  TAB[1][4]=4;
	TAB[2][1]=2; TAB[2][2]=-1; TAB[2][3]=4;  TAB[2][4]=-3;
	TAB[3][1]=3; TAB[3][2]=-4; TAB[3][3]=-1; TAB[3][4]=2;
	TAB[4][1]=4; TAB[4][2]=3;  TAB[4][3]=-2; TAB[4][4]=-1;
	
	for(int i=0; i<nb; i++)
		cout << "Case #"<<i+1<<": "<< testcase()<<endl;;
	return 0;
}
