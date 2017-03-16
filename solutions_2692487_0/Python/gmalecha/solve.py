from sys import stdin
import Queue

# delete largest or add (me-1)
def solve(me, rest):
    wl = Queue.PriorityQueue()
    wl.put((0, me, rest))

    while True:
        (p,me,rest) = wl.get()
        while len(rest) > 0 and me > rest[0]:
            me += rest[0]
            rest = rest[1:]
        if len(rest) == 0:
            return p

        wl.put((p+1,2*me-1,rest))
        wl.put((p+1,me,rest[:-1]))


def main():
    t = int(stdin.readline().strip())

    for c in range(1,t+1):
        (m,n) = stdin.readline().split()
        m = int(m)
        n = int(n)
        rest = [int(x) for x in stdin.readline().split()]
        rest.sort()
        
        print "Case #%d: %d" % (c, solve(m, rest))

if __name__ == '__main__':
    main()

    
