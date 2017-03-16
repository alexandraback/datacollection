#include <cstdio>
#include <cstring>
using namespace std;

char name[1000010];
int con[1000010];

bool vovel(char a){
	if (a=='a' || a=='e' || a=='o' || a=='i' || a=='u') return true;
	return false;
}

int main(){
	int z;
	scanf("%d", &z);
	for (int i=1; i<=z; i++){
		int n,length;
		scanf("%s%d", name,&n);
		length = strlen(name);
		int end;
		end = 0;
		int count = 0;
		long long result=0;
		if (!vovel(name[0])) con[0] = 1;
		else con[0] = 0;
		for (int j=0;j<length;j++){
			if (vovel(name[j])) con[j]=0;
			else con[j]=1+con[j-1];
		}
		for (int j=0; j<length; j++){
			count = 0;
			while(end<length){
				if (con[end] >=n && end-j+1 >= n){count = 1; break;}
				end++;
			}
			if (count=0) break;
			result+=length-end;
		}
		printf("Case #%d: %lld\n",i,result);
	}
}
