#include <stdio.h>
#include <string.h>
using namespace std;
char *num[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

int *char_array;
int to_print[26];

void delete_let(int n)
{
	for(int i=0;i<strlen(num[n]);i++)
	{
		char_array[num[n][i]-'A']--;
	}
}
void solve(char *s)
{
	int n = strlen(s);
	for(int i=0;i<n;i++)
		char_array[s[i]-'A']++;

	while(char_array['W'-'A'])
	{
		to_print[2]++;
		delete_let(2);
	}
	while(char_array['U'-'A'])
	{
		to_print[4]++;
		delete_let(4);
	}
	while(char_array['X'-'A'])
	{
		to_print[6]++;
		delete_let(6);
	}
	while(char_array['G'-'A'])
	{
		to_print[8]++;
		delete_let(8);
	}
	while(char_array['Z'-'A'])
	{
		to_print[0]++;
		delete_let(0);
	}
	while(char_array['F'-'A'])
	{
		to_print[5]++;
		delete_let(5);}
	while(char_array['V'-'A'])
	{
		to_print[7]++;
		delete_let(7);
	}
	while(char_array['T'-'A'])
	{
		to_print[3]++;
		delete_let(3);
	}

	while(char_array['O'-'A'])
	{
		to_print[1]++;
		delete_let(1);
	}
	
	while(char_array['N'-'A'])
	{
		to_print[9]++;
		delete_let(9);
	}
	

}

void print_i()
{
	for(int i=0;i<26;i++)
		while(to_print[i]!=0)
		{
			printf("%d",i);
			to_print[i]--;
		}
}
int main(){
	char_array = new int[26]();
	char s[2001];
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		printf("Case #%d: ",i);
		scanf("%s",s);
		memset(to_print,0,26*sizeof(int));
		memset(char_array,0,26*sizeof(int));
		solve(s);
		print_i();
		printf("\n");
	}
	return 0;
}
