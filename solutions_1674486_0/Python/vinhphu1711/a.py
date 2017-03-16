import sys

class MyQUEUE: # just an implementation of a queue

    def __init__(self):
    	self.holder = []

    def enqueue(self,val):
    	self.holder.append(val)

    def dequeue(self):
    	val = None
    	try:
    		val = self.holder[0]
    		if len(self.holder) == 1:
    			self.holder = []
    		else:
    			self.holder = self.holder[1:]	
    	except:
    		pass

    	return val	

    def IsEmpty(self):
    	result = False
    	if len(self.holder) == 0:
    		result = True
    	return result


path_queue = MyQUEUE() # now we make a queue


def BFS(graph,start,end,q):
    res = []
    temp_path = [start]

    q.enqueue(temp_path)

    while q.IsEmpty() == False:
    	tmp_path = q.dequeue()
    	last_node = tmp_path[len(tmp_path)-1]
    	if last_node == end:
    		res.append(tmp_path)
    	for link_node in graph[last_node]:
    		if link_node not in tmp_path:
    			#new_path = []
    			new_path = tmp_path + [link_node]
    			q.enqueue(new_path)
    return res

T = int(raw_input())

for num_t in range(T):
    res = None
    N = int(raw_input())
    inherits = {}
    inherited = {}
    for n in range(N):
        n += 1
        inherits[n] = [int(i) for i in raw_input().split(' ')][1:]
        
        for z in inherits[n]:
            inherited.setdefault(z,[])
            inherited[z].append(n)
    
    pos_start = [i for i in inherits if len(inherits[i]) > 1]
    pos_end = [i for i in inherited if len(inherited[i]) > 1]
    
    if (not pos_start) or (not pos_end):
        res = False
    else:
        for p1 in pos_start:
            for p2 in pos_end:
                if len(BFS(inherits, p1, p2, path_queue)) > 1:
                    res = True
                    break
        
    print 'Case #%d: %s' % (num_t+1, 'Yes' if res else 'No')