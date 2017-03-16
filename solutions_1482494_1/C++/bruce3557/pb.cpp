/*
 *  pb.cpp
 *
 *
 *  Created by Bruce Kuo on 12/4/28.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int n;
int S[1010][2];
bool solve[1010][2];
bool clear[1010];

inline bool check() {
	for(int i=0;i<n;++i)
		if( !clear[i] )
			return false;
	return true;
}

inline int Solve() {
	memset(solve, 0, sizeof(solve));
	memset(clear, 0, sizeof(clear));

	int count = 0;
	int star = 0;
	while(1) {
	    bool ck = true;
	    for(int i=0;i<n;++i)
            if(clear[i] == false) {
                ck = false;
                break;
            }
        if(ck)  break;
		int x = -1;
		for(int i=0;i<n;++i)
			if(clear[i] == false && S[i][1] <= star) {
				x = i;
				break;
			}
		if( x != -1 ) {
			if( solve[x][0] )	++star;
			else				star += 2;
			solve[x][1] = 1;
			clear[x] = 1;
			++count;
			//printf("%d %d %d\n",x,solve[x][1], clear[x]);
			continue;
		}
		for(int i=0;i<n;++i)
			if(clear[i] == false && solve[i][0] == false && S[i][0] <= star) {
                if(x == -1 || (S[i][1] >= S[x][1])) {
                    x = i;
                }
			}
		if(x == -1)	break;
        //printf("%d\n",x);
		solve[x][0] = 1;
		++star;
		++count;
	}

	bool fx = check();
	if( !fx )	return -1;
	return count;
}

int main() {
	int t, cases=0;

	scanf("%d",&t);
	while(t--) {
	    scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d%d",&S[i][0],&S[i][1]);
		int ans = Solve();
		printf("Case #%d: ",++cases);
		if(ans == -1)	puts("Too Bad");
		else			printf("%d\n",ans);

	}

	return 0;
}

