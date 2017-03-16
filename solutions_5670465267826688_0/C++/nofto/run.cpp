#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

class Quaternion{
  public:
	int q;
	Quaternion(int ss):q(ss){}
	Quaternion(char ss){
		switch(ss){
			case 'i': q=2;break;
			case 'j': q=3;break;
			case 'k': q=4;break;
			default: q=0;
		}
	}
	string s(){
		switch(q){
			case 1: return "1";break;
			case 2: return "i";break;
			case 3: return "j";break;
			case 4: return "k";break;
			case -1: return "-1";break;
			case -2: return "-i";break;
			case -3: return "-j";break;
			case -4: return "-k";break;
		}
		return "0";
	}
	Quaternion operator*(const Quaternion& b){
		if(q==1) return b;
		if(b.q==1) return Quaternion(q);
		if(q==-1) return Quaternion(-b.q);
		if(b.q==-1) return Quaternion(-q);
		if(q==b.q) return Quaternion(-1);
		if(q==b.q) return Quaternion(-1);
		if(q==-b.q) return Quaternion(1);
		if(q<0) return Quaternion(-1)*(Quaternion(-q)*b);
		if(b.q<0) return Quaternion(-1)*(Quaternion(q)*Quaternion(-b.q));
		if(q==2 && b.q==3) return Quaternion(4);
		if(q==3 && b.q==4) return Quaternion(2);
		if(q==4 && b.q==2) return Quaternion(3);
		if(q==3 && b.q==2) return Quaternion(-4);
		if(q==4 && b.q==3) return Quaternion(-2);
		if(q==2 && b.q==4) return Quaternion(-3);
		return Quaternion(0); 
   }
   bool operator==(Quaternion& b){
		return q==b.q;
   }
};

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int L,X;
		scanf("%d %d\n",&L,&X);
        vector <char>c(L);
		for(int i=0; i<L; i++){
		    scanf("%c",&c[i]);
		}
		vector <Quaternion> Q(L*X,Quaternion(0));
		for(int i=0;i<X;i++) for(int j=0;j<L;j++) Q[j+L*i]=Quaternion(c[j]);
		int N=L*X;
		int firstI=N;
		int firstK=N;
		Quaternion productL(1);
		Quaternion productR(1);
		Quaternion IJK(-1);
		Quaternion I('i');
		Quaternion J('j');
		Quaternion K('k');
		for(int i=0;i<N;i++){
			productL=productL*Q[i];
			if(firstI==N && productL==I) firstI=i;
			productR=Q[N-1-i]*productR;
			if(firstK==N && productR==K) firstK=i;
		}
		if(productR==IJK && firstI+firstK<N) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
  return 0;
}
