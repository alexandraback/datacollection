#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>

#define maxdim 2000005
#define maxdays 700000
#define inf (1<<30)

using namespace std;

FILE*f=fopen("tractor.in","r");
FILE*g=fopen("tractor.out","w");

int n,a,b,val,minim;
int X[maxdim],x;
vector< pair< pair<int,int> , int> >E[maxdays+5];

struct segment_tree{
	int ad,minim;
}Arb[4*maxdim];

inline void get_events () {
	
	fscanf(f,"%d",&n);
	
	for ( int j = 1 ; j <= n ; ++j ){
		
		int day,atacuri,st,dr,putere,d_day,d_st,d_putere;
		fscanf(f,"%d %d %d %d %d %d %d %d",&day,&atacuri,&st,&dr,&putere,&d_day,&d_st,&d_putere);
		for ( int i = 1 ; i <= atacuri ; ++i ){
			E[day].push_back(make_pair(make_pair(st,dr),putere));
			X[++x] = st; X[++x] = dr;
			day += d_day;
			st += d_st; dr += d_st;
			putere += d_putere;
		}
	}
}

inline void normalizare () {
	
	sort(X+1,X+x+1);
	x = unique(X+1,X+x+1) - X - 1;
}

inline void propaga ( int nod , int nodst , int noddr ){
	Arb[nodst].ad = max(Arb[nodst].ad, Arb[nod].ad);
	Arb[noddr].ad = max(Arb[noddr].ad, Arb[nod].ad);

//
	if ( Arb[nodst].minim < Arb[nod].ad ){
		Arb[nodst].minim = Arb[nodst].ad;
	}
	if ( Arb[noddr].minim < Arb[nod].ad ){
		Arb[noddr].minim = Arb[noddr].ad;
	}
	if ( Arb[nodst].minim < Arb[nodst].ad ){
		Arb[nodst].minim = Arb[nodst].ad;
	}
	if ( Arb[noddr].minim < Arb[noddr].ad ){
		Arb[noddr].minim = Arb[noddr].ad;
	}


	Arb[nod].minim = min(Arb[noddr].minim,Arb[nodst].minim);
}

void update ( int nod , int st , int dr ){
	
	if ( a <= st && dr <= b ){
		
		Arb[nod].ad = max(Arb[nod].ad,val);
		Arb[nod].minim = Arb[nod].ad;
		
		return ;
	}
	
	int mij = (st + dr)>>1;
	int nodst = nod<<1;
	int noddr = nodst|1;
	
	propaga(nod,nodst,noddr);
	
	if ( a <= mij ){
		update(nodst,st,mij);
	}
	if ( b > mij ){
		update(noddr,mij+1,dr);
	}
	
	Arb[nod].minim = min(Arb[nodst].minim,Arb[noddr].minim);
}

void query ( int nod , int st , int dr ){
	
	if ( a <= st && dr <= b ){
		minim = min(minim,Arb[nod].minim);
		return ;
	}
	
	int mij = (st + dr)>>1;
	int nodst = nod<<1;
	int noddr = nodst|1;
	
	propaga(nod,nodst,noddr);
	
	if ( a <= mij ){
		query(nodst,st,mij);
	}
	if ( b > mij ){
		query(noddr,mij+1,dr);
	}
	
	Arb[nod].minim = min(Arb[nodst].minim,Arb[noddr].minim);
}

inline int solve () {
	
	get_events();
	normalizare();
	
	int sol = 0;
	for ( int day = 0 ; day <= maxdays ; ++day ){
		
		for ( vector< pair< pair<int,int> , int > >::iterator itt = E[day].begin() ; itt != E[day].end() ; ++itt ){
			a = lower_bound(X+1,X+x+1,itt->first.first) - X,b = lower_bound(X+1,X+x+1,itt->first.second) - X - 1;
			val = itt->second; minim = inf;
			query(1,1,x);
			
			if ( minim < val )	++sol;
		}
		
		for ( vector< pair< pair<int,int> , int > >::iterator itt = E[day].begin() ; itt != E[day].end() ; ++itt ){
			a = lower_bound(X+1,X+x+1,itt->first.first) - X,b = lower_bound(X+1,X+x+1,itt->first.second) - X - 1;
			val = itt->second;
			update(1,1,x);
		}
	}
	
	return sol;
}

inline void curata () {
	
	for ( int day = 0 ; day <= maxdays ; ++day ){
		E[day].clear();
	}
	for ( int i = 1 ; i < 4*maxdim ; ++i ){
		Arb[i].ad = Arb[i].minim = 0;
	}
	x = 0;
}

int main () {
	
	int t;
	fscanf(f,"%d",&t);
	for ( int ii = 1 ; ii <= t ; ++ii ){
	
		fprintf(g,"Case #%d: %d\n",ii,solve());
		fprintf(stderr, "1");
		curata();
	}
	
	
	
	fclose(f);
	fclose(g);
	
	return 0;
}
