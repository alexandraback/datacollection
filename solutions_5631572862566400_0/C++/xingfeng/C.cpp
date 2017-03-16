


#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <map>

using namespace std;
//#define DEBUG

void solve(int index){
	int N, num, maxLen = 0, len, lastvisited, target;
	int BFFS[1010];
	map<int, int> partialLens;

	bool BFFSUsedFlag[1010];
	cin>>N;


	memset(BFFS, 0, sizeof(int)*1010);
	memset(BFFSUsedFlag, 0, sizeof(bool)*1010);

	for(int i = 0;i<N;i++){
		cin>>num;
		BFFS[i+1] = num;
	}

#ifdef DEBUG
	cout<<"after read in"<<endl;
#endif

	for(int i = 1;i<=N;i++){
		memset(BFFSUsedFlag, 0, sizeof(bool)*(N+1));
		BFFSUsedFlag[i] = true;
		len = 1;
		target = BFFS[i];
		lastvisited = i;

		while(true){
			len++;
#ifdef DEBUG
	cout<<"i len target BFFS[target] lastvisited "<<i<<" "<<len<<" "<<target<<" "<<BFFS[target]<<" "<<lastvisited<<endl;
#endif
			if(  BFFSUsedFlag[ BFFS[target] ] )
				break;
			BFFSUsedFlag[target] = true;
			lastvisited = target;
			target = BFFS[target];
		}

#ifdef DEBUG
	cout<<"i len "<<i<<" "<<len<<endl;
#endif
		if(BFFS[target] == lastvisited){

			map<int, int>::iterator it = partialLens.find(lastvisited);
			if(it == partialLens.end() || it->second < len)
				partialLens[lastvisited] = len;

			it = partialLens.find(target);
			if(it != partialLens.end()){
				len = len + it->second - 2;
			}

			if(len > maxLen){
				maxLen = len;
				#ifdef DEBUG
					cout<<"i maxLen "<<i<<" "<<maxLen<<endl;
				#endif
			}

		}
		else if(BFFS[target] == i){
			if(len > maxLen){
				maxLen = len;
				#ifdef DEBUG
					cout<<"i maxLen "<<i<<" "<<maxLen<<endl;
				#endif
			}
		}
	}

	cout<<"Case #"<<index<<": "<<maxLen<<endl;

}

int main(){
	int T;

	cin>>T;

	for(int i = 0;i<T;i++){
		solve(i+1);
	}

}
