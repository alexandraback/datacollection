#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <vector>
#include <map>

using namespace std;

typedef struct{
	char s[6];
}ZIP;

#define FCODE(i,j) ((i)*128+(j))

ZIP zips[100];
map<int,int> flights;
char min_str[5*100];

int f_avail(int i,int j){
	return flights.find(FCODE(i,j))!=flights.end();
}

void check(int N,int *route)
{
	// sanity check
	int current;
	int fs[100];//flight stack
	int fssize;
	int start;
	int i;
	fssize=0;
	current=route[0];
	start=route[0];
	int r_idx=1;
	while (1){
		if (r_idx==N)break;
try_flight:;
		// 現在地から次に直接飛べるかチェック
		if (f_avail(current,route[r_idx])){
			// outbound flightを行う
			fs[fssize]=current;
			fssize++;
			current=route[r_idx];
			r_idx++;
		}
		else{
			// stackがなくなったならこのルートはありえない
			if (fssize==0)goto ans_no;
			// stackをさかのぼる
			fssize--;
			current=fs[fssize];
			goto try_flight;
		}
		//if (r_idx==N)break;
	}
ans_yes:;
/*	for (i=0;i<N;i++){
		fprintf(stderr,"%d ",route[i]);
	}
	fprintf(stderr,": Possible ");*/
	char str[100];
	strcpy(str,"");
	for (i=0;i<N;i++){
		strcat(str,zips[route[i]].s);
	}
	//fprintf(stderr,"%s\n",str);
	if (strcmp(min_str,"")==0 || strcmp(min_str,str)>0)strcpy(min_str,str);
	return;
ans_no:;
	/*for (i=0;i<N;i++){
		fprintf(stderr,"%d ",route[i]);
	}
	fprintf(stderr,": Impossible\n");*/
	return;
}

int search(int N, int idx, int *route, int *occupied)
{
	int i;
	if (idx==N){
		/*for (i=0;i<N;i++){
			fprintf(stderr,"%d ",route[i]);
		}
		fprintf(stderr,"\n");*/
		check(N,route);
		return 0;
	}
	// occupiedがついてないところ全部に再帰
	for (i=0;i<N;i++){
		if (!occupied[i]){
			occupied[i]=1;
			route[idx]=i;
			search(N,idx+1,route,occupied);
			route[idx]=-1;
			occupied[i]=0;
		}
	}
	return 0;
}

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		int N,M;
		int i;
		scanf("%d %d\n",&N,&M);
		flights.clear();
		memset(zips,0,sizeof(zips));
		for (i=0;i<N;i++){
			scanf("%s\n",zips[i].s);
		}
		for (i=0;i<M;i++){
			int fi,fj;
			scanf("%d %d\n",&fi,&fj);
			flights[FCODE(fi-1,fj-1)]=1;
			flights[FCODE(fj-1,fi-1)]=1;
		}
		// 候補を出す
		int route[100],occupied[100];
		memset(route,0,sizeof(route));
		memset(occupied,0,sizeof(occupied));
		strcpy(min_str,"");
		search(N,0,route,occupied);
		printf("Case #%d: %s\n",t,min_str);
	}
	return 0;
}
