#include <stdio.h>
#include <set>

using namespace std;
int main() {
	int nTestCases;
	scanf("%d",  & nTestCases);
	for (int i = 0; i < nTestCases; i++) {
		int nNumber;
		scanf("%d",  & nNumber);
		if(nNumber == 0){
				printf("Case #%d: INSOMNIA\n",i + 1);
				continue;
		}
		set < char > basicSet;
		for (int j = 0; j < 10; ++j) {
			basicSet.insert(j);
		}
		int mult = 1;
		long long newNum=mult * nNumber;	
		long long pNum=newNum;		
		while (basicSet.empty() == false) {
				newNum = mult * nNumber;
				pNum=newNum;
			while (newNum > 0){
					char k =newNum % 10;
					basicSet.erase(k);
					newNum/=10;
			}
			++mult;
		}
		printf("Case #%d: %lld\n",i + 1,pNum);
	}
	return 0;
}