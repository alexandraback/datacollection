#include <iostream>
#include <map>
using namespace std;
int main(){
	int T,A,B,p10,t,tmp,l,i,j,ans,r;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d",&A);
		scanf("%d",&B);
		p10 = 1;
		tmp = B;
		l = 0;
		ans = 0;
		while(tmp > 0){
			tmp = tmp/10;
			p10 *= 10;
			l++;
		}
		p10 = p10/10;
		for(i=A;i<=B;i++){
			tmp = i;
			map<int,bool> used;
			for(j=0;j<l;j++){
				r = tmp%10;
				tmp = r*p10 + tmp/10;
				if(!used[tmp]) {
					if(tmp != i && tmp >= A && tmp <= B) 
					{
						ans++;
						used[tmp] = true;
					}
				}
			}
		}
		printf("Case #%d: %d\n",t,ans/2);
	}
}