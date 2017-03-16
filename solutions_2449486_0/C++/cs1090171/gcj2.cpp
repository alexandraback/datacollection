#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <cstring>
#include <queue>
using namespace std;


class Point{
	public:
	int val,row,col;
	Point(int x,int y,int z){
		val=x;row=y;col=z;
	}

	int operator<(const Point& other)
	{
  		return val > other.val;
	}
	
};

int t,n,m,a[100][100],row[100],col[100];

bool check_row(int i,int val){
	for(int j=0;j<m;j++){
		if(a[i][j]>val)
			return false;
	}
	return true;
}

bool check_col(int i,int val){
	for(int j=0;j<n;j++){
		if(a[j][i]>val)
			return false;
	}
	return true;
}



int main(){
	cin>>t;
	for(int T=1;T<=t;T++){
		memset(row,0,sizeof(row));
		memset(col,0,sizeof(col));
		priority_queue<Point *> pq;
		cout<<"Case #"<<T<<": ";
		cin>>n>>m;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				Point *p=new Point(a[i][j],i,j);
				pq.push(p);
			}
		}
		bool done=true;
		while(pq.size()!=0 && done){
			Point *q=pq.top();
			if(check_row(q->row,q->val)){
				pq.pop();
			}
			else if(check_col(q->col,q->val)){
				pq.pop();
			}
			else{
				done=false;
			}
		}
		if(!done)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
