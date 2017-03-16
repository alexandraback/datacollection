#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char C[30], J[30];

int bas;
int type;

bool fc(int a)
{
	int n=strlen(C);
	for (int i = n-1; i >=0; --i, a/=10)
	{
		if(C[i]=='?') continue;
		if (a%10 != C[i]-'0')
		{
			return 0;
		}
	}
	return 1;
}
bool fj(int a)
{
	int n=strlen(J);
	for (int i = n-1; i >=0; --i, a/=10)
	{
		if(J[i]=='?') continue;
		if (a%10 != J[i]-'0')
		{
			return 0;
		}
	}
	return 1;
}
inline int abs(int a){
	return (a<0)?-a:a;
}

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
    	scanf("%s%s",C,J);

    	bas=1;
    	for (int i = 0; C[i]!=0; ++i)
    	{
    		bas *= 10;
    	}
    	// for (int i = 10; i < 20; ++i)
    	// {
    	// printf("%d %d\n",i,fc(i));
    	// }

    	int ans = 1e6,ansi,ansj;
    	for (int i = 0; i < bas; ++i)
    	{
    		if(fc(i)==0) continue;
    		for(int j=0;j<bas;++j)
    		{
    			if(fj(j)==0) continue;
    			if(abs(i-j)<ans){
    				ans = abs(i-j);ansi=i;ansj=j;
    			}
    		}
    	}

    	// type = 0;
    	// for (int i = 0; C[i]!=0; ++i)
    	// {
    	// 	if (type==0)
    	// 	{
    	// 		if (C[i]=='?' && J[i]=='?')
    	// 		{
    	// 			C[i]=J[i]='0';
    	// 		} else if (C[i]=='?'){
    	// 			C[i]=J[i];
    	// 		} else if (J[i]=='?'){
    	// 			J[i]=C[i];
    	// 		} else if (C[i]>J[i]){
    	// 			type = 1;
    	// 		} else if (C[i]<J[i]){
    	// 			type=2;
    	// 		}
    	// 		continue;
    	// 	}

    	// 	if (C[i]=='?')
    	// 	{
    	// 		C[i] = (type==1?'0':'9');
    	// 	}
    	// 	if (J[i]=='?')
    	// 	{
    	// 		J[i] = (type==2?'0':'9');
    	// 	}
    	// }
        
        int n=strlen(C);
        for (int i = n-1; i >=0; --i)
        {
        	C[i]=ansi%10+'0';
        	J[i]=ansj%10+'0';
        	ansi/=10;ansj/=10;
        }
        printf("Case #%d: %s %s\n", tt, C,J);
    }
    return 0;
}

