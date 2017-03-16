#include<iostream>
#include<map>
#include<string>
using namespace std;

string a = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
string b = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
string c = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

string aa= "our language is impossible to understand";
string bb= "there are twenty six factorial possibilities";
string cc= "so it is okay if you want to just give up";


char conv[256];
bool use[256];


int main(){
	
	for( int i=0;i<a.size();++i ){
		conv[a[i]] = aa[i];
	}
	for( int i=0;i<b.size();++i ){
		conv[b[i]] = bb[i];
	}
	for( int i=0;i<c.size();++i ){
		conv[c[i]] = cc[i];
	}
	conv['z'] = 'q';
	conv['q'] = 'z';
	
	/*
	for( int i='a';i<='z';++i ){
		printf("%c => %c\n",i,conv[i]);
		use[ conv[i] ] = true;
	}
	for( int i='a';i<='z';++i ){
		if( !use[i] ){
			printf("%c\n",i);
		}
	}
	*/
	
	int n = 0;
	cin >> n;
	cin.ignore();
	
	
	for( int i=0;i<n;++i ){
		getline( cin,a );
		printf("Case #%d: ",i+1);
		for( int j=0;j<a.size();++j ){
			printf("%c",conv[a[j]]);
		}
		printf("\n");
	}
			
			
		
		
		
	
	
	
	
	
	return 0;
}
