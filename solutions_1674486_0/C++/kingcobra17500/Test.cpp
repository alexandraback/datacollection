// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <string.h>
#include <vector>

using namespace std;

void CountRecur(int node, vector<vector<int> > &graph, vector<int> &count)
{
	if(graph[node].size() == 0)
		return;
	for(int i=0; i<graph[node].size(); i++) {
		count[graph[node][i]]++;
	}
	for(int i=0; i<graph[node].size(); i++) {
		CountRecur(graph[node][i], graph, count);
	}
}

int main()
{
	ifstream in;
	in.open("A-small-attempt2.in");
	ofstream out;
	out.open("output.txt");
	int numTest;
	in >> numTest;
	for(int i=0; i<numTest; i++) {
		int N;
		in >> N;
		vector<vector<int> > graph;
		vector<int> numInherit;
		vector<int> numTargetted;
		vector<int> count;
		for(int j=0; j<N; j++) {
			count.push_back(0);
			numTargetted.push_back(0);
		}
		for(int j=0; j<N; j++) {
			vector<int> inherit;
			int numInh;
			in >> numInh;
			numInherit.push_back(numInh);
			for(int k=0; k<numInh; k++) {
				int temp;
				in >> temp;
				inherit.push_back(temp-1);
				numTargetted[temp-1]++;
			}
			graph.push_back(inherit);
		}
		out << "Case #" << i+1 << ": ";
		bool flag = false;
		for(int j=0; j<numTargetted.size(); j++) {
			if(numTargetted[j] == 0) {
				for(int k=0; k<count.size(); k++) {
					count[k] = 0;
				}
				count[j] = 1;
				CountRecur(j, graph, count);
				for(int k=0; k<count.size(); k++) {
						if(count[k] > 1) {
							flag = true;
							break;
						}
				}
				if(flag)
					break;
			}
		}
		if(flag)
			out << "Yes";
		else
			out << "No";
		if(i != numTest-1)
			out << endl;
	}
	in.close();
	out.close();
	return 0;
}