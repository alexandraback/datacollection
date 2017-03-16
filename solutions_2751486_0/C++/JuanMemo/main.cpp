#include <stdio.h>

int casos,size,n,r;
char palabra[1000002];

void lee(){
	size = 0;
	scanf("\n%c",&palabra[size]);
	while(palabra[size++] != ' ')
		scanf("%c",&palabra[size]);
	scanf("%d",&n);
	size--;
}
bool esVocal(char x){
	return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
void barrido(int fin){
	int ini = 0,sub;
	/*while(ini < size){
		if(!esVocal(palabra[fin]) && sub < n){
			sub++;
			fin++;
		}else{
			if(sub)
		}	
	}*/
	fin--;
	while(fin < size){
		sub = 0;
		for(int i = ini;i <= fin;i++){
			if(!esVocal(palabra[i]))
				sub++;
			else
				sub = 0;
			if(sub ==  n){
				r++;
				break;
			}
		}
		ini++;
		fin++;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	scanf("%d",&casos);
	for(int i = 1;i <= casos;i++){
		lee();
		r = 0;
		for(int j= n;j <= size;j++)
			barrido(j);
		printf("Case #%d: %d\n",i,r);
	}
	return 0;
}
