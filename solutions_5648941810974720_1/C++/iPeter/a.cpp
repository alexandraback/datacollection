#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int map[30];
char s[4000];

int order[20] = {0,2,4,6,8,1,3,5,7,9};
char w[20][9] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[20];

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
    	scanf("%s",s);
    	int n =strlen(s);
    	memset(map,0,sizeof(map));
    	memset(cnt,0,sizeof(cnt));
    	for (int i = 0; i < n; ++i)
    	{
    		map[s[i]-'A']++;
    	}

    	for (int i = 0; i < 10; ++i)
    	{
    		while(1){
    			bool x=true;
	    		for (int j = 0; w[order[i]][j]!=0; ++j)
	    		{
	    			if (map[w[order[i]][j]-'A'] <= 0)
	    			{
	    				x=false;
	    				break;
	    			}
	    		}
	    		if(!x) break;
	    		cnt[order[i]]++;
	    		for (int j = 0; w[order[i]][j]!=0; ++j)
	    		{
	    			map[w[order[i]][j]-'A']--;
	    		}
    		}
    	}
        
        printf("Case #%d: ", tt);
        for (int i = 0; i < 10; ++i)
        {
        	for(int j=0;j<cnt[i];j++)
        	printf("%d",i);
        }
        puts("");
    }
    return 0;
}

