#include<iostream>
#include<cstring>
#include<cstdio>
#include<sstream>
#include<fstream>
#include<cmath>
#include<map>
#define ZERO 0

using namespace std;
/*
int main()
{
	int N,a,b;
	int i,j,count;	
	scanf("%d",&N);
	while(N--){
		int si,count=0,ten=10,ik;
		scanf("%d",&a);
		scanf("%d",&b);
		i = a;
		int sii = floor(log10(b)+1);
		int tens = pow(tens,sii-1);
		int k = b/10;
		cout << "k = "<< k << endl;
		while(i <= b ){
			ik = i%10;
			si = floor(log10(i)+1);
			ten = pow(ten,si-1);
			j = i/ten;
			
			cout << "j = "<< j << endl;
			cout << "ik = "<< ik << endl;
			if((ik > j && ik !=0 && ik < k) || (i%100 > j && i%100 !=0 && i%100 < k) || (i%1000 > j && i%1000 !=0 && i%1000 < k) || (i%10000 > j && i%10000 !=0 && i%10000 < k) || (i%100000 > j && i%100000 !=0 && i%100000 < k) ||(i%1000000 > j && i%1000000 !=0 && i%1000000 < k)){
			printf("%d\n",i);
			count++;} 
			i++;
		}
		printf("%d\n",count);
	}
	return 0;
}
*/

int cal( int, int, int );

int main()
{
	int t, a, b, i, j, ans;
	fstream fout("out3.txt",ios::out);
	cin >> t;
	for( i = 1; i <= t; i++ ) {
		cin >> a >> b;
		ans = 0;
		for( j = a; j < b; j++ ) {
			ans = ans + cal(a, b, j );
		}
		cout << "Case #" << i << ": " << ans << "\n";
		fout << "Case #" << i << ": " << ans << "\n";
	}
}

int cal( int a, int b, int n )
{
	int i;
	int x;
	int ret=0;
	map<int,int> m;
	string s, s1;
	stringstream buf;
	buf << n;
	s = buf.str();
	for( i = s.size()-1; i > 0; i-- ) {
		s1 = s.substr(0, i);
		s1 = s.substr( i ) + s1;
		stringstream(s1) >> x;
		if( x > n && x<=b && m[x]==0) {
			ret++;
			m[x] = 1;
			//printf("(n,m) = (%d, %d)\n",n,x);
		}
	}
	return ret;
}
