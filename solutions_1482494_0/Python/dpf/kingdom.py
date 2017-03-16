import heapq, sys
def foo(n, pairs):
    stars_per_level = {}
    for i in xrange(n):
        stars_per_level[i] = 0
    rem_levels = n
    one_heap = []
    two_heap = []
    for level,(a,b) in enumerate(pairs):
        heapq.heappush(one_heap, (a, level))
        heapq.heappush(two_heap, (b, level))
    count = 0
    stars = 0
    while one_heap != [] and two_heap != []:
        if two_heap[0][0] <= stars:
            req, level = heapq.heappop(two_heap)
            reward = 2
        elif one_heap[0][0] <= stars:
            req, level = heapq.heappop(one_heap)
            reward = 1
        else:
            return False
        if rem_levels == 0:
            return count
        if stars_per_level[level] == 1 and reward == 2:
            stars += 1
            rem_levels -= 1
            count += 1
        elif stars_per_level[level] == 0:
            if reward == 2:
                count += 1
                rem_levels -= 1
                stars += 2
            else:
                count += 1
                stars += 1
    return count if rem_levels == 0 else False

y = int(sys.stdin.readline())
for i in xrange(1, y+1):
    bound = int(sys.stdin.readline().split()[0])
    pairs = []
    for j in xrange(bound):
        line = sys.stdin.readline().split()
        pairs.append((int(line[0]), int(line[1])))
    y = foo(bound, pairs)
    print "Case #"+str(i)+":",
    if y:
        print y
    else:
        print "Too Bad"

