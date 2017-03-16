#include<iostream>
#include<hash_set>
#include<vector>

using namespace std;
using namespace stdext;

int main(){
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-small-attempt0.out", "w", stdout);

	int n;
	long long s[250];
	int t;
	int k;
	long long suma, sss;

	hash_set<long long> hs;
	vector<long long> v1;
	vector<long long> v2;


	cin >> t;

	bool tmp;

	for (int ti = 0; ti < t; ti++){
		cin >> n;
		for (int i = 0; i < n; i++){
			cin >> s[i];
		}

		hs.clear(); tmp = false;
		for (int i = 0; i < 1048576; i++){
			k = i;
			suma = 0;
			v1.clear();
			for (int j = 0; j < 20; j++){
				if (k % 2 == 1){
					suma += s[j];
					v1.push_back(s[j]);
				}
				k /= 2;
			}

			if (hs.find(suma) != hs.end()){
				tmp = true;
				break;
			}

			hs.insert(suma);
		}

		sss = suma;

		if (tmp){
			for (int i = 0; i < 1048576; i++){
				k = i;
				suma = 0;
				v2.clear();
				for (int j = 0; j < 20; j++){
					if (k % 2 == 1){
						suma += s[j];
						v2.push_back(s[j]);
					}
					k /= 2;
				}

				if (sss == suma)
					break;
				
			}

			printf("Case #%d:\n", ti+1);
			for (int i = 0; i < v1.size(); i++)
				printf("%lld ", v1[i]);
			printf("\n");
			for (int i = 0; i < v2.size(); i++)
				printf("%lld ", v2[i]);
			printf("\n");

		} else{
			printf("Case #%d:\nImpossible", ti+1);
		}
	}

	return 0;
}