#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int tab[5][5];
int sign[5][5];
void przypisz(int nr,int a,int b,int c,int d,int e){
	tab[nr][0]=a,tab[nr][1]=b,tab[nr][2]=c,tab[nr][3]=d,tab[nr][4]=e;
}
void przyp1(int nr,int a,int b,int c,int d,int e){
	sign[nr][0]=a,sign[nr][1]=b,sign[nr][2]=c,sign[nr][3]=d,sign[nr][4]=e;
}
void ustaw(){
	//1 - 1, 2 - I, 3 - J, 4 - K
	przypisz(1, 0,1,2,3,4);
	przyp1(1, 1,1,1,1,1);
	przypisz(2, 0,2,1,4,3);
	przyp1(2, 1,1,-1,1,-1);
	przypisz(3, 0,3,4,1,2);
	przyp1(3, 1,1,-1,-1,1);
	przypisz(4, 0,4,3,2,1);
	przyp1(4, 1,1,1,-1,-1);
}
void transponuj(){
	for(int i=1;i<=4;i++)
		for(int j=1;j<i;j++)
			swap(tab[i][j],tab[j][i]),swap(sign[i][j],sign[j][i]);
}

typedef pair<int,int> PII;
PII mnoz(PII x,PII y){
	return make_pair(tab[x.first][y.first],
		sign[x.first][y.first]*x.second*y.second);
}


int used[5][5];
const int MAXN=10111;
char a[MAXN];
int val[MAXN];

void czysc(){
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			used[i][j]=0;
}
void obroc(int l){
	reverse(a+1,a+l+1);
	reverse(val+1,val+l+1);
}
main(){
	int test;scanf("%d",&test);
	ustaw();
	for(int tnr=1;tnr<=test;tnr++){
		LL l,x;scanf("%lld%lld",&l,&x);
		scanf("%s",a+1);
		PII iloczyn=make_pair(1,1);
		for(int i=1;i<=l;i++){
			val[i]=(a[i]=='1')?1:(a[i]=='i')?2:(a[i]=='j')?3:4;
			PII ob=make_pair(val[i],1);
			iloczyn=mnoz(iloczyn,ob);
			//printf("%c %d, %d %d:: %d %d\n",
			//a[i],val,ob.first,ob.second,
			//iloczyn.first,iloczyn.second);
		}
		PII obe=make_pair(1,1),pote=iloczyn;
		LL x1=x;
		//printf("%d %d\n",iloczyn.first,iloczyn.second);
		while(x1>0){
			if(x1%2) obe=mnoz(obe,pote);
			pote=mnoz(pote,pote);
			x1/=2;
		}
		int answer=1;
		if(obe!=make_pair(1,-1)) answer=0;
		//printf("A %d %d %d\n",obe.first,obe.second,answer);
		czysc();
		PII cel=make_pair(2,1);
		PII st=make_pair(1,1);
		LL odl1=0;
		int ok1=0;
		while(true){
			if(used[st.first][st.second+1]) break;
			used[st.first][st.second+1]=1;
			for(int i=1;i<=l;i++){
				PII ob=make_pair(val[i],1);
				st=mnoz(st,ob);
				odl1++;
				if(st==cel){ok1=1;break;}
				//printf("%c %d, %d %d:: %d %d\n",
				//a[i],val,ob.first,ob.second,
				//iloczyn.first,iloczyn.second);
			}
			if(ok1) break;
		}
		//printf("B %d %lld\n",ok1,odl1);
		if(!ok1) answer=0;
		czysc();
		transponuj();
		obroc(l);
		
		
		cel=make_pair(4,1);
		st=make_pair(1,1);
		LL odl2=0;
		int ok2=0;
		while(true){
			if(used[st.first][st.second+1]) break;
			used[st.first][st.second+1]=1;
			for(int i=1;i<=l;i++){
				PII ob=make_pair(val[i],1);
				st=mnoz(st,ob);
				odl2++;
				if(st==cel){ok2=1;break;}
				//printf("%c %d, %d %d:: %d %d\n",
				//a[i],val,ob.first,ob.second,
				//iloczyn.first,iloczyn.second);
			}
			if(ok2) break;
		}
		if(!ok2) answer=0;
		
		//printf("C %d %lld\n",ok2,odl2);
		czysc();
		transponuj();
		if(odl1+odl2>=x*l) answer=0;
		
		printf("Case #%d: ",tnr);
		puts(answer?"YES":"NO");
	}
}

	
	
