#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
	int T,n,s,p;
	int t;
	
	
	cin >> T;
	for( int i=0;i<T;++i ){
		int ans = 0;
		cin >> n >> s >> p;
		for( int j=0;j<n;++j ){
			cin >> t;
			
			int tmp = t/3;
			
			if( t%3 == 0 ){
				if( tmp >= p ){
					ans ++;
				}else if( tmp>0 && tmp+1 >= p && s>0 ){
					--s;
					ans ++;
				}
			}else if( t%3 == 1 ){
				if( tmp+1 >= p ){
					ans ++;
				}
			}else{
				if( tmp+1 >= p ){
					ans ++;
				}else if( tmp+2 >= p && s>0 ){
					--s;
					ans ++;
				}
			}
		}
		printf("Case #%d: ",i+1);
		printf("%d",ans);
		printf("\n");
	}
	
	return 0;
}
