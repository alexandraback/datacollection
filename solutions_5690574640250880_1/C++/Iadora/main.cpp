#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char** argv){

	if(argc<2){

		return -1;
	}
	
	ifstream fichier_input(argv[1], ios::in);
	ofstream fichier_output("output", ios::out);

	if(!fichier_input){

		cout << "ERROR : incorrect input"<<endl;
		return -1;
	}

	int n_test;

	fichier_input >> n_test;

	for(int round=1; round<=n_test; round++){

		int R, C, M;

		fichier_input >> R >> C >> M;
		fichier_output << "Case #"<< round << ":"<<endl;
		
		int tot_empty = R*C -M;
		if(tot_empty==1){

			fichier_output<< "c";
			for(int i=1; i<C; i++){

				fichier_output << "*";
			}
			fichier_output <<endl;
			for(int j=1; j<R; j++){

				for(int i=0; i<C; i++){

					fichier_output << "*";
				}
				fichier_output <<endl;
			}
		}
		else if(tot_empty <=0){
			fichier_output <<"Impossible"<<endl;
		}
		else if(R>2 && C>2){

			if(tot_empty ==2 || tot_empty ==3 || tot_empty ==5 || tot_empty ==7){

				fichier_output <<"Impossible"<<endl;
			}
			else{
		
				bool** field = new bool*[R];
				for(int i=0; i<R; i++){

					field[i] = new bool[C];
					for(int j=0; j<C; j++){

						field[i][j] = true;
					}
				}

				//Step one : find the biggest rectangle possible to include all of the empty cells
				int p=2;
				int q=2;
				bool p_last_hit = true;
				while(p*q < tot_empty && p<=R && q<=C){
					
					if(p==R){

						if((q+1)*p > tot_empty){
						
							break;
						}
						else{
							q++;
						}
					}
					else if(q==C){

						if((p+1)*q > tot_empty){

							break;
						}
						else{

							p++;
						}
					}
					else{

						if((p+1)*q > tot_empty){

							if((q+1)*p > tot_empty){

								break;
							}
							else{
							
								q++;
							}
						}
						else{

							if((q+1)*p > tot_empty){

								p++;
							}
							else{
					
								if(p_last_hit){
								
									q++;
								}
								else{
									p++;
								}
								p_last_hit = !p_last_hit;
							}
						}
					}	
				}

				//Fill the matrix
				for(int i=0; i<p; i++){

					for(int j=0; j<q; j++){

						field[i][j] = false;
					}
				}

				//Then : fill the remaining blanks
	
				int remaining = tot_empty-p*q;
				if(p<R){

					if(remaining ==1){

						field[p-1][q-1] = true;
						field[p][0]=false;
						field[p][1] = false;
					}
					else{

						for(int i=0; i< remaining; i++){

							field[p][i] = false;
						}
					}
				}
				else{

					if(remaining ==1){

						field[p-1][q-1] = true;
						field[0][q]=false;
						field[1][q] = false;
					}
					else{

						for(int i=0; i< remaining; i++){

							field[i][q] = false;
						}
					}
				}

				//Write the output

				fichier_output << "c";
				for(int i=1; i<C; i++){

					if(field[0][i]){

						fichier_output << "*";
					}
					else{

						fichier_output << ".";
					}
				}
				fichier_output <<endl;
				for(int i=1; i<R; i++){

					for(int j=0; j<C; j++){

						if(field[i][j]){

							fichier_output << "*";
						}
						else{

							fichier_output << ".";
						}
					}
					fichier_output <<endl;
				}
			}
		}
		else if(R==2 && C>=2){

			if(tot_empty % 2 ==1 || tot_empty == 2){

				fichier_output << "Impossible" <<endl;
			}
			else{
					
				int mid = tot_empty/2;
				fichier_output << "c";
				for(int i=1; i<mid; i++){

					fichier_output << ".";
				}
				for(int i=mid; i<C; i++){

					fichier_output<<"*";
				}
				fichier_output<<endl;
				for(int i=0; i<mid; i++){

					fichier_output << ".";
				}
				for(int i=mid; i<C; i++){

					fichier_output<<"*";
				}
				fichier_output<<endl;
			}
		}
		else if(C==2 && R>2){

			if(tot_empty % 2 ==1 || tot_empty == 2){

				fichier_output << "Impossible" <<endl;
			}
			else{
					
				int mid = tot_empty/2;
				fichier_output << "c"<< "." <<endl;

				for(int i=1; i<mid; i++){

					fichier_output << ".." <<endl;
				}
				for(int i=mid; i<R; i++){

					fichier_output<<"**"<<endl;
				}
			}
		}
		else if(C==1){

			fichier_output << "c" <<endl;
			for(int i=1; i<tot_empty; i++){

				fichier_output << "."<<endl;
			}
			for(int i=tot_empty; i<R; i++){

				fichier_output << "*"<<endl;
			}
		}
		else{

			fichier_output << "c";
			for(int i=1; i<tot_empty; i++){

				fichier_output << ".";
			}
			for(int i= tot_empty; i<C; i++){

				fichier_output << "*";
			}
			fichier_output <<endl;
		}
	}
}
					
				
	
				

				
					
				
				
				
		
