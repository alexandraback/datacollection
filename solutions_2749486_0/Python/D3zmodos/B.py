
import heapq;

import sys;
inFile = open("B-small-attempt0.in","r");
sys.stdin = inFile;
outFile = open("B-small-out.out","w");
sys.stdout = outFile;

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
        self.count = 0

    def push(self, item, priority):
        # FIXME: restored old behaviour to check against old results better
        # FIXED: restored to stable behaviour
        entry = (priority, self.count, item)
        # entry = (priority, item)
        heapq.heappush(self.heap, entry)
        self.count += 1

    def pop(self):
        (_, _, item) = heapq.heappop(self.heap)
        #  (_, item) = heapq.heappop(self.heap)
        return item

    def isEmpty(self):
        return len(self.heap) == 0

def getSuccessors(state):
    """Successor states take the form: (successor, action)"""
    moveCount = len(state[1])+1;
    successors = [];
    successors.append( ((state[0][0]+moveCount,state[0][1]), state[1]+"E") );
    successors.append( ((state[0][0]-moveCount,state[0][1]), state[1]+"W") );
    
    successors.append( ((state[0][0],state[0][1]+moveCount), state[1]+"N") );
    successors.append( ((state[0][0],state[0][1]-moveCount), state[1]+"S") );
    
    return tuple(successors);

def heuristic(loc,target):
    return abs(target[0]-loc[0]) + abs(target[1]-loc[1]);

def aStarSearch(target):
    result = [];
    closedSet = set();
    open = PriorityQueue();
    
    
    open.push(((0,0),"",0),0);
    while(not open.isEmpty()):
        currentState = open.pop();
        
        #If this node is already in the closed set, then ignore it, otherwise add it to the closed set and process it
        if(currentState[0] in closedSet):
            continue;
        closedSet.add(currentState[0]);
        
        #If this node is the goal node then we're finished
        if(currentState[0] == target):
            return currentState[1];
        
        #Add this node's possible successors to the open list
        for successor in getSuccessors(currentState):
            successorState = (successor[0], successor[1], currentState[2]+1);
            open.push(successorState,successorState[2]+heuristic(successorState[0],target));

caseCount = eval(input());

for caseIndex in range(0, caseCount):
    data = input().split(" ");
    targetX = eval(data[0]);
    targetY = eval(data[1]);
    
    x = 0;
    y = 0;
    moves = aStarSearch((targetX,targetY));
    
    print("Case #"+str(caseIndex+1)+": "+moves);