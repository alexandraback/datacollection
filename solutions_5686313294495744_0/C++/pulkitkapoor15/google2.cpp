#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pairs;
typedef long long ll;
#define fmaxlimit 100000000

int main(){
freopen("inputfile.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int T;
	cin >> T;

	for(int i=1;i<=T;i++){
		printf("Case #%d: ",i);
		string str1[16],str2[16];
		int arr1[16],arr2[16];
		int nent1; cin >> nent1;
		map<string,int>ment1,vecs1;

		int newgen = 1;
		for(int i=0;i<nent1;i++){
			cin >> str1[i] >> str2[i];
			ment1[str1[i]] = 0;
			vecs1[str2[i]] = 0;
		}
		for(map<string,int>::iterator itr=ment1.begin();itr!=ment1.end();itr++){
			itr->second = newgen++;
		}
		newgen = 1;
		for(map<string,int>::iterator itr=vecs1.begin();itr!=vecs1.end();itr++){
			itr->second = newgen++;
		}
		for(int i=0;i<nent1;i++){

			arr1[i] = ment1[str1[i]];
			arr2[i] = vecs1[str2[i]];
		}
		int dynamicpro[(1<<16)+5]={}; fill(dynamicpro,dynamicpro+(1<<nent1),-100000);
		dynamicpro[0] = 0;
		for(int i=0;i<(1<<nent1);i++){
			int lefts=0,rights=0;
			for(int j=0;j<nent1;j++){
				if(((i>>j)&1)){
					lefts |= (1<<arr1[j]);
					rights |= (1<<arr2[j]);
				}
			}
			for(int j=0;j<nent1;j++){
				if(!((i>>j)&1)){
					int ad = ( (lefts|(1<<arr1[j]))==lefts && (rights|(1<<arr2[j]))==rights );
					dynamicpro[i+(1<<j)] = max(dynamicpro[i+(1<<j)],dynamicpro[i]+ad);
				}
			}
		}

		cout << dynamicpro[(1<<nent1)-1] << endl;
	}
}
