#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]){
	int T,nocase;
	string C,J;

	int i;
	int c,j;
	int ckc[3],ckj[3];
	int mc[3],mj[3];
	int vc[3],vj[3];
	//unsigned long long arr[100];

	int bc,bj,bv;

	cin >> T;  // read t. cin knows that t is an int, so it reads it as such.
	//T = 1;
	for (nocase = 1; nocase <= T; ++nocase) {
		cin >> C;
		cin >> J;
		reverse(C.begin(),C.end());
		reverse(J.begin(),J.end());

		//cout <<C<<endl;
		//cout <<J<<endl;

		bc = 1000; bj = 1000; bv = 1000;

		for(i=0;i<3;i++) {mc[i]=0;mj[i]=0;}
		
		for(i=0;i<C.length();i++){
			if(C[i]!='?')  {
				mc[i] = 1;
				vc[i] = C[i]-'0';
			}
		}
		for(i=0;i<J.length();i++){
			if(J[i]!='?'){
				mj[i] = 1;
				vj[i] = J[i]-'0';
			}
		}
		//printf("%d %d %d\n",mc[0],mc[1],mc[2]);
		//printf("%d %d %d\n",mj[0],mj[1],mj[2]);
		
		for(c=0;c<1000;c++){
			ckc[0] = c % 10;
			ckc[1] = (c /10) % 10;
			ckc[2] = c/100;
			if(ckc[2] && C.length()<=2) continue;
			if(ckc[1] && C.length()==1) continue;
			for(i=0;i<C.length();i++){
				if(!mc[i]) continue;
				if(ckc[i]!=vc[i]) break;
			}
			if(i!=C.length()) continue;
			//printf("c: %d\n",c);

			//
			for(j=0;j<1000;j++){
				ckj[0] = j%10;
				ckj[1] = (j/10)%10;
				ckj[2] = j/100;
				if(ckj[2] && J.length()<=2) continue;
				if(ckj[1] && J.length()==1) continue;
				for(i=0;i<J.length();i++){
					if(!mj[i]) continue;
					if(ckj[i]!=vj[i]) break;
				}
				if(i!=J.length()) continue;

				if(abs(c-j) < bv){
					//printf("%d %d\n",c,j);
					bv = abs(c-j);
					bc = c;
					bj = j;
				}
				else if(abs(c-j) == bv){
					//printf("%d %d\n",c,j);
					if(c < bc) bc = c;
					else if(j < bj) bj = j;
				}
			}
			//
		}
		
		ckc[0] = bc % 10;
		ckc[1] = (bc /10) % 10;
		ckc[2] = bc/100;
		ckj[0] = bj%10;
		ckj[1] = (bj/10)%10;
		ckj[2] = bj/100;

		cout << "Case #" << nocase << ": ";
		for(i=C.length()-1;i>=0;i--)
			cout << ckc[i];
		cout <<" ";
		for(i=J.length()-1;i>=0;i--)
			cout << ckj[i];
		cout << endl;
		//<< bc << " " << bj <<endl;
	}

	return 0;
}