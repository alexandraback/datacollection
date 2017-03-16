#include <iostream>  
#include <cstdio>  
#include <fstream> 
#include <map> 
using namespace std;
int ans[8][32][32];

void init()
{
	int i,j,k;
	i=1;
	for(j=i;j<=20;++j)
		for(k=1;k<=i*j;++k)
			ans[i][j][k]=k;
	
	i=2;
	for(j=i;j<=10;++j)
		for(k=1;k<=i*j;++k)
			ans[i][j][k]=k;
	
	i=3;
	j=3;
	for(k=1;k<=9;++k)	
		if(k<=4)
			ans[i][j][k]=k;
		else 
			ans[i][j][k]=k-1;
	
	i=3;	
	j=4;
	for(k=1;k<=12;++k)
		if(k<=4)
			ans[i][j][k]=k;
		else if(k<=7)
			ans[i][j][k]=k-1;
		else
			ans[i][j][k]=k-2;
	
	i=3;
	j=5;
	for(k=1;k<=15;++k)
		if(k<=4)
			ans[i][j][k]=k;
		else if(k<=7)
			ans[i][j][k]=k-1;
		else if(k<=10)
			ans[i][j][k]=k-2;
		else
			ans[i][j][k]=k-3;
	
	
	i=3;
	j=6;
	for(k=1;k<=18;++k)
		if(k<=4)
			ans[i][j][k]=k;
		else if(k<=7)
			ans[i][j][k]=k-1;
		else if(k<=10)
			ans[i][j][k]=k-2;
		else if(k<=13)
			ans[i][j][k]=k-3;
		else
			ans[i][j][k]=k-4;

	i=4;
	j=4;
	for(k=1;k<=16;++k)
		if(k<=4)
			ans[i][j][k]=k;
		else if(k<=7)
			ans[i][j][k]=k-1;
		else if(k<=10)
			ans[i][j][k]=k-2;
		else if(k<=11)
			ans[i][j][k]=k-3;
		else 
			ans[i][j][k]=k-4;

	i=4;
	j=5;
	for(k=1;k<=20;++k)
		if(k<=4)
			ans[i][j][k]=k;
		else if(k<=7)
			ans[i][j][k]=k-1;
		else if(k<=10)
			ans[i][j][k]=k-2;
		else if(k<=11)
			ans[i][j][k]=k-3;
		else if(k<=13)
			ans[i][j][k]=k-4;			
		else if(k<=15)
			ans[i][j][k]=k-5;
		else
			ans[i][j][k]=k-6;

		ans[4][5][10] = 7;
		ans[4][4][10] = 7;
}

int main()  
{  
    //ifstream cin("D:\\C-small-attempt1.in");  
    //freopen("D:\\C-small-attempt1","w",stdout); 
	init();
    int t;  
    cin >> t;   
    int n, m, k;
    for(int times = 1; times <= t; times++)  
    {  
    	cin >> n >> m >> k;
    	if (n > m) swap(n, m);
        printf("Case #%d: %d\n", times, ans[n][m][k]);
    }  
}  
