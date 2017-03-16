#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <limits.h>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int test;
	cin>>test;
	for(int t=0; t<test; t++){
		int cx,cy;
		cin>>cx>>cy;
		int count=1;
		vector<char> res;
		res.reserve(1000);
		int x=0, y=0;
		while(cx != x || cy != y){
			if(x != cx){
				if(x < cx){
					if(x+count <= cx){
						res.push_back('E');
						x+=count;
					}
					else{
						res.push_back('W');
						x-=count;
					}
				}
				else{
					if(x-count >= cx){
						res.push_back('W');
						x-=count;
					}
					else{
						res.push_back('E');
						x+=count;
					}
				}
			}
			else{
				if(y < cy){
					if(y+count <= cy){
						res.push_back('N');
						y+=count;
					}
					else{
						res.push_back('S');
						y-=count;
					}
				}
				else{
					if(y-count >= cy){
						res.push_back('S');
						y-=count;
					}
					else{
						res.push_back('N');
						y+=count;
					}
				}
			}
			count++;
		}

		printf("Case #%d: ", t+1);
		for(int i=0; i<res.size(); i++){
			printf("%c", res[i]);
		}
		printf("\n");
	}
	return 0;
}
