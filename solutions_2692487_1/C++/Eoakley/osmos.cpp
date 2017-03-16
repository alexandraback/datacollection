#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
long long unsigned int A, k;
vector<long long unsigned int> vet;
int best=9999999;

int inc(int qtd) {
	//cout << "inc: qtd N "<< qtd << " " << N<<endl;
	int peguei=0;
	int front, pos=0;
	int size = A;
	int resp=0;
	while(peguei < qtd) {
	//nao pegueit odos
	//cout<<"  size "<<size << " - pguei: "<<peguei<< " qtd: " << qtd<<" front: "<<front<<endl;
		while(pos <= qtd) { //enqt conseguir pegar
			front = vet[pos];
			if(size > front) { //peguei
				size += front;
				peguei++;
				pos++;
			}
			else break;
		}
		if(peguei < qtd) {
		//se nao peguei todos
			while(1) {//nao consigo pegar o proximo
				//adiciona mais
				if(size <= front) {
					if(size - 1 == 0) return 999923232;
					resp++;
					size = size + (size-1);
					if(resp > best) return 999999988;
				}
				else break;
			}
		}
	}
	//cout << "resp: " << resp << endl;
	return resp;
}

int main() {
	int T;
	cin >> T;
	int C=1;
	
	while(T-- > 0) {

		cin >> A >> N;

		while(!vet.empty()) vet.erase(vet.begin());

		for(int i=0;i<N;i++) {
			cin >> k;
			vet.push_back(k);
		}
		
		int resp=0;
		
		sort(vet.begin(),vet.end());
		
		
		best = 99999999;
		
		//cout << A << " " << vet[0] << " " << vet[1] <<endl;
		
		for(int i=0;i<=N;i++) {
			resp = inc(N-i) + i;
			if(resp < best) best = resp;
			//remove i, ve qual eha resposta soh adicionando apos isso
		}

		cout << "Case #"<<C++<<": "<<best<<endl;
	}

	return 0;
}

