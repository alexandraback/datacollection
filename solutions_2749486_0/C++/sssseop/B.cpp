#include <fstream>

using namespace std;


ifstream in("input.txt");
ofstream out("output.txt");
int x, y;

int head, tail;
int queuex[20000000];
int queuey[20000000];
int queuel[20000000];
int queuer[20000000];
char queuem[20000000];
int visit[20001][20001] = {0,};

void prs(int ta)
{
	char dap[501] = {0,};
	int sx = 0,sy = 0;
	head = 0;
	tail = 0;
	queuex[tail] = sx;
	queuey[tail] = sy;
	queuel[tail] = 0;
	queuem[tail] = 'q';
	queuer[tail] = -1;

	int i, j;
	for(i=0; i<=20000; i++){
		for(j=0; j<=20000; j++){
			visit[i][j] = 0;
		}
	}

	visit[10000][10000] = 1;
	tail++;

	while(head<tail){
		int curx, cury, level, root;
		curx = queuex[head];
		cury = queuey[head];
		root = queuer[head];
		level = queuel[head];
		head++;
		if(curx+level+1 <= 10000 && visit[curx+level+1+10000][cury+10000] == 0){
			visit[curx+level+1+10000][cury+10000] = 1;
			queuex[tail] = curx+level+1;
			queuey[tail] = cury;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'E';
			tail++;
			if(curx+level+1 == x && cury == y){
				int len = 0;
				dap[len++] = 'E';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}else if(curx+level+1 > 10000){
			queuex[tail] = curx+level+1;
			queuey[tail] = cury;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'E';
			tail++;
			if(curx+level+1 == x && cury == y){
				int len = 0;
				dap[len++] = 'E';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}

		if(cury+level+1 <= 10000 && visit[curx+10000][cury+level+1+10000] == 0){
			visit[curx+10000][cury+10000+level+1] = 1;
			queuex[tail] = curx;
			queuey[tail] = cury+level+1;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'N';
			tail++;
			if(curx == x && cury + level + 1 == y){
				int len = 0;
				dap[len++] = 'N';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		} else if(cury+level+1 > 10000){
			queuex[tail] = curx;
			queuey[tail] = cury+level+1;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'N';
			tail++;
			if(curx == x && cury + level + 1 == y){
				int len = 0;
				dap[len++] = 'N';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}

		if(curx-(level+1) >= -10000 && visit[curx-(level+1)+10000][cury+10000] == 0){
			visit[curx-(level+1)+10000][cury+10000] = 1;
			queuex[tail] = curx-(level+1);
			queuey[tail] = cury;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'W';
			tail++;
			if(curx-(level+1) == x && cury == y){
				int len = 0;
				dap[len++] = 'W';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}else if(curx-(level+1) < -10000){
			queuex[tail] = curx-(level+1);
			queuey[tail] = cury;
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'W';
			tail++;
			if(curx-(level+1) == x && cury == y){
				int len = 0;
				dap[len++] = 'W';
				root = head - 1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}

		if(cury-(level+1) >= -10000 && visit[curx+10000][cury-(level+1)+10000] == 0){
			visit[curx+10000][cury+10000-(level+1)] = 1;
			queuex[tail] = curx;
			queuey[tail] = cury-(level+1);
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'S';
			tail++;
			if(curx == x && cury - (level + 1) == y){
				int len = 0;
				dap[len++] = 'S';
				root = head -1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}else if(cury-(level+1) < -10000){
			queuex[tail] = curx;
			queuey[tail] = cury-(level+1);
			queuel[tail] = level+1;
			queuer[tail] = head-1;
			queuem[tail] = 'S';
			tail++;
			if(curx == x && cury - (level + 1) == y){
				int len = 0;
				dap[len++] = 'S';
				root = head -1;
				while(root!=-1){
					dap[len++] = queuem[root];
					root = queuer[root];
				}
				out <<"Case #"<<ta+1<<": ";
				for(int i = len-2; i>=0; i--){
					out << dap[i];
				}
				out << endl;
				break;
			}
		}
	}
}

int main()
{
	int i;
	int t;
	in >> t;
	for(i=0; i<t; i++){
		in >> x >> y;
		prs(i);
	}
	return 0;
}