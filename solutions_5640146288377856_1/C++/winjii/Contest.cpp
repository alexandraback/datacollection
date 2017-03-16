#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<climits>
#include<string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<cmath>
#include<queue>
#include<cstring>
#include<stack>
#include<functional>
#include<deque>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int tc=1;tc<=T;tc++){
		int R,C,W;
		cin>>R>>C>>W;
		int ans = C/W*R+W-1;
		if(C%W!=0) ans++;
		printf("Case #%d: %d\n",tc,ans);
	}
    return 0;
}