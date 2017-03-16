'''
cat test_b.txt | python problem_b.py
'''

from sys import stdin
import operator

def compute_expected(keyboard, target, s):
    if s < len(target):
        return 0.0
    return (s-len(target)+1) * reduce(operator.mul, (keyboard.get(ch, 0.0) for ch in target), 1.0)

def compute_optimal(keyboard, target, s):
    l = len(target)
    if s < l:
        return 0.0
    for n in xrange(l):
        if target[n] not in keyboard:
            return 0.0
    for step in xrange(1, l+1):
        if all(target[i] == target[i+step] for i in xrange(0, l-step)):
            return (s-l)/step + 1

def main():
    tt = int(stdin.readline().strip())
    for t in xrange(1, tt+1):
        (_k, _l, s) = (int(s) for s in stdin.readline().strip().split(' '))
        keyboard = stdin.readline().strip()
        keyboard = {k:float(len([kk for kk in keyboard if kk==k]))/len(keyboard) for k in keyboard}
        #print "keyboard: {}".format(keyboard)
        target = stdin.readline().strip()
        expected = compute_expected(keyboard, target, s)
        #print "expected: {}".format(expected)
        optimal = compute_optimal(keyboard, target, s)
        #print "optimal: {}".format(expected)
        print "Case #{}: {:.6f}".format(t, optimal - expected)

main()
