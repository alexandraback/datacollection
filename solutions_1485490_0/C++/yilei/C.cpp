#include <iostream>
#include <cstring>

using namespace std;


int n,m;

int a[105], b[105];
long long na[105], nb[105];

long long f[105][105];


void solve(int p, int q)
{
	if(p==0 && q==0){
		//cout <<f[p][q]<<endl;
	}
	if(f[p][q]!=-1) return;

	long long maxans = 0;

	long long cna[105], cnb[105];
	memset(cna, 0, sizeof(cna));
	

	for(int i=p; i<n; i++){
		cna[a[i]] += na[i];
		memset(cnb, 0, sizeof(cnb));
		long long common = -1;
		for(int j=q; j<m; j++){
			cnb[b[j]] += nb[j];

			if(cnb[b[j]]>0 && cna[b[j]]>0){
				common = max(common, min(cna[b[j]], cnb[b[j]]));
			}
			solve(i+1, j+1);

			if(common!=-1) maxans = max(maxans, f[i+1][j+1]+common);
			else maxans = max(maxans, f[i+1][j+1]);
		}
	}
	/*
	sumb = 0;
	for(int j=q+1; j<m; j++){
		solve(p+1, j);
		if(a[p]==b[j]){
			sumb += nb[j];
			maxans = max(maxans, f[p+1][j+1]+min(na[p], sumb));
		}
	}
	suma = 0;
	for(int i=p+1; i<n; i++){
		solve(i, q+1);
		if(a[i]==b[q]){
			suma += na[i];
			maxans = max(maxans, f[i+1][q+1]+min(nb[q], suma));
		}
	}
	if(a[p]==b[q]){
		maxans = max(maxans, f[p+1][q+1]+min(na[p], nb[q]));
	}
	*/
	//printf("f[%d][%d] = %d\n", p, q, maxans);
	
	f[p][q] = maxans;
	
}
int main(){
	int cs;

	//freopen("output", "w", stdout);

	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>na[i]>>a[i];
		for(int i=0;i<m;i++)
			cin>>nb[i]>>b[i];

		/*
		bool flag = true;
		while(flag){
			flag = false;
			for(int i=1;i<n;i++){
				if(a[i]==a[i-1]){
					na[i-1] += na[i];
					for(int j=i; j<n-1; j++){
						na[j] = na[j+1];
						a[j] = a[j+1];
					}
					flag = true;
					n--;
					break;
				}
			}
		}
		flag = true;
		while(flag){
			flag = false;
			for(int i=1;i<m;i++){
				if(b[i]==b[i-1]){
					nb[i-1] += nb[i];
					for(int j=i; j<m-1; j++){
						nb[j] = nb[j+1];
						b[j] = b[j+1];
					}
					flag = true;
					m--;
					break;
				}
			}
		}
		*/


		memset(f, -1, sizeof(f));

		for(int i=0;i<n;i++) f[i][m] = 0;
		for(int j=0;j<m;j++) f[n][j] = 0;

		//cout << n <<" "<< m <<endl;

		if(a[n-1]==b[m-1]){
			f[n-1][m-1] = min(na[n-1], nb[m-1]);
		}else{
			f[n-1][m-1] = 0;
		}

		//printf("f[%d][%d] = %d\n", n-1, m-1, f[n-1][m-1]);

		int i,j;
		bool sd = 0;
		i=n-1; j=m-1;
		while(1){
			if(!sd && i>0){
				sd = !sd;
				i--;
			}else if(sd && j>0){
				sd = !sd;
				j--;
			}else if(i==0 && j>0){
				j--;
			}else if(j==0 && i>0){
				i--;
			}else if(i==0 && j==0){
				break;
			}
			solve(i,j);
		}

		printf("%lld\n", f[0][0]);
	}
	return 0;
}