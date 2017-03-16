import sys

def exec_man(sp):
    sp = reversed(sp)
    return "".join('-' if x == '+' else '+' for x in sp)

nt = int(sys.stdin.readline())
for t in xrange(1, nt + 1):
    stack = sys.stdin.readline().strip()
    ans = 0
    while '-' in stack:
        i = 1
        while i < len(stack) and stack[i] == stack[0]:
            i += 1
        stack = exec_man(stack[:i]) + stack[i:]
        ans += 1
    print "Case #%d:" % t, ans

