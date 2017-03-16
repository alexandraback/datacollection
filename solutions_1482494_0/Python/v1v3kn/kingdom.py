"""
Kingdom Rush problem - GCJ Round 1a
"""
from collections import deque

def plays(levels):
    two_stars = deque(sorted(levels, key=lambda (i, x, y): y))
    one_stars = deque(sorted(levels, key=lambda (i, x, y): x))
    played = set()
    stars, count = 0, 0
    points = lambda x: 1 if x in played else 2

    while two_stars:
        prev = two_stars[0]
        for next in two_stars:
            if next[2] > stars:
                break
            elif points(next[0]) == 2:
                prev = next
                break
            prev = next

        if prev[2] <= stars:
            two_stars.remove(prev)
            stars += (1 if prev[0] in played else 2)
            count += 1
        elif one_stars:
            item = one_stars.popleft()
            if stars >= item[1]:
                played.add(item[0])
                stars += 1
                count += 1
            else:
                return "Too Bad"
        else: return "Too Bad"
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
            num_levels = int(f.next().strip())
            levels = []
            for i in range(num_levels):
                a, b = map(int, f.next().strip().split())
                levels.append((i, a, b))
            lines.append("Case #%d: %s" % (index, plays(levels)))
            index += 1
        except StopIteration:
            break
    out.write('\n'.join(lines))
    out.close()

if __name__ == '__main__':
    main()