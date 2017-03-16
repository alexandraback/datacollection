#include <stdio.h>
#include <set>
#include <string.h>
using namespace std;

char * topple(char * str, int j) { //topple main string from 0 index to j index
	for (int i = 0; i < j / 2; ++i) {
		char temp = str[i];
		if (str[j - i - 1] == '-') {
			str[i] = '+';
		} else {
			str[i] = '-';
		};
		if (temp == '-') {
			str[j - i - 1] = '+';
		} else {
			str[j - i - 1] = '-';
		}
	}
	if (j % 2 == 1) {
		if (str[j / 2] == '-') {
			str[j / 2] = '+';
		} else {
			str[j / 2] = '-';
		};
	}
	return str;
}

int countPlus (char *str,int end){//returns the count 
	int i=0;
	while(*(str+i) == '+' && i < end){
		++i;
	}
	return i;
}


int main(){
		int nTestCases;
		scanf("%d",&nTestCases);
		for(int i=0;i<nTestCases;++i){
				char mainStr[102];
				char * str;
				scanf("%s",mainStr);
				str = mainStr;
				int lMain=strlen(mainStr);
				int attempts=0;
				int end=lMain;
				printf("Case #%d: ",i+1);
				do{
					if(end == 0){
							break;
					}
					if(end == 1){
							if(str[0] == '+')
							{
									break;
							}else{
									++attempts;
									break;
							}
					}
					int j=0;
					for(j=end;str[j-1]=='+' && j >0;--j){};
					end=j;
					if(end <=0 ){
						break;
					}
					if(str[0]=='+'){
						int startPlus = countPlus(str,end);
						topple(str,startPlus);
						++attempts;
					}
					topple(str,end);
					++attempts;
				}while (end > 0);
				printf("%d\n",attempts);
		}
		return 0;
}