#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<vector>
using namespace std;
typedef long long LL;
int T;
char c[20], j[20];
int main(){
	freopen("B_in.txt", "r", stdin);
	freopen("B_out.txt", "w", stdout);
	scanf("%d", &T);
	for(int C = 1; C <= T; ++C){
		scanf("%s%s", c, j);
		int len = strlen(c);
		LL cc = 0LL, jj = 0LL;
		for(int i = 0; i<len; ++i){
			if((c[i]=='?')||(j[i]=='?')){
				if(cc==jj){
					if((c[i]=='?')&&(j[i]=='?')){
						c[i] = '0';
						j[i] = '0';
						if((i<len-1)&&(c[i+1]!='?')&&(j[i+1]!='?')){
							int x = c[i+1]-'0', y = j[i+1]-'0';
							if((y+10-x)<abs(x-y)){
								j[i] = '1';
								if((x+10-y)<(y+10-x)){
									c[i] = '1';
									j[i] = '0';
								}
							}
							else if((x+10-y)<abs(x-y))
								c[i] = '1';
						}
					}
					else if((c[i]=='?')&&(j[i]!='?')){
						c[i] = j[i];
						if((i<len-1)&&(c[i+1]!='?')&&(j[i+1]!='?')){
							int x = c[i+1]-'0'+(c[i]-'0')*10, y = j[i+1]-'0'+(j[i]-'0')*10;
							if((x-10>0)&&((y-(x-10))<=abs(y-x))){
								c[i] = j[i]-1;
								if((x+10<100)&&((x+10-y)<(y-x+10)))
									c[i] = j[i]+1;
							}
							else if((x+10<100)&&((x+10-y)<abs(y-x)))
								c[i] = j[i]+1;
						}
					}
					else{
						j[i] = c[i];
						if((i<len-1)&&(c[i+1]!='?')&&(j[i+1]!='?')){
							int x = c[i+1]-'0'+(c[i]-'0')*10, y = j[i+1]-'0'+(j[i]-'0')*10;
							if((y-10>0)&&((x-(y-10))<=abs(y-x))){
								j[i] = c[i]-1;
								if((y+10<100)&&((y+10-x)<(x-y+10)))
									j[i] = c[i]+1;
							}
							else if((y+10<100)&&((y+10-x)<abs(y-x)))
								j[i] = c[i]+1;
						}
					}
				}
				else if(cc<jj){
					if((c[i]=='?')&&(j[i]=='?')){
						c[i] = '9';
						j[i] = '0';
					}
					else if((c[i]=='?')&&(j[i]!='?'))
						c[i] = '9';
					else j[i] = '0';
				}
				else{
					if((c[i]=='?')&&(j[i]=='?')){
						c[i] = '0';
						j[i] = '9';
					}
					else if((c[i]=='?')&&(j[i]!='?'))
						c[i] = '0';
					else j[i] = '9';
				}
			}
			cc = cc*10LL + (LL)(c[i]-'0');
			jj = jj*10LL + (LL)(j[i]-'0');
		}
		printf("Case #%d: %s %s\n", C, c, j);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
