#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main(void){

	freopen("B-small-attempt0.in","r",stdin);
	freopen("b2.out","w",stdout);

	int t;
	cin>>t;

	for(int test=0;test<t;test++){
		int n;
		int i,j;
		
		int a,b,k;
		cin>>a>>b>>k;

		int count = 0;


		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				int oper = (i & j);
				//cout<<oper<<endl;
				if(oper<k){
					count++;
				}
			}
		}
		printf("Case #%d: %d\n",test+1,count);
	}


}