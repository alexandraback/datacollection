#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int T,A,N,*buf,ans,tmp;
	freopen("input.in","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>A>>N;
		buf=new int[N];
		for(int j=0;j<N;j++)scanf("%d",buf+j);
		sort(buf,buf+N);
		int add=A;
		tmp=0;
		ans=N;
		if(A>1){
		    for(int j=0;j<N;j++){
			   //solution
			    while(add<=buf[j]){
				     add+=add-1;
				     tmp++;
			     }
				add+=buf[j];
			     if(ans>tmp+N-1-j)ans=tmp+N-1-j;
		     }
		}
		delete buf;
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}


