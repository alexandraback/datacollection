#include <cstdio>
#include <cstring>

using namespace std;

int main(){
	int T,S;
	int cs=0;
	char inp[110];
	char tmp[110];
	bool p[110];
	scanf("%d%*c",&T);
	while(T--){
		memset(p,false,sizeof(p));
		int pos=-1,count=0;
		gets(inp);
		for(int i=0;i<sizeof(inp);++i){
			if(inp[i]=='+'){
				p[i]=true;
			}
			else if(inp[i]=='-'){
				pos=i;
			}
		}
		while(pos!=-1){
			if(inp[0]=='+'){
				int pos1=1;
				while(inp[pos1++]=='+');
				while(--pos1) inp[pos1]='-';
				inp[0]='-';
				++count;
			}
			if(inp[0]=='-'){
				for(int i=0;i<=pos;++i){
					if(inp[i]=='+'){
						tmp[pos-i]='-';
					}
					else if(inp[i]=='-'){
						tmp[pos-i]='+';
					}
				}
				int tmp_pos=-1;
				for(int i=0;i<=pos;++i){
					inp[i]=tmp[i];
					if(tmp[i]=='-'){
						tmp_pos=i;
					}
				}
				pos=tmp_pos;
				++count;
			}
		}
		printf("Case #%d: %d\n",++cs,count);
	}
}
