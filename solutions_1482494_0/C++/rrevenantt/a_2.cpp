#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int h=0;
	scanf("%d\n",&h);
	for(int t=0;t<h;t++){
		int n;
		scanf("%d",&n);
		int *a = new int[n];
		int *b = new int[n];
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&a[i],&b[i]);
		}
		int stars = 0;
		int levels = 0;
		int newlevel = 0;
		int games = 0;
		while (levels < n){
			newlevel = 0;
			for(int i=0;i<n;i++){
				if(b[i]<=stars && b[i]!=-1) {
					levels++;
					if(a[i]==-1)
						stars+=1;
					else stars+=2;
					b[i]=-1;
					newlevel=1;
					games++;
					
				}
			}
			if(newlevel==1) continue;
			int max = -1;
			int maxi = -1;
			for(int i=0;i<n;i++){
				if(b[i]!=-1 && a[i]!=-1 && b[i]>max && a[i]<=stars)
					max = b[i],maxi=i;
			}
			if(maxi!=-1){ a[maxi]=-1; stars+=1; newlevel=1; games++;}
			if(newlevel == 0) { break;}
		}
		if(newlevel == 0) printf("Case #%d: Too Bad\n",t+1);
		else printf("Case #%d: %d\n",t+1,games);
	}
	return 0;
}