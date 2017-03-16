"""
Recycled numbers problem - Code jam
"""
from collections import defaultdict

def count_recycled(a, b):
    count = 0
    for num in range(a, b+1):
        num_string = str(num)
        candidates = (num_string[i:] + num_string[:i] for i in  range(1, len(num_string)))
        candidates = filter(lambda x: num < int(x) <= b, candidates)
        count += len(set(candidates))
    return count

def main():
    import sys
    f = open(sys.argv[1])
    out = open(sys.argv[2], 'w')
    index = 1
    lines = []
    f.next()
    while True:
        try:
            a, b = map(int, f.next().split())
            lines.append("Case #%d: %d" % (index, count_recycled(a, b)))
            index += 1
        except StopIteration:
            break
    out.write('\n'.join(lines))
    out.close()

if __name__ == '__main__':
    main()