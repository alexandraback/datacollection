#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

int min(int a, int b) {return (a<b)?a:b;}
int max(int a, int b) {return (a>b)?a:b;}

typedef long long unsigned lluint;

using namespace std;

#define MOD 1000000007

unsigned int tesztDB;
unsigned carNum;
string cars[100];
lluint groupNum[26];
string group[26];
string groupStart[26];
string groupEnd[26];
bool groupMerged[26];
lluint unionGroupNum[26];
lluint unionGroupL = 0;
lluint arrNum;

bool contains(string str, char c) {
	for (unsigned i = 0; i < str.length(); i++) {
		if (str[i] == c) return true;
	}
	return false;
} 

bool startsWith(string str, char c) {
	return (str.length() > 0 && str[0] == c);
} 

bool endsWith(string str, char c) {
	return (str.length() > 0 && str[str.length()-1] == c);
}

int main(int argc, char **argv) {
	unsigned int i;
	ifstream ifile("B-small-attempt1.in");
	FILE *ofile = fopen("out.txt", "w");
	ifile >> tesztDB;
	for (i = 0; i < tesztDB; i++) {
		ifile >> carNum;
		for (unsigned j = 0; j < carNum; j++) {
			ifile >> cars[j];
		}
		arrNum = 0;
		for (unsigned c = 0; c < 26; c++) {
			groupNum[c] = 1;
			group[c] = "";
			groupStart[c] = "";
			groupEnd[c] = "";
			groupMerged[c] = false;
			unsigned allSameCharNum = 0;
			for (unsigned k = 0; k < carNum; k++) {
				if (contains(cars[k], c+'a')) {
					if (startsWith(cars[k], c+'a') && endsWith(cars[k], c+'a')) allSameCharNum++;
					if (endsWith(cars[k], c+'a')) {
						if (startsWith(groupStart[c], c+'a')) groupStart[c] = cars[k]+groupStart[c];
						else groupStart[c] += cars[k];
					} else if (startsWith(cars[k], c+'a')) {
						if (endsWith(groupEnd[c], c+'a')) groupEnd[c] += cars[k];
						else groupEnd[c] = cars[k]+groupEnd[c];
					} else groupStart[c] += cars[k];
				}
			}
			for (; allSameCharNum > 0; allSameCharNum--) {
				groupNum[c] *= allSameCharNum;
				groupNum[c] %= MOD;
			}
			group[c] = groupStart[c]+groupEnd[c];
			//if (groupNum[c] > 0) printf("%c: %s (%lld)\n", c+'a', group[c].c_str(), groupNum[c]);
			for (int c2 = 0; c2 < 26; c2++) {
				bool found = false;
				for (unsigned j = 0; j < group[c].length(); j++) {
					if (group[c][j] == c2+'a') {
						if (found && group[c][j-1] != c2+'a') {
							goto end;
						} else found = true;
					}
				}
			}
		}
		unionGroupL = 0;
		for (unsigned c = 0; c < 26; c++) {
			if (groupMerged[c]) continue;
			groupMerged[c] = true;
			string unionGroupStr = group[c];
			unionGroupNum[unionGroupL] = groupNum[c];
			for (unsigned c2 = c+1; c2 < 26; c2++) {
				if (!groupMerged[c2]) {
					for (unsigned place = 0; place < unionGroupStr.length(); place++) {
						unsigned fPlace = group[c2].find(unionGroupStr.substr(unionGroupStr.length()-1-place));
						if (fPlace != string::npos && fPlace == 0) {
							groupMerged[c2] = true;
							//cout << char(c+'a') << "-" << char(c2+'a') << endl;
							//cout << unionGroupStr << "-" << group[c2] << endl;
							unionGroupStr += group[c2].substr(place+1);
						//	cout << "-> " << unionGroupStr << endl;
							break;
						}
						
					}
					if (!groupMerged[c2]) {
						for (unsigned place = 0; place < group[c2].length(); place++) {
							unsigned fPlace = unionGroupStr.find(group[c2].substr(group[c2].length()-1-place));
							if (fPlace != string::npos && fPlace == 0) {
								groupMerged[c2] = true;
								//cout << char(c+'a') << " " << char(c2+'a') << endl;
								//cout << unionGroupStr << " " << group[c2] << endl;
								unionGroupStr = group[c2]+unionGroupStr.substr(place+1);
								//cout << "-> " << unionGroupStr << endl;
								break;
							}
							
						}
					}
					if (groupMerged[c2]) {
						unionGroupNum[unionGroupL] *= groupNum[c2];
						unionGroupNum[unionGroupL] %= MOD;
					}
				}
			}
			if (unionGroupStr.length() > 0) {
				//cout << "U: " << unionGroupStr << "  " << unionGroupNum[unionGroupL] << endl;
				unionGroupL++;
			}
		}
		arrNum = unionGroupNum[0];
		for (unsigned j = 1; j < unionGroupL; j++) {
			arrNum = arrNum*unionGroupNum[j]*2;
			arrNum %= MOD;
		}
		end:
		fprintf(ofile, "Case #%d: %lld\n", i+1, arrNum);
	}
	ifile.close();
	fclose(ofile);
	return 0;
}
