/*
 *  pa.cpp
 *
 *
 *  Created by Bruce Kuo on 12/4/28.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include <stdio.h>
#include <string.h>

int A, B;
double prob[1000010];

int main() {
    int t, cases=0;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&A,&B);
        for(int i=0;i<A;++i)
            scanf("%lf",prob+i);

        double ans, count, rs;
        //Case C;
        ans = B+2;
		
        //case A;
		count = 0;
        rs = 1;
        for(int i=0;i<A;++i)
            rs *= prob[i];
        count = rs*(B-A+1);
        count += (1-rs)*(B-A+1+B+1);
        if(ans > count) ans = count;
		//printf("%lf %lf\n",ans,count);

		//puts("XXXX");
        //case B;
		double xx=1;
		for(int i=0;i<A;++i)
			xx *= prob[i];
        rs = xx;
        for(int i=1;i<=A;++i) {
			count = 0;	
			int pos = A-i;
            rs /= prob[A-i];
            count = (rs)*(i+B-pos+1)+(1-rs)*(i+B-pos+1+B+1);
            if(ans > count) ans = count;
        }

		printf("Case #%d: %lf\n",++cases,ans);
    }

    return 0;
}

