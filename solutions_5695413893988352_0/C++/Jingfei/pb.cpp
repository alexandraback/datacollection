#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

string C,J;
int len;

int toDigit(string s){
	int res = 0, tmp=1;
	for(int i=len-1; i>=0; --i)
		res+=(s[i]-'0')*tmp, tmp*=10;
	return res;
}

int main(){
	int T; scanf("%d",&T); getchar();
	for(int Case=1; Case<=T; ++Case){
		cin >> C >> J;
		len = C.length();
		string CC=C,JJ=J,CCC=C,JJJ=J;
		int digit;
		int cmp = 0;  // -1: C<J, 1: C>J, 2: finished
		for(int i=0; i<len; ++i) {
			if(!cmp){
				if(C[i]=='?' && J[i]=='?') C[i]=J[i]='0';
				else if(C[i]=='?') C[i]=J[i];
				else if(J[i]=='?') J[i]=C[i];
				else cmp = C[i]<J[i] ? -1 : C[i]>J[i] ? 1 : 0;
				if(cmp) digit = i;
			}
			else if(cmp==-1){
				if(C[i]=='?' && J[i]=='?') C[i]='9', J[i]='0';
				else if(C[i]=='?') C[i]='9';
				else if(J[i]=='?') J[i]='0';
			}
			else {
				if(C[i]=='?' && J[i]=='?') C[i]='0', J[i]='9';
				else if(C[i]=='?') C[i]='0';
				else if(J[i]=='?') J[i]='9';
			}
		}
		/* second way */
		if(cmp){
			bool change=false;
			for(int i=len-1; i>=0; --i) {
				if(change){
						if(CC[i]=='?' && JJ[i]=='?') CC[i]='0', JJ[i]='0';
						else if(CC[i]=='?') CC[i]=JJ[i];
						else if(JJ[i]=='?') JJ[i]=CC[i];
				}
				else{
					if(CC[i]=='?' && JJ[i]=='?'){
						if(cmp==-1) CC[i]='1', JJ[i]='0';
						else CC[i]='0', JJ[i]='1';
						change = true;
					} 
					else if(i>digit){
						if(cmp==-1){
							if(CC[i]=='?') CC[i]='0';
							else if(JJ[i]=='?') JJ[i]='9';
						}
						else {
							if(CC[i]=='?') CC[i]='9';
							else if(JJ[i]=='?') JJ[i]='0';
						}
					}
					else if(CC[i]=='?'){
						if(cmp==-1){
							 if(JJ[i]!='9') CC[i]=JJ[i]+1, change=true;
							 else CC[i]=JJ[i];
						}
						else{
							if(JJ[i]!='0') CC[i]=JJ[i]-1, change=true;
							else CC[i]=JJ[i];
						}
					}
					else if(JJ[i]=='?'){
						if(cmp==-1){
							 if(CC[i]!='0') JJ[i]=CC[i]-1, change=true;
							 else JJ[i]=CC[i];
						}
						else{
							if(CC[i]!='9') JJ[i]=CC[i]+1, change=true;
							else JJ[i]=CC[i];
						}
					}
				}
			}
		}
//		cout << CC << " " << JJ << endl;
		int c1=toDigit(C), j1=toDigit(J);
		int c2=toDigit(CC),j2=toDigit(JJ);
//		printf("1: %d %d\n",c1,j1);
//		printf("2: %d %d\n",c2,j2);
		int r1 = c1-j1;
		int r2 = c2-j2;
		r1 = r1<0 ? -r1 : r1;
		r2 = r2<0 ? -r2 : r2;
		if(r1<r2) C=C, J=J;
		else if(r1>r2) C=CC, J=JJ;
		else {
			if(c1<c2) C=C, J=J;
			else if(c1>c2) C=CC, J=JJ;
			else if(j1<j2) C=C, J=J;
			else C=CC, J=JJ;
		}
		/* third way */
		CC=CCC; JJ=JJJ;
		if(cmp){
			bool change=false;
			for(int i=0; i<len; ++i) {
				if(change){
					if(cmp==1){
						if(CC[i]=='?' && JJ[i]=='?') CC[i]='9', JJ[i]='0';
						else if(CC[i]=='?') CC[i]='9';
						else if(JJ[i]=='?') JJ[i]='0';
					}
					else {
						if(CC[i]=='?' && JJ[i]=='?') CC[i]='0', JJ[i]='9';
						else if(CC[i]=='?') CC[i]='0';
						else if(JJ[i]=='?') JJ[i]='9';
					}		
				}
				else{
					if(CC[i]=='?' && JJ[i]=='?'){
						if(cmp==-1) CC[i]='1', JJ[i]='0';
						else CC[i]='0', JJ[i]='1';
						change = true;
					} 
					else if(CC[i]=='?'){
						if(cmp==-1){
							 if(JJ[i]!='9') CC[i]=JJ[i]+1, change=true;
							 else CC[i]=JJ[i];
						}
						else{
							if(JJ[i]!='0') CC[i]=JJ[i]-1, change=true;
							else CC[i]=JJ[i];
						}
					}
					else if(JJ[i]=='?'){
						if(cmp==-1){
							 if(CC[i]!='0') JJ[i]=CC[i]-1, change=true;
							 else JJ[i]=CC[i];
						}
						else{
							if(CC[i]!='9') JJ[i]=CC[i]+1, change=true;
							else JJ[i]=CC[i];
						}
					}
				}
			}
		}
//		cout << CC << " " << JJ << endl;
		c1=toDigit(C), j1=toDigit(J);
		c2=toDigit(CC),j2=toDigit(JJ);
//		printf("1: %d %d\n",c1,j1);
//		printf("2: %d %d\n",c2,j2);
		r1 = c1-j1;
		r2 = c2-j2;
		r1 = r1<0 ? -r1 : r1;
		r2 = r2<0 ? -r2 : r2;
		if(r1<r2) C=C, J=J;
		else if(r1>r2) C=CC, J=JJ;
		else {
			if(c1<c2) C=C, J=J;
			else if(c1>c2) C=CC, J=JJ;
			else if(j1<j2) C=C, J=J;
			else C=CC, J=JJ;
		}
		printf("Case #%d:",Case);
		cout << " " << C << " " << J << endl;
	}
	return 0;
}
