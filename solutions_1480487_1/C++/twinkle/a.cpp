#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int T,n;
	double d[1111],ans[1111];
	cin >> T;
	for(int Case = 1; Case <= T ; Case ++){
		cin >> n;
		double sum = 0,tmp;
		for(int i = 1;i <= n; i ++){
			cin >> d[i];
			sum += d[i];
		}			
		tmp = (sum * 2) / double(n);
		double cnt,p,newtmp;
		cnt = p = 0;
		for(int i =1 ;i <= n ; i ++){
			if(d[i] < tmp){
				cnt += d[i];
				p += 1;
			}
		}
		newtmp = (cnt + sum) /  p;
		//cout << cnt <<' '<<sum<<' '<<newtmp<<endl;		
		for(int i = 1;i <= n ; i ++){
			if(d[i] >= tmp)
				ans[i] = 0;
			else
				ans[i] =( newtmp - d[i] ) / sum * 100.0;
		}
		printf("Case #%d: ",Case);
		for(int i = 1 ; i < n; i ++){
			printf("%lf ",ans[i]);
		}
		printf("%lf\n",ans[n]);
 	}
	
	
	return 0;
}
