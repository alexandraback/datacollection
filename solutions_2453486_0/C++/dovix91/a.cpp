#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

int T;
int mat[4][4];

int main() {
	int t;
	int i, j;
	int count1, count2, countEmpty;
	string s;
	int end;

    cin>>T;
    for(t=0; t<T; t++) {
		cout<<"Case #"<<t+1<<": ";
   	 
        for(i=0; i<4; i++) {
	  		cin>>s;
			for(j=0; j<4; j++) {
				if(s[j]=='O') mat[i][j]=2;
				else if(s[j]=='X') mat[i][j]=1;
				else if(s[j]=='.') mat[i][j]=0;
				else if(s[j]=='T') mat[i][j]=3;
				else cout<<"Error in parsing"<<endl;
			}
		}
		
		end=0;
		// horizontal		
		for(i=0; i<4 && !end; i++) {
			count1=0, count2=0;
			for(j=0; j<4; j++) {
				if(mat[i][j]==1) count1++;
				if(mat[i][j]==2) count2++;
				if(mat[i][j]==3) { count1++; count2++; }
			}
			if(count1==4) { cout<<"X won"<<endl; end=1; }
			if(count2==4) { cout<<"O won"<<endl; end=1; }
		}
		// vertical
		for(i=0; i<4 && !end; i++) {
			count1=0, count2=0;
			for(j=0; j<4; j++) {
				if(mat[j][i]==1) count1++;
				if(mat[j][i]==2) count2++;
				if(mat[j][i]==3) { count1++; count2++; }
			}
			if(count1==4) { cout<<"X won"<<endl; end=1; }
			if(count2==4) { cout<<"O won"<<endl; end=1; }
		}
		// main diagonal
		count1=0, count2=0;
		for(j=0; j<4; j++) {
			if(mat[j][j]==1) count1++;
			if(mat[j][j]==2) count2++;
			if(mat[j][j]==3) { count1++; count2++; }
		}
		if(count1==4) { cout<<"X won"<<endl; end=1; }
		if(count2==4) { cout<<"O won"<<endl; end=1; }
		//antidiagonal
		count1=0, count2=0;
		for(j=0; j<4; j++) {
			if(mat[j][3-j]==1) count1++;
			if(mat[j][3-j]==2) count2++;
			if(mat[j][3-j]==3) { count1++; count2++; }
		}
		if(count1==4) { cout<<"X won"<<endl; end=1; }
		if(count2==4) { cout<<"O won"<<endl; end=1; }
		
		// still playing?
		if(!end) {
			countEmpty=0;
			for(i=0; i<4; i++) for(j=0; j<4; j++) if(mat[i][j]==0) countEmpty++;
			if(countEmpty) cout<<"Game has not completed"<<endl;
			else cout<<"Draw"<<endl;
		}    
	}


	return 0;
}
