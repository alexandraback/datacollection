#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;

set<pair<int,int> > S;
char T[1000002];
int n, L;

bool check(char x){
	if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u') return true;
	return false;
}

void put(int a,int b){
	//printf("putting %d %d\n", a, b);
	for(int i=0; i<=a; i++)
		for(int j=b; j<L; j++)
			S.insert(make_pair(i,j));
}

int main(){
	int z;
	scanf("%d", &z);
	for(int t=0; t<z; t++){
		scanf("%s", T);
		scanf("%d", &n);
		L=0;
		vector<int> vowels;
		for(int i=0; T[i]!=0; i++)L++; 
		for(int i=0; i<L; i++)
			if(check(T[i])) vowels.push_back(i);
		vowels.push_back(L+1);
		int k=0,i=0;
		while(i+n-1<L){
			if(check(T[i])){
				k++;
				i++;
			}
			else{
				if(i+n-1<vowels[k]){
					//printf("%d %d\n", i, k);
					put(i,i+n-1);
					//printf("%d\n...\n", S.size());
					i++;
				}
				else{
					i=vowels[k];
				}
			}
		}
		printf("Case #%d: %d\n", t+1,S.size());
		S.clear();
		vowels.clear();
		//printf("=========================\n");
	}
	return 0;
}
