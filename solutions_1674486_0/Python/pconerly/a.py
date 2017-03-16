# a
"""
    public static Vertex[] graph = new Vertex[dataLength];
    public static Stack<Integer> finishingStack = new Stack<Integer>();

    public static class Vertex {
        public int leader = -1;
        public boolean explored = false;
        public List<Integer> incoming = new ArrayList<Integer>();
        public List<Integer> outgoing = new ArrayList<Integer>();
        
        public void addOutgoing(int endpoint) {
            outgoing.add(endpoint);
        }
        public void addIncoming(int endpoint) {
            incoming.add(endpoint);
        }
    }

    public static void DFS_Normal(int vertex, int leadership) {
    if (graph[vertex].explored) {
        throw new RuntimeException();
    }
    graph[vertex].explored = true;
    graph[vertex].leader = leadership;
    for( int j : graph[vertex].outgoing) {
        if (!graph[j].explored) {
            DFS_Normal(j, leadership);
        }
    }
    """

class Vertex:
    def __init__(self, i):
        self.name = i
        self.explored = False
        self.incoming = []
        self.outgoing = []
    def __repr__(self):
        return "Name:%s outgoing:%s incoming:%s" % (self.name, self.outgoing, self.incoming)

def getint(fin):
    return int(fin.readline().strip())

def main(filename):
    fin = file(filename, 'r')
    fout = file(filename + ".out", 'w')
    
    testnum = int(fin.readline())

    global graph

    for zz in xrange(testnum):
        vcount = getint(fin)
        graph = []
        for i in xrange(vcount):
            graph.append(Vertex(i))
        
        for i in xrange(vcount):
            to = i
            frm = [int(x)-1 for x in fin.readline().split()[1:]]
            #print frm
            for f in frm:
                graph[f].outgoing.append(to)
                graph[to].incoming.append(f)

        #print "second", graph

        answer = False
        for origin in [o for o in graph if len(o.incoming) == 0]:
            # do a DFS from any origins.
            #print "origin:",  origin
            for g in graph:
                g.explored = False
            answer = answer or DFS(origin.name)

        #print answer
        if answer == True:
            textanswer = "Yes"
        else:
            textanswer = "No"
        #print "========\n"

        print "Case #%d: %s \n" %(zz+1, textanswer)
        fout.write("Case #%d: %s \n" %(zz+1, textanswer))

    print "done"


def DFS(vertex):
    if graph[vertex].explored:
         raise
    graph[vertex].explored = True

    answer = False
    for j in graph[vertex].outgoing:
        if not graph[j].explored:
            answer = answer or DFS(j)
        else:
            answer = True
            #print "vertex:%s j:%s" % (vertex, j)
    return answer


if __name__ == "__main__":
    filename = "a_sample.txt"
    filename = 'A-small-attempt0.in'
    #filename = 'A-large-practice.in'
    main(filename)
    
