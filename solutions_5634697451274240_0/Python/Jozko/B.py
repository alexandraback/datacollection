import sys
T = int(sys.stdin.readline())
for case in range(1, T+1):
    sys.stdout.write("Case #%d: " % case)
    pancakes = sys.stdin.readline().strip()
    N = len(pancakes)
    goal = '+'*N
    states = set()
    states.add((pancakes, 0))
    found = False
    while not found:
        new_states = set()
        for (p, steps) in states:
            if p == goal:
                found = True
                sys.stdout.write('%d\n' % steps)
                break
            swp = ''.join(map(lambda x: '+' if x=='-' else '-', p[::-1]))
            for i in range(1, N+1):
                new_states.add((swp[-i:] + p[i:], steps+1))
        states = new_states
