#include <cstdio>
#include <map>

using namespace std;

map<char, char> data;
int main(){
	data['y']='a';
	data['e']='o';
	data['q']='z';
	data['j']='u';
	data['p']='r';
	data['m']='l';
	data['s']='n';
	data['l']='g';
	data['c']='e';
	data['k']='i';
	data['d']='s';
	data['x']='m';
	data['v']='p';
	data['n']='b';
	data['r']='t';
	data['i']='d';
	data['b']='h';
	data['t']='w';
	data['a']='y';
	data['f']='c';
	data['g']='v';
	data['h']='x';
	data['o']='k';
	data['u']='j';
	data['w']='f';
	data['z']='q';
	int t;
	scanf("%d", &t);
	while(fgetc(stdin)!='\n'){}
	for(int i=0;i<t;++i){
		printf("Case #%d: ",i+1);
		char c;
		while((c=fgetc(stdin))!='\n'){
			if(c==' '){
				printf(" ");
			}else{
				printf("%c", data[c]);
			}
		}
		printf("\n");
	}
	return 0;
}
