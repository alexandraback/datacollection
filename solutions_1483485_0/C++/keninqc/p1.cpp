#include <cstdio>
#include <string>

using namespace std;

string table = "yhesocvxduiglbkrztnwjpfmaq";

void Open() {
	freopen ("input.dat", "r", stdin);
	freopen ("output.dat", "w", stdout);
}

void Close() {
	fclose(stdin);
	fclose(stdout);
}

string GetLine() {
	char c;
	string str;
	str.clear();
	do {
		scanf ("%c", &c);
		if (c == '\n') break;
		if (c == ' ')
			str.push_back(c);
		else
			str.push_back(table[c - 97]);
	} while (1);
	return str;
}

int main() {
	int T;
	Open();
	scanf ("%d\n", &T);
	for (int i = 0; i < T; i++)
	{
		string str = GetLine();
		printf ("Case #%d: %s\n", i + 1, str.c_str());
	}
	Close();
	return 0;
}