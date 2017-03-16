#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

// defines
#define ll long long int
#define REP(a,b) for(int (a)=0;a<(int)b;a++)
#define FOR(a,b,c) for(int (a)=b;a<(int)c;a++)
#define MP(A,B) make_pair(A,B)
#define PB push_back
#define S(a) scanf("%d",&a);
#define SCH(a) scanf("%s",a);
#define foreach(a,b) for(__typeof(b).begin() a  = b.begin(); a != b.end();a++)
#define debug(a) cout<<a<<endl;
#define INIT(a) memset(a,0,sizeof(a))

using namespace std;

int A;
int B;

int table[10000001];

int test(int num){
	int k=num;
	
	int counter =0;
	
	int fak =1;
	while(fak*10<=num){
		fak*=10;
		counter++;
	}
	
	int res=0;
	
	while(counter--){
		int h = num%10;
		num/=10;
		if(h!=0){
			num=h*fak+num;
			if(table[num]!=k){
				table[num]=k;
				
				
				
				if(num>=A && num<=B && k<num){
				//	debug(k<<" , "<<num);
					res++;
				}
			}
		}
	}
	
	return res;
}

int main(){
	int T;
	S(T);
	FOR(t,1,T+1){
		memset(table,-1,sizeof(table));
		S(A);
		S(B);
		
		long long sol =0;
		
		for(int n=A;n<=B;n++){
			sol+=test(n);
		}
		
		printf("Case #%d: %lld\n",t,sol);
	}
}
