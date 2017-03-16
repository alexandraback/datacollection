#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
	int tc;
	scanf("%d\n",&tc);
	for(int i=1; i<=tc; i++){
		stack<char> before;
		vector<char> line;
		char c;
		scanf("%c",&c);
		char start = c;
		char front = c;
		char back = c;
		while(scanf("%c",&c)!=EOF&&c!='\n') {
			if(c>=front){
				before.push(c);
				front = c;
			}else{
			line.push_back(c);
		}
		}
		//sort(line.begin(),line.end());
		printf("Case #%d: ", i);
		while(!before.empty()){printf("%c",before.top() ); before.pop();}
		printf("%c",start);
		for(int j=0; j<line.size(); j++) printf("%c",line[j] );
			printf("\n");
	}
}