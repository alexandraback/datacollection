"""
Passwords question - GCJ Round 1a
"""
import operator

def keystrokes(typed, length, probs):
    strokes = []
    prod = reduce(operator.mul, probs)
    def get_prob(string):
        if not string: return 1
        return reduce(operator.mul, [probs[i] if char == '1' else (1 - probs[i]) for i, char in enumerate(string)])
    
    # Continue typing
    cost = (length - typed + 1) * prod + (2 * length - typed + 2) * (1 - prod)
    strokes.append(cost)

    # Press enter
    strokes.append(length + 2)

    # Press backspace
    for bs in range(1, typed):
        prod = prod / probs[-bs]
        cost = (length - typed + 1 + 2 * bs) * prod + (length - typed + 1 + 2 * bs + length + 1) * (1 - prod)
        strokes.append(cost)

    return min(strokes)

def main():
    import sys
    f = open(sys.argv[1])
    out = open(sys.argv[2], 'w')
    index = 1
    lines = []
    f.next()
    while True:
        try:
            typed, length = map(int, f.next().strip().split())
            probs = map(float, f.next().strip().split())
            lines.append("Case #%d: %s" % (index, keystrokes(typed, length, probs)))
            index += 1
        except StopIteration:
            break
    out.write('\n'.join(lines))
    out.close()

if __name__ == '__main__':
    main()