
#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <iomanip>

using namespace std;

//0 means accessible now, -1 means never accessible, otherwise we can wait some time for the water to drop
double howLongUntilAccess(int H, int ceilingFrom, int floorFrom, int ceilingTo, int floorTo) {
	if (ceilingFrom - floorTo < 50) return -1;
	if (ceilingTo - floorFrom < 50) return -1;
	if (ceilingTo - floorTo < 50) return -1;
	double waterLevelToDrop = H - (ceilingTo-50);
	if (waterLevelToDrop <= 0) return 0;
	else return waterLevelToDrop / 10.0;
}


int main()
{   
	ifstream fin("B-large.in");
//	ifstream fin("B.in.txt");
	int T;
	fin>>T;
	ofstream fout("B-large.out");	
	
	int H, N, M;
	int i, j;
	double timeToAccess, timeToStart, waterLevelThen;
	int **c = new int *[100];	//ceiling height
	for (int i=0;i<100;i++) c[i] = new int[100];
	int **f = new int *[100];	//floor height
	for (int i=0;i<100;i++) f[i] = new int[100];
	double **reachableAtTime = new double *[100];
	for (int i=0;i<100;i++) reachableAtTime[i] = new double[100];
	
	
	for (int n=1;n<=T;n++)
	{
		fin>>H>>N>>M;
		for (j=0;j<N;j++)
		{
			for (i=0;i<M;i++) fin>>c[j][i];
		}
		for (j=0;j<N;j++)
		{
			for (i=0;i<M;i++) fin>>f[j][i];
		}
		
		for (j=0;j<N;j++)
		{
			for (i=0;i<M;i++) reachableAtTime[j][i] = -1;	//not yet seen
		}
		reachableAtTime[0][0] = 0;	//starting point
		
		//phase 1, determine what points are reachable before the tide starts dropping
		queue<int> x, y;	//these waitlists should stay synchronized
		x.push(0);
		y.push(0);
		while (!x.empty()) {
			i = x.front();
			x.pop();
			j = y.front();
			y.pop();
			//j, i is reachable, check neighbors
			if (i-1>=0 && reachableAtTime[j][i-1]==-1 && howLongUntilAccess(H, c[j][i], f[j][i], c[j][i-1], f[j][i-1]) == 0) {	//left
				reachableAtTime[j][i-1] = 0;
				x.push(i-1);
				y.push(j);
			}
			if (i+1<M && reachableAtTime[j][i+1]==-1 && howLongUntilAccess(H, c[j][i], f[j][i], c[j][i+1], f[j][i+1]) == 0) {	//right
				reachableAtTime[j][i+1] = 0;
				x.push(i+1);
				y.push(j);
			}
			if (j-1>=0 && reachableAtTime[j-1][i]==-1 && howLongUntilAccess(H, c[j][i], f[j][i], c[j-1][i], f[j-1][i]) == 0) {	//up
				reachableAtTime[j-1][i] = 0;
				x.push(i);
				y.push(j-1);
			}
			if (j+1<N && reachableAtTime[j+1][i]==-1 && howLongUntilAccess(H, c[j][i], f[j][i], c[j+1][i], f[j+1][i]) == 0) {	//down
				reachableAtTime[j+1][i] = 0;
				x.push(i);
				y.push(j+1);
			}
		}
		
		if (reachableAtTime[N-1][M-1] == 0) {
			fout<<"Case #"<<n<<": 0\n";
			//cout<<"zero\n";
		}
		else {
			//phase 2, some squares need the water to drop before they become reachable, use something like dijkstra's algorithm
			//lazy implementation, once a square is updated, add it to waitlist stack
			//to get into the waitlist, the square has to be reachable
			for (j=0;j<N;j++)
			{
				for (i=0;i<M;i++)
				{
					if (reachableAtTime[j][i]==0)
					{
						x.push(i);
						y.push(j);
					}
				}
			}
			while (!x.empty()) {
				i = x.front();
				x.pop();
				j = y.front();
				y.pop();
				if (i-1>=0 && reachableAtTime[j][i-1]!=0) {	//left
					timeToAccess = howLongUntilAccess(H, c[j][i], f[j][i], c[j][i-1], f[j][i-1]);
					if (timeToAccess!=-1) {
						timeToStart = (timeToAccess > reachableAtTime[j][i]) ? timeToAccess : reachableAtTime[j][i];
						waterLevelThen = (H-10.0*timeToStart) - f[j][i];
						if (waterLevelThen >= 20) timeToStart += 1.0;	//can use kayak, add transition time
						else timeToStart += 10.0;
						if (timeToStart < reachableAtTime[j][i-1] || reachableAtTime[j][i-1]==-1) {
							reachableAtTime[j][i-1] = timeToStart;
							x.push(i-1);
							y.push(j);
						}
					}
				}
				
				if (i+1<M && reachableAtTime[j][i+1]!=0) {	//right
					timeToAccess = howLongUntilAccess(H, c[j][i], f[j][i], c[j][i+1], f[j][i+1]);
					if (timeToAccess!=-1) {
						timeToStart = (timeToAccess > reachableAtTime[j][i]) ? timeToAccess : reachableAtTime[j][i];
						waterLevelThen = (H-10.0*timeToStart) - f[j][i];
						if (waterLevelThen >= 20) timeToStart += 1.0;	//can use kayak, add transition time
						else timeToStart += 10.0;
						if (timeToStart < reachableAtTime[j][i+1] || reachableAtTime[j][i+1]==-1) {
							reachableAtTime[j][i+1] = timeToStart;
							x.push(i+1);
							y.push(j);
						}
					}
				}
				
				if (j-1>=0 && reachableAtTime[j-1][i]!=0) {	//up
					timeToAccess = howLongUntilAccess(H, c[j][i], f[j][i], c[j-1][i], f[j-1][i]);
					if (timeToAccess!=-1) {
						timeToStart = (timeToAccess > reachableAtTime[j][i]) ? timeToAccess : reachableAtTime[j][i];
						waterLevelThen = (H-10.0*timeToStart) - f[j][i];
						if (waterLevelThen >= 20) timeToStart += 1.0;	//can use kayak, add transition time
						else timeToStart += 10.0;
						if (timeToStart < reachableAtTime[j-1][i] || reachableAtTime[j-1][i]==-1) {
							reachableAtTime[j-1][i] = timeToStart;
							x.push(i);
							y.push(j-1);
						}
					}
				}
				
				if (j+1<N && reachableAtTime[j+1][i]!=0) {	//down
					timeToAccess = howLongUntilAccess(H, c[j][i], f[j][i], c[j+1][i], f[j+1][i]);
					if (timeToAccess!=-1) {
						timeToStart = (timeToAccess > reachableAtTime[j][i]) ? timeToAccess : reachableAtTime[j][i];
						waterLevelThen = (H-10.0*timeToStart) - f[j][i];
						if (waterLevelThen >= 20) timeToStart += 1.0;	//can use kayak, add transition time
						else timeToStart += 10.0;
						if (timeToStart < reachableAtTime[j+1][i] || reachableAtTime[j+1][i]==-1) {
							reachableAtTime[j+1][i] = timeToStart;
							x.push(i);
							y.push(j+1);
						}
					}
				}
			}
			fout<<"Case #"<<n<<": "<< fixed<<setprecision(1)<<reachableAtTime[N-1][M-1]<<"\n";
			//cout<<reachableAtTime[N-1][M-1]<<"\n";
			
		}
	}
	
	
	
	return 0;
}