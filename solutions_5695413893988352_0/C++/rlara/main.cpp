#include<iostream>
#include<algorithm>
#include<utility>
#include<string>
#include<vector>

using namespace std;

bool distintos(int i, string c, string j){
	if(c[i]=='?' && j[i]!='?')
		return true;
	if(c[i]!='?' && j[i]=='?')
		return true;
	if(c[i]=='?' && j[i]=='?')
		return true;
	if(c[i]==j[i])
		return true;
	return false;
}


string llena(char aux, string c, int k){
	string s;
	for(int l=k;l<c.size();l++){
		if(c[l]=='?') s.push_back(aux);
		else s.push_back(c[l]);
	}
	return s;
}

string igual(string c, string j, int k){
	string aux;
	int i;
//	cout << "aqui " << k << endl;
	for(i=0;i<k;i++){
		if(c[i]=='?' && j[i]=='?'){
			aux.push_back('0');
		}		
		else if(c[i]=='?' && j[i]!='?'){
			aux.push_back(j[i]); 
		}
		else if(c[i]!='?' && j[i]=='?'){
			aux.push_back(c[i]); 
		}
		else{
			aux.push_back(c[i]);
		}
	}	
	return aux;
}


bool esPosible1(string s1, string s2, int k){
	int i=0;
	if(k==0)
		return false;
	if(s1[k-1]=='?' && s2[k-1]=='?')
		return true;
	for(i=k-1;i>=0 && s1[i]=='0';i--);
	if(i<0 || (s1[i]!='1' && s1[i]!='?'))
		return false;
	for(int j=k-1;j>i;j--){
		if(s2[j]!='9' || s2[j]!='?')
			return false;
	}
	if(s2[i]!='0' || s2[i]!='?')
		return false;
	return true;
}


string cambio1(string s1, string s2, int k){
	int i=0;
	string aux;
	for(i=k-1;i>=0 && s1[i]=='0';i--);
	aux = igual(s1, s2, i);
	aux.push_back('1');
	for(int j=i;j<=k;j++)
		aux.push_back('0');
	return aux;
}

string cambio2(string s1, string s2, int k){
	int i=0;
	string aux;
	for(i=k-1;i>=0 && s1[i]=='0';i--);
	aux = igual(s1, s2, i);
	aux.push_back('0');
	for(int j=i;j<=k;j++)
		aux.push_back('9');
	return aux;
}

int main(){
	int t, i;
	string c, j;
	cin >> t;
	for(int tt=0;tt<t;tt++){
		cin >> c >> j;
		string c1, j1;
		cout << "Case #" << tt+1 << ": ";
		
		for(i=0;i<c.size() && distintos(i, c, j);i++);
		if(i<c.size()){
			if(i==0){
				if(c[i]<j[i]){
					c1 = llena('9', c, 0);
					j1 = llena('0', j, 0);
				}
				else{
					c1 = llena('0', c, 0);
					j1 = llena('9', j, 0);
				}	
			}
			else{
				if(c[i]<j[i]){
					if(j[i]-c[i]>5){
						if(j[i-1]!='9' && c[i-1]!='0'){
							c1 = j1 = igual(c, j, i-1);
							if(c[i-1]=='?' && j[i-1]=='?'){
								c1.push_back('1'); j1.push_back('0');
							}
							else if(c[i-1]!='?' && j[i-1]=='?'){
								c1.push_back(c[i-1]); j1.push_back(c[i-1]-1);
							}
							else if(c[i-1]=='?' && j[i-1]!='?'){
								c1.push_back(j[i-1]+1); j1.push_back(j[i-1]);
							}
							else{
								c1.push_back('1'); j1.push_back('0');
							}
							c1 = c1 + llena('0', c, i);
							j1 = j1 + llena('9', j, i);
						}
						else if(j[i-1]=='9'){
							if( esPosible1(c, j, i-1) ){
								c1 = cambio1(c, j, i-1);
								j1 = cambio2(c, j, i-1);
								c1 = c1 + llena('0', c, i);
								j1 = j1 + llena('9', j, i);
							}
							else{
								c1 = j1 = igual(c, j, i);
								c1 = c1 + llena('9', c, i);
								j1 = j1 + llena('0', j, i);
							} 
						}
						else{ //c[i-1]==0
							if(esPosible1(j, c, i) ){
								c1 = cambio2(c, j, i-1);
								j1 = cambio1(c, j, i-1);
								c1 = c1 + llena('0', c, i);
								j1 = j1 + llena('9', j, i);
							}
							else{
								c1 = j1 = igual(c, j, i);
								c1 = c1 + llena('9', c, i);
								j1 = j1 + llena('0', j, i);
							} 
						}			
					}
					else{
						c1 = j1 = igual(c, j, i);
						c1 = c1 + llena('9', c, i);
						j1 = j1 + llena('0', j, i);
					}
				}
				else{
					if(c[i]-j[i]>5){
						
					}
					else{
						c1 = j1 = igual(c, j, i);
						c1 = c1 + llena('0', c, i);
						j1 = j1 + llena('9', j, i);
					}
				}
			}
			
		}
		else{
			//cout << c << " " << j << endl;
			j1 = c1 = igual(c, j, c.size() );	
		}
	
		cout << c1 << " " << j1 << endl; 
	}
	return 0;
} 




