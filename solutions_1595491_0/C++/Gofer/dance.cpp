#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <algorithm>
#include <functional>

#define CAN_SURPRISE(t)	((t) ? (((t - ((t/3)*3))-1) ? 1 : 0) : 0)

typedef struct _Triplet{
	unsigned int t;
	unsigned int triplet[3];
}Triplet;

bool compareTriplet(Triplet &a, Triplet &b) {
	return a.t > b.t;
}

void make_triplet_not_surprise(unsigned int t, unsigned int* triplet) {
	unsigned int avg = t / 3;
	//(CAN_SURPRISE(t)) ? printf("SP ") : printf("NS ");
	switch(t - (avg * 3)) {
	case 0:
		triplet[0] = triplet[1] = triplet[2] = avg;
		break;
	case 1:
		triplet[0] = avg+1;
		triplet[1] = triplet[2] = avg;
		break;
	case 2:
		triplet[0] = triplet[1] = avg+1;
		triplet[2] = avg;
		break;
	}
}

void make_triplet_surprise(unsigned int t, unsigned int* triplet) {
	int avg = t / 3;
	//printf("%d\t", t - (avg * 3));
	switch(t - (avg * 3)) {
	case 0:
		triplet[0] = avg+1;
		triplet[1] = avg;
		triplet[2] = avg-1;
		break;
	/*case 1:
		triplet[0] = avg+1;
		triplet[1] = triplet[2] = avg;
		break;*/
	case 2:
		triplet[0] = avg+2;
		triplet[1] = triplet[2] = avg;
		break;
	}
}

int is_above_p(unsigned int p, unsigned int *triplet) {
	return ((triplet[0] >= p) || (triplet[1] >= p) || (triplet[2] >= p)) ? 1 : 0;
}

/****************************************
  surpriseになるか? => CAN_SURPRISE(t)
  t[i]がp*3-4以上ならば
    t[i]はsurprise, not surprise関係なく
	カウントできる
  t[i]がp*3-4未満の場合
    surpriseにできる場合カウントできる
	可能性がある
	大きいほうから順にp個のt[i]を
	surpriseにして判定する。
 ****************************************/

int main(int argc, char** argv) {
	unsigned int T, N, S, p, i, j, temp;
	unsigned int trip[3];
	
	//FILE *fp = fopen("input.txt","r");
	FILE *fp = fopen("B-small-attempt0.in","r");
	
	fscanf(fp, "%d\r\n", &T);
	//printf("T: %d\n", T);
	
	for(j=0; j<T; ++j) {
		std::list<Triplet> t;
		std::list<Triplet>::iterator t_itr;
		
		fscanf(fp, "%d %d %d", &N, &S, &p);
		//printf("N: %d, S: %d, p: %d\n", N, S, p);
		
		for(i=0; i<N; ++i) {
			fscanf(fp, "%d", &temp);
			make_triplet_not_surprise(temp, trip);
			Triplet tr;
			tr.t = temp;
			memmove(tr.triplet, trip, 3*sizeof(unsigned int));
			t.push_back(tr);
		}
		t.sort(compareTriplet);
		
		/*
		for(t_itr=t.begin(); t_itr!=t.end(); ++t_itr) {
			printf("%d (%d, %d, %d) %s\n", t_itr->t, t_itr->triplet[0], t_itr->triplet[1], t_itr->triplet[2], (is_above_p(p, t_itr->triplet) ? "A" : "B"));
		}
		putchar('\n');
		*/
		
		for(t_itr=t.begin(); t_itr!=t.end(); ++t_itr) {
			if(!is_above_p(p, t_itr->triplet) && CAN_SURPRISE(t_itr->t)) {
				if(S == 0) break;
				make_triplet_surprise(t_itr->t, t_itr->triplet);
				--S;
			}
		}
		
		/*
		for(t_itr=t.begin(); t_itr!=t.end(); ++t_itr) {
			printf("%d (%d, %d, %d) %s\n", t_itr->t, t_itr->triplet[0], t_itr->triplet[1], t_itr->triplet[2], (is_above_p(p, t_itr->triplet) ? "A" : "B"));
		}
		putchar('\n');
		*/
		
		temp = 0;
		for(t_itr=t.begin(); t_itr!=t.end(); ++t_itr) {
			if(is_above_p(p, t_itr->triplet)) ++temp;
		}
		
		printf("Case #%d: %d\n", j+1, temp);
	}
	fclose(fp);
	
	return EXIT_SUCCESS;
}
