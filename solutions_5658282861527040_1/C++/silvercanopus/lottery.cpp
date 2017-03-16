#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int bit[5][35];
long long dp[35][2][2][2][2][2];

long long DP(int pos,int bit1,int bit2,int stat1,int stat2,int stat3){
 if(pos == 0){
    if(stat1 == 0 || stat2 == 0 || stat3 == 0) return 0;
	 else return 1;		
 }
 long long &ret = dp[pos][bit1][bit2][stat1][stat2][stat3];
 if(ret != -1) return ret;
 ret = 0;
 // recurrence
 bool a,b,c;
 if(bit[3][pos-1] == 1) c = true;
 else c = false;
 // bit1 is 0, bit2 is 0
 if(bit[1][pos-1] == 1) a = true;
 else a = false;
 if(bit[2][pos-1] == 1) b = true;
 else b = false;
 ret += DP(pos-1,0,0,stat1|a,stat2|b,stat3|c);
 // bit1 is 1, bit2 is 0
 if(bit[2][pos-1] == 1) b = true;
 else b = false;
 if(bit[1][pos-1] == 0){
    if(stat1) ret += DP(pos-1,1,0,stat1,stat2|b,stat3|c);
	 else goto zero_one;		
 }
 else ret += DP(pos-1,1,0,stat1,stat2|b,stat3|c);
 // bit1 is 0, bit2 is 1
 zero_one :
 if(bit[1][pos-1] == 1) a = true;
 else a = false;
 if(bit[2][pos-1] == 0){
    if(stat2) ret += DP(pos-1,0,1,stat1|a,stat2,stat3|c);
	 else goto one_one;		
 }
 else ret += DP(pos-1,0,1,stat1|a,stat2,stat3|c);
 // bit1 is 1, bit2 is 1
 one_one :
 if(bit[1][pos-1] == 0){
    if(!stat1) goto end;		
 }
 if(bit[2][pos-1] == 0){
    if(!stat2) goto end;		
 }
 if(stat3) ret += DP(pos-1,1,1,stat1,stat2,stat3);
 else if(bit[3][pos-1] == 1) ret += DP(pos-1,1,1,stat1,stat2,stat3);
 
 end :
// printf("%d %d %d %d %d %d %d\n",pos,bit1,bit2,stat1,stat2,stat3,ret);
 return ret;
}

int main(){
 freopen("B-large (1).in","r",stdin);
 freopen("B-large (1).out","w",stdout);
 int tes;
 scanf("%d",&tes);
 for(int tcase=1;tcase<=tes;tcase++){
	 memset(bit,0,sizeof bit);
	 int a,b,k;
	 
	 scanf("%d%d%d",&a,&b,&k);
	 
	 int tmp = a, cnt = 0;
	 while(tmp){
	    bit[1][cnt] = tmp % 2;
		 tmp /= 2;
		 cnt++;		
	 }
	 
	 tmp = b, cnt = 0;
	 while(tmp){
	    bit[2][cnt] = tmp % 2;
		 tmp /= 2;
		 cnt++; 		
	 }
	 
	 tmp = k, cnt = 0;
	 while(tmp){
	    bit[3][cnt] = tmp % 2;
		 tmp /= 2;
		 cnt++;		
	 }
	 
	 memset(dp,-1,sizeof dp);
//	 printf("%d %d %d\n",a,b,k);
	 printf("Case #%d: %lld\n",tcase,DP(32,0,0,0,0,0));
 }
 
 fclose(stdin);
 fclose(stdout);
// system("pause");
 return 0;	
}
