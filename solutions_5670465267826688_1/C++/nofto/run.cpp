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
		int L;
		long long X;
		scanf("%d %llu\n",&L,&X);
        vector <char>c(L);
		for(int i=0; i<L; i++){
		    scanf("%c",&c[i]);
		}
		vector <Quaternion> Q(L*4,Quaternion(0));
		for(int i=0;i<4;i++) for(int j=0;j<L;j++) Q[j+L*i]=Quaternion(c[j]);
		int firstI=4*L;
		int firstK=4*L;
		Quaternion productL(1);
		Quaternion productAll(1);
		Quaternion productR(1);
		Quaternion IJK(-1);
		Quaternion I('i');
		Quaternion J('j');
		Quaternion K('k');
		for(int i=0;i<4*L;i++){
			productL=productL*Q[i];
			if(firstI==4*L && productL==I) firstI=i;
			productR=Q[4*L-1-i]*productR;
			if(firstK==4*L && productR==K) firstK=i;
			if(i==L-1) productAll=productL;
		}
		Quaternion productX(1);
		for(int i=0;i<X%4;i++) productX=productX*productAll;
		if(productX==IJK && firstI+firstK<L*X && firstI<4*L && firstK<4*L) printf("Case #%d: YES\n",t);
		else printf("Case #%d: NO\n",t);
	}
  return 0;
}
