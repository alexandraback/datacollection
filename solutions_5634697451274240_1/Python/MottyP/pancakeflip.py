import sys

def solveCase(state):
    state += '+'
    return len([i for i in range(len(state)-1) if state[i] != state[i+1]])

def _doMain():
    inp = sys.stdin
    ncases = int(inp.readline())
    for cs in range(1, ncases+1):
        state = inp.readline().strip()
        flipnum = solveCase(state)
        print "Case #%d: %d" % (cs, flipnum)

if __name__ == '__main__':
    _doMain()

