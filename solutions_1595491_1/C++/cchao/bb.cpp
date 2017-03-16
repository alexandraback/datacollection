#include <iostream>
using namespace std;
int n,s,p;
inline bool valid(int a,int b,int c){
	return (a>=0 && a<=10) &&
		(b>=0 && b<=10) &&
		(c>=0 && c<=10);
}
inline bool suprise(int a,int b,int c){
	return c-a==2;
}
inline bool more(int a,int b,int c){
	return a>=p || b>=p || c>=p;
}

#define R(a,b,c){ \
	if(valid(t/3+a,t/3+b,t/3+c) && suprise(t/3+a,t/3+b,t/3+c)) is=1; \
	if(valid(t/3+a,t/3+b,t/3+c) && more(t/3+a,t/3+b,t/3+c)){ \
		if(suprise(t/3+a,t/3+b,t/3+c)) ta=1; \
		else tb=1; \
	} \
}

int main(){
	int tt;
	cin >> tt;
	int k;
	for(k=0;k<tt;k++){
		cout << "Case #" << k+1 << ": ";
		cin >> n >> s >> p;
		int j;
		int t;
		int m=0,ms=0,cs=0;
		for(j=0;j<n;j++){
			cin >> t;
			int ta=0,tb=0,is=0;
			switch(t%3){
				case 0:
					R(0,0,0);
					R(-1,0,1);
					break;
				case 1:
					R(0,0,1);
					R(-1,1,1);
					break;
				case 2:
					R(0,0,2);
					R(0,1,1);
					break;
			}
			//cout << t << ' ' << ta << ' ' << tb << ' ' << is <<endl;
			if(ta==1 && tb==0) m++;
			else if(ta==1 || tb==1) ms++;
			if(is==1) cs++;
		}
		if(cs<s) cout << 0 << endl;
		else cout << (m<s? m:s) + ms << endl;
	}
	return 0;
}
