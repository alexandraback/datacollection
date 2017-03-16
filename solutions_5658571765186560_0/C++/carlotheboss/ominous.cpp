#include <bits/stdc++.h>
using namespace std;

int T, R, C, X;

int main() {
	ios::sync_with_stdio(false);
	ifstream in("input.txt");
	ofstream out("output.txt");
	in >> T;
	for(int i=1;i<=T;i++) {
	   in >> X >> R >> C;
	   if(R>C) swap(R,C);
	   out<<"Case #"<<i<<": ";
	   if(R==1) {
		   if(C==1) {
			   if(X==1) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else if(C==2) {
			   if(X==1 || X==2) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else if(C==3) {
			   if(X==1) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else {
			   if(X==1 || X==2) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
	   }
	   else if(R==2) {
		   if(C==2) {
			   if(X==1 || X==2) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else if(C==3) {
			   if(X==1 || X==2 || X==3) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else {
			   if(X==1 || X==2) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }		   
	   }
	   else if(R==3) {
		   if(C==3) {
			   if(X==1 || X==3) out<<"GABRIEL\n";
			   else out<<"RICHARD\n";
		   }
		   else {
			   out<<"GABRIEL\n";
		   }  
	   }
	   else {
	       if(X==1 || X==2 || X==4) out<<"GABRIEL\n";
		   else out<<"RICHARD\n";
       }
    }
	return 0;
}
