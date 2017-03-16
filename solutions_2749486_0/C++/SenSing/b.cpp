#include <cmath>
#include <string>
#include <cstdio>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	int x,y;
	int ca = 0;
	while(t--){
		string s;
		ca ++ ;
		scanf("%d%d",&x,&y);
		for(int i = 0 ;i < abs(x) ;i++){
			if(x>0)
				s+="WE";
			else
				s+="EW";
		}
		for(int i = 0 ;i < abs(y);i++){
			if(y>0)
				s+="SN";
			else 
				s+="NS";
		}
		printf("Case #%d: %s\n",ca,s.c_str());
	}
	return 0;
}
