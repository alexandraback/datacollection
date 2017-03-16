#include <iostream>
using namespace std;

int T,x,y,Case;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	scanf("%d",&T);
	for(int Case = 1; Case <= T ;Case ++){
		printf("Case #%d: ",Case);
		cin >> x >> y;
		if(x > 0){
			for(int i = 1; i <= x; i ++){
				printf("WE");
			}
		}
		if(x < 0){
			x *= -1;
			for(int i = 1; i <= x; i ++){
				printf("EW");
			}
		}
		if(y > 0){
			for(int i = 1; i <= y; i ++){
				printf("SN");
			}
		}
		if(y < 0){
			y *= -1;
			for(int i = 1; i <= y; i ++){
				printf("NS");
			}
		}
		cout << endl;
		
	}
	
	
	
	
	
	return 0;
}
