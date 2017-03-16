//UESTC_L3

#include <stdexcept>
#include <cstdarg>
#include <iostream>
#include <fstream>
#include <exception>
#include <memory>
#include <locale>
#include <sstream>
#include <set>
#include <list>
#include <bitset>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <string>
#include <utility>
#include <cctype>
#include <climits>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <vector>
#include <queue>
#include <deque>
#include <cstdlib>
#include <stack>
#include <iterator>
#include <functional>
#include <complex>
#include <valarray>
using namespace std;

string str[110];

int main(){
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B.out","w",stdout);
	
	int test;
	scanf("%d",&test);
	
	int ct=0;
	while(test--){
		int num;
		scanf("%d",&num);
		int a[10];
		for(int i=0;i<num;i++){
			a[i]=i;
		}
		int cnt[26];
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<num;i++){
			cin>>str[i];
			int len=str[i].size();
			for(int j=0;j<len;j++){
				cnt[str[i][j]-'a']++;
			}
		}
		int ret=0;
		do{
			string temp="";
			for(int i=0;i<num;i++){
				temp+=str[a[i]];
			}
			int len2=temp.size();
			bool judge=true;
			for(int i=0;i<len2;){
				int j=i;
				int tot=0;
				while(j<len2&&temp[j]==temp[i]){
					tot++;
					j++;
				}
				if(tot!=cnt[temp[i]-'a']){
					judge=false;
					break;
				}
				i=j;
			}
			if(judge)ret++;
		}while(next_permutation(a,a+num));
		printf("Case #%d: %d\n",++ct,ret);
	}
	return 0;
}