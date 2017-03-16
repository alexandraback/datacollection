#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

//short hand for loops
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

//quick print for answer cases
int case_number;
#define gout case_number++, printf("Case #%d: ",case_number), cout
#define INF (1<<29)

//define necessary arrays here 
float a[100000];

void main2(void){
	cout.precision(7);
	float C,F,X;
	int i,j, flag, index;
	i = 0;
	
	//pulls in data from test case
	cin >> C >> F >> X;
	
	flag = 0;
	while(!flag){
		a[i] = 0;
		if(i==0){
			a[i] = X/2;
			i++;
			continue;
		}

		REP(j,i){
			a[i] += C/(2+F*j);		 
		}
		a[i] += X/(2+F*i);
		
		if(i>0 and a[i] > a[i-1]){
			flag = 1;
			index = i-1;
		}
		i++;
	}
	
	//prints answer text
	float ans;
	ans = a[index];	
	case_number++;
	printf("Case #%d: %0.7f \n",case_number, ans);

}

int main(void){
	int number_of_test_cases, i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
