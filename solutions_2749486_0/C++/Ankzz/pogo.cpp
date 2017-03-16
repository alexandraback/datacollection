#include <stdio.h>

#define SIZE 100

#if 0
#define IN	stdin
#define OUT	stdout
#else
#define IN	in
#define OUT	out
#endif

#define readi( x ) fscanf(IN, "%d", &x )
#define readf( x ) fscanf(IN, "%f", &x )
#define readc( x ) fscanf(IN, "%c", &x )
#define reads( x ) fscanf(IN, "%s", x  )
#define readll( x ) fscanf(IN, "%lld", &x )

#define read( x ) readi( x )

#define fi( n ) for(int i=0;i<n;i++)
#define fj( n ) for(int j=0;j<n;j++)

#define print( c ) fprintf(OUT, "Case #%d: ", c)
#define println    fprintf(OUT, "\n")

#define SET( N, pos ) ( ((unsigned long long)N)  \
						& (((unsigned long long)0x1)<<(pos-1)) )

void dfs(int v, int a[][SIZE], int reach[], int n)
{
	 static short flag = 0;
	 reach[v]=1;
	 fi(n)
	  if(a[v][i])
	  {
		if(!reach[i])   dfs(i,a,reach,n);
		else flag = 1;
	  }
}

int main(int argc, char *argv[])
{
	int T,c=0;

	FILE *in = fopen(argv[1], "r");
	FILE *out = fopen(argv[2], "w" );

	fscanf(IN, "%d", &T );

	while(++c<=T) {
		int x, y;
		int px=0, py=0, i=1,k=-1;
		char way[501],flag =0;
		read(x);
		read(y);

		if(x<0) { flag = 1; x = -x; }

		while( px != x ) {
			if( (px + i) <= x ) { px += i; way[++k] = (!flag)?'E':'W'; }
			else { px -= i; way[++k] = (!flag)?'W':'E';}
			i++;
		}

		flag = 0;
		if(y<0) { flag = 1; y = -y; }

		while( py != y ) {
			if( (py + i) <= y ) { py += i; way[++k] = (!flag)?'N':'S'; }
			else { py -= i; way[++k] = (!flag)?'S':'N';}
			i++;
		}

        way[++k] = '\0';
		print(c);
        fprintf(OUT, "%s", way);
		println;
	}

	if(in) fclose(in);
	if(out) fclose(out);
	return 0;
}