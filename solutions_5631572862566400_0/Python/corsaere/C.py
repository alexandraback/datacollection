INPUT_FILE = "C-test.in"
OUTPUT_FILE = "C-test.out"

class Node(object):
    def __init__(self, identity, friend):
        self.identity = identity
        self.friend = friend
        self.visited = False
    def __repr__(self):
        return str(self.identity)

with open(INPUT_FILE) as f:
    with open(OUTPUT_FILE, "w") as of:
        cases = int(f.readline())
        for case in range(1, cases+1):
            nodesList = []
            numfriends = int(f.readline())
            friends = map(int, f.readline().split())
            for friendIndex in range(len(friends)):
                nodesList.append(Node(friendIndex, friends[friendIndex]-1))
            endStartList = {}
            for node in nodesList:
                curCount = 0
                curNode = node
                start = None
                end = None
                chain = set()
                while not curNode.visited:
                    if not start:
                        start = curNode
                    print curNode
                    chain.add(curNode)
                    curNode.visited = True
                    curCount += 1
                    friendNode = nodesList[curNode.friend]
                    end = friendNode if not friendNode in chain else curNode
                    curNode = nodesList[curNode.friend]
                if end:
                    if end not in endStartList:
                        endStartList[end] = [(start, curCount)]
                    else:
                        for x in range(len(endStartList[end])):
                            if endStartList[end][x] in chain:
                                endStartList.pop(x)
                        if len(endStartList[end]) < 2:
                            endStartList[end].append((start, curCount))
                            endStartList[end] = sorted(endStartList[end], key=lambda x: x[1])
                        else:
                            if curCount > endStartList[end][0][1]:
                                endStartList[end].pop(0)
                                endStartList[end].append((start, curCount))
                                endStartList[end] = sorted(endStartList[end], key=lambda x: x[1])
            maxCount = 0 
            for entry in endStartList:
                lists = endStartList[entry]
                if len(lists) == 2:
                    curCount = 0
                    for l in lists:
                        curCount += l[1]
                else:
                    curCount = lists[0][1]
                if curCount > maxCount:
                    maxCount = curCount
            of.write("Case #{0}: {1}".format(case, maxCount))
            of.write("\n")



