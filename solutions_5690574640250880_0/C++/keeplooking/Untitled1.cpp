#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //
using namespace std;
char A[50][50];
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t,ty = 1,r,c,m;
	cin>>t;
	while(t--){
		cin>>r>>c>>m;
		printf("Case #%d: \n",ty++);
		if(m==r*c-1){
			for(int i=1;i<r;i++){
				for(int j=0;j<c;j++)
					printf("*");
				cout<<endl;
			}
			for(int j=1;j<c;j++)
				printf("*");
			cout<<"c"<<endl;
			continue;
		}
		
		if(r==1||c==1){
			if(m>r*c-1){
				printf("Impossible\n");
			}
			else{
				for(int i=0;i<r;i++){
					for(int j=0;j<c;j++){
						if(i+j==0)
							printf("c");
						else if((i+1)*(j+1)>r*c-m)
							printf("*");
						else
							printf(".");
					}
					cout<<endl;
				}
			}
			continue;
		}
		if((r==2||c==2)&&m%2){
			printf("Impossible\n");
			continue;
		}
		if(r*c-m<4||r*c-m==5||r*c-m==7){
			printf("Impossible\n");
			continue;
		}
		int i,j;
		for(i=0;i<r;i++){
			for(j=0;j<c;j++)
				A[i][j]='*';
		}
		int cur=r*c;
		bool ov=0;
		for(j=0;j<c;j++){
			if(cur>m+1){
				A[0][j]='.';
				A[1][j]='.';
				cur-=2;
			}
			else{
				break;
			}
		}
		if(cur==m+1){
			A[0][j-1]='*';
			A[1][j-1]='*';
			A[2][0]='.';
			A[2][1]='.';
			A[2][2]='.';
			cur--;
			ov=1;
		}
		for(i=2;i<r;i++){
			if(cur==m+1){
				A[i-1][c-1]='*';
				A[i][0]='.';
				A[i][1]='.';
				cur--;
				ov=1;
				break;
			}
			else if(cur>m+1){
				A[i][0]='.';
				cur--;
			}
			for(j=1;j<c;j++){
				if(cur>m){
					A[i][j]='.';
					cur--;					
				}
				else{
					ov=1;
					break;
				}
			}
			if(ov)
				break;
		}
		A[0][0]='c';
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++)
				printf("%c",A[i][j]);
			cout<<endl;
		}
	}
}
