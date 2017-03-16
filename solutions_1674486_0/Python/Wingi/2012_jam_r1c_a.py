import StringIO, sys

if len(sys.argv)>1:
    input = file(sys.argv[1]).readline
else:
    input = StringIO.StringIO("""3
8
2 2 3
1 4
1 5
0
0
2 7 8
0
0
5
2 2 3
1 4
1 5
1 5
0
3
2 2 3
1 3
0""").readline


def solve(lines):
    #print lines
    visitors = [set() for x in range(len(lines))]

    #looking for all node who has parent
    hasParent = set()
    for parents in lines:
        for parent in parents:
            hasParent.add(parent)

    #start with all node without parents
    stack = []
    for node in range(1,len(lines)):
        if node not in hasParent:
            stack.append( (node,node) )

    #print stack, hasParent
    #work until stack empty or hit node
    while stack:
        #print stack
        (start, wayPoint) = stack.pop()
        if start in visitors[wayPoint]:
            return "Yes"
        visitors[wayPoint].add(start)
        for next in lines[wayPoint]:
            #print "%d -> %d" % (wayPoint, next)
            stack.append( (start, next) )
    return "No"

for case in range(int(input())):
    lines = ["-"]
    for line in range(int(input())):
        lines.append(map(int, input().split())[1:])
    print "Case #%d: %s" % (case+1, solve(lines))
