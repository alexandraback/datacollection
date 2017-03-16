memoized = {}


def compute(N):
    # if N in memoized:
    #     return memoized[N]
    seen = set([])
    queue = [(1, 1)]
    # print 'N', N, N == 1
    while queue[0][0] != N:
        # print queue
        if queue[0][0] in seen:
            # print 'seen'
            queue.pop(0)
            continue
        current, steps = queue.pop(0)
        seen.add(current)
        # memoized[current] = min(memoized.get(current) or steps, steps)
        # print current, steps
        # break
        # print current, steps
        queue.append((current + 1, steps + 1))
        # rev = int(str(current)[::-1])
        queue.append((int(str(current)[::-1]), steps + 1))
        # seen.update([current + 1, rev])
    return queue[0][1]
    # print c, N
    # if c == N:
    #     return 0
    # if c == N - 1:
    #     return 1
    # if (c, N) in memoized:
    #     return memoized[c, N]
    # return 1 + min(compute(c+1, N), compute(int(str(c)[::-1]), N))

input_file = open('a-small.in')
cases = int(input_file.readline().strip())
case = 0
while case < cases:
    case += 1
    N = int(input_file.readline())
    print "Case #{}: {}".format(case, compute(N))
