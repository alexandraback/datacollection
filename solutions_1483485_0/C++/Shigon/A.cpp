#include <iostream>
#include <string>

using namespace std;

class Translator
{
	char T[300];
	bool usedX[300];
	bool usedY[300];
public:
	Translator()
	{
		for (int i=0; i<300; ++i) usedX[i]=usedY[i]=false;		
	}
	void learn(const string& X, const string& Y)
	{
		int siz=X.size();
		for (int i=0; i<siz; ++i)
		{
			T[X[i]]=Y[i];
			usedX[X[i]]=true;
			usedY[Y[i]]=true;
		}
	}
	void wnioskuj()
	{
		char znX='a';
		while (znX<='z' && usedX[znX]) ++znX;
		char znY='a';
		while (znY<='z' && usedY[znY]) ++znY;

		T[znX]=znY;
	}
	string translate(const string& X)
	{
		string Y=X;
		int siz=X.size();
		for (int i=0; i<siz; ++i) Y[i]=T[X[i]];
		return Y;
	}
};

int main()
{
	ios::sync_with_stdio(0);

	string probkiX[]=
	{
		"ejp mysljylc kd kxveddknmc re jsicpdrysi",
		"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
		"de kr kd eoya kw aej tysr re ujdr lkgc jv",
		"y qee"
	};
	string probkiY[]=
	{
		"our language is impossible to understand",
		"there are twenty six factorial possibilities",
		"so it is okay if you want to just give up",
		"a zoo"
	};

	Translator Tlumacz;
	for (int i=0; i<4; ++i) Tlumacz.learn(probkiX[i],probkiY[i]);
	Tlumacz.wnioskuj();

	int T; cin>>T;
	cin.ignore();
	for (int test=1; test<=T; ++test)
	{
		string X; 
		getline(cin,X);
		cout<<"Case #"<<test<<": "<<Tlumacz.translate(X)<<endl;
	}

	return 0;
}