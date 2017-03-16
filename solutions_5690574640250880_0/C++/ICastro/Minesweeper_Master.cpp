#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
	int T;
	cin >> T;
	for (int k = 0; k < T; ++k){
		cout << "Case #" << k+1 << ":" << endl;
		int R, C, M;
		cin >> R >> C >> M;
		if (R * C == M+1){
			cout << "c";
			for (int j = 1; j < C; ++j){
				cout << "*";
			}
			cout << endl;
			for (int i = 1; i < R; ++i){
				for (int j = 0; j < C; ++j){
					cout << "*";
				}
				cout << endl;
			}
		} else if (R == 1){
			cout << "c";
			for (int i = 0; i < C - M - 1; ++i){
				cout << ".";
			}
			for (int i = 0; i < M; ++i){
				cout << "*";
			}
			cout << endl;
		} else if (C == 1){
			cout << "c" << endl;
			for (int i = 0; i < R - M - 1; ++i){
				cout << "." << endl;
			}
			for (int i = 0; i < M; ++i){
				cout << "*" << endl;
			}
		} else if (M == 2 && R == 2 && C == 2){
			cout << "Impossible" << endl;
		} else if (R == 2){
			if (M%2 == 1 || R * C == M+2){
				cout << "Impossible" << endl;
			} else {
				cout << "c";
				for (int i = 1; i < C - M/2; ++i){
					cout << ".";
				}
				for (int i = 0; i < M/2; ++i){
					cout << "*";
				}
				cout << endl;
				cout << ".";
				for (int i = 1; i < C - M/2; ++i){
					cout << ".";
				}
				for (int i = 0; i < M/2; ++i){
					cout << "*";
				}
				cout << endl;
			}
		} else if (C == 2){
			if (M%2 == 1 || R * C == M + 2){
				cout << "Impossible" << endl;
			} else {
				cout << "c." << endl;
				for (int i = 1; i < R - M/2; ++i){
					cout << ".." << endl;
				}
				for (int i = 0; i < M/2; ++i){
					cout << "**" << endl;
				}
			}
		} else {
			if (R * C - M < 4){
				cout << "Impossible" << endl;
			} else {
				if (2*C <= R*C - M){
					if(C - (M - M/C*C) == 1){
						if (C == 3){
							if (R*C - M == 7){
								cout << "Impossible" << endl;
							} else {
								cout << "c.." << endl;
								for (int i = 1; i < R - M/C - 2; ++i){
									for (int j = 0; j < C; ++j){
										cout << ".";
									}
									cout << endl;
								}
								cout << "..*" << endl;
								cout << "..*" << endl;
								for (int i = 0; i < M/C; ++i){
									for (int j = 0; j < C; ++j){
										cout << "*";
									}
									cout << endl;
								}
							}
						} else {
							if (R*C - M == C*2 + 1){
								cout << "c";
								for (int i = 1; i < C-1; ++i){
									cout << ".";
								}
								cout << "*";
								cout << endl;
								for (int i = 0; i < C-1; ++i){
									cout << ".";
								}
								cout << "*";
								cout << endl;
								cout << "...";
								for (int j = 0; j < M - M/C*C - 2; ++j){
									cout << "*";
								}
								cout << endl;
								for (int i = 0; i < M/C; ++i){
									for (int j = 0; j < C; ++j){
										cout << "*";
									}
									cout << endl;
								}
							} else {
								cout << "c";
								for (int i = 1; i < C; ++i){
									cout << ".";
								}
								cout << endl;
								for (int i = 1; i < R - M/C - 2; ++i){
									for (int j = 0; j < C; ++j){
										cout << ".";
									}
									cout << endl;
								}
								for (int j = 0; j < C - 1; ++j){
									cout << ".";
								}
								cout << "*" << endl;
								cout << "..";
								for (int j = 0; j < M - M/C*C - 1; ++j){
									cout << "*";
								}
								cout << endl;
								for (int i = 0; i < M/C; ++i){
									for (int j = 0; j < C; ++j){
										cout << "*";
									}
									cout << endl;
								}
							}
						}
					} else {
						cout << "c";
						for (int i = 1; i < C; ++i){
							cout << ".";
						}
						cout << endl;
						//...
						for (int i = 1; i < R - M/C - 1; ++i){
							for (int j = 0; j < C; ++j){
								cout << ".";
							}
							cout << endl;
						}
						for (int j = 0; j < C - (M - M/C*C); ++j){
							cout << ".";
						}
						for (int j = 0; j < M - M/C*C; ++j){
							cout << "*";
						}
						cout << endl;
						for (int i = 0; i < M/C; ++i){
							for (int j = 0; j < C; ++j){
								cout << "*";
							}
							cout << endl;
						}
					}
				} else {
					if ((R*C - M)%2 == 0){
						//////////
						cout << "c";
						for (int i = 1; i < (R*C - M)/2; ++i){
							cout << ".";
						}
						for (int i = 0; i < C - (R*C - M)/2; ++i){
							cout << "*";
						}
						cout << endl;
						for (int i = 0; i < (R*C - M)/2; ++i){
							cout << ".";
						}
						for (int i = 0; i < C - (R*C - M)/2; ++i){
							cout << "*";
						}
						cout << endl;
						///////////////
						for (int i = 2; i < R; ++i){
							for (int i = 0; i < C; ++i){
								cout << "*";
							}
							cout << endl;
						}
					} else {
						if (R*C - M == 5 || R*C - M == 7){
							cout << "Impossible" << endl;
						} else {
							//////////////////
							cout << "c";
							for (int i = 1; i < (R*C - M - 3)/2; ++i){
								cout << ".";
							}
							for (int i = 0; i < C - (R*C - M - 3)/2; ++i){
								cout << "*";
							}
							cout << endl;
							for (int i = 0; i < (R*C - M - 3)/2; ++i){
								cout << ".";
							}
							for (int i = 0; i < C - (R*C - M - 3)/2; ++i){
								cout << "*";
							}
							cout << endl;
							//////////////////
							cout << "...";
							for (int j = 0; j < C - 3; ++j){
								cout << "*";
							}
							cout << endl;
							for (int i = 3; i < R; ++i){
								for (int j = 0; j < C; ++j){
									cout << "*";
								}
								cout << endl;
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
