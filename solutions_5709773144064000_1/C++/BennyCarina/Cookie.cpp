#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long


int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;
	double C,F,X,E;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		cin>>C>>F>>X;
		double t1=0,t2=0;
		E=2.0;
		while(1){
			t1+=X/E;
			t2+=(C/E)+X/(E+F);
			if(t1<=t2)break;
			else{
				t1-=X/E;
				t1+=C/E;
				t2=t1;
				E+=F;
			}
		}
				
		printf("Case #%d: %.7lf\n",i_case,t1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}