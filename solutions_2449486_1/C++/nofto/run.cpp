#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;


int main()
{
	int T;
	scanf("%d\n",&T);  
	for(int t=1; t<=T; t++)
	{
		int N;
		int M;
		int a[100][100];
		int rowmax[100];
		int colmax[100];
		scanf("%d %d\n",&N,&M);
		for(int i=0;i<N;i++) rowmax[i]=0;
		for(int j=0;j<M;j++) colmax[j]=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&a[i][j]);
				rowmax[i]=max(rowmax[i],a[i][j]);
				colmax[j]=max(colmax[j],a[i][j]);
			}
			scanf("\n");
	    }
	    bool dasa=true;
		for(int i=0;i<N && dasa;i++){
			for(int j=0;j<M;j++){
		        if(a[i][j]!=min(rowmax[i],colmax[j])){
		            dasa=false;
					break;
		        }
			}
		}
	    if(dasa) printf("Case #%d: YES\n",t);
	    else printf("Case #%d: NO\n",t);
	}

  
  return 0;
}
