#include<iostream>
#include<string>
#define MAXN 5003
using namespace std;

int t,act;
string s;
int ilosc_liter[MAXN];
int ilosc_takich_cyfr[MAXN];

string pattern[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
char letter[] = {'Z','E','T','R','U','F','X','V','G','I'};

int kol[] = {6,4,0,5,7,8,3,2,9,1};

int main(){
	cin >> t;
	
	for(int test = 1; test <= t; test++){
		cin >> s;
		
		for(int i = 0; i < 15; i++)ilosc_takich_cyfr[i] = 0;
		
		for(int i = 0; i < s.size(); i++){
			ilosc_liter[s[i]]++;
		}
		/*
		for(int i = 'A'; i <= 'Z'; i++){
			cout <<i<<":" << ilosc_liter[i]<<endl;
		}*/
		
		for(int ind = 0; ind < 10; ind++){
			act = kol[ind];
			ilosc_takich_cyfr[act] += ilosc_liter[letter[act]];
			
			for(int i = 0; i < pattern[act].size(); i++){
				ilosc_liter[pattern[act][i]]-= ilosc_takich_cyfr[act];
			}
			
		}
		
		cout << "Case #"<<test<<": ";
		for(int i = 0; i < 10; i++){
			for(int j = 0; j < ilosc_takich_cyfr[i]; j++){
				cout << i;
			}
		}
		cout << endl;
		
	
	} 

return 0;
}
