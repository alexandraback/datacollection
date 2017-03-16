#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <complex>
#include <valarray>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

#define f(i,n) for(int i=0; i <n;i++)
#define fi(i,s,n) for(int i=s; i<n;i++)
#define isV(i) (i=='a' ||i=='e' ||i=='i' || i=='o' ||i=='u')
typedef long long ll;
int main(){
	int tc;
	scanf("%d",&tc);
	f(i,tc){
		printf("Case #%d: ",i+1);
		char* name = new char[1000002];
		int n;
		scanf("%s %d",name,&n);
		//printf("%s\n",name);
		int consec=0;
		ll num=0;
		int j=0;
		bool *con = new bool[1000002];
		f(j,1000002){
			con[j]=false;
		}
		while(name[j]!='\0'){
			if(!isV(name[j])){
				consec++;
			}
			else{
				consec=0;
			}

			if(consec==n){
				con[j-(n-1)]=true;
				//printf("%d t \n",j-(n-1));
				consec--;
			}
			j++;
		}

		int len = j;
		
		int numCon = 0, numNot=0;
		j=0;
		while(name[j]!='\0'){
			if(con[j])
				numCon++;
			else{
				numNot++;
			}
			
			if(con[j]){
				num+=(len-j-n+1)*(numNot+1);
				numNot=0;
			}
			j++;
			
		}
		

		printf("%d\n",num);
	}

	return 0;
}
