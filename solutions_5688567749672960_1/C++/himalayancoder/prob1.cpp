// Rohit Bhardwaj

#include<bits/stdc++.h>
#define md 1000003
#define ll long long
#define gc getchar_unlocked
using namespace std;
ll reverse(ll no1){
	ll n=0;
	ll no=no1;
	while(no){
		n=n*(10)+no%10;
		no/=10;
	}
	return n;
}

int main()
{
	
    	#ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
	   freopen("out.txt","w",stdout);		
		#endif
		int test;
		ll no;
		ll count;
		scanf("%d",&test);
		for(int tst=1;tst<=test;tst++){
			printf("Case #%d: ",tst);
			count=0;
			scanf("%lld",&no);
			while((no-1)/1000000000000000){
				if(no%100000000)
				{count+=(no%100000000)-1;
				no=no-no%100000000+1;}
				else{
					count+=99999999;
				no=no-99999999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/10000000000000){
				if(no%10000000)
				{count+=(no%10000000)-1;
				no=no-no%10000000+1;}
				else{
					count+=9999999;
				no=no-9999999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/100000000000){
				if(no%1000000)
				{count+=(no%1000000)-1;
				no=no-no%1000000+1;}
				else{
					count+=999999;
				no=no-999999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/1000000000){
				if(no%100000)
				{count+=(no%100000)-1;
				no=no-no%100000+1;}
				else{
					count+=99999;
				no=no-99999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/10000000){
				if(no%10000)
				{count+=(no%10000)-1;
				no=no-no%10000+1;}
				else{
					count+=9999;
				no=no-9999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/100000){
				if(no%1000)
				{count+=(no%1000)-1;
				no=no-no%1000+1;}
				else{
					count+=999;
				no=no-999;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while((no-1)/1000){
				if(no%100)
				{count+=(no%100)-1;
				no=no-no%100+1;}
				else{
					count+=99;
				no=no-99;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			while(no/10){
				
				if(no%10)
				{count+=(no%10)-1;
				no=no-no%10+1;}
				else{
					count+=9;
				no=no-9;
				}
				ll x=reverse(no);
				if(x<no){
					count++;
					no=x;
				}
				count+=2;
				no-=2;
			}
			count+=no%10;
			printf("%lld\n",count);
			
			
			
			
		}
    return 0;
}
