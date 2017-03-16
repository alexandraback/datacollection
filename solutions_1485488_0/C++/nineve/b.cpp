#include <iostream>
#include <cstdio>
using namespace std;

#define maxn 102
#define maxm 102
#define heapsize (maxn*maxm)
#define GETETIME(x) etime[row[x]][col[x]]
#define INF (1e10)
#define eps (1e-10)


int H,N,M;
int F[maxn][maxm];
int C[maxn][maxm];
double etime[maxn][maxm];	//earliest time

int pos2heap[maxn][maxm];	//position in heap

//heap
int row[heapsize];
int col[heapsize];
int hsize;


void swap(int i,int j){	//swap 2 elements in heap
	int tmp;
	tmp=row[i]; row[i]=row[j]; row[j]=tmp;
	tmp=col[i]; col[i]=col[j]; col[j]=tmp;
	pos2heap[row[i]][col[i]]=i;
	pos2heap[row[j]][col[j]]=j;
}

void heap_down(int v){
	int p = v;
	int c = p*2;
	while(c<hsize){
		if(    ( c+1<hsize )
		    && ( GETETIME(c+1) < GETETIME(c) ) ){
			//c+1 is better than c
			c++;
		}
		if (GETETIME(c) < GETETIME(p)){
			swap(c,p);
		}else{
			return;
		}
		p = c;
		c = p*2;
	}
}

void heap_up(int v){
	int c = v;
	int p;
	while(c>0){
		p = (c-1)/2;
		if(GETETIME(c) < GETETIME(p)){
			swap(c,p);
		}else{
			return;
		}
		c = p;
	}
}

double heap_updown(int v){
	if(v==0){
		heap_down(v);
	}else{
		heap_up(v);
		heap_down(v);
	}
}


double heap_pop(){
	double ret = etime[row[0]][col[0]];
	pos2heap[row[0]][col[0]] = -1;
	hsize--;
	row[0] = row[hsize];
	col[0] = col[hsize];
	pos2heap[row[0]][col[0]]=0;
	heap_down(0);
	return ret;
}

void flood(int r,int c);
void check(int r,int c,int tor,int toc){
	if(tor<0 || toc<0 || tor>=N || toc>=M)
		return;
	if(C[r][c] - F[tor][toc] < 50) return;
	if(C[tor][toc] - F[tor][toc] < 50) return;
	if(C[tor][toc] - F[r][c] < 50) return;
	if(C[tor][toc] - H < 50) return;
	flood(tor,toc);
}

void flood(int r,int c){
	if(etime[r][c] < eps)
		return;
	etime[r][c] = 0;
	check(r,c,r-1,c);
	check(r,c,r+1,c);
	check(r,c,r,c-1);
	check(r,c,r,c+1);
}

double max(double a,double b){
	if(a>b)return a;
	return b;
}

void getto(int r,int c,int tor,int toc,double time){
	if(C[r][c] - F[tor][toc] < 50) return;
	if(C[tor][toc] - F[tor][toc] < 50) return;
	if(C[tor][toc] - F[r][c] < 50) return;
    double artime;
	if(C[tor][toc] - max(0,H-10*time) >= 50){
		//if can go, then go
		artime = time;
	}else{
		//else, check if can wait to water level down
		if(C[tor][toc] - 0 < 50) return;
		artime = ( H - (C[tor][toc]-50) )/10.0;
	}
	if(max(0,H-10*artime) - F[r][c] >= 20){
		artime += 1;
	}else{
		artime += 10;
	}
	if(artime < etime[tor][toc]){
		etime[tor][toc] = artime;
		heap_updown(pos2heap[tor][toc]);
	}
}

double solveone(){
	scanf("%d%d%d",&H,&N,&M);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&C[i][j]);
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			scanf("%d",&F[i][j]);


	//init etime:
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			etime[i][j]=INF;
	//find states can get at time 0
	flood(0,0);
	hsize = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++){
			row[hsize] = i;
			col[hsize] = j;
			pos2heap[i][j] = hsize;
			hsize++;
			heap_up(hsize-1);
		}

	while(hsize>0){
		int r = row[0];
		int c = col[0];
		heap_pop();
		if(r==N-1 && c==M-1)
			break;
		getto(r,c,r-1,c,etime[r][c]);
		getto(r,c,r+1,c,etime[r][c]);
		getto(r,c,r,c-1,etime[r][c]);
		getto(r,c,r,c+1,etime[r][c]);
	}

	return etime[N-1][M-1];
}


int main(){
	int T;
	scanf("%d",&T);
	for(int I=0;I<T;I++){
		printf("Case #%d: %.8lf\n",I+1,solveone());
	}

	//test:
	// hsize = 1;
	// row[0]=0;
	// col[0]=0;
	// row[1]=0;
	// col[1]=1;
	// etime[0][0]=1.2;
	// etime[0][1]=3;
	// printf("%lf\n",GETETIME(0+1));


	return 0;
}
