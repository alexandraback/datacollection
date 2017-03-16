#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(a,b) for(int a=0; a<b; a++)
#define ABS(a) ((a)<0 ? (-(a)) : (a))

using namespace std;

int vovel(char a){
	if (a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
		return 1;
	return 0;
}

char input[2000000];
int solveCase(){
	int n;
	scanf("%s", input);
	scanf("%d", &n);
	
	vector < int > str;
	FOR(i, 2000000 && input[i]!=0)
		str.push_back(!vovel(input[i]));
		
	vector < int > subStart;
	int justFound=0;

	//finds all substring with proper start
	FOR(i, str.size()-n+1){
		justFound=0;
		if(justFound){
			if(str[i+n-1])
				subStart.push_back(i);
		}else{
			int notThere = 0;
			FOR(j, n)
				if(!str[i+j]){
					notThere++;
					break;
				}
//			printf("Checking %d and its %d\n", i , notThere);
			if(!notThere){
				subStart.push_back(i);
				justFound=1;
			}else
				justFound=0;				
		}
	}

/*	printf("%s %d\n", input, n);
	FOR(i, str.size())
		printf("%d", str[i]);
	printf("\n");
	FOR(i, subStart.size())
		printf("%d", subStart[i]);
	printf("\n\n");
*/		

	
	if(subStart.size()==0)
		return 0;
	
	int ret=0;
	//sums over all strings
	ret+=(subStart[0]+1)*(str.size()-subStart[0]-n+1);
//	printf("%d\n", (subStart[0]+1)*(str.size()-subStart[0]-n+1));
	for(int i=1; i<subStart.size(); i++){
		ret+=(subStart[i]-subStart[i-1])*(str.size()-subStart[i]-n+1);
//		printf("%d\n", (subStart[i]-subStart[i-1])*(str.size()-subStart[i]-n+1));
	}
	
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	FOR(i,T)
		printf("Case #%d: %d\n", i+1, solveCase());	
}
