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

 

#if 1

	void prework() {

	} 


	QString s1, s2;

	QString t1, t2;

	QString r1, r2;
	long long dif;

	void newR() {
		r1 = t1;
		r2 = t2;
		long long a = r1.toLongLong();
		long long b = r2.toLongLong();
		dif = abs(a - b);
	}

	void decide() { 
			if (r1 == "")  {
				newR();
				return;
			}
			long long a = t1.toLongLong();
			long long b = t2.toLongLong();

			long long d = abs(a - b);
			if (d > dif) return;
			if (d< dif){
				newR();
				return;
			}

			if (t1 > r1) return;
			if (t1 < r1) {
				newR();
				return;
			}

			if (t2 < r2) {
				newR();
				return;
			}
	 
	}

	void work(int order) {
		char cc[1000];
		cin.getline(cc, 30);
		cin >> cc;
		s1 = QString(cc);
		cin >> cc;
		s2 = QString(cc);
		qDebug() << s1 << ' ' << s2;
		r1 = "";
		r2 = "";
		dif = 1e19;
		for (int i = 0; i <= s1.size(); i++) {
			t1 = s1;
			t2 = s2;
			bool ok = true;
			for (int j = 0; j < i; j++) {
				if (s1[j] != '?' && s2[j] != '?') {
					if (s1[j] != s2[j]) {
						ok = false;
						break;
					}
				}
				if (t1[j] != '?') {
					t2[j] = t1[j];
					continue;
				}
				if (t2[j] != '?') {
					t1[j] = t2[j];
					continue;
				}
				t1[j] = t2[j] = '0';
			}
			if (!ok) break;
			if (i == s1.size()) {
				decide();
				break;
			}

			QString o1 = t1, o2 = t2;
			t1 = o1, t2 = o2;

			ok = true;
			if (s1[i] != '?' && s2[i] != '?') {
				if (s1[i] >= s2[i]) {
					ok = false; 
				}
			}
			else if (t1[i] != '?'  ) {
				if (t1[i] != '9') {
					t2[i] = t1[i].toLatin1() + 1; 
				}
				else ok = false;
			}
			else if (t2[i] != '?'  ) {
				if (t2[i] != '0') {
					t1[i] = t2[i].toLatin1() - 1; 
				}
				else ok = false;
			}
			else if (s1[i] == '?' && s2[i] == '?') {
				t1[i] =  '0';
				t2[i] = '1';
			}
			else {
				assert(false);
			}
			if (ok) {
				for (int j = i + 1; j < s1.size(); j++) {
					if (t1[j] == '?') t1[j] = '9';
					if (t2[j] == '?') t2[j] = '0';
				}
				decide();
			}


			ok = true;

			t1 = o1, t2 = o2;
			if (s1[i] != '?' && s2[i] != '?') {
				if (s1[i] <= s2[i]) {
					ok = false;
				}
			}
			else if (t1[i] != '?' ) {
				if (t1[i] != '0') {
					t2[i] = t1[i].toLatin1() - 1; 
				}
				else ok = false;
			}
			else if (t2[i] != '?'  ) {
				if (t2[i] != '9') {
					t1[i] = t2[i].toLatin1() + 1; 
				}
				else ok = false;
			}
			else if (s1[i] == '?' && s2[i] == '?') {
				t1[i] = '1';
				t2[i] = '0';
			}
			else {
				assert(false);
			}
			if (ok) {
				for (int j = i + 1; j < s1.size(); j++) {
					if (t1[j] == '?') t1[j] = '0';
					if (t2[j] == '?') t2[j] = '9';
				}
				decide();
			}
		}
		qDebug() << r1 << ' ' << r2;
		cout << r1.toLatin1().constData() << ' ' << r2.toLatin1().constData();
	}


 

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

		qDebug() << "case " << i + 1;
		cout << "Case #" << i + 1 << ": ";

		work(i + 1);
		cout << endl;
	}
	qDebug() << "end!";
	return 0;
	return a.exec();
}
#endif