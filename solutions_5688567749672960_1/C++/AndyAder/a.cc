#include <cstdio>
#include <cstring>


#define FOR0(i,N) for(int i=0; i<(N); i++)
#define FOR1(i,N) for(int i=1; i<=(N); i++)

char buf[20], tmpbuf[20];
long I;

long reverse(long a) {
	long r;
	char b[20];
	FOR0(i,20) {
		if(a == 0) {
			b[i] = 0;
			break;
		}
		b[i] = a%10 + '0';
		a/=10;
	}
	sscanf(b, "%ld", &r);
	return r;
}

long counter1(int len)
{
	int len2 = len / 2;
	long tmpI, retval(0);
//	printf("[%s]\n", buf);
	if(strncmp(buf,"1000000000", len2)) {
		int i;
		for(i=len2; i<len-1; i++) {
			tmpbuf[i] = '0';
		}
		tmpbuf[i] = '1';
//		printf("[[%s][%s]]\n", buf, tmpbuf);
		sscanf(tmpbuf, "%ld", &tmpI);
		retval = I - tmpI + 1;
		if(retval > 0)
			I = reverse(tmpI);
	}
	sprintf(tmpbuf, "%ld", I);
	sscanf(tmpbuf+len2, "%ld", &tmpI);
	I -= tmpI+1;
	return retval + tmpI + 1;
}

int main()
{
	FILE *fin, *fout;
//	fin = fopen("A-small-attempt1.in", "r");
//	fin = fopen("a-sample.in", "r");
	fin = fopen("A-large.in", "r");
	fout = fopen("output", "w");
	int test_case;
	long O, tmp;
	int length;

	fscanf(fin, "%d", &test_case);
	FOR1(T,test_case) {
		O=1;
		fscanf(fin, "%ld", &I);
		while(I>=100){
			sprintf(buf, "%ld", I);
			sprintf(tmpbuf, "%ld", I);
			length = strlen(buf);
			O += counter1(length);
//			printf("%ld %ld\n", I, O);
		}


		while(I!=1) {
			O++;
			if(I%10==1 && (tmp=reverse(I)) < I) {
//				printf("%ld -> %ld\n", I, tmp);
				I = tmp;
			}
			else I--;
		}

		fprintf(fout, "Case #%d: %ld\n", T, O);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
