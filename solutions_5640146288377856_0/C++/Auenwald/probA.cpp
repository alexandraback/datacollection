#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <cmath>

using namespace std;

#define INTMAX 0x7FFFFFFF
#define LONGMAX 0x7FFFFFFFFFFFFFFF

int main(){
	int T;
	cin>>T;
	for(int i=1; i<=T; i++){
		int R,C,W;
		cin>>R>>C>>W;
		int moves = 0;
		if(W==C)
			moves=R+C-1;
		else{
			if(W==1)
				moves=R*C;
			else{
				if(C%W==0)
					moves=R*(C/W)+W-1;
				else 
					moves=R*(C/W)+W;
			}
		}
		cout<<"Case #"<<i<<": "<<moves;
		if(i!=T)
			cout<<"\n";
	}
}