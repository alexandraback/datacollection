from collections import deque

def solve(b, t):
    #print b, t
    while len(t) and len(b):
        if t[0][1] != b[0][1]:
            t.popleft()
        else:
            break
    if (not len(t)) or (not len(b)):
        return 0
    nums = []
    while len(t) and len(b):
        #temp1, temp2 = deque(b), deque(t)
        #temp1.popleft()
        #temp2.popleft()
        if b[0][0] > t[0][0]:
            n = t[0][0]
            tnew = deque(t)
            tnew.popleft()
            bnew = deque(b)
            bnew[0][0] -= n
            nums.append(solve(deque(bnew), deque(tnew)) + n)
        if b[0][0] < t[0][0]:
            n = b[0][0]
            bnew = deque(b)
            bnew.popleft()
            tnew = deque(t)
            tnew[0][0] -= n
            nums.append(solve(deque(bnew), deque(tnew)) + n)
        b1 = b.popleft()
        t1 = t.popleft()
        nums.append(solve(deque(b), deque(t)) + min(b1[0], t1[0]))
        #while len(t) and len(b) and t[0][1] != b[0][1]:
            #t.popleft()
    #print nums
    return max(nums)

T = int(raw_input())

for case in range(T):
    N, M = [int(i) for i in raw_input().split()]
    box, toy = deque(), deque()
    line = raw_input().split()
    for i in range(N):
        box.append([int(line[2*i]), int(line[2*i+1])])
    line = raw_input().split()
    for i in range(M):
        toy.append([int(line[2*i]), int(line[2*i+1])])
    #print box, toy
    nums = []
    while len(box):
        #print "start", box, toy
        nums.append(solve(deque(box), deque(toy)))
        #print "nums", nums
        if not len(box):
            break
        box.popleft()
    print "Case #{0}: {1}".format(case+1, max(nums))
        
