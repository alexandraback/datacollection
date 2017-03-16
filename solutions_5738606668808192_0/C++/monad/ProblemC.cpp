#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void next_permute(char *str){
	if(str[0] == '1'){
		int lastCount=0;
		while(str[lastCount] == '1'){
			++lastCount;
		}
		str[lastCount]='1';
		for(int i = 0;i<lastCount;++i){
				str[i]='0';
		}
	}else{
			str[0]='1';
	}
}

vector<int> convertToOneArr(const char *str, int len){
	vector<int> powerStorage;
	for(int i=0;i<len;++i){
		if(str[i]=='1'){
				powerStorage.push_back(i);
		}
	}
	return powerStorage;
}

string reverse(const string str){
	string toRet(str);
	std::reverse(toRet.begin(),toRet.end());
	return toRet;
};

string addFirstAndLastOne(const char * const str){
		std::string toRet = "1" + std::string(str) + "1";
		return toRet;
};

int moduloBaseN(vector<int> vec,int base,int number){
		int modulo=0;
		int smallMod=base % number;
		for(vector<int>::const_iterator i=vec.begin();i!=vec.end();++i){
				int curMod=1;
				for(int j=0;j<(*i);++j){
						curMod = (curMod * smallMod) % number; 
				}
				modulo=(curMod + modulo)%number;
		}
		return modulo;
}

int main(){
	int nTestCases;
	char str16[16] ="00000000000000";
	char str32[32] ="000000000000000000000000000000";
	char * str;
	scanf("%d",&nTestCases);
	int n,j;
	int len;
	scanf("%d %d",&n,&j);
	if(n == 16){
		str=str16;
		len=16;
	}else{
		str=str32;
		len=32;
	}
	int count=0;
	printf("Case #1:\n");
	do{
		string newStr=addFirstAndLastOne(str);	
		vector<int> curVect=convertToOneArr(newStr.c_str(),len);
		std::string toOut;
		bool found=true;
		for(int b=2;b<11;++b){
			if (moduloBaseN(curVect,b,3) == 0 ) {
				toOut = toOut + " 3";
				continue;	
			}
			if (moduloBaseN(curVect,b,5) == 0 ) {
				toOut = toOut + " 5";
				continue;	
			}
			if (moduloBaseN(curVect,b,7) == 0 ) {
				toOut = toOut + " 7";
				continue;	
			}
			if (moduloBaseN(curVect,b,11) == 0 ) {
				toOut = toOut + " 11";
				continue;	
			}
			if (moduloBaseN(curVect,b,13) == 0 ) {
				toOut = toOut + " 13";
				continue;	
			}
			if (moduloBaseN(curVect,b,17) == 0 ) {
				toOut = toOut + " 17";
				continue;	
			}
			
			if (moduloBaseN(curVect,b,19) == 0 ) {
				toOut = toOut + " 19";
				continue;	
			}
			
			if (moduloBaseN(curVect,b,23) == 0 ) {
				toOut = toOut + " 23";
				continue;	
			}
			
			found=false;
			break;
		}
		if(found == true){
			//printf("%d ",count);
			printf("%s%s\n",reverse(newStr).c_str(),toOut.c_str());
			++count;
		}
		next_permute(str);
	}while(count < j);
	return 0;
}

/*int main(){
	char str[17]="00000000000000";
	std::cout << addFirstAndLastOne(str) << "\n";
	for(int i=0;i<14;++i){
		//printf("%s\n",str);
		next_permute(str);
		vector<int> powerVect = convertToOneArr(str,14);
		//std::cout << powerVect;	
	}
	int myInts[] = {3,6,8,12};
	vector<int> testVect (myInts,myInts + 4);
	printf("%d\n",moduloBaseN(testVect,4,5));
	
	//printf("%s\n",str);
	return 0;
}*/