#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;


int main(){
	freopen("in.in","r",stdin);
	freopen("output.txt","w",stdout);
	int T,x,y;
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x>>y;
        //solution
		printf("Case #%d: ",i);
		if(x>0){
			while(x--){
				printf("WE");
			}
		}
		else {
			x=-x;
			while(x--){
				printf("EW");
			}
		}
		if(y>0){
			while(y--){
				printf("SN");
			}
		}
		else {
			y=-y;
			while(y--){
				printf("NS");
			}
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}