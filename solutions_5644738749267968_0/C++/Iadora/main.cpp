#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

inline void insert_order(vector<double> &elements, double new_element){

	int size = elements.size();
		
	int i=0;
	while(i<size && new_element> elements[i]){

		i++;
	}

	elements.insert(elements.begin() +i, new_element);
}

int main(int argc, char** argv){

	if(argc<2){

		return -1;
	}
	
	ifstream fichier_input(argv[1], ios::in);
	ofstream fichier_output("output2", ios::out);

	if(!fichier_input){

		cout << "ERROR : incorrect input"<<endl;
		return -1;
	}

	int n_test;

	fichier_input >> n_test;

	for(int round=1; round<=n_test; round++){

		int n_weights;
		fichier_input >> n_weights;
		
		vector<double> weights_Nao;
		for(int i=0; i<n_weights; i++){

			double elem;
			fichier_input>>elem;
			insert_order(weights_Nao, elem);
		}
	
		vector<double> weights_Ken;
		for(int i=0; i<n_weights; i++){

			double elem;
			fichier_input>>elem;
			insert_order(weights_Ken, elem);
		}

		int score_war =0;
		int score_cheat =0;	
		vector<bool> situation_Ken;

		for(int i=0; i<n_weights; i++){

			situation_Ken.push_back(true);
		}

		//If Naomi cheats
		for(int i=0; i<n_weights; i++){

			//Get the minimal non used element of Vector_Ken
			int indice =0;
			while(indice < n_weights && !situation_Ken[indice]){

				indice++;
			}
			if(indice==n_weights){
	
				cout << "BWAAA"<<endl;	
			}
			if(weights_Nao[i] < weights_Ken[indice]){

				//Get the maximal unused element of Vector_Ken and discard it
				int i_Ken=n_weights-1;
				while(i_Ken>=0 && !situation_Ken[i_Ken]){

					i_Ken--;
				}
				situation_Ken[i_Ken]=false;
			}
			else{
	
				score_cheat++;
				situation_Ken[indice]=false;
			}
		}

		//If she plays fair
		for(int i=0; i<n_weights; i++){

			situation_Ken[i] = true;
		}


		for(int i=0; i<n_weights; i++){

			//Get the minimal non used element of Vector_Ken which is higher than Naomi's
			int indice =0;
			while(indice < n_weights &&( weights_Ken[indice] < weights_Nao[i] || !situation_Ken[indice])){
				
				indice++;
			}

			//If their is no such elements
			if(indice==n_weights){

				//Then discard the smallest element possible

				indice =0;
				while(indice < n_weights && !situation_Ken[indice]){

					indice++;
				}
				situation_Ken[indice] = false;

				//Naomi scores
				score_war++;

			}
			//Else : discard this element
			else{

				situation_Ken[indice] = false;
			}
		}
		
		fichier_output << "Case #" << round << ": " << score_cheat << " " <<score_war <<endl;
	}
}

			
		
		
