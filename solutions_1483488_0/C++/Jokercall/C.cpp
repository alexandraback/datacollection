#include <iostream>
using namespace std;

bool check[3000000]={0};
int T;
int A,B;
FILE *fp = fopen("file.out","w");

int ndigit(int m){
	if(m<10) return 1;
	if(m<100) return 2;
	if(m<1000) return 3;
	if(m<10000) return 4;
	if(m<100000) return 5;
	if(m<1000000) return 6;
	if(m<10000000) return 7;
}
int ten(int d){
	switch(d){
	case 2: return 10;
	case 3: return 100;
	case 4: return 1000;
	case 5: return 10000;
	case 6: return 100000;
	case 7: return 1000000;
	case 8: return 10000000;
	default: cout<<"Error2"<<endl;
	}
}

int recycle(int m ,int mten){
	return m/10 + m%10 * mten;
}
int mc2(int m){
	return m*(m+1)/2;
}
void solve(){
	int cnt=0;
	memset(check+A,0,B-A+1000);
	for(int i=A ; i <= B ;i++){
		int d = ndigit(i);
		if(d<2)
			continue;
		int mten = ten(d);
		int r = i;
		int fcnt=0;
		for(int j=0 ; j<d ;j++)
		{
			r = recycle(r,mten);
			if( r <= i || r > B )
				continue;
			if( check[r] == 0)
			{
				check[r]=1;
				fcnt++;
			}
		}
		cnt+= mc2(fcnt);
	}
	fprintf(fp,"%d\n",cnt);
	
}



int main(){
	cin>>T;
	for(int k=0;k<T;k++){
		cin>>A>>B;
		fprintf(fp,"Case #%d: ",k+1);
		solve();
	}
}