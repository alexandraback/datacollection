import sys

def findMaxOccur(target, presses):
    ln = len(target)
    common = 0
    for i in range(1, ln):
        if target[-i:] == target[:i]:
            common = i
    return (presses-ln) / (ln-common) + 1

def findExpectedOccur(keydist, target, presses):
    nkeys = sum(keydist.values())
    prod = 1
    for letter in target:
        prod *= keydist[letter] / float(nkeys)
    return prod * (presses - len(target) + 1)


def doMain():
    ncases = int(sys.stdin.readline())
    for cs in range(1, ncases+1):
        K, L, presses = [int(part) for part in sys.stdin.readline().split()]
        keyboard = sys.stdin.readline().strip()
        target = sys.stdin.readline().strip()
        assert len(keyboard) == K and len(target) == L
        keydist = {letter: keyboard.count(letter) for letter in [chr(ord('A') + i) for i in range(26)]}
        assert sum(keydist.values()) == K
        if presses<L or any(keydist[letter] == 0 for letter in target):
            expleft = 0
        else:
            maxoccur = findMaxOccur(target, presses)
            expoccur = findExpectedOccur(keydist, target, presses)
            expleft = maxoccur-expoccur
        print 'Case #%d: %s' % (cs, expleft)

if __name__ == "__main__":
    doMain()
