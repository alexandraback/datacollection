#include<iostream>
#include<cstring>
#include<cstdio>
#define CLR(x) memset(x,0,sizeof(x))
using namespace std;

char word[30][8] = { 
	".-",		
	"-...",		
	"-.-.",		
	"-..",		
	".",		
	"..-.",		
	"--.",		
	"....",		
	"..",		
	".---",		
	"-.-",		
	".-..",		
	"--",		
	"-.",		
	"---",		
	".--.",		
	"--.-",		
	".-.",		
	"...",		
	"-",		
	"..-",		
	"...-",		
	".--",		
	"-..-",		
	"-.--",		
	"--..",		
};

char number[12][8] =
{
	"-----",		
	".----",		
	"..---",		
	"...--",		
	"....-",		
	".....",		
	"-....",		
	"--...",		
	"---..",		
	"----.",		
};

int main()
{
	int num;
	cin >> num;

	for(int i=0;i<num;i++)
	{
		int n;
		char res[105],temp[5];
		cin >> n;
		
		for(int j=0;j<n;j++){
			cin >> temp;

				for(int r=0;r<10;r++){
					if( strcmp(temp, number[r])==0 ){
						res[j] = '0' + r;
						break;
					}
				}
				for(int r=0;r<26;r++){
					if( strcmp(temp, word[r])==0 ){
						res[j] = 'A' + r;
						break;
					}
				}
		}
		res[n] = '\0';
		printf("Case #%d: %s\n",i+1,res);
	}
	return 0;
}