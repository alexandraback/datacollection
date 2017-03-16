#include<iostream>
#include<string>

using namespace std;

string tenTotwo(int num){
		string temp, tmp;
			while (1){
						if (num == 0) break;
								if (num % 2 == 0) temp += "0";
										else temp += "1";
												num = num / 2;
													}
														tmp = temp;
															for (int i = 0; i < temp.length(); i++){
																		tmp[i] = temp[temp.length() - i - 1];
																			}
																				return tmp;
}

int convert(string a, int b){
		int temp = 0;
			for (int i = 0; i < a.length(); i++){
						if (a[i] == '1'){
										temp++;
												}
														temp = temp * b;
															}
																return temp/b;
}

int main(){
		int num, N, J;
			int tmpLen;
				cin >> num;

					for (int i = 0; i < num; i++){
								cin >> N;
										cin >> J;
												if (N % 2 == 0){
																tmpLen = N / 2;
																		}
																				else{
																								tmpLen = (N - 1) / 2;
																										}

																												cout << "Case #" << i + 1 << ":" << endl;
																														for (int j = 1; j < J+1; j++){
																																		string temp = tenTotwo(j);
																																					temp += "1";
																																								string tmp = temp;
																																											if (N>2 * temp.length()){
																																																for (int k = 0; k < N - 2 * tmp.length(); k++){
																																																						temp += "0";
																																																										}
																																																													}
																																																																temp += tmp;
																																																																			cout <<temp << " ";

																																																																						for (int k = 2; k <= 9; k++){
																																																																											cout << convert(tmp, k) <<" ";
																																																																														}
																																																																																	cout << convert(tmp, 10) << endl;
																																																																																			}
																																																																																				}
}
