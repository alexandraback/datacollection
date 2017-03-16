# include <stdio.h>
# include <stdlib.h>
# include <cstdlib>
# include <iostream>
# include <cstdio>
# include <string>
# include <cstring>
# include <sstream>
# include <math.h>
# include <algorithm>
# include <map>
# include <vector>
# include <stack>
# include <queue>
# include <set>
#include <vector>

using namespace std;

int main(){
	int cnt,cases,i,j,k,l,m,n,ans,mn;
	scanf("%d\n",&cases);
	int bd[100][100],s[100][100];
	for(cnt = 1 ; cnt <= cases ; cnt++){
		scanf("%d %d\n",&n,&m);
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < m ; j++){
				bd[i][j] = 100;
				scanf("%d ",&s[i][j]);
			}
		}
		//row max remover
		for(i = 0 ; i < n ; i++){
			for(j = 0 , mn = 0; j < m ; j++){
				mn = (mn < s[i][j])?s[i][j]:mn;
			}
			for(j = 0 ; j < m ; j++){
				bd[i][j] = (mn > bd[i][j])?bd[i][j]:mn;
			}
		}
		//col max remover
		for(i = 0 ; i < m ; i++){
			for(j = 0 , mn = 0; j < n ; j++){
				mn = (mn < s[j][i])?s[j][i]:mn;
			}
			for(j = 0 ; j < n ; j++){
				bd[j][i] = (mn > bd[j][i])?bd[j][i]:mn;
			}
		}
		//checking
		char a[2][5] = {"YES" , "NO"};
		ans = 0;
		for(i = 0 ; i < n ; i++){
			for(j = 0 ; j < m ; j++){
				if(bd[i][j] != s[i][j]){ans = 1; break;}
			}
		}
		
		cout << "Case #" << cnt << ": " << a[ans] << endl;
	}

	return 0;
}
