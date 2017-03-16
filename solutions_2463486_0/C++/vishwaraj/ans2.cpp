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

char c[20];

inline bool pali(int i){
	//palindrome check
	int j=0;
	while(i){
		c[j]=i%10;
		i/=10;
		j++;
	}
	j--;
	while(i < j){
		if(c[i]==c[j]){
			i++;
			j--;
		}
		else
			break;
	}
	if(i >= j)return true;
	else return false;
}

inline bool fair(int i){
	int sqr = (int)sqrt(i*1.0);
	if((sqr*sqr==i)&&(pali(i))&&(pali(sqr)))
		return true;
	return false;
}

int main(){
	int cnt,cases,i,j,k,l,m,n,a,b,ans;
	cin >> cases;
	for(cnt = 1 ; cnt <= cases ; cnt++){
		cin >> a >> b;
		ans = 0;
		for(i = a; i<=b ; i++){
			if(fair(i))ans++;
		}
		cout << "Case #" << cnt << ": " << ans << endl;
	}

	return 0;
}
