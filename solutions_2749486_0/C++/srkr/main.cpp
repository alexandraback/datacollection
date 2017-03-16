
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

CRITICAL_SECTION		CS;

enum TASK_STATE
{
	TASK_ADDED,
	TASK_PROCESSING,
	TASK_COMPLETED,
};

struct task
{
	int						case_number;
	int						state;
	string					result;
	int						time;

	int						X;
	int						Y;

	task					(int case_number) : case_number(case_number), state(TASK_ADDED) {}
};

struct task_pred {
  bool		operator()		(const task& lhs, const task& rhs) {
	  return lhs.case_number < rhs.case_number;
  }
};

vector<task>				tasks;

void approach				(int v, int &step, stringstream &ss, const char* pos_dir, const char* neg_dir)
{
	while (v) {
		if (abs(v) > step) {
			if (v > 0) {
				v			-= step;
				++step;
				ss << pos_dir;
			} else {
				v			+= step;
				++step;
				ss << neg_dir;
			}
		} else {
			while(v) {
				if (v > 0) {
					--v;
					step	+= 2;
					ss << neg_dir << pos_dir;
				} else {
					++v;
					step	+= 2;
					ss << pos_dir << neg_dir;
				}
			}
		}
	}
}

void go						(int& v, int& step, stringstream &ss, bool by_x)
{
	if (v > 0) {
		v					-= step;
		++step;
		ss << (by_x ? "E" : "N");
	} else {
		v					+= step;
		++step;
		ss << (by_x ? "W" : "S");
	}
}

void execute_task			(task& t)
{
	stringstream ss;
	int x					= t.X;
	int y					= t.Y;
	int step				= 1;
	while (abs(x) > step || abs(y) > step) {
		if (abs(x) == step) {
			go				(x, step, ss, true);
		} else if (abs(y) == step) {
			go				(y, step, ss, false);
		} else {
			if (0 == x) {
				go			(y, step, ss, false);
			} else if (0 == y) {
				go			(x, step, ss, true);
			} else {
				if (abs(x) > abs(y)) {
					go		(y, step, ss, false);
				} else {
					go		(x, step, ss, true);
				}
			}
		}
	}
	while (x) {
		if (x > 0) {
			--x;
			step			+= 2;
			ss << "WE";
		} else {
			++x;
			step			+= 2;
			ss << "EW";
		}
	}
	while (y) {
		if (y > 0) {
			--y;
			step			+= 2;
			ss << "SN";
		} else {
			++y;
			step			+= 2;
			ss << "NS";
		}
	}

	t.result				= ss.str();
}

bool get_line				(ifstream& stream, char* buffer, int buffer_size)
{
	if (!stream.good()) {
		cout << "wrong input file format" << endl;
		return false;
	}
	stream.getline			(buffer, buffer_size);
	return true;
}

bool read_task				(task& t, ifstream& file)
{
	char buffer[4*4096];
	if (!get_line(file, buffer, sizeof(buffer))) {
		return false;
	}
	{
		stringstream ss		(buffer);
		ss >> t.X;
		ss >> t.Y;
	}
	return true;
}

void print_task				(task& t)
{
	//cout << "Task #" << t.case_number << " Text = " << t.N << endl;
}

void print_result			(task& t)
{
	cout << "Case #" << t.case_number << ": " << t.result.c_str() << endl;
}

DWORD WINAPI worker_thread	(void* arg)
{
	while (true) {
		task* t				= 0;
		{
			EnterCriticalSection(&CS);
			for (int i=0, size=tasks.size(); i!=size; ++i) {
				if (tasks[i].state == 0) {
					t		= &tasks[i];
					t->state= TASK_PROCESSING;
					break;
				}
			}
			LeaveCriticalSection(&CS);
		}
		if (t == 0) {
			return 0;
		}
		execute_task		(*t);
		t->state			= TASK_COMPLETED;
	}
	return 0;
}

int main					(int argc, char** argv)
{
	if (argc < 2) {
		cout << "Input file missing" << endl;
		return -1;
	}
	int time				= timeGetTime();
	ifstream file			(argv[1]);
	if (!file.is_open()) {
		return -1;
	}
	char line[4*4096];
	file.getline			(line, sizeof(line));
	int line_count			= atoi(line);
	for (int i=0; i!=line_count; ++i) {
		task t(i+1);
		if (!read_task(t, file)) {
			return -1;
		}
		tasks.push_back		(t);
	}

	if (IsDebuggerPresent()) {
		for (int i=0; i!=tasks.size(); ++i) {
			task& t			= tasks[i];
			t.time			= timeGetTime();
			//print_task	(t);
			execute_task	(t);
			t.time			= timeGetTime() - t.time;
			//cout << "Task " << t.case_number << " done in [" << t.time << "] ms" << endl;
			print_result	(t);
		}
	} else {
		InitializeCriticalSection(&CS);
		HANDLE handles[4];
		for (int i=0; i<4; ++i) {
			handles[i]			= CreateThread( NULL, 0, &worker_thread, 0, 0, 0);
		}
		WaitForSingleObject		(handles[0], INFINITE);
		WaitForSingleObject		(handles[1], INFINITE);
		WaitForSingleObject		(handles[2], INFINITE);
		WaitForSingleObject		(handles[3], INFINITE);
		DeleteCriticalSection	(&CS);
		::sort					(tasks.begin(), tasks.end(), task_pred());
		//cout << "Work done in [" << timeGetTime() - time << "] ms" << endl;
		for (int i=0; i!=tasks.size(); ++i) {
			print_result		(tasks[i]);
		}
	}
	return 0;
}
