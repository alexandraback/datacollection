#include <cstdio>

int T,R,C,M,N,tr;
int fld[58][58];
void printsol(void) {
	if(tr) {
		for(int j=0;j<C;j++) {
			for(int i=0;i<R;i++) {
				if(fld[i][j]==2) {
					printf("c");
				} else if(fld[i][j]==1) {
					printf("*");
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
	} else {
		for(int i=0;i<R;i++) {
			for(int j=0;j<C;j++) {
				if(fld[i][j]==2) {
					printf("c");
				} else if(fld[i][j]==1) {
					printf("*");
				} else {
					printf(".");
				}
			}
			printf("\n");
		}
	}
}

int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",ts);
		tr=0;
		if(R>C) {
			tr=R;
			R=C;
			C=tr;
			tr=1;
		}
		N=R*C-M;
		for(int i=0;i<58;i++) {
			for(int j=0;j<58;j++) {
				fld[i][j]=1;
			}
		}
		if(N==1) {
			fld[0][0]=2;
			printsol();
		} else {
			if(R==1) {
				for(int i=0;i<N;i++) fld[0][i]=0;
				fld[0][0]=2;
				printsol();
			} else if(R==2) {
				if(N%2==1||N==2) {
					printf("Impossible\n");
				} else {
					for(int i=0;i<N/2;i++) {
						fld[0][i]=0;
						fld[1][i]=0;
					}
					fld[0][0]=2;
					printsol();
				}
			} else {
				if(M==1) {
					for(int i=0;i<R;i++) {
						for(int j=0;j<C;j++) {
							fld[i][j]=0;
						}
					}
					fld[0][0]=2;
					fld[R-1][C-1]=1;
					printsol();
				} else {
					if(N%2) {
						if(N>8) {
							N-=9;
							fld[0][0]=2;
							fld[0][1]=0;
							fld[0][2]=0;
							fld[1][0]=0;
							fld[1][1]=0;
							fld[1][2]=0;
							fld[2][0]=0;
							fld[2][1]=0;
							fld[2][2]=0;
							for(int i=1;i<R;i++) {
								for(int j=1;j<C;j++) {
									if(N>0&&fld[i][j]==1&&fld[i-1][j]==1) {
										if(fld[i][j-1]==0&&fld[i-1][j-1]==0) {
											fld[i][j]=0;
											fld[i-1][j]=0;
											N-=2;
										}
									}
									if(N>0&&fld[i][j]==1&&fld[i][j-1]==1) {
										if(fld[i-1][j]==0&&fld[i-1][j-1]==0) {
											fld[i][j]=0;
											fld[i][j-1]=0;
											N-=2;
										}
									}
								}
							}
							printsol();
						} else {
							printf("Impossible\n");
						}
					} else {
						if(N>3) {
							N-=4;
							fld[0][0]=2;
							fld[0][1]=0;
							fld[1][0]=0;
							fld[1][1]=0;
							for(int i=1;i<R;i++) {
									for(int j=1;j<C;j++) {
									if(N>0&&fld[i][j]==1&&fld[i-1][j]==1) {
										if(fld[i][j-1]==0&&fld[i-1][j-1]==0) {
											fld[i][j]=0;
											fld[i-1][j]=0;
											N-=2;
										}
									}
									if(N>0&&fld[i][j]==1&&fld[i][j-1]==1) {
										if(fld[i-1][j]==0&&fld[i-1][j-1]==0) {
											fld[i][j]=0;
											fld[i][j-1]=0;
											N-=2;
										}
									}
								}
							}
							printsol();
						} else {
							printf("Impossible\n");
						}
					}
				}
			}
		}
	}
	return 0;
}
