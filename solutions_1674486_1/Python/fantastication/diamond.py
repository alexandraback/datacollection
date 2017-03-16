import sys

def check(n, path):
    #print "path to", n, ": ", path
    parents = classes[n-1]
    for parent in parents:
        if parent == -1:
            continue
        if parent in path:
            #print "FOUND", path
            return True
        else:
            path.append(parent)
            #print "adding", parent
    for parent in parents:
        if check(parent, path):
            return True
    return False

sys.setrecursionlimit(1000000)

inp = open("input.txt", "r")
out = open("output.txt", "w")

num_cases = int(inp.readline())
for case in xrange(num_cases):
    #print "\nnew case:", case+1
    num_classes = int(inp.readline())
    classes = []
    for i in xrange(num_classes):
        cl = [int(a) for a in inp.readline().split()]
        if cl[0]:
            classes.append(cl[1:])
        else:
            classes.append([])
    #print "classes:", classes
    hooray = False
    for i in xrange(num_classes):
        if check(i + 1, []):
            hooray = True
            break
    if hooray:
        out.write("Case #{0}: Yes\n".format(case+1))
    else:
        out.write("Case #{0}: No\n".format(case+1))


