#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<string.h>
#include<algorithm>

using namespace std;

const char table[8][8] = {
	{'1','i','j','k','1','i','j','k'},
	{'i','1','k','j','i','1','k','j'},
	{'j','k','1','i','j','k','1','i'},
	{'k','j','i','1','k','j','i','1'},
	{'1','i','j','k','1','i','j','k'},
	{'i','1','k','j','i','1','k','j'},
	{'j','k','1','i','j','k','1','i'},
	{'k','j','i','1','k','j','i','1'}
};
const int sign[8][8] = {
	{ 1,  1,  1,  1, -1, -1, -1, -1},
	{ 1, -1,  1, -1, -1,  1, -1,  1},
	{ 1, -1, -1,  1, -1,  1,  1, -1},
	{ 1,  1, -1, -1, -1, -1,  1,  1},
	{-1, -1, -1, -1,  1,  1,  1,  1},
	{-1,  1, -1,  1,  1, -1,  1, -1},
	{-1,  1,  1, -1,  1, -1, -1,  1},
	{-1, -1,  1,  1,  1,  1, -1, -1}
};
const int maxlen = 10050;
char str[maxlen];
inline int trans(char input, int tmps){
	int base = 0;
	switch(input){
		case('1'):
			base = 0;
			break;
		case('i'):
			base = 1;
			break;
		case('j'):
			base = 2;
			break;
		case('k'):
			base = 3;
			break;
	}
	int add = (tmps == -1) ? 4 : 0;
	base += add;
	return base;
}
int main(){
	int t;
	scanf("%d", &t);
	int ks = 1, len, rep;
	while(t > 0){
		t--;
		scanf("%d%d",&len, &rep);
		scanf("%s", str);
		int status = 0;
		char tmpchar = '1';
		int ss = 1;
		bool meet = false;
		for(int i = 0; i < rep; ++i){
			for(int j = 0; j < len; ++j){
				char  tmp = str[j];
				int rowid = trans(tmpchar, ss);
				int columnid = trans(tmp, 1);
				//printf("rowid is %d, and columnid is %d\n", rowid, columnid);
				ss = sign[rowid][columnid];
				tmpchar = table[rowid][columnid];
				if(status == 0 && tmpchar == 'i' && ss == 1){
					status = 1;
				}
				if(status == 1 && tmpchar == 'k' && ss == 1){
					status = 2;
				}
				if(status == 2 && tmpchar == '1' && ss == -1){
					meet = true;
					status = 3;
				}	
				//printf("status is %d, tmpchar is %c, sign is %d\n", status, tmpchar, ss);
			}
		}
		if(status == 3 && tmpchar == '1' && ss == -1){
			printf("Case #%d: Yes\n", ks++);
		}
		else{
			printf("Case #%d: No\n", ks++);
		}
	}
	return 0;
}
