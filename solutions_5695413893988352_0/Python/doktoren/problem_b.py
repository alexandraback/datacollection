'''
cat b_test.in | python problem_b.py
cat B-small-attempt2.in | python problem_b.py >B-small.out
cat B-large-.in | python problem_b.py >B-large.out
'''

import sys

sx = None
sy = None
factors = None
to_beat = None
best_x = None
best_y = None

def solve(vx, vy, i):
    global to_beat, best_x, best_y
    if i == len(sx):
        if abs(vx - vy) < to_beat:
            best_x = vx
            best_y = vy
            to_beat = abs(vx - vy)
        return
    if vy - (vx + 10*factors[i]) > to_beat:
        return
    if vx - (vy + 10*factors[i]) > to_beat:
        return
    if sx[i] == '?' and sy[i] == '?':
        solve(vx, vy, i+1)
        solve(vx, vy + factors[i], i+1)
        solve(vx, vy + 9*factors[i], i+1)
        solve(vx + factors[i], vy, i+1)
        solve(vx + 9*factors[i], vy, i+1)
        return
    if sx[i] == '?':
        solve(vx, vy, i+1)
        if sy[i] not in '01':
            solve(vx + (int(sy[i])-1) * factors[i], vy, i+1)
        solve(vx + int(sy[i]) * factors[i], vy, i+1)
        if sy[i] not in '89':
            solve(vx + (int(sy[i])+1) * factors[i], vy, i+1)
        solve(vx + 9 * factors[i], vy, i+1)
        return
    if sy[i] == '?':
        solve(vx, vy, i+1)
        if sx[i] not in '01':
            solve(vx, vy + (int(sx[i])-1) * factors[i], i+1)
        solve(vx, vy + int(sx[i]) * factors[i], i+1)
        if sx[i] not in '89':
            solve(vx, vy + (int(sx[i])+1) * factors[i], i+1)
        solve(vx, vy + 9 * factors[i], i+1)
        return
    solve(vx, vy, i+1)

def main():
    t = int(sys.stdin.readline().strip())
    for k in xrange(t):
        global sx, sy, factors, to_beat, best_x, best_y
        sx, sy = sys.stdin.readline().strip().split(' ')
        factors = [10 ** (len(sx) - i - 1) for i in xrange(len(sx))]
        vx = sum(int(ch)*factors[i] for i, ch in enumerate(sx) if ch != '?')
        vy = sum(int(ch)*factors[i] for i, ch in enumerate(sy) if ch != '?')
        to_beat = abs(vx-vy)
        best_x = vx
        best_y = vy
        solve(vx, vy, 0)
        print "Case #{}: {}".format(k+1, ("{:0"+str(len(sx))+"} {:0"+str(len(sx))+"}").format(best_x, best_y))

main()
