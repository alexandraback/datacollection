#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <ctime>


using namespace std;
string memo[201][201];
int recursive(int i,int j,int n,char dir){

	if(i>200 || i<0 || j>200 || j<0 || (i==100 && j==100)) return 0;
	//int sizem=;
	
	if(memo[i][j].empty()==true || memo[i][j].size()>n){
		string tempstr;
		switch(dir){
		case 'E':
			tempstr=memo[i-n][j]+'E';
			break;
		case 'W':
			tempstr=memo[i+n][j]+'W';
			break;
		case 'N':
			tempstr=memo[i][j+n]+'N';
			break;
		case 'S':
			tempstr=memo[i][j-n]+'S';
			break;
		}
		memo[i][j]=tempstr;
	}
	else{
		return 0;
	}

		recursive(i+(n+1) ,j,n+1,'E');
		recursive(i-(n+1) ,j,n+1,'W');
		recursive(i ,j-(n+1),n+1,'N');
		recursive(i ,j+(n+1),n+1,'S');

}

int main()
{
	freopen("B-small-attempt0 (1).in", "r", stdin);
	  freopen("B.out", "w", stdout);
	clock_t start,end;
	start = clock();
	int testcasenum;
	cin >> testcasenum;//
	recursive(101,100,1,'E');
		recursive(99,100,1,'W');
		recursive(100,99,1,'N');
		recursive(100,101,1,'S');
	for (int t = 1; t <= testcasenum; ++t) {

		printf("Case #%d: ", t);
		string ans="ENWSEN";
		int goalx;int goaly;
		cin >> goalx >> goaly;
		goaly=-goaly;
		//cout<<endl;
		//cout<<"Å‘å˜A‘±"<<maxval<<"count"<<count<<endl;
		
		/*for(int y=0;y<201;y++){
			for(int x=0;x<201;x++){
				cout<<memo[x][y]<<",";
			}
			cout<<endl;
		}*/
		cout<<memo[goalx+100][goaly+100]<<endl;
		// cout<< str<<" cons="<<consec;

	}
	end = clock();
	// printf("%.2f•b‚©‚©‚è‚Ü‚µ‚½\n",(double)(end-start)/CLOCKS_PER_SEC);
	return 0;
}
