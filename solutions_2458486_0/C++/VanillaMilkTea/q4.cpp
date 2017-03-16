#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

#define _USE_MATH_DEFINES
#define NUM_ARR 39

using namespace std;

typedef unsigned long long ull;

int N=0;
int locks[201];
int unlock[201][201];
int nkeys[201][401];
int tkeys[201][401];

int ter=0;
int arr[401],inarr[401];
int cnkeys[401];
vector< int > kk;

void addKey(int tar,int num){
	if(cnkeys[tar]==0)
		kk.push_back(tar);
	cnkeys[tar]+=num;
}

void subKey(int tar,int num){
	cnkeys[tar]-=num;
	if(cnkeys[tar]<0) printf("error!!!\n");
	if(cnkeys[tar]==0)
		kk.erase(find(kk.begin(),kk.end(),tar));
}

void recur(int arr[401],int len){
	int i=0,j=0,k=0,tmpkey=0,chest=0,tmp=0,tmp2=0;
	//printf("len %d: 0",len);
	//for(i=1;i<=len;i++) printf(" %d",arr[i]);//printf("\n");
	//for(i=0;i<kk.size();i++) printf("key %d num %d\n",kk[i],cnkeys[kk[i]]);
	//getchar();

	if(ter) return;
	if(len==N){
		ter=1;
		return;
	}

	//for(i=0;i<kk.size();i++){
	for(chest=1;chest<=N;chest++){
		if(inarr[chest]) continue;
		for(i=0;i<kk.size();i++){
			if(kk[i]==locks[chest]){
				break;
			}
		}
		if(i==kk.size()) continue;
		tmpkey=kk[i];

		
		if((cnkeys[tmpkey]==1)&&(nkeys[chest][tmpkey]==0)){
			tmp=0;tmp2=0;
			for(i=1;i<=N;i++){
				if(i==chest) continue;
				if(inarr[i]) continue;
				if(locks[i]==tmpkey)
					tmp++;
				else 
					tmp2+=nkeys[i][tmpkey];
			}
			//tmp=(cnkeys[tmpkey]-1+nkeys[chest][tmpkey])-(tmp-1);
			//printf("tmp = %d\n",tmp);getchar();
			if((tmp>0)&&(tmp2==0)) continue;
			//if((tmp>0)&&(nkeys[chest][tmpkey]==0))continue;
		}
		//if(tmp<0) continue;

//		for(j=1;j<=unlock[kk[i]][0];j++){
//			chest=unlock[kk[i]][j];
			arr[len+1]=chest;
			inarr[chest]=1;
			
			subKey(tmpkey,1);
			for(k=1;k<=tkeys[chest][0];k++)
				addKey(tkeys[chest][k],nkeys[chest][tkeys[chest][k]]);
			sort(kk.begin(),kk.end());
			recur(arr,len+1);
			//if(ter) return;

			for(k=1;k<=tkeys[chest][0];k++)
				subKey(tkeys[chest][k],nkeys[chest][tkeys[chest][k]]);
			addKey(tmpkey,1);
			sort(kk.begin(),kk.end());
			inarr[chest]=0;
//		}
			//printf("len = %d\n",len);
			//for(i=0;i<kk.size();i++) printf("key %d num %d\n",kk[i],cnkeys[kk[i]]);
		if(ter) return;
	}
}

int main(int argc,char **argv){
	FILE *fin,*fout,*fchk;
	int cases=0;
	int K=0;
	int c=0,i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	int tmp=0,tmp2=0,skip=0;
	int check[401];

	fin =fopen("D-small-attempt3.in","rt");
	fout=fopen("D-small-attempt3.out","wt");
	fchk=fopen("check.out","wt");
		
	fscanf(fin,"%d\n",&cases);
	fprintf(fchk,"%d\n",cases);
	for(c=1;c<=cases;c++){
		fprintf(fout,"Case #%d: ",c);
		fprintf(fchk,"Case #%d:\n",c);
		printf("Case #%d\n",c);

		memset(locks,0x0,201*sizeof(int));
		memset(tkeys,0x0,201*401*sizeof(int));
		memset(nkeys,0x0,201*401*sizeof(int));
		memset(check,0x0,401*sizeof(int));
		memset(unlock,0x0,201*201*sizeof(int));

		fscanf(fin,"%d %d",&K,&N);
		fprintf(fchk,"%d %d\n",K,N);

		for(i=0;i<K;i++){
			fscanf(fin,"%d",&tmp);
			fprintf(fchk,"%d ",tmp);
			nkeys[0][tmp]++;
			if(!check[tmp]){
				tkeys[0][0]++;
				tkeys[0][tkeys[0][0]]=tmp;
				check[tmp]=1;
			}
		}
		fprintf(fchk,"\n");
		for(i=1;i<=N;i++){
			memset(check,0x0,401*sizeof(int));
			fscanf(fin,"%d %d",&(locks[i]),&K);
			fprintf(fchk,"%d %d ",locks[i],K);
			for(j=0;j<K;j++){
				fscanf(fin,"%d",&tmp);
				fprintf(fchk,"%d ",tmp);
				nkeys[i][tmp]++;
				if(!check[tmp]){
					tkeys[i][0]++;
					tkeys[i][tkeys[i][0]]=tmp;
					check[tmp]=1;
				}
			}
			fprintf(fchk,"\n");
		}
		/*
		for(i=0;i<=N;i++){
			printf("chest %d:\n",i);
			for(j=1;j<=tkeys[i][0];j++)
				printf("keys %d num %d\n",tkeys[i][j],nkeys[i][tkeys[i][j]]);
		}
		*/
		fprintf(fchk,"\n");
		for(i=1;i<=N;i++){
			for(j=1;j<=N;j++){
				if(locks[j]==i){
					unlock[i][0]++;
					unlock[i][unlock[i][0]]=j;
				}
			}
		}

		skip=0;
		//
		for(i=1;i<=N;i++){
			tmp=0;tmp2=nkeys[0][i];
			//if(c==4)printf("%d = %d\n",nkeys[0][i],nkeys[0][i]);
			for(j=1;j<=N;j++){
				if(locks[j]==i)tmp++;
				tmp2+=nkeys[j][i];
				//if(c==4)printf("nkeys[%d][%d] = %d\n",j,i,nkeys[j][i]);
			}
			//if(c==1) printf("%d %d\n",tmp,tmp2);
			if(tmp>tmp2) {
				//if(c==1) printf(" fail: %d %d\n",tmp,tmp2);
				printf("skip %d: %d %d\n",i,tmp,tmp2);
				fprintf(fout,"IMPOSSIBLE\n");
				skip=1;
				break;
			}
		}
		//
		
		if(!skip){
		memset(arr,0x0,401*sizeof(int));
		memset(inarr,0x0,401*sizeof(int));
		memset(cnkeys,0x0,401*sizeof(int));
		ter=0;
		kk.clear();

		for(i=1;i<=tkeys[0][0];i++){
			kk.push_back(tkeys[0][i]);
			sort(kk.begin(),kk.end());
			cnkeys[tkeys[0][i]]=nkeys[0][tkeys[0][i]];
		}

		recur(arr,0);

		if(ter){
			fprintf(fout,"%d",arr[1]);
			for(i=2;i<=N;i++)
				fprintf(fout," %d",arr[i]);
			fprintf(fout,"\n");
		}
		else fprintf(fout,"IMPOSSIBLE\n");
		}
		//fprintf(fout,"\n");
	}
		
	fclose(fin);
	fclose(fout);
	fclose(fchk);
	//

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}