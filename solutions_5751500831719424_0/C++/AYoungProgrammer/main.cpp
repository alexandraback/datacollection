#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void){

	freopen("A-small-attempt0.in","r",stdin);
	freopen("a2.out","w",stdout);

	int t;
	int freq[100][100];
	char letter[100][100];
	int len[100];
	cin>>t;

	for(int test=0;test<t;test++){
		int n;
		int i,j,k;
		cin>>n;
		vector<string> strs;
		for(i=0;i<n;i++){
			string str;
			cin>>str;
			strs.push_back(str);
		}
		for(i=0;i<n;i++){
			j = 1;
			k = 0;
			freq[i][0] = 1;
			letter[i][k] = strs[i][0];
			
			while(j<strs[i].length()){
				if(strs[i][j]!=strs[i][j-1]){
					k++;
					letter[i][k] = strs[i][j];
					freq[i][k] = 0;
				}
				freq[i][k]++;
				j++;
			}
			len[i] = k;

		}
		int sum = 0;
		bool check = false;
		for(i=0;i<=len[0];i++){
			
			if(letter[0][i]!=letter[1][i]){
				check = true;
			}
			sum+=abs(freq[0][i]-freq[1][i]);
		}
		
		if(len[0]!=len[1]||check){
			printf("Case #%d: Fegla Won\n",test+1);
		}else {
			printf("Case #%d: %d\n",test+1,sum);
		}

		
		
	}


}