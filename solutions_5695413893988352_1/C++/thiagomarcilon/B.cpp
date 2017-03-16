#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int main(){
	int t,T;
	FILE *fin = fopen("B.in","r");
	FILE *fout = fopen("B.txt","w");
	char s[50];
	string c,j;
	fscanf(fin,"%d",&t);
	fgets(s,20,fin);
	//scanf("%d",&t);
	//getchar();
	T = t;
	while(t--){
		int i;
		bool maxc,ja=false;
		fgets(s,40,fin);
		//fgets(s,40,stdin);
		c.clear();
		j.clear();
		for(i=0;(s[i]!=' ');i++)
			c.push_back(s[i]);
		i++;
		for(;(s[i]!='\n') && (s[i]!='\0');i++)
			j.push_back(s[i]);
		
		for(int i=0;i<c.length();i++){
			if(!ja){
				if((c[i] == '?') && (j[i]=='?')){
					c[i]='0';
					j[i]='0';
				}
				else if(c[i]== '?'){
					c[i] = j[i];
				}
				else if(j[i]== '?'){
					j[i] = c[i];
				}
				else{
					if (c[i]!=j[i]){
						if(c[i]>j[i])
							maxc=true;
						else
							maxc=false;
						ja=true;
					}
				}
			}
			else{
				if(maxc){
					if(c[i] == '?')
						c[i] = '0';
					if(j[i] == '?')
						j[i] = '9';
				}
				else{
					if(j[i] == '?')
						j[i] = '0';
					if(c[i] == '?')
						c[i] = '9';
				}
			}
		}
		fprintf(fout,"Case #%d: %s %s\n",T-t,c.c_str(),j.c_str());
		//printf("Case #%d: %s %s\n",T-t,c.c_str(),j.c_str());
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
