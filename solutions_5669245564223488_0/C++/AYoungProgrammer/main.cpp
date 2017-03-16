#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

char connect[100][2];


int main(void){

	freopen("B-small-attempt2.in","r",stdin);
	freopen("bs.out","w",stdout);
	int t;
	cin>>t;
	string str[100];
	char str2[100][100];
	int length_s[100];
	int lastChar[27];
	for(int test=0;test<t;test++){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str[i];
			str2[i][0] = str[i][0];
			int j=1;
			int k=0;
			while(j<str[i].length()){
				if(str[i][j]==str2[i][k])j++;
				else {
					k++;
					str2[i][k]= str[i][j];
					j++;
				}
			}
			k++;
			str2[i][k]='\0';
			length_s[i]=k;
			//printf("%s\n",str2[i]);
		}
		int permute[] = {0,1,2,3,4,5,6,7,8,9};
		int count = 0;
		do{
			for(int i=0;i<27;i++)lastChar[i] = -1;
			bool found = true;
			int index = 0;
			for(int i=0;i<n;i++){
				for(int j=0;j<length_s[permute[i]];j++){
					if(lastChar[str2[permute[i]][j]-'a']==-1 || lastChar[str2[permute[i]][j]-'a']==index-1){
						lastChar[str2[permute[i]][j]-'a'] = index;
						index++;
					}else {
						found = false;
						i = 10000;
						j=  100000;
						break;
					}
				}
			}
			if(found){
				//for(int i=0;i<n;i++)printf("%d ",permute[i]);
				//printf("\n");
				count++;
			}
			
		}while(next_permutation(permute,permute+n));
		printf("Case #%d: %d\n",test+1,count);
		
	}


}