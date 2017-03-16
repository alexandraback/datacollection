#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>

using namespace std;

void Print( int now, int total,int M)
{
	if ( now == 1 ) 
	{
		printf("c");
		for ( int i = 1; i <= total - 1; ++i ) printf(".");
		for ( int i = 1; i <= M; ++i ) printf("*");
		printf("\n");
	}
	else{
		printf("c\n");
		for ( int i = 1; i <= total - 1; ++i ) printf(".\n");
		for ( int i = 1; i <= M; ++i ) printf("*\n");
	}

}

int main()
{
	freopen("C-small-attempt7.in","r",stdin);
	freopen("C-small-attempt7.out","w",stdout);

	int total,M,R,C,T;
	scanf("%d",&T);
	for ( int cas = 1; cas <= T; ++cas )
	{
		scanf ("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",cas);
		//printf("%d %d %d %d\n",R,C,M,R*C-M);
		total = R * C;
		if ( M >= total ) { printf("Impossible\n"); continue; }
		total = total - M;
		
		if ( R == 1 || C == 1 )
		{
			if ( R == 1 )
				Print(1,total,M);
			else Print(2,total,M);
			continue;
		}	

		

		//cout << '^' << endl;
		if ( total == 1 )
		{
			for ( int i =1; i <= R - 1; ++i ){
				for ( int j = 1; j <= C; ++j ) printf("*");
				printf("\n");
			}
			for ( int i = 1; i <= C -1 ; ++i ) printf("*");
			printf("c\n");
			continue;
		}
		
		if ( R == 2 || C == 2 )
		{
			if ( total % 2 == 1 ) {printf("Impossible\n"); continue; }
		}

		int flag = 0, x = 0, y = 0;

		for ( int i = 2; i <= R; ++i )
			if ( total % i == 0 && total / i <= C && total / i != 1 )
			{
				flag = 1;
				x = i;
				y = total / x;
				break;
			}
		//cout << "^^^" << endl;
		if( flag == 1 )
		{
			printf("c");
			for ( int i = 1; i <= y - 1; ++i ) printf(".");
			for ( int i = 1; i <= C - y; ++i ) printf("*");
			printf("\n");
		    for( int i = 1; i <= x - 1; ++i )
		    {
		    	for ( int j = 1; j <= y; ++j ) printf(".");
		    	for ( int j = 1; j <= C - y; ++j ) printf("*");
		    	printf("\n");
		    }
		    for ( int i = 1; i <= R - x; ++i )
		    {
		    	for ( int j = 1; j <= C; ++j ) printf("*");
		    	printf("\n");
		    }
		    continue;
		}
		int RR = R, CC = C, MM = M, Tot = total,now;
		//cout << "&&&&" << endl;
		//cout << RR << " " << CC << " " << Tot << endl;
		//cout << "!" << endl;
		now = RR * 2 + CC * 2 - 4;
		
		if ( now <= Tot )
		{
			
			RR -= 2; CC -= 2;  Tot -= now;
			
			//cout << "^%@@#@" << endl;

			while ( 1 )
			{
				if ( Tot > CC ) RR--, Tot -= CC;
				else break;
 			}

		    for ( int i = 1; i <= RR - 1; ++i ){
		    	for ( int j = 1; j <= CC; ++j ) printf("*");
		    	for ( int j = 1; j <= C - CC; ++j ) printf(".");
				printf("\n");
		    }
		    for ( int i = 1; i <= CC - Tot; ++i ) printf("*");
		    for ( int i = CC - Tot + 1; i <= C; ++i ) printf(".");
		    printf("\n");

			for ( int i = 1; i <= R - RR - 1; ++i ){
				for ( int j = 1; j <= C; ++j ) printf(".");
				printf("\n");
			}

			for ( int i = 1; i <= C - 1; ++i ) printf(".");
			printf("c\n");	
		    continue;
		}

		if ( total >= 8 )
		{
			total -= 8;
			int chu = total / 2, yu = total % 2;
			int Rx = R - 3, Cx = C - 3;
			if ( Cx < chu )
			{
				Rx -= ( chu - Cx );
				Cx = 0;
			}
			else Cx -= chu;

			for  ( int i = 1; i <= Rx; ++i ) {
				for ( int j = 1; j <= C; ++j )printf("*");
				printf("\n");
			}		
			
			for ( int i = 1; i <= R - Rx - 3; ++i ){
				for ( int j = 1; j <= C - 2; ++j ) printf("*");
				printf("..\n");
			}
			if ( yu == 1 ){
				for ( int i = 1; i <= C - 3; ++i ) printf("*");
				printf("...\n");;
			}
			else {
				for( int i = 1; i <= C - 2; ++i ) printf("*");
				printf("..\n");
			}

			for ( int j = 1; j <= Cx; ++j ) printf("*");
			for ( int j = 1; j <= C - Cx; ++j ) printf(".");
			printf("\n");
			for ( int j = 1; j <= Cx; ++j ) printf("*");
			for ( int j = 1; j <= C - Cx - 1; ++j ) printf(".");
			printf("c\n");
			continue;	
		}

		printf("Impossible\n");

	}
	return 0;
}