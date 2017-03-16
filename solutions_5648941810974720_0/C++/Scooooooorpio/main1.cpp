#include <QCoreApplication>
#include <QString>
#include <QTextStream>
#include <QMap>
#include <QSet>
#include <QList>
#include <QString>

#include <iostream>
#include <string>
#include <QDebug>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;
 

void prework() {

} 


void work(int order) {
	char s1[10000];
	cin.getline(s1, 100);
	cin >> s1;
	int count[300];
	for (int i = 0; i < 300; i++) count[i] = 0;
	for (int i = 0; i < strlen(s1); i++) {
		count[s1[i]] ++;
	}
	int re[20];
	for (int i = 0; i < 20; i++) re[i] = 0;

	auto substring = [&](int x, char * s) {
		for (int i = 0; i < strlen(s); i++) {
			count[s[i]] -= x;
		}
	};


	re[0] = count['Z'];
	substring(re[0], "ZERO");

	re[2] = count['W'];
	substring(re[2], "TWO");


	re[6] = count['X'];
	substring(re[6], "SIX");


	re[7] = count['S'];
	substring(re[7], "SEVEN");

	re[5] = count['V'];
	substring(re[5], "FIVE");


	re[4] = count['F'];
	substring(re[4], "FOUR");

	re[1] = count['O'];
	substring(re[1], "ONE");


	re[3] = count['R'];
	substring(re[3], "THREE");


	re[9] = count['N'] /2 ;
	substring(re[9], "NINE");


	re[8] = count['H'];
	substring(re[8], "EIGHT");


	for (int i = 0; i < 300; i++) {
		if (count[i] != 0) {
			assert(false);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < re[i]; j++) {
			cout << i;
		}
	}
}

 


#if 1
int main(int argc, char *argv[])
{
	 
	QCoreApplication a(argc, argv);

	if (freopen("..\\temp\\output.txt", "w", stdout) == NULL)
		fprintf(stderr, "error redirecting stdout\n");
	if (freopen("..\\temp\\input.txt", "r", stdin) == NULL)
		fprintf(stderr, "error redirecting stdin\n");
	int t;
	cin >> t;
	prework();
	for (int i = 0; i<t; i++) {

		qDebug() << "case " << i + 1 <<endl;
		cout << "Case #" << i + 1 << ": ";

		work(i + 1);
		cout << endl;
	}
	qDebug() << "end!";
	return 0;
	return a.exec();
}

#endif