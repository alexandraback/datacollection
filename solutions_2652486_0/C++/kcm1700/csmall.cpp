#include <stdio.h>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main()
{
	int R;
	int N,M,K;
	scanf("%*d%d%d%d%d",&R,&N,&M,&K);
	printf("Case #1:\n");
	while(R-->0)
	{
		vector<int> inputs;
		for(int i = 0; i < K; i++) {
			int val;
			scanf("%d",&val);
			inputs.push_back(val);
		}
		int ans = 0;
		char ansstr[100];
		for(int i = 2; i <= 5; i++) {
			for(int j = 2; j <= 5; j++) {
				for(int k = 2; k <= 5; k++){
					vector<int> values;
					values.push_back(1);
					values.push_back(i);
					values.push_back(j);
					values.push_back(k);
					values.push_back(i*j);
					values.push_back(j*k);
					values.push_back(i*k);
					values.push_back(i*j*k);
					int cur = 1;
					for(int l = 0; l < K ;l ++) {
						int cnt = 0;
						for(int m = 0; m < 8; m++) {
							if (values[m] == inputs[l]) {
								cnt ++;
							}
						}
						cur *= cnt;
						if (cnt == 0) break;
					}
					if (cur > ans){
						ans = cur;
						sprintf(ansstr,"%d%d%d",i,j,k);
					}
				}
			}
		}
		printf("%s\n",ansstr);
	}
	return 0;
}
