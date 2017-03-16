import sys

def winningWord(given):
    res = ''
    for letter in given:
        res = max(res+letter, letter+res)
    return res

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        word = inp.readline().strip()
        print "Case #%d: %s" % (cs, winningWord(word))

if __name__ == '__main__':
    _doMain()

