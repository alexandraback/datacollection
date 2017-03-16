//
//  main.cpp
//  GCJ_R1A_A
//
//  Created by Ningchen Ying on 4/27/13.
//  Copyright (c) 2013 Ningchen Ying. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <vector>

using namespace std;
int T;
long long ans;
long long r,t;

int main(int argc, const char * argv[])
{
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_A/GCJ_R1A_A/A-small-attempt2.in","r",stdin);
    freopen("/Users/YNingC/Documents/CodeForces/GCJ_R1A_A/GCJ_R1A_A/A-small-attempt2.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++){
        cin>>r>>t;
        ans=0;
        long long L=0,R=t;
		while(L<=R){
			long long mid=(L+R)/2;
            long long f=(mid+1)*mid/2;
			if(2*r*mid+4*f-3*mid<=t){
				ans=mid;
				L=mid+1;
			}else R=mid-1;
		}
        
        
        printf("Case #%d: ",ca);
        cout<<ans<<endl;
    }
    return 0;
}

//n(n+1)(2n+1)/6
