def is_ready(pan, target):
    for p in pan:
        if p != target:
            return False
    return True

def solve(pan, target):
    if is_ready(pan, target):
        return 0
    nextTarget = pan[-1]
    if target == pan[-1]:
        return solve(pan[0:len(pan)-1], nextTarget)
    else:
        return solve(pan[0:len(pan)-1], nextTarget)+1

T = int(raw_input())
for t in range(1, T+1):
    pan = list(raw_input().rstrip())
    step = solve(pan, '+')
    print("Case #%d: %d" % (t, step))
