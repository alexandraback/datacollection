#include <bits/stdc++.h>
using namespace std;

string C, J, C2, J2; 
bool cMin, jMin;

void fillRight2(int idx){	
	for(int i=idx; i<C2.size(); i++){
		if(C2[i]=='?' && J2[i]=='?'){
			if(cMin){
				C2[i] = '9';
				J2[i] = '0';				
			}
			else{
				C2[i] = '0';
				J2[i] = '9';
			}			
		}
		else if(C2[i]=='?' || J2[i]=='?'){
			if(C2[i]=='?'){
				if(cMin) C2[i] = '9';
				else C2[i] = '0';
			}
			else{
				if(jMin) J2[i] = '9';
				else J2[i] = '0';
			}
		}		
	}
}

void fillLeft2(int idx){
	for(int i=idx; i>=0; i--){
		if(C2[i]=='?' && J2[i]=='?'){
			C2[i] = J2[i] = '0';			
		}
		else if(C2[i]=='?'){
			C2[i] = J2[i];			
		}
		else if(J2[i]=='?'){
			J2[i] = C2[i];
		}		
	}
}

void fillRight(int idx){
	for(int i=idx; i<C.size(); i++){
		if(C[i]=='?' && J[i]=='?'){
			if(cMin){
				C[i] = '9';
				J[i] = '0';				
			}
			else{
				C[i] = '0';
				J[i] = '9';
			}			
		}
		else if(C[i]=='?' || J[i]=='?'){
			if(C[i]=='?'){
				if(cMin) C[i] = '9';
				else C[i] = '0';
			}
			else{
				if(jMin) J[i] = '9';
				else J[i] = '0';
			}
		}		
	}
}

void fillLeft(int idx){
	for(int i=idx; i>=0; i--){
		if(C[i]=='?' && J[i]=='?'){
			C[i] = J[i] = '0';			
		}
		else if(C[i]=='?'){
			C[i] = J[i];			
		}
		else if(J[i]=='?'){
			J[i] = C[i];
		}		
	}
}

bool checkLeft(int idx){
	bool allnine = true, allzero = true;
	for(int i=idx; i>=0; i--){
		if(cMin && C[i] != '0') allzero = false;
		if(jMin && J[i] != '0') allzero = false;
		if(cMin && J[i] != '9') allnine = false;
		if(jMin && C[i] != '9') allnine = false;		
	}
	return !(allnine || allzero);
}

void complete(int idx){
	for(int i=idx; i>=0; i--){
		if(C[i]=='?' && J[i]=='?'){
			if(cMin){
				C[i] = '0'; J[i] = '1';
			}
			else{
				C[i] = '1'; J[i] = '0';
			}
			fillLeft(i-1);
			return;
		}
		else if(C[i]=='?'){
			if(cMin){
				if(J[i]!='0'){
					C[i] = J[i]-1;
					fillLeft(i-1);
					return;
				}
				else C[i] = '9';				
			}
			else{
				if(J[i]!='9') {
					C[i] = J[i]+1;
					fillLeft(i-1);
					return;
				}
				else C[i] = '0';
			}
		}
		else if(J[i]=='?'){			
			if(jMin){
				if(C[i]!='0') {
					J[i] = C[i]-1;
					fillLeft(i-1);
					return;
				}
				else J[i] = '9';				
			}
			else{
				if(C[i]!='9') {
					J[i] = C[i]+1;
					fillLeft(i-1);
					return;
				}
				else J[i] = '0';
			}
		}		
	}
}

int main(){
	int t; cin >> t;
	for(int k=1; k<=t; k++){
		cin >> C >> J; cMin = jMin = false;
		int idx = 0;
		for(int i=0; i<C.size(); i++){
			if(C[i]!='?' && J[i]!='?' && C[i]!=J[i]) break;
			idx++;
		}
		if(idx==C.size()){
			fillLeft(idx-1);				
		}		
		else{
			int nC = C[idx]-'0';
			int nJ = J[idx]-'0';
			if(nC<nJ) cMin = true; //<=?
			jMin = 1-cMin;
			if(abs(nC-nJ) < 10+min(nC,nJ)-max(nC,nJ)){ //<=?				
				fillLeft(idx-1);				
				fillRight(idx+1); //use cMin and jMin
			}
			else{
				if(abs(nC-nJ) == 10+min(nC,nJ)-max(nC,nJ)){
					C2 = C; J2 = J;
					fillLeft2(idx-1);
					fillRight2(idx+1);
				}					
				bool ok = checkLeft(idx-1); // check 999... in big and 000... in small				
				if(ok){					
					cMin = 1-cMin;
					jMin = 1-jMin;
					complete(idx-1); //will call fillLeft					
					fillRight(idx+1);
				}
				else{
					fillLeft(idx-1);
					fillRight(idx+1);
				}	
				if(abs(nC-nJ) == 10+min(nC,nJ)-max(nC,nJ)){
					cMin = 1-cMin;
					jMin = 1-jMin;
				}	
				if(abs(nC-nJ) == 10+min(nC,nJ)-max(nC,nJ)){
					istringstream isC(C), isC2(C2), isJ(J), isJ2(J2);					
					long long dC, dC2, dJ, dJ2;				
					isC >> dC; isC2 >> dC2; isJ >> dJ; isJ2 >> dJ2;
					if(dC2 < dC || dC2 == dC && dJ2 < dJ){
						C = C2;
						J = J2;
					}
				}	
			}
		}
		cout << "Case #" << k << ": " << C << " " << J << "\n";
	}
	return 0;
}