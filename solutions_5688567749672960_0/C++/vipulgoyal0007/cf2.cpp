#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <bitset>
#include <map>
#include <queue>
#include <climits>
#include <bitset>
#define LL long long
#define INFI 100000000000
#define D double
using namespace std;
#include <iomanip>

LL dp[1000005] = {0};

int main()
{
    LL tt;
    cin>>tt;
    
    	dp[0] = 1;
    	dp[1] = 1;
    	for(LL i=2; i<=1000000; i++)
    	{
    		string s = to_string(i);
    		string t = to_string(i);
    		reverse(t.begin(),t.end());
    		
    		LL num = 0;
    		
    		for(LL j=0; j<t.size(); j++)
    		{
    			num = num*10 + (LL)(t[j]-'0');
    		}
    		if(t[0] != '0' && num < i)
    		{
    			dp[i] = min(dp[i-1],dp[num]) + 1;
    		}
    		else
    		{
    			dp[i] = dp[i-1]+1;
    		}
    	}
    	for(LL t=1; t<=tt; t++)
    	{
    		LL n;
    		cin>>n;
    		
			cout<<"Case #"<<t<<": "<<dp[n]<<endl;    	
		}
	
	return 0;
}

/*
Case #1: 1
Case #2: 19
Case #3: 15
Case #4: 351
Case #5: 3405
Case #6: 3278
Case #7: 156
Case #8: 14
Case #9: 153
Case #10: 37
Case #11: 251
Case #12: 3503
Case #13: 255
Case #14: 3404
Case #15: 3496
Case #16: 3495
Case #17: 817
Case #18: 9
Case #19: 479
Case #20: 2795
Case #21: 968
Case #22: 3496
Case #23: 1367
Case #24: 389
Case #25: 3406
Case #26: 35
Case #27: 350
Case #28: 488
Case #29: 151
Case #30: 380
Case #31: 11
Case #32: 1482
Case #33: 152
Case #34: 3406
Case #35: 34
Case #36: 3497
Case #37: 17
Case #38: 266
Case #39: 478
Case #40: 378
Case #41: 367
Case #42: 47
Case #43: 1379
Case #44: 467
Case #45: 14
Case #46: 265
Case #47: 19
Case #48: 22
Case #49: 150
Case #50: 136
Case #51: 12
Case #52: 7
Case #53: 3506
Case #54: 2482
Case #55: 252
Case #56: 3494
Case #57: 3406
Case #58: 3407
Case #59: 3504
Case #60: 156
Case #61: 489
Case #62: 2482
Case #63: 1483
Case #64: 377
Case #65: 40
Case #66: 1378
Case #67: 3621
Case #68: 17
Case #69: 388
Case #70: 368
Case #71: 3396
Case #72: 35
Case #73: 135
Case #74: 254
Case #75: 1366
Case #76: 174
Case #77: 36
Case #78: 477
Case #79: 151
Case #80: 21
Case #81: 2
Case #82: 3504
Case #83: 165
Case #84: 366
Case #85: 1471
Case #86: 20
Case #87: 38
Case #88: 3495
Case #89: 173
Case #90: 3505
Case #91: 23
Case #92: 478
Case #93: 46
Case #94: 1585
Case #95: 2713
Case #96: 10
Case #97: 1472
Case #98: 3505
Case #99: 349
Case #100: 468
*/