#include <stdio.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
int minimum = 99999999;
string ansX = "";
string ansY = "";

int SUB(string x, string y){
	int xx = atoi(x.c_str());
	int yy = atoi(y.c_str());
	
	int tmp = xx - yy;
	if(tmp < 0){
		tmp = 0 - tmp;
	} 
	
	return tmp;
}

void f(string x, string y, int index){
	if(index >= x.length()){
		int tmp = SUB(x, y);
		//cout << x << " " << y << endl;
		if(minimum > tmp){
			minimum = tmp;
			ansX = x;
			ansY = y;
		}
		else if(tmp == minimum && x < ansX){
			ansX = x;
			ansY = y;
		}
		else if(tmp == minimum && x == ansX && y < ansY){
			ansX = x;
			ansY = y;
		}
		return;
	}
	//cout << "index= " << index << endl;
	//cout << x[index] << " " << y[index] << endl; 
	int tmp = 0;
	if(x[index] == '?' && y[index] == '?'){
		for(int i = 0; i <= 9; ++i){
			x[index] = '0' + i;
		    
		    for(int j = 0; j <= 9; ++j){
		    	tmp = (i + j)%10;
			    y[index] = '0' + tmp;
			    f(x, y, index+1);
			}
		}	
	}
	else if(y[index] == '?' && x[index] != '?'){
		int i = x[index] -'0';
		
		for(int j = 0; j <= 9; ++j){
		    tmp = (i + j)%10;
			y[index] = '0' + tmp;
			f(x, y, index+1);
		}
	}
	else if(x[index] == '?' && y[index] != '?'){
		int i = y[index]-'0';
		
		for(int j = 0; j <= 9; ++j){
		    tmp = (i + j)%10;
			x[index] = '0' + tmp;
			f(x, y, index+1);
		}
	}
	else{
		f(x, y, index+1);
	}
}

int main(){	
    
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("myoutB-samll2.txt", "w", stdout);
	int T;
	cin >> T;
	
	string x;
	string y;
	for(int t = 1; t <= T; ++t){
        cin >> x;
        cin >> y;
        //cout << "length = " << x.length() << " " << y.length() <<endl;
        minimum = 99999999;
        f(x, y, 0);
        
		cout << "Case #" << t << ": ";
		cout << ansX << " " << ansY <<endl;
	}
	
	return 0;
}
