#include <iostream>

using namespace std;

int isUsed[10];

void findINS(int N){
		int temp;
			int times = 1;
				while (1){
							temp = times*N;
									times++;
											while (1){
															if (temp == 0) break;
																		isUsed[temp % 10] = 1;
																					temp = temp / 10;
																							}
																									int aa = 0;
																											for (int i = 0; i < 10; i++){
																															if (isUsed[i] == 1) aa++;
																																	}
																																			if (aa == 10){
																																							cout << (times-1)*N << endl;
																																										return;
																																												}
																																													}
}

int main() {
		int num, N;
			cin >> num;

				for (int i = 0; i < num; i++){
							for (int j = 0; j < 10; j++){
											isUsed[j] = 0;
													}

															cin >> N;
															cout << "Case #"<<i+1<<": ";
																	if (N == 0) cout << "INSOMNIA" << endl;
																			else	findINS(N);
																				}
																					return 0;
}
