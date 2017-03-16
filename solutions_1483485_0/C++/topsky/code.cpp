//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//
//const int MAXN = 26;
//int dict[MAXN];
//int main(){
//	int T;
//	for(int i = 0; i < MAXN; i++){
//		dict[i] = -1;
//	}
//	cin >> T; getchar();
//	for(int cas = 0; cas < T; cas++){
//		/*printf("Case #%d: ", cas + 1);
//		printf("\n");*/
//		string str, line;
//		getline(cin, str);
//		getline(cin, line);
//		for(int i = 0; i < str.size(); i++){
//			if(dict[str[i] - 'a'] != -1){
//				if(dict[str[i] - 'a'] != line[i] - 'a')cout << "error" << endl;
//			}
//			dict[str[i] - 'a'] = line[i] - 'a';
//		}
//	}
//	cout << "char ch[26] = {" ; 
//	for(int i = 0; i < MAXN; i++){
//		cout << "'" << (char) (dict[i] + 'a') << "', ";
//		//cout << (char) (i + 'a') << " " << (char) (dict[i] + 'a') << endl;
//	}
//	cout << "};" << endl;
//}
#include <iostream>
#include <string>
using namespace std;

int main(){
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	char ch[26] = {'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
		'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q', };
		int T;
		cin >> T; getchar();
		for(int cas = 0; cas < T; cas++){
			printf("Case #%d: ", cas + 1);
			string str;
			getline(cin, str);
			for(int i = 0; i < str.size(); i++){
				if(str[i] != ' '){
					cout <<(ch[str[i] - 'a']) ;
				}else{
					cout << str[i] ;
				}
			}
			printf("\n");
		}
}