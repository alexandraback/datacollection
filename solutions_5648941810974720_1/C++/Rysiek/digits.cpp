#include<stdio.h>
#include<stdlib.h>

// Kubełki z licznikiem danej litery
int cube[256];

// Kubełki z wynikowymi cyframi
int digits[10];

// funkcja odfiltrująca wyrazy po danej literze
void filterOut(int digit, char det, const char* word) {
	int c=cube[det];	// tyle będzie danych wyrazów, bo dana litera jest wyznacznikiem w danym momencie
	if(c>0) {
		digits[digit]+=c;	// zwiększamy licznik danej cyrfy
		while(*word!='\0') {	// zmniejszamy wystąpienia wszystkich liter z danego wyrazu
			cube[*word]-=c;	// to nie powinno być nigdy mniejsze od 0
//			if(cube[*word]<0) throw "Złe założenia!";
			++word;
		}
	}
}

int main(int argc, char** argv) {
	int tests;
	char buf[2005];
	
	scanf("%d", &tests);
	
	for(int t=1;t<=tests;++t) {
		scanf("%s", buf);
		
		// zerujemy kubełki
		for(int i=0;i<256;++i) cube[i]=0;
		// zliczamy litery
		for(int i=0;buf[i]!='\0';++i) cube[buf[i]]++;
		
		// zerujemy kubełki z cyframi
		for(int i=0;i<10;++i) digits[i]=0;
		
		filterOut(0, 'Z', "ZERO");
		filterOut(2, 'W', "TWO");
		filterOut(6, 'X', "SIX");
		filterOut(7, 'S', "SEVEN");
		filterOut(5, 'V', "FIVE");
		filterOut(4, 'F', "FOUR");
		filterOut(3, 'R', "THREE");
		filterOut(1, 'O', "ONE");
		filterOut(8, 'T', "EIGHT");
		filterOut(9, 'E', "NINE");
		
		printf("Case #%d: ",t);
		for(int i=0;i<10;++i) {
			for(int j=0;j<digits[i];++j) {
				printf("%d",i);
			}
		}
		printf("\n");
	}
	
	return 0;
}