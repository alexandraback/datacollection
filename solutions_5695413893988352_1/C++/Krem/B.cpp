#include<cstdio>
#include<cstring>

char C[20], J[20];
char tmpC[20], tmpJ[20];
char bestC[20], bestJ[20];
char decision[20];

bool flip(int l) {
	for (int i = l-1; i >= 0; --i) {
		if(decision[i] == -1) {
			decision[i] = 1;
			return true;
		}
		if(decision[i] == 1) {
			decision[i] = 0;
			if (i > 0)
				decision[i-1] = -1;
			return true;
		}
	}
	return false;
}

int main() {
	int T; scanf("%d", &T);
	for (int _ = 0; _ < T; ++_) {
		scanf(" %s %s", C, J);
		int l = strlen(C);
		memset(decision, 0, sizeof(decision));
		decision[l-1] = -1;
		long long best = 2000000000000000000ll; //2e18
		int dec_point = -1;
		do {
			long long val = 0;
			dec_point = -1;
			for (int i = 0; C[i]; ++i) {
				val *= 10;
				if (val != 0 && dec_point < 0) dec_point = i;
				if(C[i] == '?') {
					if(J[i] == '?') {
						if (val == 0) {
							switch(decision[i]) {
								case -1:
									tmpC[i] = '0';
									tmpJ[i] = '1';
									break;
								case 0:
									tmpC[i] = '0';
									tmpJ[i] = '0';
									break;
								case 1:
									tmpC[i] = '1';
									tmpJ[i] = '0';
							}
						} else {
							if (val > 0) {
								tmpC[i] = '9';
								tmpJ[i] = '0';
							} else {
								tmpC[i] = '0';
								tmpJ[i] = '9';
							}
						}
					} else {
						tmpJ[i] = J[i];
						if (val == 0) {
							tmpC[i] = J[i];
							switch(decision[i]) {
								case -1:
									if (J[i] > '0')
										tmpC[i] = J[i]-1;
									break;
								case 1:
									if (J[i] < '9')
										tmpC[i] = J[i]+1;
									break;
								default:
									break;
							}
						} else {
							if (val > 0) {
								tmpC[i] = '9';
							} else {
								tmpC[i] = '0';
							}
						}
					}
				} else {
					tmpC[i] = C[i];
					if (J[i] == '?') {
						if (val == 0) {
							tmpJ[i] = C[i];
							switch(decision[i]) {
								case -1:
									if (C[i] < '9')
										tmpJ[i] = C[i]+1;
									break;
								case 1:
									if (C[i] > '0')
										tmpJ[i] = C[i]-1;
									break;
							}
						} else {
							if (val > 0) {
								tmpJ[i] = '0';
							} else {
								tmpJ[i] = '9';
							}
						}
					} else {
						tmpJ[i] = J[i];
					}
				}
				val += tmpJ[i] - tmpC[i];
			} 
			val = (val < 0)?(-val):val;
			if (val < best) {
				best = val;
				strcpy(bestC, tmpC);
				strcpy(bestJ, tmpJ);
			}
			if (val == best) {
				bool better = 0;
				for (int i = 0; C[i]; ++i) {
					if(tmpC[i] < bestC[i]) {
						better = 1;
						break;
					}
					if(tmpC[i] > bestC[i])
						break;
					if(tmpJ[i] < bestJ[i]) {
						better = 1;
						break;
					}
					if(tmpJ[i] > bestJ[i])
						break;
				}
				if (better) {
					strcpy(bestC, tmpC);
					strcpy(bestJ, tmpJ);
				}
			}
		} while(flip(l));
		bestC[l] = bestJ[l] = 0;
		printf("Case #%d: %s %s\n", _+1, bestC, bestJ);
	}

	return 0;
}

