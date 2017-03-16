#include  <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int min_dif;
int cod, jam;
int tam;
int sum;
string coder, jammer;
string best_cod, best_jam;



void solve_jam(int sum_jam, int id){
	if(id >= tam){
		if(abs(sum - sum_jam) < min_dif){
			cod = sum;
			jam = sum_jam;
			min_dif = abs(sum - sum_jam);
			best_cod = coder;
			best_jam = jammer;
			return;
		}
		else if(abs(sum - sum_jam) == min_dif && sum < cod){
			cod = sum;
			best_cod = coder;
			best_jam = jammer;
			return;
		}
		else if(abs(sum - sum_jam) == min_dif && sum == cod && sum_jam < jam){
			jam = sum_jam;
			best_cod = coder;
			best_jam = jammer;
			return;
		}
		return;
	}

	if(jammer[tam - id - 1] == '?'){
		int pot = 1, cont = 0;
		while(cont < id){
			pot *= 10;
			cont++;
		}
		for(int i = 0; i <= 9; i++){
			jammer[tam - id - 1] = i + '0';
			solve_jam(sum_jam + i * pot, id + 1);
		}
		jammer[tam - id - 1] = '?';
	}
	else{
		int pot = 1, cont = 0;
		while(cont < id){
			pot *= 10;
			cont++;
		}
		solve_jam(sum_jam + (jammer[tam - id - 1] - '0') * pot, id + 1);
	}

}

void solve_cod(int sum_cod, int id){
	if(id >= tam){
		sum = sum_cod;
		solve_jam(0, 0);
		return;
	}

	if(coder[tam - id - 1] == '?'){
		int pot = 1, cont = 0;
		while(cont < id){
			pot *= 10;
			cont++;
		}
		for(int i = 0; i <= 9; i++){
			coder[tam - id - 1] = '0' + i;
			solve_cod(sum_cod + i * pot, id + 1);
		}
		coder[tam - id - 1] = '?';
	}
	else{
		int pot = 1, cont = 0;
		while(cont < id){
			pot *= 10;
			cont++;
		}
		solve_cod(sum_cod + (coder[tam - id - 1] - '0') * pot, id + 1);
	}
}

int main(){
	int casos;
	cin >> casos;

	for(int caso = 1; caso <= casos; caso++){
		printf("Case #%d: ", caso);

		cin >> coder >> jammer;
		tam = coder.length();

		min_dif = INF;
		solve_cod(0, 0);
		cout << best_cod << " " << best_jam << endl;
	}
}