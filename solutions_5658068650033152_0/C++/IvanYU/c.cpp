#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main(){
	int T;
	int n,m,k;
	cin>>T;
	for(int x=0;x<T;x++){
		cin>>n;
		cin>>m;
		cin>>k;
		int z,lk;
		int ans=0;
		int temp;
		int a,b;
		if(k<=4){
			printf("Case #%d: %d\n",x+1,k);
		}
		else if(n<=2 || m<=2){
			printf("Case #%d: %d\n",x+1,k);
		}
		else if(n==3 || m==3){
			if(k<=n*m-4)
				printf("Case #%d: %d\n",x+1,k-((k-2)/3));
			else 
				printf("Case #%d: %d\n",x+1,k-((n*m)/3)+2);
		}
		else if(k<8){
			printf("Case #%d: %d\n",x+1,k-1);

		}else if(k==8){
			printf("Case #%d: %d\n",x+1,k-2);

		}
		else if(k>=(n*m-4)){
			printf("Case #%d: %d\n",x+1,k-(n-2)*(m-2));
		}
		else{
			if(n<m){
				temp=n;
				n=m;
				m=temp;
			}

			z=sqrt(k+4);
			if(z<=m&&z<=n){
				ans=(z-2)*(z-2);
				lk=k-z*z+4;
				if(k>=2&&k<(2*z)-3)
					ans+=k-2;
				else if(k==(2*z)-2)
					ans+=k-3;
				else if(k==(2*z)-1)
					ans+=k-3;
				printf("Case #%d: %d\n",x+1,k-ans);
			}
			else if(z<n && z>=m){
				a=(k+4)/m;
				ans=(a-2)*(m-2);
				b=(k+4)%m;
				if(b<=2){
					printf("Case #%d: %d\n",x+1,k-ans);
				}
				else{
					printf("Case #%d: %d\n",x+1,k-(ans+b-2));
				}

			}

		}



	}



	return 0;
}