#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	string S;
	cin>>T;
	
	for(int k=0;k<T;k++){
		cin>>S;
		int n[20];
		int pos;
		for(int i=0;i<20;i++){
			n[i]=0;
		}
		
		//buscar Z (nº 0)
		int nz=0;
		int ne=0;
		int nr=0;
		int no=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='Z'){
				n[0]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='Z' && nz<n[0]){
				nz++;
				S.erase(pos,1);
			}
			else if(S[pos]=='E' && ne<n[0]){
				ne++;
				S.erase(pos,1);
			}
			else if(S[pos]=='R' && nr<n[0]){
				nr++;
				S.erase(pos,1);
			}
			else if(S[pos]=='O' && no<n[0]){
				no++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar W (nº 2)
		int nt=0;
		int nw=0;
		no=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='W'){
				n[2]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='T' && nt<n[2]){
				nt++;
				S.erase(pos,1);
			}
			else if(S[pos]=='W' && nw<n[2]){
				nw++;
				S.erase(pos,1);
			}
			else if(S[pos]=='O' && no<n[2]){
				no++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar X (nº 6)
		int ns=0;
		int ni=0;
		int nx=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='X'){
				n[6]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='S' && ns<n[6]){
				ns++;
				S.erase(pos,1);
			}
			else if(S[pos]=='I' && ni<n[6]){
				ni++;
				S.erase(pos,1);
			}
			else if(S[pos]=='X' && nx<n[6]){
				nx++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar U (nº 4)
		int nf=0;
		no=0;
		int nu=0;
		nr=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='U'){
				n[4]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='F' && nf<n[4]){
				nf++;
				S.erase(pos,1);
			}
			else if(S[pos]=='O' && no<n[4]){
				no++;
				S.erase(pos,1);
			}
			else if(S[pos]=='U' && nu<n[4]){
				nu++;
				S.erase(pos,1);
			}
			else if(S[pos]=='R' && nr<n[4]){
				nr++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar F (nº 5)
		nf=0;
		ni=0;
		int nv=0;
		ne=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='F'){
				n[5]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='F' && nf<n[5]){
				nf++;
				S.erase(pos,1);
			}
			else if(S[pos]=='I' && ni<n[5]){
				ni++;
				S.erase(pos,1);
			}
			else if(S[pos]=='V' && nv<n[5]){
				nv++;
				S.erase(pos,1);
			}
			else if(S[pos]=='E' && ne<n[5]){
				ne++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar V (nº 7)
		ns=0;
		ne=0;
		nv=0;
		int nn=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='V'){
				n[7]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='S' && ns<n[7]){
				ns++;
				S.erase(pos,1);
			}
			else if(S[pos]=='E' && ne<2*n[7]){
				ne++;
				S.erase(pos,1);
			}
			else if(S[pos]=='V' && nv<n[7]){
				nv++;
				S.erase(pos,1);
			}
			else if(S[pos]=='N' && nn<n[7]){
				nn++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar R (nº 3)
		nt=0;
		int nh=0;
		nr=0;
		ne=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='R'){
				n[3]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='T' && nt<n[3]){
				nt++;
				S.erase(pos,1);
			}
			else if(S[pos]=='H' && nh<n[3]){
				nh++;
				S.erase(pos,1);
			}
			else if(S[pos]=='R' && nr<n[3]){
				nr++;
				S.erase(pos,1);
			}
			else if(S[pos]=='E' && ne<2*n[3]){
				ne++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar G (nº 8)
		ne=0;
		ni=0;
		int ng=0;
		nh=0;
		nt=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='G'){
				n[8]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='E' && ne<n[8]){
				ne++;
				S.erase(pos,1);
			}
			else if(S[pos]=='I' && ni<n[8]){
				ni++;
				S.erase(pos,1);
			}
			else if(S[pos]=='G' && ng<n[8]){
				ng++;
				S.erase(pos,1);
			}
			else if(S[pos]=='H' && nh<n[8]){
				nh++;
				S.erase(pos,1);
			}
			else if(S[pos]=='T' && nt<n[8]){
				nt++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//buscar I (nº 9)
		nn=0;
		ni=0;
		ne=0;
		for(int i=0;i<S.length();i++){
			if(S[i]=='I'){
				n[9]++;
			}
		}
		pos=0;
		while(true){
			if(S[pos]=='N' && nn<2*n[9]){
				nn++;
				S.erase(pos,1);
			}
			else if(S[pos]=='I' && ni<n[9]){
				ni++;
				S.erase(pos,1);
			}
			else if(S[pos]=='E' && ne<n[9]){
				ne++;
				S.erase(pos,1);
			}
			else pos++;
			if(pos>=S.length()) break;
		}
		//longitud cadena / 3 (nº 1)
		n[1]=S.length()/3;
		
		cout<<"Case #"<<(k+1)<<": ";
		for(int j=0;j<10;j++){
			while(n[j]>0){
				cout<<j;
				n[j]--;
			}
		}
		cout<<endl;
	}
}
