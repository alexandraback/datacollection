#include<iostream>
#include <fstream>
#include<list>
#include <string>
#include<vector>
#include<algorithm>
#include <cstdlib>
using namespace std;

class FileReader {
public:
   bool openFile(string);
   int readInt();
   char readChar();
   string readString();
   void close();
   void flush();
private:
   ifstream mystream;
};

void FileReader::flush() {
   mystream.clear();
}

bool FileReader::openFile(string fn) {
   mystream.open(fn.c_str());
   return mystream.is_open();
}

int FileReader::readInt() {
   int val;
   mystream >> val;

   return val;
}

char FileReader::readChar() {
   char val;
   mystream >> val;

   return val;
}

string FileReader::readString() {
   string val;
   getline(mystream, val);

   return val;
}

void FileReader::close() {
   mystream.close();
}

class FileWriter {
public:
   bool openFile(string fn);
   void writeString(string);
   void writeInt(int);
   void writeChar(char);
   void endLine();
   void close();

private:
   ofstream mystream;
};

bool FileWriter::openFile(string fn) {
   mystream.open(fn.c_str());
   return mystream.is_open();
}

void FileWriter::writeString(string s) {
   mystream << s;
}

void FileWriter::writeInt(int val) {
   mystream << val;
}

void FileWriter::writeChar(char val) {
   mystream << val;
}

void FileWriter::endLine() {
   mystream << endl;
}

void FileWriter::close() {
   mystream.close();
}

//////////////////////////////////////////////

// This class represents a directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices
    list<int> *adj;    // Pointer to an array containing adjacency lists
public:
    Graph(int V);  // Constructor
    void addEdge(int v, int w); // function to add an edge to graph
    int isReachable(int s, int d);  // returns true if there is a path from s to d
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}
// A BFS based function to check whether d is reachable from s.
int Graph::isReachable(int s, int d)
{
    // Base case
    if (s == d)
      return 0;
 
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<int> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // it will be used to get all adjacent vertices of a vertex
    list<int>::iterator i;
 
	int count = 0;
    while (!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        queue.pop_front();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // and enqueue it
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            // If this adjacent node is the destination node, then return true
            if (*i == d)
                count++;
			           // Else, continue to do BFS
            if (!visited[*i])
            {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
 
    return count;
}
/////////////////////////////////////////////

int main()
{
	FileReader in;
	FileWriter out;

	in.openFile("inn.in");
	out.openFile("out.txt");

	int num_test_cases = in.readInt();
	in.readString();


	for( int tnum = 0; tnum < num_test_cases; tnum++ )
	{
		int num_class = in.readInt();
		in.readString();

		Graph g(num_class);
		for ( int i = 0; i < num_class; i++)
		{
			int paths = in.readInt();

			for (int j = 0; j < paths; j++)
			{
				int path = in.readInt();
				g.addEdge(i, path-1);
			}

			in.readString();
		}

		int count = 0;
		for (int i = 0 ; i < num_class; i++)
		{
			for( int j = 0 ; j < num_class; j++)
			{
				count = g.isReachable(i, j);
				if (count >= 2)
				{
					goto A;
				}
			}
		}
		A:
		out.writeString("Case #");
		out.writeInt(tnum + 1);
		out.writeString(": ");
		if(count >= 2)
			out.writeString("Yes");
		else
			out.writeString("No");
		out.endLine();
	}

	return 0;
}
