#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define FOR(i,n) for(int i=0;i<n;++i)

#include <unordered_set>

using namespace std;



int main(void) {
	int t;
	scanf("%d",&t);
	FOR(aaa,t) {
		int k,l,s;
		scanf("%d%d%d",&k,&l,&s);
		char alfa[200], res[200];
		int jump[200];
		scanf("%s\n%s\n",alfa,res);
		
		
		//printf("%d %d %d\n",k,l,s);
		//printf("%s\n%s\n",alfa,res);
		
		
		
		jump[0]=-1;
		for(int i=0,j=-1;i<l;++j,++i,jump[i]=j) {
            while(j!=-1 && res[i]!=res[j]) j=jump[j];
        }
        jump[0]=-1;
		
		bool consist_of_one_char = true;
		FOR(i,l-1) {
			consist_of_one_char = consist_of_one_char && (res[i]==res[i+1]);
		}
		
		//printf("%d\n",consist_of_one_char);
		
        //FOR(i,l) printf("%d %d\n",i,jump[i]);
        
        
        double probability[30];
		FOR(i,30) probability[i]=0;
		
		FOR(i,k) ++probability[alfa[i]-'A'];
		FOR(i,30) probability[i]/=k;
		
		//FOR(i,l) printf("%lf\n",probability[res[i]-'A']);
		
		int max_count=0;
		int j=0;
		FOR(i,s) {
			if(probability[res[j]-'A']>0) {
				j+=1;
				if(j==l) {
					++max_count;
					j = consist_of_one_char?j-1:jump[j];
				}
			}
			else j=0;
		}
		//printf("%d\n",max_count);
		
		

        double memo[2][150];
		FOR(i,2) FOR(j,150) memo[i][j]=0;
		memo[0][0] = 1;
		
		double ans=0;
		
		int curr=0;
		FOR(rounds,s) {
			/*
			FOR(i,3) {
				printf("%lf ",memo[curr][i]);
			}
			printf("\n");
			*/
			
			
			int other=curr^1;
			FOR(i,150) memo[other][i]=0;
			FOR(i,l-1) {
				for(char x='A';x<='Z';++x) {
					int pos;
					if(x==res[i]) pos=i+1;
					else {
						pos = i;
						while(pos!=-1 && res[pos]!=x) pos = jump[pos];
						++pos;
					}
					//int pos = x==res[i]?i+1:jump[i];
					memo[other][pos]+=probability[x-'A']*memo[curr][i];
				}
			}
			for(char x='A';x<='Z';++x) {
				if(x==res[l-1]) {
					ans+=probability[x-'A']*memo[curr][l-1];
					//printf("ans: %.20lf\n",probability[x-'A']*memo[curr][l-1]);
				}
				// vyskyyt
				//int neww = consist_of_one_char?l-1:jump[l-1];
				int neww;
				if(consist_of_one_char) neww=l-1;
				else {
					neww = jump[l-1];
					while(neww!=-1 && res[neww]!=x) neww = jump[neww];
					++neww;
				}
				memo[other][neww]+=probability[x-'A']*memo[curr][l-1];
			}
			curr^=1;
		}
		printf("Case #%d: %.20lf\n",aaa+1,max_count-ans);
	}
}