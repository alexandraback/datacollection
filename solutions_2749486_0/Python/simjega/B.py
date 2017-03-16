import heapq

class PriorityQueue:
    """
      Implements a priority queue data structure. Each inserted item
      has a priority associated with it and the client is usually interested
      in quick retrieval of the lowest-priority item in the queue. This
      data structure allows O(1) access to the lowest-priority item.

      Note that this PriorityQueue does not allow you to change the priority
      of an item.  However, you may insert the same item multiple times with
      different priorities.
    """
    def  __init__(self):
        self.heap = []

    def push(self, item, priority):
        pair = (priority,item)
        heapq.heappush(self.heap,pair)

    def pop(self):
        (priority,item) = heapq.heappop(self.heap)
        return item

    def empty(self):
        return len(self.heap) == 0


def process(end): # heuristic=nullHeuristic):
    state = (0,0)
    nodes = PriorityQueue()
    usedstates = set()
    node = [state,[],0]
    # h = heuristic(state,problem)
    nodes.push(node,0)# +h)
    while not nodes.empty():
        node = nodes.pop()
        # print node
        [s, actions, cost] = node
        if not s in usedstates:
            usedstates.add(s)
            # print nodes
            if node[0] == end:
                return ''.join(node[1])
            for x in getSuccessors(s,cost+1):
                [sx, actionx, costx] = x
                actionx = (actions + [actionx])
                # h = heuristic(sx,problem)
                # print 'cost: ',costx,', h: ',h,', f: ', costx
                nodes.push([sx,actionx,cost+1],cost+1)# +h)
    util.raiseNotDefined()

def getSuccessors(state,n):
	ans = []
	[x,y] = state
	ans.append([(x+n,y),'E',n])
	ans.append([(x,y+n),'N',n])
	ans.append([(x-n,y),'W',n])
	ans.append([(x,y-n),'S',n])
	# print "state given: ", state, " successors: ", ans
	return ans

lines = [line.strip() for line in open('../Input/B-small-attempt0.in')]
output = open('../Output/B.txt', 'w')

L = int(lines[0]);
counter = 1
for i in range(L):
	end = tuple(map(int,lines[counter].split()))
	case = "Case #" + str(i+1) + ": " + process(end) + "\n"
	print case
	output.write(case)
	counter += 1
