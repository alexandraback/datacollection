#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <memory>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
LL MAX (LL a, LL b){ return (a) > (b) ? (a) : (b); }
LL MIN (LL a, LL b){ return a < b ? a : b; }

LL L, X;
const int NN = 10000+10;
char ch[NN];
int rec;
int total_s;
int rec_s [100];

char dic[8][8] = {{0,1,2,3,4,5,6,7},
				  {1,4,3,6,5,0,7,2},
				  {2,7,4,1,6,3,0,5},
				  {3,2,5,4,7,6,1,0},
				  {4,5,6,7,0,1,2,3},
				  {5,0,7,2,1,4,3,6},
				  {6,3,0,5,2,7,4,1},
				  {7,6,1,0,3,2,5,4}};

void calc (){
	int now = 0;
	for (int i=0;i<L;i++){
		if (ch[i] == 'i')		now = dic[now][1];
		else if (ch[i] == 'j')	now = dic[now][2];
		else 					now = dic[now][3];
	}
	total_s = now;
	
	rec_s[0] = 0; rec_s[1] = now;
	int cnt = 1, s = now ;
	for ( ; s!=0;){
		s = dic[s][now]; cnt++;
		rec_s[cnt] = s;
	}
//	for (int i=0;i<cnt;i++)	printf ("%d **", rec_s[i]);	printf ("\n");
	rec = cnt;
}

int pre_s[NN], suf_s[NN];
int ss[1000];
bool ok[10][10][10][10];
bool half[10][10];

void calc2 (){
	ss['i'] = 1; ss['j'] = 2; ss['k'] = 3;
	pre_s[0] = ss[ ch[0] ];
	for (int i=1;i<L;i++){
//		printf ("AAA:%d %c\n",ss[ch[i]], ch[i]);
		pre_s[i] = dic[ pre_s[i-1] ][ ss[ch[i]] ];
	}	
/*
	for (int i=0;i<L;i++)	printf ("%d ",pre_s[i]);
	printf ("\n");
*/	
	suf_s[L] = 0;
	for (int i=L-1;i>=0;i--){
		suf_s[i] = dic[ ss[ch[i]] ][ suf_s[i+1] ];
	}
/*
	for (int i=0;i<L;i++)	printf ("%d ",suf_s[i]);
	printf ("\n");
*/
	
	memset (half, 0, sizeof(half));
	half[0][total_s] = 1;
//	printf ("%d %d\n",0 ,total_s);
	for (int i=0;i<L;i++){
		half[ pre_s[i] ][ suf_s[i+1] ] = 1;
//		printf ("%d %d\n",pre_s[i], suf_s[i+1]);
	}
	
	memset (ok, 0, sizeof(ok));
	
	for (int kk=0;kk<rec;kk++){
	for (int i=0;i<8;i++) for(int j=0;j<8;j++) for (int k=0;k<8;k++){ 
		for (int ii=0;ii<8;ii++) if(half[i][ii]){
			for (int jj=0;jj<8;jj++) if(half[jj][k] && dic[ dic[ii][rec_s[kk]] ][jj]==j ){
				ok[kk][i][j][k] = 1;
//				printf ("%d %d %d\n",i,j,k);
			}
		}
	}
	}
}

bool check (){
//	int total_ = MIN (3 * rec, X-2);
	LL left = X - 2;
//	printf ("AAAAAAAAAA:%d %d %d\n", total_, rec, ok[2][1][0]);
	for (int i=0;i<8;i++) for (int j=2;j<3;j++) for (int k=0;k<8;k++) for (int aj=0;aj<rec;aj++) if(ok[aj][i][j][k]){
		for (int ai=0;ai<rec;ai++) for (int ak=0;ak<rec;ak++) if (ai+aj+ak<=left && (left-ai-aj-ak)%rec==0){
			if (dic[ rec_s[ai] ][i]==1 && dic[k][rec_s[ak]]==3 ){
				return true;
			}
		}
	}
	return false;
}

int main (){
//	freopen ("F:\\C++\\C-large.in","r",stdin);
//	freopen ("F:\\C++\\C-large.out", "w", stdout);
	int T; scanf ("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf ("%lld%lld",&L,&X);
		scanf ("%s", ch);
		calc ();
		calc2 ();
		printf ("Case #%d: ",cas);
		if (X == 1){
			int low=0,high=L-1;
			for (;low<high && pre_s[low]!=1;low++);
			if (pre_s[low] != 1){
				printf ("NO\n");	continue;
			}
			for (;low<high && suf_s[high]!=3;high--);
			if (suf_s[high] != 3){
				printf ("NO\n");	continue;
			}
			int tt = 0;
			for (low++; low<high; tt=dic[tt][ss[ch[low]]], low++);
			if (tt == 2)	printf ("YES\n");
			else			printf ("NO\n");
			continue;
		}
		// TODO X == 1
		
		if (check ())	printf ("YES\n");
		else			printf ("NO\n");
	}
	return 0;
}