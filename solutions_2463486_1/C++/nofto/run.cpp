#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include "ttmath/ttmath.h"  // available at http://www.ttmath.org/

using namespace std;

bool isPalindrom(int p){
	int r=0;
	int z=p;
	while(z>0){
		r*=10;
		r+=(z%10);
		z/=10;
	}
	if(p==r) return true;
	return false;
}
bool isPalindrom(ttmath::UInt<11> p){
	ttmath::UInt<11> r=0;
	ttmath::UInt<11> z=p;
	while(z>0){
		r*=10;
		r+=(z%10);
		z/=10;
	}
	if(p==r) return true;
	return false;
}
ttmath::UInt<11> intSqrt(ttmath::UInt<11> n){
	ttmath::UInt<11> r;
    r=1;
	while((r-1)*(r-1)>n || (r+2)*(r+2)<n){
		r=(r+n/r)/2;
	}
	r+=3;
	while(r*r>n) r--;
	return r;
}

int main()
{
    vector< ttmath::UInt<11> > fair;
   	fair.push_back("1");
   	fair.push_back("2");
   	fair.push_back("3");
   	ttmath::UInt<11> z=1;
   	for(int i=0;i<49;i++){
   		z*=10;
   	    fair.push_back(z+1);
   	}
	z=2;
	for(int i=0;i<49;i++){
   		z*=10;
   	    fair.push_back(z+2);
   	}
    z=1;
	for(int i=0;i<24;i++){
   		z*=10;
   	    fair.push_back(z*z+z+1);
   	}	
    z=1;
	for(int i=0;i<24;i++){
   		z*=10;
   	    fair.push_back(z*z+z*2+1);
   	}	
    z=1;
	for(int i=0;i<24;i++){
   		z*=10;
   	    fair.push_back(z*z*2+z+2);
   	}
    z=1;
	for(int i=0;i<24;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=46-2*i;j++){
   			zz*=10;
     	    fair.push_back(z*zz*z+zz*z+z+1);
   		}
   	}
    z=1;
	for(int i=0;i<23;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=22-i;j++){
   			zz*=10;
     	    fair.push_back(z*zz*zz*z+zz*zz*z+zz*z+z+1);
   		}
   	}
    z=1;
	for(int i=0;i<23;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=22-i;j++){
   			zz*=10;
     	    fair.push_back(z*zz*zz*z+zz*zz*z+zz*z*2+z+1);
   		}
   	}
    z=1;
	for(int i=0;i<23;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=22-i;j++){
   		    zz*=10;
   		    ttmath::UInt<11> zzz=1;
   		    for(int k=0;k<=44-2*i-2*j;k++){
   			    zzz*=10;
     	        fair.push_back(z*zz*zzz*zz*z+zz*zzz*zz*z+zzz*zz*z+zz*z+z+1);
   		    }
		}
   	}
    z=1;
	for(int i=0;i<22;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=21-i;j++){
   		    zz*=10;
   		    ttmath::UInt<11> zzz=1;
   		    for(int k=0;k<=21-i-j;k++){
   			    zzz*=10;
     	        fair.push_back(z*zz*zzz*zzz*zz*z + zz*zzz*zzz*zz*z + zzz*zzz*zz*z + zzz*zz*z + zz*z + z + 1);
   		    }
		}
   	}
    z=1;
	for(int i=0;i<22;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=21-i;j++){
   		    zz*=10;
   		    ttmath::UInt<11> zzz=1;
   		    for(int k=0;k<=21-i-j;k++){
   			    zzz*=10;
   		        ttmath::UInt<11> zzzz=1;
   		        for(int m=0;m<=42-2*i-2*j-2*k;m++){
   			        zzzz*=10;
     	            fair.push_back(z*zz*zzz*zzzz*zzz*zz*z + zz*zzz*zzzz*zzz*zz*z + zzz*zzzz*zzz*zz*z + zzzz*zzz*zz*z + zzz*zz*z + zz*z + z + 1);
   		        }
   		    }
		}
   	}
    z=1;
	for(int i=0;i<21;i++){
		z*=10;
   		ttmath::UInt<11> zz=1;
   		for(int j=0;j<=20-i;j++){
   		    zz*=10;
   		    ttmath::UInt<11> zzz=1;
   		    for(int k=0;k<=20-i-j;k++){
   			    zzz*=10;
   		        ttmath::UInt<11> zzzz=1;
   		        for(int m=0;m<=20-i-j-k;m++){
   			        zzzz*=10;
     	            fair.push_back(z*zz*zzz*zzzz*zzzz*zzz*zz*z + zz*zzz*zzzz*zzzz*zzz*zz*z + zzz*zzzz*zzzz*zzz*zz*z + zzzz*zzzz*zzz*zz*z + zzzz*zzz*zz*z + zzz*zz*z + zz*z + z + 1);
   		        }
   		    }
		}
   	}
   	sort(fair.begin(),fair.end());
   	
	/*
	1 -> 1
	2 -> 4
	3 -> 9
	1[A]1 -> 121                      A+2     A<=48
	2[A]2 -> 484                      A+2   
	1[A]1[A]1 -> 12321                2A+3    A<=23
	1[A]2[A]1 -> 14641                2A+3
	2[A]1[A]2 -> 44944                2A+3
	1[A]1[B]1[A]1 -> 1234321            2A+B+4      2A+B<=46     A=0..23, B=0..46-2A    
	1[A]1[B]1[B]1[A]1 -> 123454321         2A+2B+5   2A+2B<=45   A=0..22, B=0..(45-2A)/2
	1[A]1[B]2[B]1[A]1 -> 125686521         2A+2B+5
	1[A]1[B]1[C]1[B]1[A]1 -> 12345654321         2A+2B+C+6       2A+2B+C<=44    A=0..22, B=0..(44-2A)/2, C=0..44-2A-2B
	1[A]1[B]1[C]1[C]1[B]1[A]1 -> 1234567654321           2A+2B+2C+7    2A+2B+2C<=43  A=0..21, B=0..21-A, C=0..21-A-B 
	1[A]1[B]1[C]1[D]1[C]1[B]1[A]1 -> 123456787654321  2A+2B+2C+D+8 2A+2B+2C+D<=42 A=0..21, B=0..21-A, C=0..21-A-B, D=0..42-2A-2B-2C
    1[A]1[B]1[C]1[D]1[D]1[C]1[B]1[A]1 -> 12345678987654321      
	                     2A+2B+2C+2D+9     2A+2B+2C+2D<=41   A=0..20, B=0..20-A,   C=0..20-A-B,   D=0..20-A-B-C
*/

	int T;
	scanf("%d\n",&T);  
	ttmath::UInt<11> A, B, rA, rB;
	for(int t=1; t<=T; t++)
	{
		char a[102];
		char b[102];
		scanf("%s %s\n",a,b);
	    A=a;
	    B=b;
	    rA=intSqrt(A);
	    if(rA*rA!=A) rA++;
        rB=intSqrt(B);
		int low=0;
		int up=fair.size()-1;
		while(fair[low]<rA){
			int mid=(low+up)/2;
			if(fair[mid]>=rA) up=mid;
			else low=mid+1;
		}
		int low2=0;
		int up2=fair.size()-1;
		while(fair[up2]>rB){
			int mid=(low2+up2+1)/2;
			if(fair[mid]>rB) up2=mid-1;
			else low2=mid;
		}
		
		printf("Case #%d: %d\n",t,up2-low+1);
	}
	

    //for(int n=1;n<120000;n++) if(isPalindrom(n*n)) printf("%d -> %d\n",n,n*n);
    //for(ttmath::UInt<11> n=1;n<22222222;n++) if(n%10<4 && isPalindrom(n) && isPalindrom(n*n)) printf("%s -> %s\n",n.ToString().c_str(),(n*n).ToString().c_str());
    
    //ttmath::UInt<11> n="11111111";
    /*printf("%s -> %s\n",n.ToString().c_str(),(n*n).ToString().c_str());    
    n="111111111";
	printf("%s -> %s\n",n.ToString().c_str(),(n*n).ToString().c_str());    
    n="11111011111";
	printf("%s -> %s\n",n.ToString().c_str(),(n*n).ToString().c_str());    
    */
	//n="101001000100101";
	//printf("%s -> %s\n",n.ToString().c_str(),(n*n).ToString().c_str());
    //for(int i=0;i<fair.size();i++)
	//   printf("%s\n",fair[i].ToString().c_str());
    //printf("%d\n",fair.size());
    
    return 0;
}
