#include<bits/stdc++.h>

#define getcx getchar_unlocked
#define putcx putchar_unlocked
#define ll int
#define MOD 1000000007

using namespace std;

inline void inp(ll *n){
	*n=0;
	//bool neg=false;
	register char ch=getcx();
	while(ch<33){
		ch=getcx();
	}
	while(ch>32){
		//if(ch!='-'){
			*n=(*n<<3)+(*n<<1)+ch-'0';
		//}
		/*else {
			neg=true;
		}*/
		ch=getcx();
	}
	/*if(neg){
		*n=-(*n);
	}*/
}


inline void op(ll n) {
        /*if(n<0){
                n=-n;
                putcx('-');
        }*/
        int i=21;
        char store[21];
        do{
                store[--i]=(n%10)+'0';
		n/=10;
        }while(n);
        do{
                putcx(store[i++]);
        }while(i<21);
}


int main(){
	int T,Smax;
	char S[1005];
	inp(&T);
	for(int t=1;t<=T;t++){
		int ans=0;
		scanf("%d %s",&Smax,S);
		int cumul=S[0]-'0';
		for(int i=1;i<=Smax;i++){
			if(S[i]!='0' && i>cumul){
				ans+=i-cumul;
				cumul=i;
			}
			cumul+=(S[i]-'0');
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;

}
