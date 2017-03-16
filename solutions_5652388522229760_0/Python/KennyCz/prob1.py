import sys
from sets import Set



def answer(n):
    if n == 0:
        return 'INSOMNIA'
    res = 0
    digs = Set([])
    for i in range(1000):
        res += n
        digs |= Set(str(res))
        if len(digs) == 10:
            return res


if __name__ == "__main__":

    T = int(sys.stdin.next())
    queries = []
    for i in range(T):
        queries.append(int(sys.stdin.next()))
    for i,n in enumerate(queries):
        print "".join(["Case #", str(i+1), ": ", str(answer(n))])

