

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//#define DEBUG

void solve(int index){
	char str[1005], result[1005], tmp[1005], lch;
	gets(str);
#ifdef DEBUG
	printf("str is %s\n", str);
#endif

	result[0] = str[0];
	result[1] = 0;
	lch = result[0];

	for(int i = 1; str[i]; i++){
		#ifdef DEBUG
			cout<<"i lch str[i] "<<i<<" "<<lch<<" "<<str[i]<<endl;
		#endif
		if(str[i] >= lch){
			lch = str[i];

			strcpy(tmp, result);
			result[0] = lch;
			strcpy(result+1, tmp);
		}
		else{
			result[i] = str[i];
			result[i+1] = 0;
		}
		#ifdef DEBUG
			printf("result: %s\n", result);
		#endif
	}


	//cout<<"Case #"<<index<<": "<<endl;
	printf("Case #%d: %s\n", index, result);
}

int main(){
	int T;

	cin>>T;

	getchar();

	for(int i = 0;i<T;i++){
		solve(i+1);
	}

}
