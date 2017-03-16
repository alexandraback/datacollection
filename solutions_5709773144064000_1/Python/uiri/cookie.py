import sys

stdin = sys.stdin.readlines()
cases = int(stdin.pop(0))
for case in xrange(1, cases+1):
    seconds = 0.0
    dcdt = 2.0
    nums = stdin.pop(0).split(' ')
    goal = float(nums.pop())
    inc = float(nums.pop())
    cost = float(nums.pop())
    while (goal/dcdt) > (goal/(dcdt+inc) + cost/dcdt):
        seconds += cost/dcdt
        dcdt += inc
    seconds += goal/dcdt
    print "Case #"+str(case)+": "+str(round(seconds, 7))
