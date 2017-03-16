#include <stdio.h>
#include <string.h>

#include <vector>

using namespace std;

char cod[30];
char jam[30];


void go(int pos, vector<int>& vec,char *str,int num,int bas)
{
	if(pos==-1){
		vec.push_back(num);
		return ;
	}
	if(str[pos]=='?'){
		for(int i=0; i<10; i++){
			go(pos-1,vec,str,num+bas*i,bas*10);
		}
	}else{
		go(pos-1,vec,str,num+bas*(str[pos]-'0'),bas*10);
	}
}

int mabs(int n)
{
	return n<0?-n:n;
}


int main()
{
	int cas;
	int len;
	scanf("%d",&cas);
	for(int T=1; T<=cas; T++){
		scanf("%s %s",cod,jam);
		len=strlen(cod);
		vector<int> co,ja;
		go(len-1,co,cod,0,1);
		go(len-1,ja,jam,0,1);
		int cs=co[0],js=ja[0];
		for(int i=0; i<co.size(); i++)
			for(int j=0; j<ja.size(); j++){
				if(mabs(cs-js)>mabs(co[i]-ja[j])){
					cs=co[i];
					js=ja[j];
				}else if(mabs(cs-js)==mabs(co[i]-ja[j])){
					if(cs>co[i]){
						cs=co[i];
						js=ja[j];
					}else if(cs==co[i]){
						if(js>ja[j]){
							cs=co[i];
							js=ja[j];
						}
					}
				}
			}
		printf("Case #%d: %0*d %0*d\n",T,len,cs,len,js);
	}
	return 0;
}
