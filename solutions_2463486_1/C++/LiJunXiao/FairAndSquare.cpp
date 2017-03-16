#include <fstream>
#include <iostream>

using namespace std;
string Generate(char leading, string literal1, bool middle, char middleNum) {
	string str;
	str += leading;
	str += literal1;
	if (middle) str += middleNum;
	//cout << str.c_str() << endl;
	for (size_t i = literal1.size(); i != 0; i--) {
		str += literal1[i - 1];
		//cout << i << " " << str.c_str() << endl;
	}
	str += leading;
	return str;
}
void FairAndSquareLarge2(char * fileInput, char * fileOutput) {
	ifstream input(fileInput);
	ofstream output(fileOutput);

	char buffer[256];
	input.getline(buffer, 256);
	int testcaseCount = atoi(buffer);
	list<large_int> fair;
	list<large_int> fairSquare;
	vector<string> literals;
	fairSquare.push_back(1); fair.push_back(1);
	fairSquare.push_back(4); fair.push_back(2);
	fairSquare.push_back(9); fair.push_back(3);
	fairSquare.push_back(11 * 11); fair.push_back(11);
	fairSquare.push_back(22 * 22); fair.push_back(22);
	
	fairSquare.push_back(101 * 101); fair.push_back(101);
	fairSquare.push_back(111 * 111); fair.push_back(111);
	fairSquare.push_back(121 * 121); fair.push_back(121);
	fairSquare.push_back(202 * 202); fair.push_back(202);
	fairSquare.push_back(212 * 212); fair.push_back(212);
	literals.push_back("0");
	literals.push_back("1");
	
	for (int i = 4; i <= 50; i++) {
		cout << i << endl;
		if (i % 2 == 0) {
			string literal0;
			for (int j = 0; j < (i - 2) / 2; j++)
				literal0 += "0";
			
			large_int square0(Generate('1', literal0, false, '\0'));
			fairSquare.push_back(square0 * square0);
			fair.push_back(square0);

			for (size_t j = 0; j < literal0.size(); j++) {
				string literal1 = literal0;
				literal1[j] = '1';
				
				large_int square1(Generate('1', literal1, false, '\0'));
				fairSquare.push_back(square1 * square1);
				fair.push_back(square1);
			}

			for (size_t j = 0; j < literal0.size(); j++) {
				for (size_t k = j + 1; k < literal0.size(); k++) {
					
					string literal2 = literal0;
					literal2[j] = '1';
					literal2[k] = '1';
					
					large_int square2(Generate('1', literal2, false, '\0'));
					fairSquare.push_back(square2 * square2);
					fair.push_back(square2);
				}
			}
			for (size_t j = 0; j < literal0.size(); j++) {
				for (size_t k = j + 1; k < literal0.size(); k++) {
					for (size_t l = k + 1; l < literal0.size(); l++) {
						string literal3 = literal0;
						literal3[j] = '1';
						literal3[k] = '1';
						literal3[l] = '1';
						large_int square3(Generate('1', literal3, false, '\0'));
						fairSquare.push_back(square3 * square3);
						fair.push_back(square3);
					}
				}
			}
			string literal1;
			for (int j = 0; j < (i - 2) / 2; j++)
				literal1 += "0";

			large_int square4(Generate('2', literal1, false, '\0'));
			fairSquare.push_back(square4 * square4);
			fair.push_back(square4);
		} else {
			string literal0;
			for (int j = 0; j < (i - 2) / 2; j++)
				literal0 += "0";
			
			large_int square0(Generate('1', literal0, true, '0'));
			fairSquare.push_back(square0 * square0);
			fair.push_back(square0);

			
			large_int square1(Generate('1', literal0, true, '1'));
			fairSquare.push_back(square1 * square1);
			fair.push_back(square1);

			
			large_int square2(Generate('1', literal0, true, '2'));
			fairSquare.push_back(square2 * square2);
			fair.push_back(square2);
			for (size_t j = 0; j < literal0.size(); j++) {
				string literal1 = literal0;
				literal1[j] = '1';
				
				large_int square1(Generate('1', literal1, true, '0'));
				fairSquare.push_back(square1 * square1);
				fair.push_back(square1);

				large_int square2(Generate('1', literal1, true, '1'));
				fairSquare.push_back(square2 * square2);
				fair.push_back(square2);
			}

			for (size_t j = 0; j < literal0.size(); j++) {
				string literal1 = literal0;
				literal1[j] = '1';
				
				large_int square1(Generate('1', literal1, true, '2'));
				fairSquare.push_back(square1 * square1);
				fair.push_back(square1);
			}
			for (size_t j = 0; j < literal0.size(); j++) {
				for (size_t k = j + 1; k < literal0.size(); k++) {
					
					string literal2 = literal0;
					literal2[j] = '1';
					literal2[k] = '1';
					
					large_int square2(Generate('1', literal2, true, '0'));
					fairSquare.push_back(square2 * square2);
					fair.push_back(square2);

					large_int square3(Generate('1', literal2, true, '1'));
					fairSquare.push_back(square3 * square3);
					fair.push_back(square3);
				}
			}
			for (size_t j = 0; j < literal0.size(); j++) {
				for (size_t k = j + 1; k < literal0.size(); k++) {
					for (size_t l = k + 1; l < literal0.size(); l++) {
						string literal3 = literal0;
						literal3[j] = '1';
						literal3[k] = '1';
						literal3[l] = '1';
						large_int square3(Generate('1', literal3, true, '0'));
						fairSquare.push_back(square3 * square3);
						fair.push_back(square3);

						large_int square4(Generate('1', literal3, true, '1'));
						fairSquare.push_back(square4 * square4);
						fair.push_back(square4);
					}
				}
			}
			string literal1;
			for (int j = 0; j < (i - 2) / 2; j++)
				literal1 += "0";
			
			large_int square3(Generate('2', literal1, true, '0'));
			fairSquare.push_back(square3 * square3);
			fair.push_back(square3);
			//output << Generate('2', literal1, true, '0').c_str() << endl;

			large_int square4(Generate('2', literal1, true, '1'));
			fairSquare.push_back(square4 * square4);
			fair.push_back(square4);
			//output << Generate('2', literal1, true, '1').c_str() << endl;
		}
	}
	cout << fairSquare.size();
	fairSquare.sort();
	fair.sort();
	/*
	for (std::list<large_int>::iterator iter = fair.begin(); iter != fair.end(); iter++) {
		output << *iter << endl;
	}*/
	
	for (int i = 0; i < testcaseCount; i++) {
		cout << "case " << (i + 1) << endl;
		char *left, *right;
		input.getline(buffer, 256);
		left = strtok(buffer, " ");
		right = strtok(NULL, " ");
		large_int leftNum(left);
		large_int rightNum(right);
		large_int number = 0;
		for (std::list<large_int>::iterator iter = fairSquare.begin(); iter != fairSquare.end(); iter++) {
			if (*iter >= leftNum && *iter <= rightNum)
				number = number + 1;
			if (*iter > rightNum) break;
		}
		
		output << "Case #" << (i + 1) << ": " << number << endl;


	}
	
	input.close();
	output.close();
}

int main() {
	FairAndSquare("C-input.in", "C-output.out");
	
}

