#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

bool input[1000010];
int accumu[1000010];

int main () {
	
    freopen("in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++){
    	int len = 0;
    	int n;
    	char xd;
    	xd = getchar();
    	while((xd = getchar()) != ' ') {
    		//printf("%c\n", xd);
    		if (xd == 'a' || xd == 'e' || xd == 'i' || xd == 'o' || xd == 'u'){
    			input[len] = false;
    			accumu[len++] = 0;
    		}else {
    			input[len] = true; // consonent
    			accumu[len] = (len == 0)? 1: (accumu[len - 1] + 1);
    			len++;
    		}
    	}
    	//for (int i=0; i<len;i++)printf("%d ", accumu[i]); printf("\n");
    	//printf("len = %d\n", len);
    	cin >> n;
    	int prevOK = -1;
    	int ans = 0;
    	for (int i=0; i<len; i++) {
    		if (accumu[i] >= n) {
    			prevOK = i;
    			//printf("%d XDD\n", i);
    		}
    		if (prevOK >= 0) {
    			ans += (prevOK + 1 - n + 1);
    		}
    	}
    	printf("Case #%d: %d\n", t, ans);
    }
    
    return 0;
}