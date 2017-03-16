#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <string>
#include <fstream>
using namespace std;
char EW[] = "EW";
char NS[] = "NS";
	
string genPath(int X, char *p){
	string ans = "";
    int f = 0;
 	if(X != 0){
	   	if(X < 0) {
    		f = 0;
    		X = -X;
       	}else f = 1;
	   	
     	while(X--){
	   		ans += p[f];
	   		ans += p[1-f];
		}    
 	}
 	return ans;
}
int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);
	int T, X, Y;
	cin>>T;
	for(int tt = 1; tt <= T; ++tt){
	    cin>>X>>Y;
		string sans = genPath(X, EW) + genPath(Y, NS);
		cout<<"Case #"<<tt<<": "<<sans<<endl;
	}    
	return 0;
//	system("pause");
}    

