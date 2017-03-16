#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 11111
#define LEN 1111

char strNumber1[LEN];
char resultStr[N][LEN];
int resultCount;

char startNum[LEN], endNum[LEN];

FILE *fin = fopen ( "input.txt", "r" );
FILE *fout = fopen ( "output.txt", "w" );

void getResult( int maxLength );
void getFairAndSquare( int length, int position );
char* getStrSquare(char *str);
bool checkPalindrome( char *str);

void input();
void output ( int t );

int main()
{
	int i, T;
	getResult( 10 );

	fscanf( fin, "%d", &T );
	for ( i=0; i<T; i++ )
	{
		input();
		output(i);
	}
	return 0;
}

void getResult( int maxLength )
{
	int i, j, k, frontPos, backPos;
	for ( i=1; i<=maxLength; i++ )
	{
		strNumber1[i] = '\0';
		getFairAndSquare( i, 0 );
	}
}
void getFairAndSquare( int length, int position )
{
	int k;
	char *strSquare;
	if ( position > length-position-1 )
	{
		strSquare = getStrSquare( strNumber1 );
		if ( checkPalindrome( strSquare ) )
		{
			strcpy( resultStr[resultCount++], strSquare );
		}
		return;
	}
	for ( k=0; k<=9; k++ )
	{
		if ( position == 0 && k == 0 ) continue;

		strNumber1[position] = strNumber1[length-position-1] = k+'0';
		getFairAndSquare( length, position+1 );
	}
}
char* getStrSquare(char *str)
{
	int i, j, len;
	char *returnStr;
	int temp[LEN];

	len = strlen ( str );
	strrev( str );
	returnStr = (char *)malloc( sizeof ( char ) * len*3 );

	memset ( temp, 0x00, sizeof ( temp ) );

	for ( i=0; i<len; i++ )
	{
		for ( j=0; j<len; j++ )
		{
			temp[i+j] += (str[i]-'0')*(str[j]-'0');
//			returnStr[i+j] = 
		}
	}

	for ( i=0; i<len*2; i++ )
	{
		temp[i+1] += temp[i]/10;
		temp[i] = temp[i]%10;
		returnStr[i] = temp[i]+'0';
	}
	returnStr[len*2]='\0';
	len = strlen( returnStr );
	for ( i=len-1; i>=0; i-- )
	{
		if ( returnStr[i] == '0')
		{
			returnStr[i] = '\0';
		}
		else
		{
			break;
		}
	}

	strrev( str );
	strrev( returnStr );
	return returnStr;

}

bool checkPalindrome( char *str)
{
	int i, len;
	len = strlen ( str );
	for ( i=0;; i++ )
	{
		if ( i >= len-i-1 ) break;
		if ( str[i] != str[len-i-1])
		{
			return false;
		}
	}
	return true;
}

void input()
{
	fscanf( fin, "%s%s", &startNum, &endNum );
}
void output ( int t )
{
	int i, startPosition = -1, endPosition = -1;
	int startLen, endLen, len;

	startLen = strlen ( startNum );
	endLen = strlen ( endNum );
	for ( i=0; i<resultCount; i++ )
	{
		len = strlen ( resultStr[i] );
		if ( startPosition == -1 && ( len > startLen || ((len == startLen) && strcmp( resultStr[i], startNum ) >=0 ) ) )
		{
			startPosition = i;
		}
		if ( endPosition == -1 && ( len > endLen || ((len == endLen) && strcmp( resultStr[i], endNum ) >0 ) ) )
		{
			endPosition = i;
		}
	}

	fprintf( fout, "Case #%d: %d\n", t+1, endPosition-startPosition );
}