#include <iostream>
#include <list>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdlib>

#define ASCII_SPACE 32
#define ASCII_NEWLINE 10


using namespace std;




#define PRINT_TOKEN(token)\
	do{\
		cout<<#token<<" is "<<token<<endl; \
	}while(0)


#define READ(arg)\
	do{\
		long long arg;\
		cin>>arg;\
	}while(0)

//#define PRINT_ARR()
typedef long long ll;

char in_str[128][128];
int N;
char tab[128][128] ;
int tab_len[128];
int tab_count[128][128];

void printInput()
{
	for(int i=0;i< N;i++){
		cout << in_str[i] << endl;
	}
	cout << endl;
}

void printTab()
{
	for(int i=0; i<N ;i++){
		int a = 0;
		while( tab[i][a] != 0){
			cout<< tab[i][a] << " ";
			cout<< tab_count[i][a] << " ";
		
			//printf("%c ",tab[i][a]);
			a++;
		}

//		for(int a=0; a< 2;a++){
//			printf("%c ", tab[i][a]);
//		}
		cout << endl;
	}
}
int solve()
{

	for(int i =0;i< N; i++){
		for(int a = 0; a< strlen(in_str[i] ); a++ ){
			if(tab_len[i] == 0){
				tab_count[i][tab_len[i]]++;
				tab[i][ tab_len[i] ]  =  in_str[i][a];
				tab_len[i]++;
			} else if( tab[i][tab_len[i]-1] == in_str[i][a] ){
				tab_count[i][tab_len[i]-1]++;
			}else{
				tab[i][ tab_len[i] ]  =  in_str[i][a];
				tab_count[i][tab_len[i]]++;
				tab_len[i]++;
			}
		}
	}

	//printTab();

		
	for(int n = 1; n<N;n++){
		if(strcmp(tab[0] , tab[n]) != 0 ){
			return -1;
		}
	}

	int result = 0;
	for(int i=0 ; i< strlen(tab[0]); i++){
		
		int int_tab[128];
		for(int n = 0; n< N;n++){
			int_tab[n] = tab_count[n][i];
		}

		sort(int_tab, int_tab+N);
		//for(int d =0 ;d< N; d++){
		//	cout<< int_tab[d] << " " ;
		//}
		//cout<<endl;
		
		if( N% 2 == 1){
			int middle = int_tab[N/2];

			for(int e=0;e< N;e++){
				result += abs(middle - int_tab[e] );
			}
		} else {
			int middle = int_tab[ N/2 -1];
			int val_a = 0;
			int val_b = 0;
			for(int e=0;e< N;e++){
				val_a += abs(middle - int_tab[e] );
			}
			middle = int_tab[ N/2 -1];
			for(int e=0;e< N;e++){
				val_b += abs(middle - int_tab[e] );
			}

			if(val_a < val_b){
				result += val_a;
			}else {
				result += val_b;
			}
		}
		
	}

	return result;
}

void init()
{
	//memset(tab,0,128*128);
	for(int a =0 ;a < 128;a++){
		for(int b= 0; b< 128;b++){
			tab[a][b] = 0;
			tab_count[a][b] = 0;
		}
	}
	memset(tab_len,0 , sizeof(tab_len));
}


int main()
{
	long long T;

	cin>>T;

	for(long long i=0;i<T;i++){

		long long result=0 ;
		cin>>N;
		for(int n=0; n< N;n++){
			cin>>in_str[n];
		}
		init();
		result = solve();
		//printInput();
		if( result == -1){
			cout<<"Case "<<"#"<<i+1<<": Fegla Won";
		}else{
			cout<<"Case "<<"#"<<i+1<<": "<<result;
		}
		cout<<endl;

	}
	return 0;
}


