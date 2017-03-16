
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

string R="RICHARD";
string G="GABRIEL";

int main()
{
	int cs = 0, T=0;
	scanf("%d",&T);
	while(++cs <= T){
		string res = R;
		int X,R,C;
		scanf("%d%d%d",&X,&R, &C);

		if(R*C % X > 0){}
		else if(X==1 || X == 2){
			res = G;
		}
		else if(min(R,C) == 1){}
		else if(X==3){
			res = G;
		}
		else if(X == 4){
			if(min(R,C)==2) {}
			else if(min(R,C)==3){
				res = G;
			}
			else{
				res = G;
			}
		}

		printf("Case #%d: %s\n", cs, res.c_str());
	}

	return 0;
}
