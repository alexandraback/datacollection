#include<iostream>
#include<stdio.h>
using namespace std;
bool check_draw( char a[4][4] )
{
for ( int i = 0; i < 4; i++)
{
for ( int j = 0; j < 4; j++)
	if ( a[i][j] == '.' )
		return 0;
}
return 1;
}
bool is_true( char a,char b)
{
if(a==b || a=='T')
	return 1;
return 0;

}
bool check ( char a[4][4], char key )
{

for ( int i = 0; i < 4; i++)
	if ( is_true(a [i][0], key ) && is_true(a[i][1],key) && is_true( a[i][2], key ) && is_true ( a[i][3],key) )
    {
		
			  return 1;
	}
for ( int j = 0; j < 4; j++)
	if ( is_true ( a[0][j], key ) && is_true ( a[1][j], key )   && is_true (a[2][j], key) && is_true(a[3][j],key) )
		  {
			
			  return 1;
		  }	
if ( is_true ( a[0][0], key)  && is_true ( a[1][1], key )  && is_true ( a[2][2], key ) && is_true(a[3][3],key))
  {
		return 1;
}

if ( is_true ( a[0][3], key)  && is_true ( a[1][2], key )  && is_true ( a[2][1], key ) && is_true(a[3][0],key))
  {
		return 1;
}

	
return 0;	
	

}

int main()
{
	int n;
	char a[4][4];
	cin>>n;
	for ( int yy = 1; yy <= n; yy++ )
	{
	  for ( int i = 0; i < 4; i++)
		  for (int j = 0; j < 4; j++)
		    scanf ( " %c ",&a[i][j]);

	  cout << "Case #" << yy <<": ";
      
	  if (check ( a, 'X') )
		  cout << "X won\n";
	  else if (check ( a, 'O' ) )
		  cout << "O won\n";
	  else if ( check_draw ( a ) )
		  cout << "Draw\n";
	  else
		  cout << "Game has not completed\n";
	}
}