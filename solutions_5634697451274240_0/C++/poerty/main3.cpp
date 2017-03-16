#include<iostream>
#include<string>

using namespace std;

int  main(){
		int num;
			string S;
				cin >> num;

					for (int j = 0; j < num; j++){
								cin >> S;
										char a = S[0];
												char b = S[S.length()-1];
														int aa = 0;
																for (int i = 1; i < S.length(); i++){
																				if (S[i] != a) {
																									a = S[i];
																													aa++;
																																}
																																		}
																																				if (b == '-')aa++;
																																						cout << "Case #"<<j+1<<": "<<aa << endl;
																																							}
}
