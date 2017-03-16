#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	int T,r,c,m;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",iT);
		if (r==1) {
			for (int i=m; i; --i) {
				printf("*");
			}
			for (int i=c-m-1; i; --i) {
				printf(".");
			}
			printf("c\n");
		}
		else if (c==1){
			for (int i=m; i; --i) {
				printf("*\n");
			}
			for (int i=r-m-1; i; --i) {
				printf(".\n");
			}
			printf("c\n");
		}
		else{
			int v=r*c-m;
			switch (v) {
			case 1:
				for (int i=1; i<r; ++i) {
					for (int j=0; j<c; ++j) {
						printf("*");
					}
					printf("\n");
				}
				for (int j=1; j<c; ++j) {
					printf("*");
				}
				printf("c\n");
				break;
			case 2 ... 3:
			case 5:
			case 7:
				printf("Impossible\n");
				break;
			default:
				if (m==0) {
					for (int i=1; i<r; ++i) {
						for (int j=0; j<c; ++j) {
							printf(".");
						}
						printf("\n");
					}
					for (int j=1; j<c; ++j) {
						printf(".");
					}
					printf("c\n");
				}
				else if (r==2) {
						if (v&1) {
							printf("Impossible\n");
						}
						else{
							for (int i=c-(v>>1); i; --i) {
								printf("*");
							}
							for (int i=v>>1; i; --i) {
								printf(".");
							}
							printf("\n");
							for (int i=c-(v>>1); i; --i) {
								printf("*");
							}
							for (int i=(v>>1)-1; i; --i) {
								printf(".");
							}
							printf("c\n");
						}
					}
				else if (c==2){
					if (v&1) {
						printf("Impossible\n");
					}
					else{
						for (int i=r-(v>>1); i; --i) {
							printf("**\n");
						}
						for (int i=(v>>1)-1; i; --i) {
							printf("..\n");
						}
						printf(".c\n");
					}
				}
				else{
					int i=max((v+r-1)/r,2),end=min(v>>1,c);
					for (; i<=end; ++i) {
						if (v%i!=1) {
							for (int j=r-(v+i-1)/i; j; --j) {
								for (int k=0; k<c; ++k) {
									printf("*");
								}
								printf("\n");
							}
							int vmi=(v%i)?(v%i):i;
							for (int k=c-vmi; k; --k) {
								printf("*");
							}
							for (int k=vmi; k; --k) {
								printf(".");
							}
							printf("\n");
							for (int j=(v+i-1)/i-2; j; --j) {
								for (int k=c-i; k; --k) {
									printf("*");
								}
								for (int k=i; k; --k) {
									printf(".");
								}
								printf("\n");
							}
							for (int k=c-i; k; --k) {
								printf("*");
							}
							for (int k=i-1; k; --k) {
								printf(".");
							}
							printf("c\n");
							break;
						}
						if(i>2&&v/i>2){
							for (int j=r-(v+i-1)/i; j; --j) {
								for (int k=0; k<c; ++k) {
									printf("*");
								}
								printf("\n");
							}
							for (int k=c-v%i-1; k; --k) {
								printf("*");
							}
							for (int k=v%i+1; k; --k) {
								printf(".");
							}
							printf("\n");
							for (int k=c-i+1; k; --k) {
								printf("*");
							}
							for (int k=i-1; k; --k) {
								printf(".");
							}
							printf("\n");
							for (int j=(v+i-1)/i-3; j; --j) {
								for (int k=c-i; k; --k) {
									printf("*");
								}
								for (int k=i; k; --k) {
									printf(".");
								}
								printf("\n");
							}
							for (int k=c-i; k; --k) {
								printf("*");
							}
							for (int k=i-1; k; --k) {
								printf(".");
							}
							printf("c\n");
							break;
						}
					}
					if (i>end)
						printf("Impossible\n");
				}
			}
		}
	}
    return 0;
}