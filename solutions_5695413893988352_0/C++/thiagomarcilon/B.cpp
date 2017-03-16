#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <iostream>

using namespace std;

int mini;
string minc, minj;

void resolve(string c, string j){
	//bool tem=false;
	int i;
	for(i=0;(i < c.length()) && (c[i]!='?');i++);
	if(i == c.length()){
		for(i=0;(i < j.length()) && (j[i]!='?');i++);
		if(i == j.length()){
			int diff = abs(atoi(c.c_str()) - atoi(j.c_str()));
			if(diff<mini){
				mini = diff;
				minc = c;
				minj = j;
			}
			else if(diff==mini){
				if(c < minc){
					minc = c;
					minj = j;
				}
				else if(c == minc){
					if(j < minj)
						minj=j;
				}
			}
			return;
		}
		for(int k=0;k<=9;k++){
			j[i] = ((char)48+k);
			resolve(c,j);
		}
		return;
	}
	for(int k=0;k<=9;k++){
		c[i] = ((char)48+k);
		resolve(c,j);
	}
	return;
}

int main(){
	int t,T;
	FILE *fin = fopen("B.in","r");
	FILE *fout = fopen("B.txt","w");
	char s[40];
	string c,j;
	fscanf(fin,"%d",&t);
	fgets(s,20,fin);
	//scanf("%d",&t);
	//getchar();
	T = t;
	while(t--){
		int i;
		fgets(s,40,fin);
		//fgets(s,40,stdin);
		c.clear();
		j.clear();
		for(i=0;(s[i]!=' ');i++)
			c.push_back(s[i]);
		i++;
		for(;(s[i]!='\n') && (s[i]!='\0');i++)
			j.push_back(s[i]);
		mini = 10000;
		minc="1000";
		minj="1000";
		resolve(c,j);
		fprintf(fout,"Case #%d: %s %s\n",T-t,minc.c_str(),minj.c_str());
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
