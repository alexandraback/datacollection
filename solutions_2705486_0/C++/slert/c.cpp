#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

#define ds 521196
char d[522000][12];
int l[522000];
int m[4010][6];
char s[4010];
int sl;

inline int cmp(int i, int k, int& a, int& b){
	int lst = -1;
	int c = 0;
	for(int j = 0; j < l[k]; j++){
		if(d[k][j] != s[i+j]){
			c++;
			if(lst == -1){
				lst = a = j;
			}else if(j-lst<5){
				return -1;
			}else{
				lst = j;
			}
		}
	}
	if(c==0){
		a = b = 5;
	}
	else{
		b = l[k]-lst;
	}
	return c;
}

int main(){
	ifstream dicts("garbled_email_dictionary.txt");
	for(int i = 0; i < ds; i++){
		string dx;
		dicts >> dx;
		strcpy(d[i],dx.c_str());
		l[i] = dx.length();
	}
	dicts.close();

	// freopen("test.in","r",stdin);
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);

	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		scanf("%s", s);
		sl = strlen(s);
		for(int i = 0; i <= sl; i++)
			for(int j = 0; j < 6; j++)
				m[i][j] = sl+1;
		m[0][5] = 0;

		for(int i = 0; i < sl; i++)
			for(int k = 0; k < ds; k++){
				if(i+l[k]>sl)continue;
				int a,b;
				int c = cmp(i,k,a,b);
				if(c>=0){
					int mn = sl+1;
					if(a > 5)a = 5;
					if(b > 5)b = 5;
					for(int j = 5; j >= 5-a; j--){
						if(mn > m[i][j])
							mn = m[i][j];
						int bb = min(j+l[k],b);
						if(bb>5)bb=5;
						if(m[i+l[k]][bb] > mn+c)
							m[i+l[k]][bb] = mn+c;
					}
					
				}
			}
		int mn = sl+1;
		for(int i = 0; i < 6; i++)
			if(mn > m[sl][i])mn = m[sl][i];
		printf("Case #%d: %d\n", ti, mn);
	}
	return 0;
}