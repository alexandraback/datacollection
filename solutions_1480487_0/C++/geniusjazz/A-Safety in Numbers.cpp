#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    ifstream fin("A-small-attempt2.in");
    ofstream fout("A-small.out");
    int T, N;
    fin >> T;
    int score[205];
    
    for (int i = 1 ; i <= T; i++)
    {  
		fin >> N;

		int totalScore = 0;
		for (int j = 0 ; j < N ; j++)
		{
            fin >> score[j];
            totalScore += score[j];
		}
		    
		fout << "Case #" << i << ":";

		fout.unsetf(ios::floatfield);
		fout.precision(8);
		
		double answer[205];
		double temp;
		bool correct[205];
		memset(correct,false,sizeof(bool)*205);
		int oldN = N; int oldTotal = totalScore;
		
		while (true)
		{
			bool finish = true;
			int newTotal = 0; int newN = 0;
			double totaltemp = (double)oldTotal/(double)totalScore;
            for (int j = 0 ; j < N ; j++)
			{
				if (correct[j] == false)
				{
                    temp = (double)score[j] / (double)totalScore;
					answer[j] = ((double)(1+totaltemp) / (double)oldN - temp)*100;
					if (answer[j] > 0) {
						newTotal += score[j];
						newN++;
					}
					else
					{
						finish = false;
						answer[j] = 0;
						correct[j] = true;
					}
				}
			}
			oldTotal = newTotal;
			oldN = newN;
			if (finish) break;

		}
		for (int j = 0 ; j < N ; j++)
		{
		    fout << " " << answer[j];
		}
		fout << endl;
    }
}
