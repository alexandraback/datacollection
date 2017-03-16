import sys

def reachable(h, i, j, visited):
    paths = []
    # if j in h[i]: return [j]
    for x in h[i]:
        if x==j:
            paths.append([x])
        else:
            if not x in visited:
                visited.append(x)
                paths.extend([[i]+f for f in reachable(h, x, j, visited)])
    return paths

def main(line):
        N = int(line[0])
        lines = [sys.stdin.readline().strip().split(' ') for x in range(N)]
        h = dict()
        i = 1
        for line in lines:
            M = int(line[0])
            h[i] = []
            if M > 0:
                s = [int(x) for x in line[1:]]
                h[i] = s
            i += 1
        # print h
        for i in xrange(1, N+1):
            for j in xrange(1, N+1):
                if i==j: continue
                # print i, j, reachable(h, i, j, [])
                paths = reachable(h, i, j, [])
                if len(paths) > 1:
                    return 'Yes'
        return 'No'

if __name__ == '__main__':
	N = int(sys.stdin.readline())
	for i in xrange(N):
		res = main(sys.stdin.readline().strip().split(' '))
		print "Case #%d: %s" % (i + 1, res)	
