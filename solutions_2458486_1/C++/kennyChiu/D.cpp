#include <iostream>
#include <math.h>
#include <sstream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//from chest_id,  to key type

bool reachkey(vector<int> chest_type, vector<bool> opened, vector<vector<int> > keys_inside, int from, int to){
	//cout << "chest id" << from ;
	int i, j;
	int N=chest_type.size();
	bool* visited = new bool[N];
	for (i=0;i<N;i++){
		visited[i] = opened[i];
	}
	visited[from] = true;
	
	queue<int> q;

	for (i=0;i<keys_inside[from].size();i++){
		q.push(keys_inside[from][i]);
		if (keys_inside[from][i] == to){
			delete [] visited;
			return true;
		}
	}
	while(!q.empty()){
		int key_in = q.front();
		//cout <<" key use : " << key_in;
		q.pop();
		for (i=0;i<N;i++){
			if (!visited[i] && chest_type[i] == key_in){
				visited[i] = true;
				for (j=0;j<keys_inside[i].size();j++){
					q.push(keys_inside[i][j]);
					if (keys_inside[i][j] == to){
						delete [] visited;
						return true;
					}
				}
			}
		}
	}
	delete [] visited;
	return false;
}


bool someonereach(int k2k[201][201], int from, int to){
	bool visited[201];
	int i;
	for (i=0;i<201;i++){
		visited[i] = false;
	}

	queue<int> q;
//	bool found = false;
	q.push(from);
	while(!q.empty()){
		int in = q.front();
		q.pop();
		if (!visited[in]){
			visited[in] = true;
			for (i=0;i<201;i++){
				if (k2k[in][i] > 0){
					q.push(i);
					if (i == to){
						return true;
					}
				}
			}
		}
	}
	return false;
}


int main(){
	int T;
	cin >> T;
	int i,j,k;

	for (i=1;i<=T;i++){
		int my_K, N;
		cin >> my_K >> N;

		int keys[201];
		int keys4chest[201];
		int num_keys = my_K;
		int key2key[201][201];

		for (j=0;j<201;j++){
			keys[j] = 0;
			keys4chest[j] = 0;
			for (k=0;k<201;k++){
				key2key[j][k] = 0;
			}
		}

		for (j=0;j<my_K;j++){
			int k_types;
			cin >> k_types;
			keys[k_types]++;
		}

		vector<int> chest_type;
		vector<bool> opened;
		vector<int> num_inside;
		vector<vector<int> > keys_inside;
		int num_chest = N;


		for (j=0;j<N;j++){
			int c_type;
			cin >> c_type;
			chest_type.push_back(c_type);
			opened.push_back(false);
			keys4chest[c_type]++;

			vector<int> keys_in;
			int n_k;
			cin >> n_k;
			num_inside.push_back(n_k);
			
			for (k=0;k<n_k;k++){
				int k_type;
				cin >> k_type;
				keys_in.push_back(k_type);
				key2key[c_type][k_type]++;
			}
			keys_inside.push_back(keys_in);
		}

		bool found = false;
		vector<int> order;
		while (num_chest > 0){
			//find the nearest chest able to open
			int id_chest = -1;
			int id_type = 0;
			found = false;

			for (j=0;j<N;j++){
				bool opened_it = false;
				if (!opened[j] && keys[chest_type[j]] > 0){
					// check key enough for opening all that type of chest?
					// check any other chest need to same key
					if (keys[chest_type[j]] >= keys4chest[chest_type[j]]){
						//open it
						opened_it = true;
					}else if (keys[chest_type[j]] > 1){
						//open it
						opened_it = true;

						// check that key can return same type of key
					}else if (reachkey(chest_type, opened, keys_inside, j, chest_type[j])){
						//open it
						opened_it = true;

						// check any other key can return the same type of key
					}else {
						for(k=0;k<201;k++){
							if (keys[k] > 0 && k != chest_type[j]  ){
								if (someonereach(key2key, k, chest_type[j])){
//								if (reachkey(chest_type, opened, keys_inside, k, chest_type[j])){
									//open it
									opened_it = true;
									break;
								}
							}
						}
					}

					if (opened_it){
						id_chest = j;
						id_type = chest_type[j];
						found = true;
						break;
					}
				}
			}
			if (found){
				//cout << id_chest + 1 << endl;
				//reduce key
				order.push_back(id_chest+1);
				keys[id_type]--;
				keys4chest[id_type]--;
				num_keys --;
				num_chest--;
				//open chest
				opened[id_chest] = true;
				//get keys
				if (num_inside[id_chest] > 0){
					num_keys += num_inside[id_chest];
					for (j=0;j<num_inside[id_chest];j++){
						keys[keys_inside[id_chest][j]]++;
						key2key[id_type][keys_inside[id_chest][j]]--;
					}
				}
			}

			if (!found){
				break;
			}
		}
		if (found){
			cout<<"Case #"<< i<< ":";
			for (j=0;j<order.size();j++){
				cout <<" " << order[j];
			}
			cout << endl;
		}else{
			cout <<"Case #"<< i <<": IMPOSSIBLE" <<endl;
		}


	}

	return 0;
}