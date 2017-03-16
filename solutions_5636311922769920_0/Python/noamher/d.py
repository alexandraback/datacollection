import os
import sys
from sets import Set


def main():
    if len(sys.argv) != 2:
        print 'usage: a.py <input_file>'
        sys.exit(1)

    with open(sys.argv[1], 'r') as f, open('res', 'w') as out:
        [count] = map(int, f.readline().split())
        for i in xrange(count):
            [K, C, S] = f.readline().split()
            out.write('Case #' + str(i+1) + ': ' + str(find(int(K), int(C), int(S))) + '\n')

def find(K, C, S):
    if S * C < K:
        return 'IMPOSSIBLE'

    remains = set(range(K))
    poses = []
    while len(remains) > 0:
        pos = 0
        for i in range(C):
            next = 0
            if len(remains) > 0:
                next = remains.pop()
            pos += next * (K ** i)
        poses.append(pos+1)

    if len(poses) > S:
        raise Exception("illegal state")
    return ' '.join([str(x) for x in poses])


if __name__ == "__main__":
    main()