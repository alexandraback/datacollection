#include "stdafx.h"

#include <cstdio>
#include <iostream>
#include <fstream>
#include <iomanip>
#include<vector>
#include<stack>
#include<queue>
#include<cstring>
#include<string>

#define INPUTFILE "B-small-attempt6.in"
#define OUTPUTFILE "result.out"

using namespace std;

//#pragma warning(disable:4996)


int main()
{
	fstream infile(INPUTFILE, ios::in);
	fstream outfile(OUTPUTFILE, ios::out);
	int caseN, count, N;
	infile >> caseN;
	count = 1;
	int same[26];
	bool start[26],end[26];
	bool alone[26];
	bool visit[26];
	char fromthisto[26];
	char tothisfrom[26];
	char buffer[150];
	int middle[26];
	char last,head;
	string refine;
	int len;
	bool bOK;
	long long int factorial[105];

	factorial[0] = 1;
	for (int i = 1; i <= 104; i++){
		factorial[i] = (factorial[i - 1] * i) % 1000000007;
	}

	
	while (count <= caseN){
		infile >> N;
		infile.get();
		memset(middle, 0, sizeof(middle));
		memset(same, 0, sizeof(same));
		memset(fromthisto, 0, sizeof(fromthisto));
		memset(start, false, sizeof(start));
		memset(alone, true, sizeof(alone));
		memset(end, false, sizeof(end));
		bOK = true;
		while (N--){
			if (N==0)
				infile.getline(buffer, 140, '\n');
			else
				infile.getline(buffer, 140, ' ');
			len = strlen(buffer);
			last = buffer[0];
			refine = "";
			for (int i = 1; i < len; i++){
				if (buffer[i] != last){
					refine.push_back(last);
					last = buffer[i];
				}
			}
			refine.push_back(last);
			if (refine.size() == 1)
				same[refine[0] - 'a'] ++;
			else{
				len = refine.size();
				if (start[refine[0] - 'a'] || end[refine[len-1] - 'a'])
					bOK = false;
				start[refine[0] - 'a'] = end[refine[len - 1] - 'a'] = true;
				fromthisto[refine[0] - 'a'] = refine[len-1];		
				tothisfrom[refine[len-1] - 'a'] = refine[0];
				if (len >= 3){
					if (refine[0] == refine[len - 1])
						bOK = false;
				}
				for (int i = 1; i < len - 1;i++){
					middle[refine[i] - 'a'] ++;
				}
			}
		}
		//count middle
		for (int i = 0; i < 26; i++){
			if (middle[i] >= 2
				|| (middle[i] == 1 && start[i])
				|| (middle[i] == 1 && end[i]) 
				|| (middle[i] == 1 && same[i]>=1) )
				bOK = false;
		}
		
		if (!bOK){
			outfile << "Case #" << count++ << ": " << 0 << endl;
			continue;
		}

		memset(visit, false, sizeof(visit));

		int countFac = 0;
		long long int result = 1;

		//loop or link
		refine = "";
		string former;
		bool bLoop=false;
		for (int i = 0; i < 26; i++){
			if (visit[i]==false && start[i]){
				bLoop = false;
				refine = "";
				former = "";
				head = last = i;
				while (true){	
					visit[last] = true;
					refine.push_back(last+'a');
					if (start[last] == false || fromthisto[last] == head + 'a')
						break;
					last = fromthisto[last] - 'a';
				}
				if (start[last] != false)
					bLoop = true;
				if (!bLoop){
					last = head;
					while (end[last])
					{
						last = tothisfrom[last]-'a';
						visit[last] = true;
						refine.push_back(last + 'a');
					}

				}
				
				//count num
				len = refine.size();
				for (int j = 0; j < len; j++){
					alone[refine[j] - 'a'] = false;
				}

				if (bLoop){
					/*	long long int tempResult = 1;
						long long int tempCount = 0;
						for (int j = 0; j < len; j++){
						long long int tempResult = 1;
						for (int x = 0; x < len; x++){
						if (x==j)
						tempResult = (tempResult*factorial[same[refine[x] - 'a']+1]) % 1000000007;
						else
						tempResult = (tempResult*factorial[same[refine[x] - 'a']]) % 1000000007;
						}
						tempCount = (tempCount + tempResult) % 1000000007;
						}
						result = (result*tempCount) % 1000000007;*/
					bOK = false;
				}
				else{

					for (int j = 0; j < len; j++){
						result = (result*factorial[same[refine[j]-'a']]) % 1000000007;
					}
					
				}
				
				countFac++;
			}
		}
		//
		if (!bOK){
			outfile << "Case #" << count++ << ": " << 0 << endl;
			continue;
		}

		for (int i = 0; i < 26; i++){
//			result = (result*factorial[same[i]]) % 1000000007;
			if (alone[i] && same[i] >= 1){
				result = (result*factorial[same[i]]) % 1000000007;
				countFac++;
			}
		}
		result = (result*factorial[countFac]) % 1000000007;
		
		outfile << "Case #" << count++ << ": " << result << endl;

	}

	infile.close();
	outfile.close();
	return 0;
}

