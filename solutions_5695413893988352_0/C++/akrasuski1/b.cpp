#include <cstdio>
#include <climits>
#include <vector>
#include <map>

using namespace std;

char num1[30];
char num2[30];

int main(){
	int t;
	scanf("%d", &t);
	for(int tc=0;tc<t;tc++){
		printf("Case #%d: ",tc+1);
		scanf("%s %s", num1, num2);
		int p10=1;
		vector<char*> places;
		int l1=0;
		int l2=0;
		for(char* c=num1;*c;c++){
			l1++;
			if(*c=='?'){places.push_back(c);p10*=10;}
		}
		for(char* c=num2;*c;c++){
			l2++;
			if(*c=='?'){places.push_back(c);p10*=10;}
		}
		long long best=LLONG_MAX;
		long long bestn1,bestn2;
		for(int i=0;i<p10;i++){
			int ii=i;
			for(int j=0;j<places.size();j++){
				*(places[j])='0'+(ii%10);
				ii/=10;
			}
			long long n1,n2;
			sscanf(num1, "%lld",&n1);
			sscanf(num2, "%lld",&n2);
			long long diff=n1-n2;
			if(diff<0){diff=-diff;}
			bool ok=false;
			if(diff<best){
				ok=true;
			}
			else if(diff==best){
				if(n1<bestn1){
					ok=true;
				}
				else if(n1==bestn1){
					if(n2<bestn2){
						ok=true;
					}
				}
			}
			if(ok){
				best=diff;
				bestn1=n1;
				bestn2=n2;
			}
		}
		printf("%.*lld %.*lld\n", l1, bestn1, l2, bestn2);
	}
}
