#include<iostream>
#include<string>

using namespace std;

int main(){
		int num;
			int K, C, S;
				cin >> num;

					for (int i = 0; i < num; i++){
								cin >> K >> C >> S;
										cout << "Case #" << i + 1 << ": ";
												if (K>C*S) cout << "IMPOSSIBLE" << endl;
														else{
																		int t = 0;
																					if (K%C == 0)t = K / C;
																								else t = 1 + (K / C);
																											for (int j = 0; j < t; j++){
																																long long int temp = 0;
																																				for (int k = 0; k < C; k++){
																																										if (j*C + k + 1 > K) temp = temp;
																																															else temp+=(j*C + k);
																																																				if(k!=C-1)temp *= K;
																																																								}
																																																												if (j != 0) cout << " ";
																																																																cout << (temp) + 1;
																																																																			}
																																																																						cout << endl;
																																																																								}
																																																																									}
}
