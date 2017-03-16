#include<iostream>
#include<string>
using namespace std;


int main() {
	FILE *fpi, *fpo;
	fpi = fopen("A-small-attempt0.in", "r");
	fpo = fopen("smallA.out", "w");
	int re;
	fscanf(fpi, "%d", &re);
	for (int co = 1; co <= re; co++) {
		char t[1010];
		fscanf(fpi, "%s", t);
		string st = "";
		for (int i = 0; i < strlen(t); i++) {
			if (st == "")
				st += t[i];
			else if (st[0] > t[i])
				st += t[i];
			else st = t[i] + st;
		}
		fprintf(fpo, "Case #%d: %s\n", co, st.c_str());
	}
	fclose(fpi);
	fclose(fpo);
}