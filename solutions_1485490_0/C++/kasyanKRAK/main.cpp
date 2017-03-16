#include <cstdio>
#include <algorithm>

using namespace std;

long long a[100], A[100], b[1000], B[1000];

long long sn1[1000], sn2[1000], sn3[1000], sr1[1000], sr2[1000], sr3[1000];

int main()
{
	freopen("inC.txt","r",stdin);
	freopen("outC.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for (int t=0; t<T; t++) {
		int n,m;
		scanf("%d%d",&n,&m);
		for (int i=0; i<n; i++)
			scanf("%I64d%I64d",&a[i],&A[i]);
		for (int i=0; i<m; i++)
			scanf("%I64d%I64d",&b[i],&B[i]);
		if (n==2)
			if (A[0]==A[1]) {
				n--;
				a[0]+=a[1];
			}
		if (n==3) 
			if (A[0]==A[1] && A[1]==A[2]) {
				n=1;
				a[0]+=a[1]+a[2];
			}
		if (n==3)
			if (A[0]==A[1]) {
				n--;
				a[0]+=a[1];
				A[1]=A[2];
				a[1]=a[2];
			}
		if (n==3)
			if (A[1]==A[2]) {
				n--;
				a[1]+=a[2];
			}

		long long ans;
		if (n==1) {
			long long sum=0;
			for (int i=0; i<m; i++)
				if (B[i]==A[0]) sum++;
			ans=min(a[0],sum);
		}

		if (n==2) {
			long long sum;
			sum=0;
			for (int i=0; i<m; i++) {
				if (A[0]==B[i])
					sum+=b[i];
				sn1[i]=sum;
			}
			sum=0;
			for (int i=0; i<m; i++) {
				if (A[1]==B[i])
					sum+=b[i];
				sn2[i]=sum;
			}
			sum=0;
			for (int i=m-1; i>=0; i--) {
				if (A[0]==B[i])
					sum+=b[i];
				sr1[i]=sum;
			}
			sr1[m]=0;
			sum=0;
			for (int i=m-1; i>=0; i--) {
				if (A[1]==B[i])
					sum+=b[i];
				sr2[i]=sum;
			}
			sr2[m]=0;

			ans=min(sr2[0],a[1]);
			for (int i=0; i<m; i++) 
				ans=max(ans,min(sn1[i],a[0])+min(sr2[i+1],a[1]));
		}

		if (n==3) {
//			printf("ololo");
			long long sum;
			sum=0;
			for (int i=0; i<m; i++) {
				if (A[0]==B[i])
					sum+=b[i];
				sn1[i]=sum;
			}
			sum=0;
			for (int i=0; i<m; i++) {
				if (A[1]==B[i])
					sum+=b[i];
				sn2[i]=sum;
			}
			sum=0;
			for (int i=m-1; i>=0; i--) {
				if (A[0]==B[i])
					sum+=b[i];
				sr1[i]=sum;
			}
			sr1[m]=0;

			sum=0;
			for (int i=m-1; i>=0; i--) {
				if (A[1]==B[i])
					sum+=b[i];
				sr2[i]=sum;
			}
			sr2[m]=0;

			sum=0;
			for (int i=0; i<m; i++) {
				if (A[2]==B[i])
					sum+=b[i];
				sn3[i]=sum;
			}
			sum=0;
			for (int i=m-1; i>=0; i--) {
				if (A[2]==B[i])
					sum+=b[i];
				sr3[i]=sum;
			}
			sr3[m]=0;

			ans=min(sr3[0],a[2]);
			if (A[0]==A[2]) ans=max(ans,min(a[0]+a[2],sr1[0]));
			long long res;
			for (int i=0; i<m; i++) {
				res=min(sn1[i],a[0]);
				for (int j=i; j<m; j++) {
					long long resres=min(sn1[i],a[0]);
					resres+=min(sn2[j]-sn2[i],a[1]);
					resres+=min(sr3[j+1],a[2]);
					res=max(resres,res);
					ans=max(res,ans);
				}
				ans=max(res,ans);
			}
			for (int i=0; i<m; i++) 
				ans=max(ans,min(sn2[i],a[1])+min(sr3[i+1],a[2]));
		}

		printf("Case #%d: %I64d\n",t+1,ans);

	}

	return 0;
}