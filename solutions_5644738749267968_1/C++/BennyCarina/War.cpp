#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long
#define LarN 1000
double A[LarN+5],B[LarN+5];
int N;

int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case,ans1,ans2;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		cin>>N;
		for(int i=1;i<=N;i++)scanf("%lf",&A[i]);
		for(int i=1;i<=N;i++)scanf("%lf",&B[i]);
		sort(A+1,A+N+1);
		sort(B+1,B+N+1);
		int idxa,idxb;
		ans2=N;
		idxb=N;
		for(idxa=N;idxa>0;idxa--){
			if(B[idxb]>A[idxa]){
				idxb--;
				ans2--;
			}
		}
		ans1=0;
		idxa=N;
		for(idxb=N;idxb>0;idxb--){
			if(A[idxa]>B[idxb]){
				ans1++;
				idxa--;
			}
		}
		printf("Case #%d: %d %d\n",i_case,ans1,ans2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}