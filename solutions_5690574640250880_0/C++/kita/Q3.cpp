
#include "stdafx.h"

#include <stdlib.h>
#include <math.h>

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

const string OUTPUT_FILENAME = "output.txt";

template <typename T>
T StringToNumber ( const string &Text )
{
	istringstream ss(Text);
	T result;
	return ss >> result ? result : 0;
}

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

struct TestData {
	long R;
	long C;
	long M;
};

struct InputDataSet {
	int T;
	vector<TestData> vecData;
};

void Calc( InputDataSet& data , ofstream& ofs ) 
{
	long long output = 0;

	//cout << "Input (" << data.lineNumber << ") " << data.name << " n=" << data.n << endl;

	for( int i = 0; i < data.vecData.size() ; i++ ) {
		TestData test = data.vecData.at(i);
		char ans[52][52] = {};
		//memset( ans , 0 , test.R*test.C );

		cout << i << " M:" << test.M << " R:" << test.R << " C:" << test.C << endl;

		bool bFailed = false;
		int nFreeSpaceCount = test.C * test.R - test.M;
		int nRestFreeSpaceCount = nFreeSpaceCount;

		if( i == 178 ) {
			bFailed = false;
		}

		do {
			if( test.M == 0 ) {
				// 爆弾が０の場合は無条件で成功
				for( int j = 0 ; j < test.R ; j++ ) {
					for( int k = 0 ; k < test.C ; k++ ){
						if( ans[j][k] == 0 ) {
							ans[j][k] = '.';
						}
					}
				}
				break;
			}
			if( nRestFreeSpaceCount == 1 ) {
				// 残りが１の場合はどんな形状でも成功
				break;
			}
			if( test.C == 1 || test.R == 1 ) {
				// 1 行か１列の行列
				// 常にセーフ
				for( int j = 0 ; j < test.R ; j++ ) {
					for( int k = 0 ; k < test.C ; k++ ) {
						if( 0 == ans[j][k] ) {
							ans[j][k] = '.';
							nRestFreeSpaceCount--;
						}
						if( nRestFreeSpaceCount <= 0 ) {
							break;
						}
					}
					if( nRestFreeSpaceCount <= 0 ) {
						break;
					}
				}
			}
			if( test.C == 2 || test.R == 2 ) {
				// 2と奇数は全滅
				if( ( nFreeSpaceCount == 2 ) ||
					( nFreeSpaceCount % 2 == 1 ) ) {
					bFailed = true;
					break;
				}

				if( test.C == 2 ) {
					for( int j = 0 ; j < test.R ; j++ ) {
						ans[j][0] = '.';
						ans[j][1] = '.';
						nRestFreeSpaceCount-=2;
						if( nRestFreeSpaceCount <= 0 ) {
							break;
						}
					}
					if( nRestFreeSpaceCount <= 0 ) {
						break;
					}
				}
				else {
					for( int j = 0 ; j < test.C ; j++ ) {
						ans[0][j] = '.';
						ans[1][j] = '.';
						nRestFreeSpaceCount-=2;
						if( nRestFreeSpaceCount <= 0 ) {
							break;
						}
					}
					if( nRestFreeSpaceCount <= 0 ) {
						break;
					}
				}
			}
			if( test.C >= 3 && test.R >= 3 ) {
				// 行も列も３以上
				bool bBreak = false;
				switch( nFreeSpaceCount ) {
				case 1: //  ここには入らない
				case 2:
				case 3:
				case 5:
				case 7:
					bFailed = true;
					break;
				case 4:
					ans[0][0]= '.';
					ans[0][1]= '.';
					ans[1][0]= '.';
					ans[1][1]= '.';
					bBreak = true;
					break;
				case 6:
					ans[0][0]= '.';
					ans[0][1]= '.';
					ans[0][2]= '.';
					ans[1][0]= '.';
					ans[1][1]= '.';
					ans[1][2]= '.';
					bBreak = true;
					break;
				default:
					// 8 以上
					break;
				}
				if( bFailed || bBreak ) {
					break;
				}

				// 8以上の場合
				// 固定部分
				ans[0][0]= '.';
				ans[0][1]= '.';
				ans[0][2]= '.';
				ans[1][0]= '.';
				ans[1][1]= '.';
				ans[1][2]= '.';
				ans[2][0]= '.';
				ans[2][1]= '.';

				nRestFreeSpaceCount -= 8;

				int RRow = 0;
				int RCol = 3;
				int BRow = 3;
				int BCol = 0;

				int lastPosR = 2;
				int lastPosC = 2;
				
				bool bTestRight = true;

				while(1) {
					if( nRestFreeSpaceCount == 1 ) {
						ans[lastPosR][lastPosC] = '.';
						break;
					}
					if( nRestFreeSpaceCount == 0 ) {
						break;
					}

					if( bTestRight ) {
						// →に埋めていくターン
						if( ( RCol < test.C ) && 
							( RRow + 1 < test.R ) ) {
							ans[RRow][RCol]= '.';
							ans[RRow+1][RCol]= '.';
							if( RRow == lastPosR ) {
								// 奇数用の置き場所を上書きした場合
								if( lastPosR + 2 >= test.R ) {
									lastPosC += 1;
								}
								else {
									lastPosR += 2;
								}
							}
							RCol++;
							nRestFreeSpaceCount -= 2;
						}
						else {
							// 下に埋めるターンに変更
							bTestRight = false;
							RCol = BCol + 2; // 次回開始位置
							RRow += 2;
							if( RRow + 1 >= test.R )  {
								// 元に戻す
								RRow -= 2;
								// これ以上→は実施しない
								RCol = test.C;
							}
						}
					}
					else {
						// 下に埋めていくターン
						if( ( BRow < test.R ) && 
							( BCol + 1 < test.C )) {
							ans[BRow][BCol]= '.';
							ans[BRow][BCol+1]= '.';
							nRestFreeSpaceCount -= 2;
							if( BCol == lastPosC ) {
								// 奇数用の置き場所を上書きした場合
								if( lastPosC + 2 >= test.C ) {
									lastPosR += 1;
								}
								else {
									lastPosC += 2;
								}
							}
							BRow++;
						}
						else {
							// →に埋めるターンに変更
							bTestRight = true;
							BRow = RRow + 2; // 次回開始位置
							BCol += 2;
							if( BCol + 1 >= test.C )  {
								// 元に戻す
								BCol -= 2;
								// これ以上下は実施しない
								BRow =  test.R;
							}
						}
					}
				}
			}
		}while(0);
		// 残りをマインで埋める
		for( int j = 0 ; j < test.R ; j++ ) {
			for( int k = 0 ; k < test.C ; k++ ){
				if( ans[j][k] == 0 ) {
					ans[j][k] = '*';
				}
			}
		}
		// 00 にチェックを入れる
		ans[0][0] = 'c';

		cout << "Case #" << i+1 << ":" << endl;
		ofs << "Case #" << i+1 << ":" << endl;

		if( bFailed ) {
			cout << "Impossible" << endl;
			ofs << "Impossible" << endl;
		}
		else {
			for( int j = 0 ; j < test.R ; j++ ) {
				cout << ans[j] << endl;
				ofs << ans[j] << endl;
			}
		}

		int nMines = 0;
		for( int j = 0 ; j < test.R ; j++ ) {
			for( int k = 0 ; k < test.C ; k++ ){
				if( ans[j][k] == '*' ) {
					nMines++;
				}
			}
		}
		if( !bFailed && (nMines != test.M) ) {
			cout << "invalid mines counts" << endl;
		}

		//ofs << fixed << setprecision(7) 
		//	<< "Case #" << i+1 << ": " 
		//	<< timeTotalPrev << endl;

		// test bad magician
		//cout << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;
		//ofs << "Case #" << i+1 << ": " <<  "Bad magician!" << endl;

	}

	//cout << "Case #" << data.lineNumber << ": " << output << endl;
	//ofs <<  "Case #" << data.lineNumber << ": " << output << endl;
}

void MainFunc( ifstream& ifs ,  ofstream& ofs )
{
	InputDataSet inputData;

	string lineBuf;
	vector<string> splittedLineBuf;
	vector<long> splittedLineNums;

	int lineCount = 0;
	int Tcount = 0;
	TestData testData;

	while(ifs) {
		splittedLineBuf.clear();
		lineBuf.clear();
		splittedLineNums.clear();

		if( !getline(ifs, lineBuf) ) {
			cout << "eof" << endl;
			break;
		}
		split( lineBuf , ' ' , splittedLineBuf );
		
		if( lineCount == 0 ) {
			Tcount = StringToNumber<int>( lineBuf );
			inputData.T = Tcount;
		}
		else {
			if( splittedLineBuf.size() < 3 ) {
				continue;
			}

			testData.R = StringToNumber<long>( splittedLineBuf[0] );
			testData.C= StringToNumber<long>( splittedLineBuf[1] );
			testData.M = StringToNumber<long>( splittedLineBuf[2] );
			
			inputData.vecData.push_back( testData );
			memset( &testData , 0 , sizeof(testData) );
		}

		lineCount++;
	}

	Calc( inputData , ofs );

}

int _tmain(int argc, _TCHAR* argv[])
{
	if( argc > 3 || argc == 1 ) {
		cout << "invalid args" << endl;
		return -1;
	}

	ifstream ifs( argv[1] );
	ofstream ofs( OUTPUT_FILENAME );

	MainFunc( ifs , ofs );

	ifs.close();
	ofs.close();

	cout << "enter any key ..." << endl;
	char in;
	cin.get(in);

	return 0;
}

