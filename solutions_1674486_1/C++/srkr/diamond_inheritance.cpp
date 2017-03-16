
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
#include <algorithm>

using namespace std;

struct Task
{
							Task		(int id) : task_id(id) {}
	bool					load		(ifstream& reader);
	void					save		(ostream& writer);
	void					execute		();

	int						task_id;

	vector<vector<int>>		classes;
	bool					result;
};

vector<Task*>				threading_tasks;
CRITICAL_SECTION			CS;

DWORD WINAPI worker_thread	(void* arg)
{
	while (true) {
		Task* t				= 0;
		{
			EnterCriticalSection(&CS);
			if (threading_tasks.size()) {
				t			= threading_tasks.back();
				threading_tasks.pop_back();
			}
			LeaveCriticalSection(&CS);
		}
		if (t == 0) {
			return 0;
		}
		t->execute			();
	}
	return 0;
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

int diamond_inheritance		(int argc, char** argv)
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
	vector<Task> tasks;
	char line[4*4096];
	file.getline			(line, sizeof(line));
	int task_count			= atoi(line);
	for (int i=0; i!=task_count; ++i) {
		Task task(i+1);
		if (!task.load(file)) {
			return -1;
		}
		tasks.push_back		(task);
	}

	if (IsDebuggerPresent()) {
		for (int i=0; i!=tasks.size(); ++i) {
			tasks[i].execute();
		}
	} else {
		InitializeCriticalSection(&CS);
		threading_tasks.resize	(tasks.size());
		for (int i=0, size=tasks.size(); i!=size; ++i) {
			threading_tasks[i]	= &tasks[i];
		}
		HANDLE handles[4];
		for (int i=0; i<4; ++i) {
			handles[i]			= CreateThread( NULL, 0, &worker_thread, 0, 0, 0);
		}
		WaitForSingleObject		(handles[0], INFINITE);
		WaitForSingleObject		(handles[1], INFINITE);
		WaitForSingleObject		(handles[2], INFINITE);
		WaitForSingleObject		(handles[3], INFINITE);
		DeleteCriticalSection	(&CS);
	}

	string result_file			= argv[1];
	result_file					+= ".result";
	ofstream result;
	result.open					(result_file);
	for (int i=0, size=tasks.size(); i!=size; ++i) {
		tasks[i].save			(result);
	}
	result.close				();

	int elapsed					= timeGetTime() - time;
	int mm						= elapsed / (60 * 1000);
	int ss						= (elapsed - mm * 60 * 1000) / 1000;
	int ms						= elapsed - mm * 60 * 1000 - ss * 1000;
	
	printf						("Work done in %.2d:%.2d:%d", mm, ss, ms);

	return 0;
}

bool Task::load					(ifstream& reader)
{
	char line[4*4096];
	if (!get_line(reader, line, sizeof(line)))		return false;
	stringstream ss				(line);
	int count					= 0;
	ss >> count;
	classes.resize				(count);
	for (int i=0; i<count; ++i) {
		if (!get_line(reader, line, sizeof(line)))		return false;
		stringstream cs			(line);
		int p_count				= 0;
		cs >> p_count;
		for (int k=0; k<p_count; ++k) {
			int p				= 0;
			cs >> p;
			classes[i].push_back(p);
		}
	}
	return true;
}

void Task::save					(ostream& writer)
{
	writer << "Case #" << task_id << ": " << (result ? "Yes" : "No") << endl;
}

bool diamond					(int idx, vector<vector<int>>& cls, vector<int>& parents)
{
	if (parents.end() == ::find(parents.begin(), parents.end(), idx)) {
		parents.push_back		(idx);
	} else {
		return true;
	}
	vector<int>& vec			= cls[idx-1];
	for (int i=0, size=vec.size(); i!=size; ++i) {
		int parent				= vec[i];
		if (diamond(parent, cls, parents)) {
			return true;
		}
	}
	return false;
}

void Task::execute				()
{
	result						= false;
	for (int i=0, size=classes.size(); i!=size; ++i) {
		int class_idx			= i+1;
		vector<int>& parents	= classes[i];
		vector<int> grands;
		for (int j=0, j_size=parents.size(); j!=j_size; ++j) {
			if (diamond(parents[j], classes, grands)) {
				result			= true;
				return;
			}
		}
	}
}
