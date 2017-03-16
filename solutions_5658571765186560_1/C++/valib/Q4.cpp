// Q4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
bool win(int X, int R, int C){
	if(X>=7) return true;
	else{
		if((R*C)%X!=0) return true;
		else{
			if(X<=2) return false;
			else{
				if(min(R,C)<=X-2) return true;
				else return false;
			}
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("D://Practice//D-large.in", "r", stdin);
    freopen("D://Practice//D-large.out", "w", stdout);
	int cases;
	cin>>cases;
	for(int i=0; i<cases; i++){
		int X, R, C;
		cin>>X>>R>>C;
		if(win(X,R,C)){
			cout<<"Case #"<<i+1<<": "<<"RICHARD"<<endl;
		}
		else{
			cout<<"Case #"<<i+1<<": "<<"GABRIEL"<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

