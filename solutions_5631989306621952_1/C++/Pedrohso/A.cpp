#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#define mk make_pair
#define ps push_back
#define lw lower_bound
using namespace std;
//const int inf=;

int n;
char maxc='A',at;
vector <char> fr,tr;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		maxc='A'-1;
		scanf(" %c",&at);
		while('A'<=at && at<='Z'){
			if(at>=maxc){
				fr.ps(at);
				maxc=at;
			}
			else{
				tr.ps(at);
			}
			scanf("%c",&at);
		}
		printf("Case #%d: ",i);
		for(int j=fr.size()-1;j>=0;j--) printf("%c",fr[j]);
		for(int j=0;j<tr.size();j++) printf("%c",tr[j]);
		printf("\n");
		fr.clear();
		tr.clear();
	}
	return 0;
}
