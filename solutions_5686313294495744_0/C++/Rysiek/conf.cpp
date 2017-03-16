#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<inttypes.h>

/**
 * Struktura która opisuje słowo.
 * Odpowiednio jest to zakodowana wartość słowa 27^10 < 2^64, więc w dwóch 64 bitowych liczbach kodujemy
 * wyraz, który może mieć do 20 znaków zgodnie z założeniami
 */
struct Word {
	uint64_t a;
	uint64_t b;
};

bool operator==(const Word& wa, const Word& wb) {
	return wa.a==wb.a && wa.b==wb.b;
}

// Funkcja kodująca słowo z liter alfabetu angielskiego do wartości kodowej
Word encode(const char* word) {
	Word w;
	w.a=0;
	w.b=0;
	int i=0;
	for(;;) {
		if(*word=='\0') return w;
		
		w.a=w.a*27+(*word-'A'+1);	// kodujemy jeden znak
		++word;
		++i;
		if(i==10) break;	// przechodzimy do kodowania drugiej części
	}
	for(;;) {
		if(*word=='\0') return w;
		w.b=w.b*27+(*word-'A'+1);
		++word;
	}
};

// Ilość haseł w przypadku testowym
int n;
// Wczytane dane
Word first[1001], second[1001];
// Możliwy fałszywy
bool fake[1001];

bool find(const Word w, Word* data, int skip) {
	for(int i=0;i<skip;++i) if(w==data[i]) return true;
	for(int i=skip+1;i<n;++i) if(w==data[i]) return true;
	return false;
}



int main(int argc, char** argv) {
	int tests;
	char wordA[21], wordB[21];
	
	scanf("%d",&tests);
	
	for(int t=1;t<=tests;++t) {
		scanf("%d", &n);
		
		for(int i=0;i<n;++i) {
			scanf("%s %s", wordA, wordB);
			fake[i]=true;
			first[i]=encode(wordA);
			second[i]=encode(wordB);
		}
		
		int fakeCount=n;
		// etap 1 - wyszukujemy pewniaków
		for(int i=0;i<n;++i) {
			if(!find(first[i], first, i)) {	// jeżeli pierwszy wyraz występuje tylko w tym temacie
				fake[i]=false;	// to na pewno nie jest to fałszywy tytuł
				fakeCount--;
				continue;
			}
			if(!find(second[i], second, i)) {	// jeżeli drugi wyraz występuje tylko w tym temacie
				fake[i]=false;	// to na pewno nie jest to fałszywy tytuł
				fakeCount--;
				continue;
			}
			// jeżeli obywa gdzies występują, to koniec?
		}
		
		printf("Case #%d: %d\n", t, fakeCount);
		
	};
	return 0;
}